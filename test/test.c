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

#include <stdio.h>

int main()
{
	test_vm_result TEST_RESULTS_INIT(test_result);
	test_vm_result TEST_RESULTS_INIT(test_results);

	u32 instruction_length = ARRAY_LENGTH(instructions);
	u32 tests_length       = ARRAY_LENGTH(test_instructions);

	for (u32 i = 0; i < tests_length; i++)
	{
		test_result = test_instructions[i]();
		RESULTS_ADD_RESULT(test_results, test_result);
	}

	TEST_BEGIN();

	TEST_ASSERT_MESSAGE(instruction_length == INSTRUCTION_LENGTH,
			    "checks if all instruction are in instructions");
	TEST_ASSERT_MESSAGE(tests_length == INSTRUCTION_LENGTH,
			    "checks if all instructions got a test function");

	test_result = test_string();
	RESULTS_ADD_RESULT(test_results, test_result);

	test_result = test_tokenstream();
	RESULTS_ADD_RESULT(test_results, test_result);

	TEST_END(test_results);

	return test_results.failed;
}