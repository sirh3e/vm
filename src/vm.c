//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>

#include "vm.h"
#include "instructions.h"

int vm_instruction_evaluate(Vm* vm, int instruction){

    assert(vm != NULL);
    assert(instruction > 0);

    return instructions[instruction](vm);
}

int vm_instruction_fetch(Vm* vm){

    assert(vm != NULL);

    return vm->instructions[vm->instruction_index++];
}