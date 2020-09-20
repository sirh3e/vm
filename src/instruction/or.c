//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>

#include "../instructions.h"
#include "../registers.h"
#include "../macros.h"

int instruction_or(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH);

    vm->registers[A] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;
    vm->registers[B] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;

    vm->registers[C] = vm->registers[A] | vm->registers[B];

    return 0;
}