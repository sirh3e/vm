//
// Created by sirh3e on 06.10.20.
//

#include "../assert.h"
#include "../instructions.h"
#include "../registers.h"
#include "../statuscode.h"
#include "../vm.h"

vm_instruction_result vm_instruction_jg(Vm *vm)
{
	VM_ASSERT(vm);
	VM_ASSERT_INSTRUCTION_INDEX(vm, 1);

	if (vm->registers[C] <= vm->registers[D])
	{
		vm->instruction_index += 1;
		return STATUS_CODE_SUCCESSFUL;
	}

	return vm_instruction_jmp(vm);
}