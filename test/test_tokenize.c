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

#include "test.h"

#include <string.h>

test_vm_result test_tokenstream_new();
test_vm_result test_tokenstream_free();
test_vm_result test_tokenize_program_code();

test_vm_result test_tokenstream()
{
	test_vm_result TEST_RESULTS_INIT(test_result);
	test_vm_result TEST_RESULTS_INIT(test_results);

	test_result = test_tokenstream_new();
	RESULTS_ADD_RESULT(test_results, test_result);

	test_result = test_tokenstream_free();
	RESULTS_ADD_RESULT(test_results, test_result);

	test_result = test_tokenize_program_code();
	RESULTS_ADD_RESULT(test_results, test_result);

	return test_results;
}

test_vm_result test_tokenstream_new()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	TEST_BEGIN();

	char *program_text = { "push 1000\n"
			       "load %rd\n"
			       "log %rd\n"
			       "\n"
			       "mylabel:\n"
			       "inc %rc, 1\n"
			       "jl mylabel\n"
			       "\n"
			       "halt" };

	String *program_string = string_new();
	string_init(program_string, program_text);

	TokenStream *stream =
		tokenstream_new(program_string, TOKEN_ITEMS_ALLOCATED);

	TEST_ASSERT(stream != NULL);
	TEST_ASSERT(stream->program_string_text->length ==
		    (strlen(program_text) + 1));
	TEST_ASSERT(strcmp(stream->program_string_text->data, program_text) ==
		    0);
	TEST_ASSERT(stream->token_items_allocated == TOKEN_ITEMS_ALLOCATED);
	TEST_ASSERT(stream->token_items_length == 0);
	TEST_ASSERT(stream->token_items_index == 0);

	tokenstream_free(stream);

	TEST_END(test_results);
	return test_results;
}

test_vm_result test_tokenstream_free()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	TEST_BEGIN();

	u32 amount	   = 8192;
	char *program_text = { "push 1000\n"
			       "load %rd\n"
			       "log %rd\n"
			       "\n"
			       "mylabel:\n"
			       "inc %rc, 1\n"
			       "jl mylabel\n"
			       "\n"
			       "halt" };

	String *program_string = string_new();
	string_init(program_string, program_text);

	TokenStream *stream = tokenstream_new(program_string, amount);
	tokenstream_free(stream);

	TEST_END(test_results);
	return test_results;
}

