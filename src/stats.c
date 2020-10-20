//
// Created by sirh3e on 10/18/2020.
//

#include <stdio.h>

#include "assert.h"
#include "stats.h"

void vm_stats(Vm *vm) {

    VM_ASSERT(vm);

    for (int i = 0; i < REGISTERS_LENGTH; ++i) {
        printf("vm->registers[%d]: %-32d\n", i, vm->registers[i]);
    }

    printf("vm->instruction_allocated : %-32d\n", vm->instruction_allocated);
    printf("vm->instruction_index     : %-32d\n", vm->instruction_index);
    printf("vm->instruction_length    : %-32d\n", vm->instruction_length);

    for (u32 i = 0; i < vm->instruction_length; i += 4) {
        printf("[%8d - %8d]: %-32d %-32d %-32d %-32d\n", i, i + 3, vm->instructions[i], vm->instructions[i + 1],
               vm->instructions[i + 2], vm->instructions[i + 3]);
    }

    printf("vm->stack_allocated : %-32d\n", vm->stack_allocated);
    printf("vm->stack_index     : %-32d\n", vm->stack_index);
    printf("vm->stack_length    : %-32d\n", vm->stack_length);

    for (u32 i = 0; i < vm->stack_length; i += 4) {
        printf("[%8d - %8d]: %-32d %-32d %-32d %-32d\n", i, i + 3, vm->stack[i], vm->stack[i + 1], vm->stack[i + 2],
               vm->stack[i + 3]);
    }
}
