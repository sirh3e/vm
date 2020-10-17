//
// Created by sirh3e on 9/20/2020.
//

#include "../assert.h"
#include "../statuscode.h"
#include "../util.h"
#include "../vm.h"

vm_instruction_result vm_instruction_push(Vm *vm) {

    VM_ASSERT(vm);
    VM_ASSERT_INSTRUCTION_INDEX(vm, 1);
    VM_ASSERT_STACK_INDEX(vm, 1);

    VM_STACK_SET_BY_INDEX(vm, vm->stack_index++, VM_INSTRUCTION_GET_BY_INDEX(vm, vm->instruction_index++));

    return STATUS_CODE_SUCCESSFUL;
}