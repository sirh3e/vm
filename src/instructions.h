//
// Created by sirh3e on 9/20/2020.
//

#ifndef VM_INSTRUCTIONS_H
#define VM_INSTRUCTIONS_H

#include "vm.h"
#include "types.h"

//ToDo https://www.cs.yale.edu/flint/cs421/papers/x86-asm/asm.html

//ToDo simple:
//  not,

//ToDo flow:
//  jz <label> (jump when last result was zero)
//  cmp
//  call, ret | functions

// instruction: halt
//  will stop the vm
//
//  example code:
//   INSTRUCTION_HALT
vm_instruction_result vm_instruction_halt(Vm*);

// instruction: nop
//  this instruction does nothing
//
//  example code:
//   INSTRUCTION_NOP
vm_instruction_result vm_instruction_nop(Vm *vm);

// instruction: label
//  defines a label
//  where you can jump to later with the
//      instructions:
//          je, jne, jg, jge, jl, jmp
//
//  example code:
//   INSTRUCTION_LABEL,
//   INSTRUCTION_JMP  , 0
//  LABEL got the index of 0
vm_instruction_result vm_instruction_label(Vm *vm);

// instruction: je
//  jumps to a label if the value in register C and D are equal
//
//  example code:
//   INSTRUCTION_LABEL,
//   INSTRUCTION_PUSH, 2,
//   INSTRUCTION_PUSH, 2,
//   INSTRUCTION_POP,  C,
//   INSTRUCTION_POP,  D,
//   INSTRUCTION_JE ,  0,
//  LABEL got the index of 0
//   registers:
//    A = 0, B = 0, C = 2, D = 2
vm_instruction_result vm_instruction_je(Vm *vm);

// instruction: jne
//  jumps to a label if the value in register C and D are not equal
//
//  example code:
//   INSTRUCTION_LABEL,
//   INSTRUCTION_PUSH, 1,
//   INSTRUCTION_PUSH, 2,
//   INSTRUCTION_POP , C,
//   INSTRUCTION_POP , D,
//   INSTRUCTION_JNE , 0,
//  LABEL got the index of 0
//   registers:
//    A = 0, B = 0, C = 1, D = 2
vm_instruction_result vm_instruction_jne(Vm *vm);

// instruction: jg
//  jumps to a label if the value in register C is greater the value in D
//
//  example code:
//   INSTRUCTION_LABEL,
//   INSTRUCTION_PUSH, 12345678,
//   INSTRUCTION_PUSH, 1,
//   INSTRUCTION_POP,  C,
//   INSTRUCTION_POP,  D,
//   INSTRUCTION_JG ,  0,
//  LABEL got the index of 0
//   registers:
//    A = 0, B = 0, C = 12345678, D = 1
vm_instruction_result vm_instruction_jg(Vm *vm);

// instruction: jge
//  jumps to a label if the value in register C is greater or equal the value in D
//
//  example code:
//   INSTRUCTION_LABEL,
//   INSTRUCTION_PUSH, 12345678,
//   INSTRUCTION_PUSH, 12345678,
//   INSTRUCTION_POP , C,
//   INSTRUCTION_POP , D,
//   INSTRUCTION_JGE , 0,
//  LABEL got the index of 0
//   registers:
//    A = 0, B = 0, C = 12345678, D = 12345678
vm_instruction_result vm_instruction_jge(Vm *vm);

// instruction: jl
//  jumps to a label if the value in register C is less the value in D
//
//  example code:
//   INSTRUCTION_LABEL,
//   INSTRUCTION_PUSH, 1,
//   INSTRUCTION_PUSH, 12345678,
//   INSTRUCTION_POP,  C,
//   INSTRUCTION_POP,  D,
//   INSTRUCTION_JL ,  0,
//  LABEL got the index of 0
//   registers:
//    A = 0, B = 0, C = 1, D = 12345678
vm_instruction_result vm_instruction_jl(Vm *vm);

// instruction: jge
//  jumps to a label if the value in register C is less or equal the value in D
//
//  example code:
//   INSTRUCTION_LABEL,
//   INSTRUCTION_PUSH, 12345678,
//   INSTRUCTION_PUSH, 12345678,
//   INSTRUCTION_POP,  C,
//   INSTRUCTION_POP,  D,
//   INSTRUCTION_JLE,  0,
//  LABEL got the index of 0
//   registers:
//    A = 0, B = 0, C = 12345678, D = 12345678
vm_instruction_result vm_instruction_jle(Vm *vm);

