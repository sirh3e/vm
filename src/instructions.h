//
// Created by sirh3e on 9/20/2020.
//

#ifndef VM_INSTRUCTIONS_H
#define VM_INSTRUCTIONS_H

#include <assert.h>
#include <stdio.h>

#include "vm.h"
#include "types.h"

//ToDo https://www.cs.yale.edu/flint/cs421/papers/x86-asm/asm.html

//ToDo simple:
//  not,

//ToDo flow:
//  jz <label> (jump when last result was zero)
//  cmp
//  call, ret | functions

vm_instruction_result vm_instruction_halt(Vm*);
vm_instruction_result vm_instruction_nop(Vm *vm);

vm_instruction_result vm_instruction_label(Vm *vm);
vm_instruction_result vm_instruction_je(Vm *vm);
vm_instruction_result vm_instruction_jne(Vm *vm);
vm_instruction_result vm_instruction_jg(Vm *vm);
vm_instruction_result vm_instruction_jge(Vm *vm);
vm_instruction_result vm_instruction_jl(Vm *vm);
vm_instruction_result vm_instruction_jle(Vm *vm);
vm_instruction_result vm_instruction_jmp(Vm *vm);

vm_instruction_result vm_instruction_add(Vm *vm);
vm_instruction_result vm_instruction_sub(Vm *vm);
vm_instruction_result vm_instruction_mul(Vm *vm);
vm_instruction_result vm_instruction_div(Vm *vm);

vm_instruction_result vm_instruction_dec(Vm *vm);
vm_instruction_result vm_instruction_inc(Vm *vm);
vm_instruction_result vm_instruction_neg(Vm*);

vm_instruction_result vm_instruction_and(Vm *vm);
vm_instruction_result vm_instruction_or(Vm *vm);
vm_instruction_result vm_instruction_xor(Vm *vm);
vm_instruction_result vm_instruction_shr(Vm *vm);
vm_instruction_result vm_instruction_shl(Vm *vm);

vm_instruction_result vm_instruction_push(Vm*);
vm_instruction_result vm_instruction_pop(Vm *vm);

vm_instruction_result vm_instruction_save(Vm *vm);
vm_instruction_result vm_instruction_load(Vm *vm);

vm_instruction_result vm_instruction_log(Vm *vm);

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

static vm_instruction_result (*instructions[])(Vm*) = {
        [INSTRUCTION_HALT] = vm_instruction_halt, //ToDo
        [INSTRUCTION_NOP] = vm_instruction_nop,
        
        [INSTRUCTION_LABEL] = vm_instruction_label,
        [INSTRUCTION_JE] = vm_instruction_je,
        [INSTRUCTION_JNE] = vm_instruction_jne,
        [INSTRUCTION_JG] = vm_instruction_jg,
        [INSTRUCTION_JGE] = vm_instruction_jge,
        [INSTRUCTION_JL] = vm_instruction_jl,
        [INSTRUCTION_JLE] = vm_instruction_jle,
        [INSTRUCTION_JMP] = vm_instruction_jmp,

        [INSTRUCTION_ADD] = vm_instruction_add,
        [INSTRUCTION_SUB] = vm_instruction_sub,
        [INSTRUCTION_MUL] = vm_instruction_mul,
        [INSTRUCTION_DIV] = vm_instruction_div,

        [INSTRUCTION_DEC] = vm_instruction_dec,
        [INSTRUCTION_INC] = vm_instruction_inc,
        [INSTRUCTION_NEG] = vm_instruction_neg,


        [INSTRUCTION_AND] = vm_instruction_and,
        [INSTRUCTION_OR] = vm_instruction_or,
        [INSTRUCTION_XOR] = vm_instruction_xor,
        [INSTRUCTION_SHR] = vm_instruction_shr,
        [INSTRUCTION_SHL] = vm_instruction_shl,

        [INSTRUCTION_PUSH] = vm_instruction_push,
        [INSTRUCTION_POP] = vm_instruction_pop,

        [INSTRUCTION_SAVE] = vm_instruction_save,
        [INSTRUCTION_LOAD] = vm_instruction_load,

        [INSTRUCTION_LOG] = vm_instruction_log,
};

#endif //VM_INSTRUCTIONS_H