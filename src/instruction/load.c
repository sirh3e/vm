//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>

#include "../instructions.h"
#include "../registers.h"
#include "../macros.h"

int instruction_load(Vm* vm){

    assert(vm != NULL);
    VM_ASSERT_INSTRUCTION_INDEX(vm, 1);
    VM_REGISTER_ASSERT(vm->instructions[vm->instruction_index]);
    VM_STACK_INDEX_ASSERT(vm, -1);

    vm->stack_index -= 1;
    vm->registers[vm->instructions[vm->instruction_index]] = vm->stack[vm->stack_index];
    vm->instruction_index += 1;

    return 0;
}