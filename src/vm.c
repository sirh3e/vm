//
// Created by sirh3e on 9/21/2020.
//

#include <stdlib.h>
#include <string.h>

#include "assert.h"
#include "defaults.h"
#include "statuscode.h"
#include "vm.h"
#include "instructions.h"

Vm *vm_new() {

    Vm *vm = (Vm *) malloc(sizeof(Vm));

    if (vm == NULL)
        exit(1); //ToDo find the right error message

    return vm;
}

u32 vm_init(Vm *vm) {

    VM_ASSERT(vm);

    vm->registers = (i32 *) malloc(sizeof(vm->registers) * REGISTERS_LENGTH);
    if (vm->registers == NULL)
        exit(1); //ToDo find the right error message

    vm->stack_allocated = VM_DEFAULT_STACK_ALLOCATED_SIZE;
    vm->stack_index = 0;
    vm->stack_length = vm->stack_allocated;
    vm->stack = (i32 *) malloc(sizeof(vm->stack) * vm->stack_allocated);
    if (vm->stack == NULL)
        exit(1); //ToDo find the right error message

    vm->instruction_allocated = VM_DEFAULT_INSTRUCTIONS_ALLOCATED_SIZE;
    vm->instruction_index = 0;
    vm->instruction_length = vm->instruction_allocated;
    vm->instructions = (i32 *) malloc(sizeof(vm->instructions) * vm->instruction_allocated);
    if (vm->instructions == NULL)
        exit(1); //ToDo find the right error message

    return 0;
}

void vm_free(Vm *vm) {

    if(vm == NULL)
        return;

    free(vm->registers);
    free(vm->stack);
    free(vm->instructions);

    free(vm);
}

u32 vm_program_set(Vm *vm, i32 *program, u32 program_length) {

    VM_ASSERT(vm);

    //ToDo check if the length is larger or smaller then the allocated size
    vm->instruction_length = program_length;
    memcpy(vm->instructions, program, sizeof(vm->instructions) * vm->instruction_length);

    return 0;
}

u32 vm_program_run(Vm *vm) { //ToDo create a result handler

    VM_ASSERT(vm);

    int instruction;
    while ((instruction = vm_instruction_fetch(vm)) != INSTRUCTION_HALT) {
        vm_instruction_result_handler(vm, vm_instruction_evaluate(vm, instruction));
    }

    return 0;
}

u32 vm_instruction_fetch(Vm *vm) {

    VM_ASSERT(vm);

    return vm->instructions[vm->instruction_index++];
}

vm_instruction_result vm_instruction_evaluate(Vm *vm, int instruction) {

    VM_ASSERT(vm);
    VM_ASSERT_INSTRUCTION(instruction);

    return instructions[instruction](vm);
}

vm_instruction_result vm_instruction_result_handler(Vm* vm, vm_instruction_result instruction_result) {

    VM_ASSERT(vm);

    return status_code_handlers[instruction_result](vm, instruction_result);
}