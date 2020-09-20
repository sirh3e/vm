//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>

#include "../instructions.h"

int instruction_shl(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH);

    vm->registers[vm->instructions[vm->instruction_index]] <<= vm->instructions[vm->instruction_index++];
    vm->instruction_index++;

    return 0;
}
