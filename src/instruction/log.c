//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>
#include <stdio.h>

#include "../instructions.h"
#include "../macros.h"

int instruction_log(Vm* vm){

    assert(vm != NULL);
    VM_INSTRUCTION_INDEX_ASSERT(vm, 1);
    VM_REGISTER_ASSERT(vm->instructions[vm->instruction_index]);

    printf("%d\n", vm->registers[vm->instructions[vm->instruction_index++]]);

    return 0;
}