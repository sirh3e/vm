//
// Created by sirh3e on 9/21/2020.
//

#ifndef VM_TEST_INSTRUCTIONS_H
#define VM_TEST_INSTRUCTIONS_H

#include "test.h"

test_result_t test_instruction_add();
test_result_t test_instruction_and();
test_result_t test_instruction_dec();
test_result_t test_instruction_div();
test_result_t test_instruction_halt();
test_result_t test_instruction_inc();
test_result_t test_instruction_load();
test_result_t test_instruction_log();
test_result_t test_instruction_mul();
test_result_t test_instruction_neg();
test_result_t test_instruction_or();
test_result_t test_instruction_pop();
test_result_t test_instruction_push();
test_result_t test_instruction_save();
test_result_t test_instruction_shl();
test_result_t test_instruction_shr();
test_result_t test_instruction_sub();
test_result_t test_instruction_xor();

static test_result_t (*tests[])() = {
        //all instructions:
        test_instruction_and,
        test_instruction_dec,
        test_instruction_div,
        test_instruction_halt,
        test_instruction_inc,
        test_instruction_load,
        test_instruction_log,
        test_instruction_mul,
        test_instruction_neg,
        test_instruction_or,
        test_instruction_pop,
        test_instruction_push,
        test_instruction_save,
        test_instruction_shl,
        test_instruction_shr,
        test_instruction_sub,
        test_instruction_xor,
};

#endif //VM_TEST_INSTRUCTIONS_H
