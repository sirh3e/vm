//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>

#include "../instructions.h"
#include "../macros.h"

int instruction_shr(Vm* vm){ //right

    assert(vm != NULL);
    VM_INSTRUCTION_INDEX_ASSERT(vm, 2);
    VM_REGISTER_ASSERT(vm->instructions[vm->instruction_index]);

    vm->registers[vm->instructions[vm->instruction_index]] >>= vm->instructions[vm->instruction_index + 1];
    vm->instruction_index += 2;

    return 0;
}