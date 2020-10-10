//
// Created by sirh3e on 9/20/2020.
//

#ifndef VM_INSTRUCTIONS_H
#define VM_INSTRUCTIONS_H

#include <assert.h>
#include <stdio.h>

#include "vm.h"

//ToDo https://www.cs.yale.edu/flint/cs421/papers/x86-asm/asm.html

//ToDo simple:
//  not,

//ToDo flow:
//  jz <label> (jump when last result was zero)
//  cmp
//  call, ret | functions

int vm_instruction_halt(Vm*);
int vm_instruction_nop(Vm *vm);

int vm_instruction_label(Vm *vm);
int vm_instruction_je(Vm *vm);
int vm_instruction_jne(Vm *vm);
int vm_instruction_jg(Vm *vm);
int vm_instruction_jge(Vm *vm);
int vm_instruction_jl(Vm *vm);
int vm_instruction_jle(Vm *vm);
int vm_instruction_jmp(Vm *vm);

int vm_instruction_add(Vm *vm);
int vm_instruction_sub(Vm *vm);
int vm_instruction_mul(Vm *vm);
int vm_instruction_div(Vm *vm);

int vm_instruction_dec(Vm *vm);
int vm_instruction_inc(Vm *vm);
int instruction_neg(Vm*);

int vm_instruction_and(Vm *vm);
int vm_instruction_or(Vm *vm);
int vm_instruction_xor(Vm *vm);
int vm_instruction_shr(Vm *vm);
int vm_instruction_shl(Vm *vm);

int instruction_push(Vm*);
int vm_instruction_pop(Vm *vm);

int vm_instruction_save(Vm *vm);
int vm_instruction_load(Vm *vm);

int vm_instruction_log(Vm *vm);

enum Instruction{
    INSTRUCTION_HALT,   //ToDo
    INSTRUCTION_NOP,

    INSTRUCTION_LABEL,
    INSTRUCTION_JE,
    INSTRUCTION_JNE,
    INSTRUCTION_JG,
    INSTRUCTION_JGE,
    INSTRUCTION_JL,
    INSTRUCTION_JLE,
    INSTRUCTION_JMP,

    INSTRUCTION_ADD,        //register c = register a + register b; and store it on the stack
    INSTRUCTION_SUB,        //register c = register a - register b; and store it on the stack
    INSTRUCTION_MUL,        //register c = register a * register b; and store it on the stack
    INSTRUCTION_DIV,        //register c = register a / register b; and store it on the stack

    INSTRUCTION_DEC,
    INSTRUCTION_INC,
    INSTRUCTION_NEG,

    INSTRUCTION_AND,
    INSTRUCTION_OR,
    INSTRUCTION_XOR,
    INSTRUCTION_SHR,
    INSTRUCTION_SHL,

    INSTRUCTION_PUSH,
    INSTRUCTION_POP,

    INSTRUCTION_SAVE,
    INSTRUCTION_LOAD,

    INSTRUCTION_LOG,

    INSTRUCTION_LENGTH
};

const static int (*instructions[])(Vm*) = {
        [INSTRUCTION_HALT] = vm_instruction_halt, //ToDo
        [INSTRUCTION_NOP] = instruction_nop,
        
        [INSTRUCTION_LABEL] = instruction_label,
        [INSTRUCTION_JE] = instruction_je,
        [INSTRUCTION_JNE] = instruction_jne,
        [INSTRUCTION_JG] = instruction_jg,
        [INSTRUCTION_JGE] = instruction_jge,
        [INSTRUCTION_JL] = instruction_jl,
        [INSTRUCTION_JLE] = instruction_jle,
        [INSTRUCTION_JMP] = instruction_jmp,

        [INSTRUCTION_ADD] = instruction_add,
        [INSTRUCTION_SUB] = instruction_sub,
        [INSTRUCTION_MUL] = instruction_mul,
        [INSTRUCTION_DIV] = instruction_div,

        [INSTRUCTION_DEC] = instruction_dec,
        [INSTRUCTION_INC] = instruction_inc,
        [INSTRUCTION_NEG] = instruction_neg,


        [INSTRUCTION_AND] = instruction_and,
        [INSTRUCTION_OR] = instruction_or,
        [INSTRUCTION_XOR] = instruction_xor,
        [INSTRUCTION_SHR] = instruction_shr,
        [INSTRUCTION_SHL] = instruction_shl,

        [INSTRUCTION_PUSH] = instruction_push,
        [INSTRUCTION_POP] = instruction_pop,

        [INSTRUCTION_SAVE] = instruction_save,
        [INSTRUCTION_LOAD] = instruction_load,

        [INSTRUCTION_LOG] = instruction_log,
};

#endif //VM_INSTRUCTIONS_H
