//
// Created by sirh3e on 9/21/2020.
//

#ifndef VM_TEST_INSTRUCTIONS_H
#define VM_TEST_INSTRUCTIONS_H

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

#define TEST_INSTRUCTION_MAP(test_instruction_func) \
        test_vm_instruction_  ## test_instruction_func

static test_vm_instruction_result (*tests[])() = {
        TEST_INSTRUCTION_MAP(and),
        TEST_INSTRUCTION_MAP(dec),
        TEST_INSTRUCTION_MAP(div),
        TEST_INSTRUCTION_MAP(halt),
        TEST_INSTRUCTION_MAP(inc),
        TEST_INSTRUCTION_MAP(je),
        TEST_INSTRUCTION_MAP(jge),
        TEST_INSTRUCTION_MAP(jl),
        TEST_INSTRUCTION_MAP(jle),
        TEST_INSTRUCTION_MAP(jmp),
        TEST_INSTRUCTION_MAP(jne),
        TEST_INSTRUCTION_MAP(load),
        TEST_INSTRUCTION_MAP(log),
        TEST_INSTRUCTION_MAP(mul),
        TEST_INSTRUCTION_MAP(neg),
        TEST_INSTRUCTION_MAP(or),
        TEST_INSTRUCTION_MAP(pop),
        TEST_INSTRUCTION_MAP(push),
        TEST_INSTRUCTION_MAP(save),
        TEST_INSTRUCTION_MAP(shl),
        TEST_INSTRUCTION_MAP(shr),
        TEST_INSTRUCTION_MAP(sub),
        TEST_INSTRUCTION_MAP(xor),
};

#endif //VM_TEST_INSTRUCTIONS_H
