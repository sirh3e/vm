//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>

#include "../instructions.h"
#include "../registers.h"
#include "../macros.h"

int instruction_div(Vm* vm){

    assert(vm != NULL);
    assert(VM_INSTRUCTION_GET_BY_INDEX(vm, vm->instruction_index + 1) == 0);

    vm->registers[A] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;
    vm->registers[B] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;

    vm->registers[C] = vm->registers[A] / vm->registers[B];
    vm->stack[vm->stack_index++] = vm->registers[C];

    return 0;
}