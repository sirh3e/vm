/*
* BSD 3-Clause License
*
* Copyright (c) 2020, Huber Marvin <marvin dot huber at protonmail dot com>
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* * Redistributions of source code must retain the above copyright notice, this
*   list of conditions and the following disclaimer.
*
* * Redistributions in binary form must reproduce the above copyright notice,
*   this list of conditions and the following disclaimer in the documentation
*   and/or other materials provided with the distribution.
*
* * Neither the name of the copyright holder nor the names of its
*   contributors may be used to endorse or promote products derived from
*   this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "tokenize.h"

#include "assert.h"
#include "config.h"
#include "types.h"

#include <stdlib.h>

#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Winitializer-overrides"
#pragma GCC diagnostic ignored "-Woverride-init"

#define STRING_DATA_ALLOCATED 4096

#define TOKEN_STREAM_TOKEN_ITEM_GET_NEXT(stream, token_item)                   \
	token_item = tokenstream_get_token(stream);                            \
	stream->token_items_index++;                                           \
	stream->token_items_length++;

#define TOKEN_STREAM_TOKEN_ITEM_PUSH(token_item)                               \
	token_item->index_start = index_start;                                 \
	token_item->index_end	= index_end;                                   \
	token_item->token	= token

#define STATE_INVALID_DEFAULT [0 ... 255] = &&label_invalid

#define STATE_NEWLINE(label)  ['\n'] = &&label
#define STATE_NEWLINE_DEFAULT STATE_NEWLINE(label_newline)

#define STATE_WHITESPACE(label)	 [' '] = &&label
#define STATE_WHITESPACE_DEFAULT STATE_WHITESPACE(label_whitespace)

#define STATE_ALPHABET_UPPER(label)  /* A-Z */ [65 ... 90] = &&label
#define STATE_ALPHABET_UPPER_DEFAULT STATE_ALPHABET_UPPER(label_instruction)

#define STATE_ALPHABET_LOWER(label)  /* a-z */ [97 ... 122] = &&label
#define STATE_ALPHABET_LOWER_DEFAULT STATE_ALPHABET_LOWER(label_instruction)

#define STATE_CONST(label)                                                     \
	/* 0-9 */ [48 ... 57] = &&label,                                       \
			  /* A-Z */ STATE_ALPHABET_UPPER(label),               \
			  /* a-z */ STATE_ALPHABET_LOWER(label)

#define STATE_CONST_DEFAULT STATE_CONST(label_const)

#define STATE_REGISTER(label)  ['%'] = &&label
#define STATE_REGISTER_DEFAULT STATE_REGISTER(label_register)

#define STATE_COMMA(label)  [','] = &&label
#define STATE_COMMA_DEFAULT STATE_COMMA(label_comma)

#define STATE_COLON(label)  [':'] = &&label
#define STATE_COLON_DEFAULT STATE_COLON(label_colon)

//INSTRUCTION-WHITESPACE-*{TOKEN_REGISTER/TOKEN_STACK/TOKEN_CONST}
//  INSTRUCTION-{:,WHITESPACE}-{TOKEN_REGISTER/TOKEN_STACK/TOKEN_CONST}{,/\n}

#define LABEL_STATEMENT(stream, token_item, _token)                            \
	index_end = current - start - 1;                                       \
	TOKEN_STREAM_TOKEN_ITEM_GET_NEXT(stream, token_item);                  \
	TOKEN_STREAM_TOKEN_ITEM_PUSH(token_item);                              \
                                                                               \
	index_start = current - start;                                         \
	token	    = _token

TokenStream *tokenstream_new(String *program_string_text,
			     u32 token_items_allocate)
{
	TokenStream *tokenstream = (TokenStream *)malloc(sizeof(TokenStream));
	tokenstream->token_items_allocated = token_items_allocate;
	tokenstream->token_items_length	   = 0;
	tokenstream->token_items_index	   = 0;
	tokenstream->token_items	   = (TokenItem *)malloc(
		  sizeof(TokenItem) * tokenstream->token_items_allocated);

	tokenstream->program_string_text = program_string_text;

	return tokenstream;
}

void tokenstream_free(TokenStream *tokenstream)
{
	if (tokenstream == NULL)
		return;

	free(tokenstream->token_items);
	string_free(tokenstream->program_string_text);
	free(tokenstream);
	tokenstream = NULL;
}

