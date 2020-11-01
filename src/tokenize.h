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

#ifndef VM_TOKENIZE_H
#define VM_TOKENIZE_H

#include "string.h"
#include "types.h"

enum Token
{
	TOKEN_INSTRUCTION,
	TOKEN_INVALID,
	TOKEN_NEWLINE,
	TOKEN_WHITESPACE,
	TOKEN_COMMA,
	TOKEN_LABEL,
	TOKEN_CONST,
	TOKEN_REGISTER,
	TOKEN_LENGTH
};

static const char *token_text[] = { [TOKEN_INSTRUCTION] = "instruction",
				    [TOKEN_INVALID]	= "invalid",
				    [TOKEN_NEWLINE]	= "newline",
				    [TOKEN_WHITESPACE]	= "whitespace",
				    [TOKEN_COMMA]	= "comma",
				    [TOKEN_LABEL]	= "label",
				    [TOKEN_CONST]	= "const",
				    [TOKEN_REGISTER]	= "register" };

typedef struct
{
	u32 index_start;
	u32 index_end;
	enum Token token;
} TokenItem;

typedef struct
{
	u32 token_items_allocated;
	u32 token_items_length;
	u32 token_items_index;

	TokenItem *token_items;
	String *program_string_text;
} TokenStream;

TokenStream *tokenstream_new(String *, u32);
void tokenstream_free(TokenStream *);
TokenStream *tokenize_program_code(String *);

#endif //VM_TOKENIZE_H
