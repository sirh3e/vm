//
// Created by sirh3e on 08.10.20.
//

#ifndef VM_ASSERT_H
#define VM_ASSERT_H

#include <assert.h>
#include <stdio.h>

#include "registers.h"

#define ASSERT(expression) \
    assert(expression)

#define VM_ASSERT(vm) \
    ASSERT(vm != NULL)

#define VM_ASSERT_STACK(vm, index) \
    ASSERT(index <= vm->stack_length)

#define VM_ASSERT_STACK_INDEX(vm, amount) \
    VM_ASSERT_STACK(vm, vm->stack_index + amount)

#define VM_ASSERT_INSTRUCTION(instruction) \
    ASSERT(instruction < INSTRUCTION_LENGTH)

#define VM_ASSERT_INSTRUCTION_INDEX(vm, amount) \
    ASSERT(vm->instruction_index + amount <= vm->instruction_length)

#define VM_ASSERT_REGISTER(register_index) \
    ASSERT(register_index < REGISTERS_LENGTH)

#endif //VM_ASSERT_H
