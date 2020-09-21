//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>

#include "../instructions.h"

int instruction_dec(Vm* vm){

    assert(vm != NULL);
    assert(vm->instruction_index + 2 < INSTRUCTION_LENGTH); //a tmp variable would be cheating

    vm->registers[vm->instructions[vm->instruction_index]] -= vm->instructions[vm->instruction_index + 1];

    vm->instruction_index += 2;

    return 0;
}