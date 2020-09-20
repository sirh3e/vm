//
// Created by sirh3e on 9/20/2020.
//

#ifndef VM_VM_H
#define VM_VM_H

#include "types.h"

typedef struct{
    i32* registers;

    i32* stack;
    u32 stack_allocated;
    u32 stack_length;
    u32 stack_index;

    i32* instructions; // program
    u32 instruction_allocated;
    u32 instruction_length;
    u32 instruction_index;
}Vm;

Vm* vm_new();
int vm_init(Vm*);
void vm_free(Vm*);

int vm_program_set(Vm*, i32*, u32);

int vm_instruction_evaluate(Vm*, int instruction);
int vm_instruction_fetch(Vm*);

#endif //VM_VM_H
