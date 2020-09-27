//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>

#include "../instructions.h"
#include "../registers.h"
#include "../macros.h"

int instruction_save(Vm* vm) {

    assert(vm != NULL);
    VM_INSTRUCTION_INDEX_ASSERT(vm, 1);
    VM_REGISTER_ASSERT(vm->instructions[vm->instruction_index + 1]);
    VM_STACK_INDEX_ASSERT(vm, 1);

    vm->stack[vm->stack_index++] = vm->registers[vm->instructions[vm->instruction_index++]];

    return 0;
}