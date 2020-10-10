//
// Created by sirh3e on 9/20/2020.
//

#include "../assert.h"

#include "../instructions.h"
#include "../macros.h"

int instruction_push(Vm* vm){

    VM_ASSERT(vm);
    VM_ASSERT_INSTRUCTION_INDEX(vm, 1);
    VM_STACK_INDEX_ASSERT(vm, 1);

    VM_STACK_SET_BY_INDEX(vm, vm->stack_index++, VM_INSTRUCTION_GET_BY_INDEX(vm, vm->instruction_index++));

    return 0;
}