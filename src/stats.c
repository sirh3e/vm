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

#include "stats.h"

#include "assert.h"

#include <stdio.h>

void vm_stats(Vm *vm)
{
	VM_ASSERT(vm);

	for (int i = 0; i < REGISTERS_LENGTH; ++i)
	{
		printf("vm->registers[%d]: %-32d\n", i, vm->registers[i]);
	}

	printf("vm->instruction_allocated : %-32d\n",
	       vm->instruction_allocated);
	printf("vm->instruction_index     : %-32d\n", vm->instruction_index);
	printf("vm->instruction_length    : %-32d\n", vm->instruction_length);

	for (u32 i = 0; i < vm->instruction_length; i += 4)
	{
		printf("[%8d - %8d]: %-32d %-32d %-32d %-32d\n",
		       i,
		       i + 3,
		       vm->instructions[i],
		       vm->instructions[i + 1],
		       vm->instructions[i + 2],
		       vm->instructions[i + 3]);
	}

	printf("vm->stack_allocated : %-32d\n", vm->stack_allocated);
	printf("vm->stack_index     : %-32d\n", vm->stack_index);
	printf("vm->stack_length    : %-32d\n", vm->stack_length);

	for (u32 i = 0; i < vm->stack_length; i += 4)
	{
		printf("[%8d - %8d]: %-32d %-32d %-32d %-32d\n",
		       i,
		       i + 3,
		       vm->stack[i],
		       vm->stack[i + 1],
		       vm->stack[i + 2],
		       vm->stack[i + 3]);
	}
}
