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

test_vm_result test_vm_instruction_sub()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	i32 program[] = {
		INSTRUCTION_SUB, 64,	 2,
		INSTRUCTION_SUB, 64,	 -36,
		INSTRUCTION_SUB, 167474, 252503,
		INSTRUCTION_SUB, 311546, -350241,
		INSTRUCTION_SUB, 150201, 826156,
	};

	VM_INIT(program);
	TEST_BEGIN();

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 3);
	TEST_ASSERT(vm->registers[A] == 64);
	TEST_ASSERT(vm->registers[B] == 02);
	TEST_ASSERT(vm->registers[C] == 62);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 6);
	TEST_ASSERT(vm->registers[A] == 64);
	TEST_ASSERT(vm->registers[B] == -36);
	TEST_ASSERT(vm->registers[C] == 100);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 9);
	TEST_ASSERT(vm->registers[A] == 167474);
	TEST_ASSERT(vm->registers[B] == 252503);
	TEST_ASSERT(vm->registers[C] == -85029);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 12);
	TEST_ASSERT(vm->registers[A] == 311546);
	TEST_ASSERT(vm->registers[B] == -350241);
	TEST_ASSERT(vm->registers[C] == 661787);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->instruction_index == 15);
	TEST_ASSERT(vm->registers[A] == 150201);
	TEST_ASSERT(vm->registers[B] == 826156);
	TEST_ASSERT(vm->registers[C] == -675955);

	TEST_END(vm, test_results);

	return test_results;
}