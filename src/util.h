//
// Created by sirh3e on 10/10/2020.
//

#ifndef VM_UTIL_H
#define VM_UTIL_H

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

// VM_INSTRUCTION:
#define VM_INSTRUCTION_GET_BY_INDEX(vm, index) (vm->instructions[index])
#define VM_INSTRUCTION_GET(vm) (VM_INSTRUCTION_GET_BY_INDEX(vm, vm->instruction_index))

#define VM_INSTRUCTION_SET_BY_INDEX(vm, index, instruction) (vm->instructions[index] = instruction)
#define VM_INSTRUCTION_SET(vm, instruction) (VM_INSTRUCTION_SET_BY_INDEX(vm, vm->instruction_index, instruction))

// VM_STACK:
#define VM_STACK_GET_BY_INDEX(vm, index) (vm->stack[index])
#define VM_STACK_GET(vm) (VM_STACK_GET_BY_INDEX(vm, vm->stack_index))

#define VM_STACK_SET_BY_INDEX(vm, index, value) (vm->stack[index] = value)
#define VM_STACK_SET(vm, value) (VM_STACK_SET_BY_INDEX(vm, vm->stack_index, value))

#endif //VM_UTIL_H