// instruction: jmp
//  jumps to a label
//
//  example code:
//   INSTRUCTION_LABEL,
//   INSTRUCTION_JMP  , 0
//  LABEL got the index of 0
//   registers:
//    A = 0, B = 0, C = 0, D = 0
vm_instruction_result vm_instruction_jmp(Vm *vm);

// instruction: add
//  adds the value in register a and b together into register c
//
//  example code:
//   INSTRUCTION_PUSH, 123,
//   INSTRUCTION_PUSH, 321,
//   INSTRUCTION_ADD ,
//   registers:
//    A = 123, B = 321, C = 444, D = 0
vm_instruction_result vm_instruction_add(Vm *vm);

// instruction: sub
//  subtracts the value in register a and b together into register c
//
//  example code:
//   INSTRUCTION_PUSH, 123,
//   INSTRUCTION_PUSH, 321,
//   INSTRUCTION_SUB ,
//   registers:
//    A = 123, B = 321, C = -202, D = 0
vm_instruction_result vm_instruction_sub(Vm *vm);

// instruction: mul
//  multiples the value in register a and b together into register c
//
//  example code:
//   INSTRUCTION_PUSH, 123,
//   INSTRUCTION_PUSH, 321,
//   INSTRUCTION_MUL ,
//   registers:
//    A = 123, B = 321, C = 39483, D = 0
vm_instruction_result vm_instruction_mul(Vm *vm);

// instruction: div
//   the value in register a and b together into register c
//   note div is integer / integer = integer
//
//  example code:
//   INSTRUCTION_PUSH, 303,
//   INSTRUCTION_PUSH, 321,
//   INSTRUCTION_MUL ,
//   registers:
//    A = 123, B = 321, C = 0, D = 0
vm_instruction_result vm_instruction_div(Vm *vm);

// instruction: dec
//   the value in register <register> <integer> will be in decreased
//
//  example code:
//   INSTRUCTION_PUSH, 303,
//   INSTRUCTION_POP , A,
//   INSTRUCTION_DEC , A, 303
//   registers:
//    A = 0, B = 0, C = 0, D = 0
vm_instruction_result vm_instruction_dec(Vm *vm);

// instruction: inc
//   the value in register <register> <integer> will be in increased
//
//  example code:
//   INSTRUCTION_PUSH, 303,
//   INSTRUCTION_POP , A,
//   INSTRUCTION_INC , A, 303
//   registers:
//    A = 606, B = 0, C = 0, D = 0
vm_instruction_result vm_instruction_inc(Vm *vm);

// instruction: neg
//   the value in register <register> will be in negate
//
//  example code:
//   INSTRUCTION_PUSH, 303,
//   INSTRUCTION_POP , A,
//   INSTRUCTION_NEG , A
//   registers:
//    A = -303, B = 0, C = 0, D = 0
vm_instruction_result vm_instruction_neg(Vm*);

// instruction: and
//   the value in register A and register B operate a bitwise and result in register c
//
//  example code:
//   INSTRUCTION_PUSH, 1281141, /* 00000000000100111000110001110101 */
//   INSTRUCTION_POP , A,
//   INSTRUCTION_PUSH, 3472199, /* 00000000001101001111101101000111 */
//   INSTRUCTION_POP , B,
//   INSTRUCTION_AND ,          /* 00000000000100001000100001000101 */
//   registers:
//    A = 1281141, B = 3472199, C = 1083461, D = 0
vm_instruction_result vm_instruction_and(Vm *vm);

// instruction: or
//   the value in register A and register B operate a bitwise and result in register c
//
//  example code:
//   INSTRUCTION_PUSH, 1281141, /* 00000000000100111000110001110101 */
//   INSTRUCTION_POP , A,
//   INSTRUCTION_PUSH, 3472199, /* 00000000001101001111101101000111 */
//   INSTRUCTION_POP , B,
//   INSTRUCTION_OR  ,          /* 00000000000011011111111111011101 */
//   registers:
//    A = 1281141, B = 3472199, C = 4753340, D = 0
vm_instruction_result vm_instruction_or(Vm *vm);

// instruction: xor
//   the value in register A and register B operate a xor operation and result in register c
//
//  example code:
//   INSTRUCTION_PUSH, 1281141, /* 00000000000100111000110001110101 */
//   INSTRUCTION_POP , A,
//   INSTRUCTION_PUSH, 3472199, /* 00000000001101001111101101000111 */
//   INSTRUCTION_POP , B,
//   INSTRUCTION_XOR ,          /* 00000000001001110111011100110010 */
//   registers:
//    A = 1281141, B = 3472199, C = 2586418, D = 0
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

    INSTRUCTION_ADD,
    INSTRUCTION_SUB,
    INSTRUCTION_MUL,
    INSTRUCTION_DIV,

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