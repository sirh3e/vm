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

test_vm_result test_vm_instruction_nop()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	i32 program[] = { INSTRUCTION_NOP,
			  INSTRUCTION_NOP,
			  INSTRUCTION_NOP,
			  INSTRUCTION_HALT };

	VM_INIT(program);
	TEST_VM_BEGIN();

	TEST_ASSERT(vm->instruction_index == 0);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm); // nop
	TEST_ASSERT(vm->instruction_index == 1);
	TEST_INSTRUCTION_EXECUTE_NEXT(vm); // nop
	TEST_ASSERT(vm->instruction_index == 2);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm); // nop
	TEST_ASSERT(vm->instruction_index == 3);

	TEST_VM_END(vm, test_results);

	return test_results;
}