test_vm_result test_tokenize_program_code()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	TEST_BEGIN();

	char *program_text = { "push 1000\n"
			       "load %rd\n"
			       "log %rd\n"
			       "\n"
			       "mylabel:\n"
			       "inc %rc, 1\n"
			       "jl mylabel\n"
			       "\n"
			       "halt" };

	String *program_string = string_new();
	string_init(program_string, program_text);

	TokenStream *stream = tokenize_program_code(program_string);

	TEST_ASSERT(stream != NULL);
	TEST_ASSERT(stream->program_string_text->length ==
		    (strlen(program_text) + 1));
	TEST_ASSERT(strcmp(stream->program_string_text->data, program_text) ==
		    0);
	TEST_ASSERT(stream->token_items_allocated == TOKEN_ITEMS_ALLOCATED);
	TEST_ASSERT(stream->token_items_length == 27);
	TEST_ASSERT(stream->token_items_index == 0);

	u32 token_item_index = 0;
	TokenItem *token_item;

	//"push 1000\n"
	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"push"
	TEST_ASSERT(token_item->token == TOKEN_INSTRUCTION);
	TEST_ASSERT(token_item->index_start == 0);
	TEST_ASSERT(token_item->index_end == 3);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//" "
	TEST_ASSERT(token_item->token == TOKEN_WHITESPACE);
	TEST_ASSERT(token_item->index_start == 4);
	TEST_ASSERT(token_item->index_end == 4);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"1000"
	TEST_ASSERT(token_item->token == TOKEN_CONST);
	TEST_ASSERT(token_item->index_start == 5);
	TEST_ASSERT(token_item->index_end == 8);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"\n"
	TEST_ASSERT(token_item->token == TOKEN_NEWLINE);
	TEST_ASSERT(token_item->index_start == 9);
	TEST_ASSERT(token_item->index_end == 9);

	//"load %rd\n"
	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"load"
	TEST_ASSERT(token_item->token == TOKEN_INSTRUCTION);
	TEST_ASSERT(token_item->index_start == 10);
	TEST_ASSERT(token_item->index_end == 13);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//" "
	TEST_ASSERT(token_item->token == TOKEN_WHITESPACE);
	TEST_ASSERT(token_item->index_start == 14);
	TEST_ASSERT(token_item->index_end == 14);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"%rd"
	TEST_ASSERT(token_item->token == TOKEN_REGISTER);
	TEST_ASSERT(token_item->index_start == 15);
	TEST_ASSERT(token_item->index_end == 17);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"\n"
	TEST_ASSERT(token_item->token == TOKEN_NEWLINE);
	TEST_ASSERT(token_item->index_start == 18);
	TEST_ASSERT(token_item->index_end == 18);

	//"log %rd\n"
	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"log"
	TEST_ASSERT(token_item->token == TOKEN_INSTRUCTION);
	TEST_ASSERT(token_item->index_start == 19);
	TEST_ASSERT(token_item->index_end == 21);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//" "
	TEST_ASSERT(token_item->token == TOKEN_WHITESPACE);
	TEST_ASSERT(token_item->index_start == 22);
	TEST_ASSERT(token_item->index_end == 22);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"%rd"
	TEST_ASSERT(token_item->token == TOKEN_REGISTER);
	TEST_ASSERT(token_item->index_start == 23);
	TEST_ASSERT(token_item->index_end == 25);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"\n\n"
	TEST_ASSERT(token_item->token == TOKEN_NEWLINE);
	TEST_ASSERT(token_item->index_start == 26);
	TEST_ASSERT(token_item->index_end == 27);

	//"mylabel:\n"
	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"mylabel:"
	TEST_ASSERT(token_item->token == TOKEN_LABEL);
	TEST_ASSERT(token_item->index_start == 28);
	TEST_ASSERT(token_item->index_end == 35);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"\n"
	TEST_ASSERT(token_item->token == TOKEN_NEWLINE);
	TEST_ASSERT(token_item->index_start == 36);
	TEST_ASSERT(token_item->index_end == 36);

	//"inc %rc, 1\n"
	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"inc"
	TEST_ASSERT(token_item->token == TOKEN_INSTRUCTION);
	TEST_ASSERT(token_item->index_start == 37);
	TEST_ASSERT(token_item->index_end == 39);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//" "
	TEST_ASSERT(token_item->token == TOKEN_WHITESPACE);
	TEST_ASSERT(token_item->index_start == 40);
	TEST_ASSERT(token_item->index_end == 40);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"%rc"
	TEST_ASSERT(token_item->token == TOKEN_REGISTER);
	TEST_ASSERT(token_item->index_start == 41);
	TEST_ASSERT(token_item->index_end == 43);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//","
	TEST_ASSERT(token_item->token == TOKEN_COMMA);
	TEST_ASSERT(token_item->index_start == 44);
	TEST_ASSERT(token_item->index_end == 44);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//" "
	TEST_ASSERT(token_item->token == TOKEN_WHITESPACE);
	TEST_ASSERT(token_item->index_start == 45);
	TEST_ASSERT(token_item->index_end == 45);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"1"
	TEST_ASSERT(token_item->token == TOKEN_CONST);
	TEST_ASSERT(token_item->index_start == 46);
	TEST_ASSERT(token_item->index_end == 46);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"\n"
	TEST_ASSERT(token_item->token == TOKEN_NEWLINE);
	TEST_ASSERT(token_item->index_start == 47);
	TEST_ASSERT(token_item->index_end == 47);

	//"jl mylabel\n\n"
	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"jl"
	TEST_ASSERT(token_item->token == TOKEN_INSTRUCTION);
	TEST_ASSERT(token_item->index_start == 48);
	TEST_ASSERT(token_item->index_end == 49);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//" "
	TEST_ASSERT(token_item->token == TOKEN_WHITESPACE);
	TEST_ASSERT(token_item->index_start == 50);
	TEST_ASSERT(token_item->index_end == 50);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"mylabel"
	TEST_ASSERT(token_item->token == TOKEN_CONST);
	TEST_ASSERT(token_item->index_start == 51);
	TEST_ASSERT(token_item->index_end == 57);

	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"\n\n"
	TEST_ASSERT(token_item->token == TOKEN_NEWLINE);
	TEST_ASSERT(token_item->index_start == 58);
	TEST_ASSERT(token_item->index_end == 59);

	//"halt"
	token_item = tokenstream_get_token_by_index(stream, token_item_index++);
	//"halt"
	TEST_ASSERT(token_item->token == TOKEN_INSTRUCTION);
	TEST_ASSERT(token_item->index_start == 60);
	TEST_ASSERT(token_item->index_end == 63);

	tokenstream_free(stream);

	TEST_END(test_results);
	return test_results;
}