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

test_vm_result test_vm_instruction_shl()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	i32 program[] = {
		INSTRUCTION_PUSH,
		1,
		INSTRUCTION_LOAD,
		A,
		INSTRUCTION_SHL,
		A,
		1,

		INSTRUCTION_PUSH,
		44,
		INSTRUCTION_LOAD,
		A,
		INSTRUCTION_SHL,
		A,
		2,

		INSTRUCTION_PUSH,
		1,
		INSTRUCTION_LOAD,
		B,
		INSTRUCTION_SHL,
		B,
		2,

		INSTRUCTION_PUSH,
		36987,
		INSTRUCTION_LOAD,
		B,
		INSTRUCTION_SHL,
		B,
		14,

		INSTRUCTION_PUSH,
		1,
		INSTRUCTION_LOAD,
		C,
		INSTRUCTION_SHL,
		C,
		4,
	};

	VM_INIT(program);
	TEST_BEGIN();

	TEST_ASSERT(vm->instruction_index == 0);
	TEST_ASSERT(vm->stack_index == 0);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 7);
	TEST_ASSERT(vm->registers[A] == 2);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 14);
	TEST_ASSERT(vm->registers[A] == 176);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 21);
	TEST_ASSERT(vm->registers[B] == 4);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 28);
	TEST_ASSERT(vm->registers[B] == 605995008);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 35);
	TEST_ASSERT(vm->registers[C] == 16);

	TEST_END(vm, test_results);

	return test_results;
}