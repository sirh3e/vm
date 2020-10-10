//
// Created by sirh3e on 9/21/2020.
//

#ifndef VM_TEST_INSTRUCTIONS_H
#define VM_TEST_INSTRUCTIONS_H

// ToDo list:
//  add tests:
//      je
//      jg
//      jge
//      jl
//      jle
//      jmp
//      jne
//      label

#include "test_types.h"

test_vm_instruction_result test_vm_instruction_add();
test_vm_instruction_result test_vm_instruction_and();
test_vm_instruction_result test_vm_instruction_dec();
test_vm_instruction_result test_vm_instruction_div();
test_vm_instruction_result test_vm_instruction_halt();
test_vm_instruction_result test_vm_instruction_inc();
test_vm_instruction_result test_vm_instruction_je();
test_vm_instruction_result test_vm_instruction_jg();
test_vm_instruction_result test_vm_instruction_jge();
test_vm_instruction_result test_vm_instruction_jl();
test_vm_instruction_result test_vm_instruction_jle();
test_vm_instruction_result test_vm_instruction_jmp();
test_vm_instruction_result test_vm_instruction_jne();
test_vm_instruction_result test_vm_instruction_load();
test_vm_instruction_result test_vm_instruction_log();
test_vm_instruction_result test_vm_instruction_mul();
test_vm_instruction_result test_vm_instruction_neg();
test_vm_instruction_result test_vm_instruction_or();
test_vm_instruction_result test_vm_instruction_pop();
test_vm_instruction_result test_vm_instruction_push();
test_vm_instruction_result test_vm_instruction_save();
test_vm_instruction_result test_vm_instruction_shl();
test_vm_instruction_result test_vm_instruction_shr();
test_vm_instruction_result test_vm_instruction_sub();
test_vm_instruction_result test_vm_instruction_xor();

static test_vm_instruction_result (*tests[])() = {
        //all instructions:
        test_vm_instruction_and,
        test_vm_instruction_dec,
        test_vm_instruction_div,
        test_vm_instruction_halt,
        test_vm_instruction_inc,
        test_vm_instruction_je,
        test_vm_instruction_jge,
        test_vm_instruction_jg,
        test_vm_instruction_jl,
        test_vm_instruction_jle,
        test_vm_instruction_jmp,
        test_vm_instruction_jne,
        test_vm_instruction_load,
        test_vm_instruction_log,
        test_vm_instruction_mul,
        test_vm_instruction_neg,
        test_vm_instruction_or,
        test_vm_instruction_pop,
        test_vm_instruction_push,
        test_vm_instruction_save,
        test_vm_instruction_shl,
        test_vm_instruction_shr,
        test_vm_instruction_sub,
        test_vm_instruction_xor,
};

#endif //VM_TEST_INSTRUCTIONS_H
