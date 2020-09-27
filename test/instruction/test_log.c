//
// Created by sirh3e on 9/27/2020.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"

int test_instruction_log_0();

int test_instruction_log(){

    i32 test_results = 0;

    test_results |= test_instruction_log_0();

    return test_results;
}

int test_instruction_log_0(){

    i32 test_results = 0;
    i32 program[] = {
            INSTRUCTION_LOG, A,
            INSTRUCTION_LOG, B,
            INSTRUCTION_LOG, C,

            INSTRUCTION_PUSH, 128,
            INSTRUCTION_LOAD, A,
            INSTRUCTION_LOG, A,
    };

    Vm* vm = vm_new();

    vm_init(vm);
    vm_program_set(vm, program, ARRAY_LENGTH(program));

    TEST_BEGIN();

    char buffer[2048];
    char* text = "0\n";

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    fread(buffer, strlen(text) + 1, 0, stdout);
    TEST_ASSERT(strcmp(text, buffer), "stdout should be equal to: '0\\n'");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    fread(buffer, strlen(text) + 1, 0, stdout);
    TEST_ASSERT(strcmp(text, buffer), "stdout should be equal to: '0\\n'");

    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    fread(buffer, strlen(text) + 1, 0, stdout);
    TEST_ASSERT(strcmp(text, buffer), "stdout should be equal to: '0\\n'");

    text = "128\n";
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    vm_instruction_evaluate(vm, vm_instruction_fetch(vm));
    fread(buffer, strlen(text) + 1, 0, stdout);
    TEST_ASSERT(strcmp(text, buffer), "stdout should be equal to: '128\\n'");

    TEST_END();
    vm_free(vm);

    return test_results;
}