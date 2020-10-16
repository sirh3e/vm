//
// Created by sirh3e on 9/20/2020.
//

#include <stdio.h>

#include "../assert.h"
#include "../vm.h"

vm_instruction_result vm_instruction_log(Vm* vm){

    VM_ASSERT(vm);
    VM_ASSERT_INSTRUCTION_INDEX(vm, 1);
    VM_ASSERT_REGISTER(vm->instructions[vm->instruction_index]);

    printf("%d\n", vm->registers[vm->instructions[vm->instruction_index]]);
    vm->instruction_index += 1;

    return 0;
}