TokenStream *tokenize_program_code(String *program_string_text)
{
	enum Token token = TOKEN_INSTRUCTION;
	TokenItem *token_item;

	static void *state_instruction[] = {
		STATE_INVALID_DEFAULT,
		//default:
		STATE_ALPHABET_LOWER(label_loop),
		STATE_ALPHABET_UPPER(label_loop),
		//custom:
		STATE_COLON_DEFAULT,
		//whitespace:
		STATE_WHITESPACE_DEFAULT,
		//newline:
		STATE_NEWLINE_DEFAULT,
	};

	static void *state_label[] = {
		STATE_INVALID_DEFAULT,
		//newline:
		STATE_NEWLINE_DEFAULT,
	};

	static void *state_whitespace[] = {
		STATE_INVALID_DEFAULT,
		//default:
		STATE_WHITESPACE(label_loop),

		//custom:
		STATE_CONST_DEFAULT,
		STATE_REGISTER_DEFAULT,

		//newline:
		STATE_NEWLINE_DEFAULT,
	};

	static void *state_const[] = {
		STATE_INVALID_DEFAULT,
		//default:
		STATE_CONST(label_loop),
		//custom:
		STATE_COMMA_DEFAULT,
		//whitespace:
		//newline:
		STATE_NEWLINE_DEFAULT,
	};

	static void *state_comma[] = {
		STATE_INVALID_DEFAULT,
		//default:
		STATE_COMMA(label_loop),
		//custom:
		//whitespace:
		STATE_WHITESPACE_DEFAULT,
		//newline:
	};

	static void *state_newline[] = {
		STATE_INVALID_DEFAULT,
		//default:
		STATE_NEWLINE(label_loop),
		//custom:
		STATE_ALPHABET_LOWER_DEFAULT,
		STATE_ALPHABET_UPPER_DEFAULT,
		//whitespace:
		//newline:
	};

	static void *state_register[] = {
		STATE_INVALID_DEFAULT,
		//default
		STATE_ALPHABET_LOWER(label_loop),
		STATE_ALPHABET_UPPER(label_loop),
		//custom:
		STATE_COMMA_DEFAULT,
		//whitespace:
		//newline:
		STATE_NEWLINE_DEFAULT,
	};

	void **go = state_instruction;

	TokenStream *stream =
		tokenstream_new(program_string_text, TOKEN_ITEMS_ALLOCATED);
	if (stream == NULL)
	{
		exit(1);
	}

	if (stream->token_items == NULL)
	{
		exit(1);
	}

	u32 index_start = 0, index_end = 0;
	char *current, *start, *end;
	for (current = start = program_string_text->data,
	    end		     = current + stream->program_string_text->length;
	     current < end;
	     current++)
	{
		goto *go[(u8)*current];
label_loop:;
	}

	index_end = current - start - 1;
	TOKEN_STREAM_TOKEN_ITEM_GET_NEXT(stream, token_item);
	TOKEN_STREAM_TOKEN_ITEM_PUSH(token_item);

	stream->token_items_index = 0; //ToDo remove this attribute
	return stream;

label_const:

	LABEL_STATEMENT(stream, token_item, TOKEN_CONST);

	go = state_const;
	goto label_loop;

label_newline:

	LABEL_STATEMENT(stream, token_item, TOKEN_NEWLINE);

	go = state_newline;
	goto label_loop;

label_comma:

	LABEL_STATEMENT(stream, token_item, TOKEN_COMMA);

	go = state_comma;
	goto label_loop;

label_whitespace:

	LABEL_STATEMENT(stream, token_item, TOKEN_WHITESPACE);

	go = state_whitespace;
	goto label_loop;

label_colon:

	token = TOKEN_LABEL;

	go = state_label;
	goto label_loop;

label_instruction:

	LABEL_STATEMENT(stream, token_item, TOKEN_INSTRUCTION);

	go = state_instruction;
	goto label_loop;

label_register:

	LABEL_STATEMENT(stream, token_item, TOKEN_REGISTER);

	go = state_register;
	goto label_loop;

label_invalid:

	LABEL_STATEMENT(stream, token_item, TOKEN_INVALID);

	go = state_instruction;
	goto label_loop;
}