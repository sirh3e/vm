//
// Created by sirh3e on 9/20/2020.
//

#ifndef VM_MACROS_H
#define VM_MACROS_H

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

#define VM_STACK_INDEX_POS_ASSERT(vm, amount) assert(vm->stack_index + amount <= vm->stack_length)
#define VM_STACK_INDEX_NEG_ASSERT(vm, amount) assert(vm->stack_index + amount >= 0)
#define VM_STACK_INDEX_ASSERT(vm, amount) amount >= 0 ? VM_STACK_INDEX_POS_ASSERT(vm, amount) : VM_STACK_INDEX_NEG_ASSERT(vm, amount)

#define VM_INSTRUCTION_INDEX_ASSERT(vm, amount) assert(vm->instruction_index + amount <= vm->instruction_length)

#define VM_REGISTER_ASSERT(register_index) assert(register_index < REGISTER_LENGTH && register_index >= 0)

#define STACK_DEFAULT_ALLOCATED_SIZE 4096
#define INSTRUCTION_DEFAULT_ALLOCATED_SIZE 4096

#define VM_STACK_GET_BY_INDEX(vm, index) (vm->stack[index])
#define VM_STACK_GET(vm) (VM_STACK_GET_BY_INDEX(vm, vm->stack_index))

#define VM_STACK_SET_BY_INDEX(vm, index, value) (vm->stack[index] = value)
#define VM_STACK_SET(vm, value) (VM_STACK_SET_BY_INDEX(vm, vm->stack_index, value))

#define VM_INSTRUCTION_GET_BY_INDEX(vm, index) (vm->instructions[index])
#define VM_INSTRUCTION_GET(vm) (VM_INSTRUCTION_GET_BY_INDEX(vm, vm->instruction_index))

#define VM_INSTRUCTION_SET(vm, instruction) (vm->instructions[vm->instruction_index++] = instruction)

#endif //VM_MACROS_H
