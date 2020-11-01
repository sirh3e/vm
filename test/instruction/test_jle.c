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

#include "../test.h"

test_vm_result test_vm_instruction_jle_equals();

test_vm_result test_vm_instruction_jle_less();

test_vm_result test_vm_instruction_jle()
{
	test_vm_result TEST_RESULTS_INIT(test_result);
	test_vm_result TEST_RESULTS_INIT(test_results);

	test_result = test_vm_instruction_jle_equals();
	test_results.failed += test_result.failed;
	test_results.passed += test_result.passed;

	test_result = test_vm_instruction_jle_less();
	test_results.failed += test_result.failed;
	test_results.passed += test_result.passed;

	return test_results;
}

test_vm_result test_vm_instruction_jle_equals()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	i32 program[] = { INSTRUCTION_LABEL,

			  INSTRUCTION_PUSH,
			  1,
			  INSTRUCTION_PUSH,
			  2,
			  INSTRUCTION_POP,
			  C,
			  INSTRUCTION_POP,
			  D,
			  // will not pass C = 2, D = 1
			  INSTRUCTION_JLE,
			  0,
			  INSTRUCTION_NOP,

			  INSTRUCTION_PUSH,
			  1,
			  INSTRUCTION_POP,
			  C,
			  // will pass C = 1, D = 1
			  INSTRUCTION_JLE,
			  0,
			  INSTRUCTION_NOP };

	VM_INIT(program);
	TEST_BEGIN();

	for (int i = 0; i < 5; ++i)
	{
		TEST_ASSERT(vm->instruction_index == 0);
		TEST_ASSERT(vm->instructions[vm->instruction_index] ==
			    INSTRUCTION_LABEL);
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // label

		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // push 1
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // push 2
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // pop C
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // pop D

		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // je C = 2, D = 1 false

		TEST_ASSERT(vm->instruction_index == 11);
		TEST_ASSERT(vm->instructions[vm->instruction_index] ==
			    INSTRUCTION_NOP);

		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // nop
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // push 1
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // pop C

		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // je C = 1, D = 1 true
	}

	TEST_END(vm, test_results);

	return test_results;
}

test_vm_result test_vm_instruction_jle_less()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	i32 program[] = { INSTRUCTION_LABEL,

			  INSTRUCTION_PUSH,
			  1,
			  INSTRUCTION_PUSH,
			  2,
			  INSTRUCTION_POP,
			  C,
			  INSTRUCTION_POP,
			  D,
			  // will not pass C = 2, D = 1
			  INSTRUCTION_JLE,
			  0,
			  INSTRUCTION_NOP,

			  INSTRUCTION_PUSH,
			  0,
			  INSTRUCTION_POP,
			  C,
			  // will pass C = 0, D = 1
			  INSTRUCTION_JLE,
			  0,
			  INSTRUCTION_NOP };

	VM_INIT(program);
	TEST_BEGIN();

	for (int i = 0; i < 5; ++i)
	{
		TEST_ASSERT(vm->instruction_index == 0);
		TEST_ASSERT(vm->instructions[vm->instruction_index] ==
			    INSTRUCTION_LABEL);
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // label

		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // push 1
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // push 2
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // pop C
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // pop D

		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // je C = 2, D = 1 false

		TEST_ASSERT(vm->instruction_index == 11);
		TEST_ASSERT(vm->instructions[vm->instruction_index] ==
			    INSTRUCTION_NOP);

		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // nop
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // push 0
		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // pop C

		TEST_INSTRUCTION_EXECUTE_NEXT(vm); // je C = 0, D = 1 true
	}

	TEST_END(vm, test_results);

	return test_results;
}