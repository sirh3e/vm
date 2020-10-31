//
// Created by sirh3e on 9/20/2020.
//

#include "../assert.h"
#include "../statuscode.h"
#include "../vm.h"

vm_instruction_result vm_instruction_shl(Vm *vm)
{
	VM_ASSERT(vm);
	VM_ASSERT_INSTRUCTION_INDEX(vm, 2);
	VM_ASSERT_REGISTER(vm->instructions[vm->instruction_index]);

	vm->registers[vm->instructions[vm->instruction_index]] <<=
		vm->instructions[vm->instruction_index + 1];
	vm->instruction_index += 2;

	return STATUS_CODE_SUCCESSFUL;
}
