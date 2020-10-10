//
// Created by Marvin Henke on 08.10.20.
//

#ifndef VM_ASSERT_H
#define VM_ASSERT_H

#include <assert.h>
#include <stdio.h>

#include "registers.h"

#define VM_ASSERT(vm) assert(vm != NULL)
#define VM_ASSERT_STACK_INDEX(vm, amount) assert(vm->stack_index + amount >= 0 && vm->stack_index + amount >= vm->stack_length)
#define VM_ASSERT_INSTRUCTION_INDEX(vm, amount) assert(vm->instruction_index + amount <= vm->instruction_length)
#define VM_ASSERT_REGISTER(register_index) assert(register_index < REGISTERS_LENGTH && register_index >= 0)

#endif //VM_ASSERT_H