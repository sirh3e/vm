//
// Created by sirh3e on 9/27/2020.
//

#include <stdio.h>
#include <string.h>

#include "../test_instructions.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"

test_vm_instruction_result test_vm_instruction_log() {

    i32 test_results = 0;
    i32 program[] = {
            INSTRUCTION_LOG, A,
            INSTRUCTION_LOG, B,
            INSTRUCTION_LOG, C,

            INSTRUCTION_PUSH, 128,
            INSTRUCTION_LOAD, A,
            INSTRUCTION_LOG, A,
    };

    VM_INIT(program);
    TEST_BEGIN();

    char buffer[2048];
    char *text = "0\n";

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    fread(buffer, strlen(text) + 1, 0, stdout);
    TEST_ASSERT(strcmp(text, buffer), "stdout should be equal to: '0\\n'");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    fread(buffer, strlen(text) + 1, 0, stdout);
    TEST_ASSERT(strcmp(text, buffer), "stdout should be equal to: '0\\n'");

    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    fread(buffer, strlen(text) + 1, 0, stdout);
    TEST_ASSERT(strcmp(text, buffer), "stdout should be equal to: '0\\n'");

    text = "128\n";
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    TEST_INSTRUCTION_EXECUTE_NEXT(vm);
    fread(buffer, strlen(text) + 1, 0, stdout);
    TEST_ASSERT(strcmp(text, buffer), "stdout should be equal to: '128\\n'");

    TEST_END(vm);

    return test_results;
}