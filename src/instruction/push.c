//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>

#include "../instructions.h"
#include "../macros.h"

int instruction_push(Vm* vm){

    assert(vm != NULL);

    VM_STACK_SET_BY_INDEX(vm, vm->stack_index++, VM_INSTRUCTION_GET_BY_INDEX(vm, vm->instruction_index++));

    return 0;
}