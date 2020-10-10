//
// Created by sirh3e on 9/20/2020.
//

#include "../assert.h"

#include "../instructions.h"
#include "../macros.h"

int vm_instruction_shr(Vm* vm){ //right

    VM_ASSERT(vm);
    VM_ASSERT_INSTRUCTION_INDEX(vm, 2);
    VM_ASSERT_REGISTER(vm->instructions[vm->instruction_index]);

    vm->registers[vm->instructions[vm->instruction_index]] >>= vm->instructions[vm->instruction_index + 1];
    vm->instruction_index += 2;

    return 0;
}