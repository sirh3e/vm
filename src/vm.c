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

#include "vm.h"

#include "assert.h"
#include "config.h"
#include "instructions.h"
#include "statuscode.h"

#include <stdlib.h>
#include <string.h>

Vm *vm_new()
{
	Vm *vm = (Vm *)malloc(sizeof(Vm));

	if (vm == NULL)
		exit(1); // ToDo find the right error message

	return vm;
}

u32 vm_init(Vm *vm)
{
	VM_ASSERT(vm);

	vm->registers = (i32 *)malloc(sizeof(vm->registers) * REGISTERS_LENGTH);
	if (vm->registers == NULL)
		exit(1); // ToDo find the right error message

	for (int i = 0; i < REGISTERS_LENGTH; ++i)
	{
		vm->registers[i] = 0;
	}

	vm->stack_allocated = VM_CONFIG_STACK_ALLOCATED_SIZE;
	vm->stack_index	    = 0;
	vm->stack_length    = vm->stack_allocated;
	vm->stack = (i32 *)malloc(sizeof(vm->stack) * vm->stack_allocated);
	if (vm->stack == NULL)
		exit(1); // ToDo find the right error message

	vm->instruction_allocated = VM_CONFIG_INSTRUCTIONS_ALLOCATED_SIZE;
	vm->instruction_index	  = 0;
	vm->instruction_length	  = vm->instruction_allocated;
	vm->instructions	  = (i32 *)malloc(sizeof(vm->instructions) *
					  vm->instruction_allocated);
	if (vm->instructions == NULL)
		exit(1); // ToDo find the right error message

	return 0;
}

void vm_free(Vm *vm)
{
	if (vm == NULL)
		return;

	free(vm->registers);
	free(vm->stack);
	free(vm->instructions);

	free(vm);
}

u32 vm_program_set(Vm *vm, i32 *program, u32 program_length)
{
	VM_ASSERT(vm);

	// ToDo check if the length is larger or smaller then the allocated size
	vm->instruction_length = program_length;
	memcpy(vm->instructions,
	       program,
	       sizeof(vm->instructions) * vm->instruction_length);

	return 0;
}

u32 vm_program_run(Vm *vm)
{ // ToDo create a result handler

	VM_ASSERT(vm);

	int instruction;
	while ((instruction = vm_instruction_fetch(vm)) != INSTRUCTION_HALT)
	{
		vm_instruction_result_handler(
			vm,
			vm_instruction_evaluate(vm, instruction));
	}

	return 0;
}

u32 vm_instruction_fetch(Vm *vm)
{
	VM_ASSERT(vm);

	return vm->instructions[vm->instruction_index++];
}

vm_instruction_result vm_instruction_evaluate(Vm *vm, int instruction)
{
	VM_ASSERT(vm);
	VM_ASSERT_INSTRUCTION(instruction);

	return instructions[instruction](vm);
}

vm_instruction_result
vm_instruction_result_handler(Vm *vm, vm_instruction_result instruction_result)
{
	VM_ASSERT(vm);

	return status_code_handlers[instruction_result](vm, instruction_result);
}