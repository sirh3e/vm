//
// Created by sirh3e on 9/21/2020.
//

#include <stdlib.h>
#include <string.h>

#include "assert.h"
#include "defaults.h"
#include "vm.h"
#include "instructions.h"

Vm* vm_new(){

    Vm* vm = (Vm*)malloc(sizeof(Vm));

    if(vm == NULL)
        exit(1); //ToDo find the right error message

    return vm;
}

int vm_init(Vm* vm){

    VM_ASSERT(vm);

    vm->registers = (i32*) malloc(sizeof(i32) * REGISTERS_LENGTH);
    if(vm->registers == NULL)
        exit(0); //ToDo find the right error message

    vm->stack_allocated = VM_DEFAULT_STACK_ALLOCATED_SIZE;
    vm->stack_index = 0;
    vm->stack_length = 0;
    vm->stack = (i32*) malloc(sizeof(i32) * vm->stack_allocated);
    if(vm->stack == NULL)
        exit(0); //ToDo find the right error message

    vm->instruction_allocated = VM_DEFAULT_INSTRUCTIONS_ALLOCATED_SIZE;
    vm->instruction_index = 0;
    vm->instruction_length = 0;
    vm->instructions = (i32*) malloc(sizeof(i32) * vm->instruction_allocated);
    if(vm->instructions == NULL)
        exit(0); //ToDo find the right error message

    return 0;
}

void vm_free(Vm* vm){ //ToDo

    //free(vm->registers);
    //free(vm->stack);
    //free(vm->instructions);

    free(vm);
}

int vm_program_set(Vm* vm, i32* program, u32 program_length){

    VM_ASSERT(vm);

    //ToDo check if the length is larger or smaller then the allocated size
    vm->instruction_length = program_length;
    memcpy(vm->instructions, program, sizeof(i32) * vm->instruction_length);

    return 0;
}

int vm_program_run(Vm* vm){ //ToDo create a result handler

    VM_ASSERT(vm);

    int instruction = INSTRUCTION_HALT, instruction_result = 0;

    while ((instruction = vm_instruction_fetch(vm)) != INSTRUCTION_HALT){
        instruction_result = vm_instruction_evaluate(vm, instruction);
    }

    return 0;
}

int vm_instruction_evaluate(Vm* vm, int instruction){

    VM_ASSERT(vm);
    assert(instruction < INSTRUCTION_LENGTH);
    assert(instruction > 0);

    return instructions[instruction](vm);
}

int vm_instruction_fetch(Vm* vm){

    VM_ASSERT(vm);
    //VM_ASSERT_INSTRUCTION_INDEX(vm, 1);

    return vm->instructions[vm->instruction_index++];
}