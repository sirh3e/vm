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

#include "test.h"

test_result_t test_vm_instruction_add();
test_result_t test_vm_instruction_and();
test_result_t test_vm_instruction_dec();
test_result_t test_vm_instruction_div();
test_result_t test_vm_instruction_halt();
test_result_t test_vm_instruction_inc();
test_result_t test_vm_instruction_load();
test_result_t test_vm_instruction_log();
test_result_t test_vm_instruction_mul();
test_result_t test_vm_instruction_neg();
test_result_t test_vm_instruction_or();
test_result_t test_vm_instruction_pop();
test_result_t test_vm_instruction_push();
test_result_t test_vm_instruction_save();
test_result_t test_vm_instruction_shl();
test_result_t test_vm_instruction_shr();
test_result_t test_vm_instruction_sub();
test_result_t test_vm_instruction_xor();

static test_result_t (*tests[])() = {
        //all instructions:
        test_vm_instruction_and,
        test_vm_instruction_dec,
        test_vm_instruction_div,
        test_vm_instruction_halt,
        test_vm_instruction_inc,
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
