//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>

#include "../instructions.h"
#include "../registers.h"

int instruction_dec(Vm* vm){

    assert(vm != NULL);
    VM_ASSERT(vm, 2);

    vm->registers[vm->instructions[vm->instruction_index]] -= vm->instructions[vm->instruction_index + 1];
    vm->instruction_index += 2;

    return 0;
}