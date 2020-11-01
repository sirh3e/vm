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

	TEST_ASSERT(stream != NULL);
	TEST_ASSERT(stream->program_string_text->length ==
		    (strlen(program_text) + 1));
	TEST_ASSERT(strcmp(stream->program_string_text->data, program_text) ==
		    0);
	TEST_ASSERT(stream->token_items_allocated == amount);
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

	TokenStream *stream = tokenize_program_code(program_string);

	TEST_ASSERT(stream != NULL);
	TEST_ASSERT(stream->program_string_text->length ==
		    (strlen(program_text) + 1));
	TEST_ASSERT(strcmp(stream->program_string_text->data, program_text) ==
		    0);
	TEST_ASSERT(stream->token_items_allocated == amount);
	TEST_ASSERT(stream->token_items_length == 0);
	TEST_ASSERT(stream->token_items_index == 0);

	TokenItem token_item;

	//printf("%d\n", stream->token_items_length);
	for (int i = 0; i < stream->token_items_length; i++)
	{
		printf("%s\n", token_text[stream->token_items[i].token]);
	}

	token_item = stream->token_items[0];
	TEST_ASSERT(token_item.token == TOKEN_INSTRUCTION);
	TEST_ASSERT(token_item.index_start == 0);
	TEST_ASSERT(token_item.index_end == 3);

	TEST_END(test_results);
	return test_results;
}