//
// Created by sirh3e on 10/18/2020.
//

#include "statuscode.h"

#include "assert.h"
#include "config.h"
#include "stats.h"

#include <stdio.h>

vm_instruction_result status_code_handler_failed(Vm *vm,
						 vm_instruction_result result)
{
	if (VM_CONFIG_DEBUG_ENABLE)
		vm_stats(vm);

	return result;
}

vm_instruction_result
status_code_handler_successful(Vm *vm, vm_instruction_result result)
{
	VM_ASSERT(vm);

	if (VM_CONFIG_DEBUG_ENABLE)
		vm_stats(vm);

	return result;
}