//
// Created by sirh3e on 9/20/2020.
//

#ifndef VM_INSTRUCTIONS_H
#define VM_INSTRUCTIONS_H

#include "vm.h"

#include "./instruction/add.h"
#include "./instruction/halt.h"

int vm_instruction_fetch(Vm*);

int instruction_evaluate(Vm*, int instruction);

int instruction_sub(Vm*);
int instruction_mul(Vm*);
int instruction_div(Vm*);

int instruction_dec(Vm*);
int instruction_inc(Vm*);
int instruction_neg(Vm*);

int instruction_and(Vm*);
int instruction_or(Vm*);
int instruction_xor(Vm*);
int instruction_shr(Vm*);
int instruction_shl(Vm*);

int instruction_push(Vm*);
int instruction_pop(Vm*);

int instruction_save(Vm*);
int instruction_load(Vm*);

int instruction_log(Vm*);

enum Instruction{
    INSTRUCTION_HALT = 0,   //ToDo

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


int (*instructions[])(Vm*) ={
        [INSTRUCTION_HALT] = instruction_halt, //ToDo

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
