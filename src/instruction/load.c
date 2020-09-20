//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>

#include "../instructions.h"
#include "../registers.h"

int instruction_load(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < REGISTERS_LENGTH);

    vm->registers[vm->instructions[vm->instruction_index++]] = vm->stack[vm->stack_index];

    return 0;
}