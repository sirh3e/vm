//
// Created by sirh3e on 9/20/2020.
//

#ifndef VM_VM_H
#define VM_VM_H

#ifndef VM_TYPES_H
    #include "types.h"
#endif

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

#endif //VM_VM_H
