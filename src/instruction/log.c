//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>
#include <stdio.h>

#include "../instructions.h"

int instruction_log(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH); //a tmp variable would be cheating

    printf("%d\n", vm->registers[vm->instructions[vm->instruction_index++]]);

    return 0;
}