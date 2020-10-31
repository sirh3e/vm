//
// Created by sirh3e on 9/20/2020.
//

#ifndef VM_VM_H
#define VM_VM_H

#include "types.h"

typedef struct
{
	i32 *registers;

	i32 *stack;
	u32 stack_allocated;
	u32 stack_length;
	u32 stack_index;

	i32 *instructions; // program
	u32 instruction_allocated;
	u32 instruction_length;
	u32 instruction_index;
} Vm;

Vm *vm_new();

u32 vm_init(Vm *);

void vm_free(Vm *);

u32 vm_program_run(Vm *);

u32 vm_program_set(Vm *, i32 *, u32);

u32 vm_instruction_fetch(Vm *);

vm_instruction_result vm_instruction_evaluate(Vm *, int instruction);

u32 vm_instruction_result_handler(Vm *, vm_instruction_result);

#endif // VM_VM_H
