//
// Created by sirh3e on 9/20/2020.
//

#include <stdio.h>

#include "test.h"

int main() {

    test_vm_instruction_result test_results = 0;

    u32 instruction_length = ARRAY_LENGTH(instructions);
    u32 tests_length = ARRAY_LENGTH(tests);

    for (u32 i = 0; i < tests_length; i++) {
        test_results |= tests[i]();
    }

    TEST_BEGIN();

    TEST_ASSERT_MESSAGE(instruction_length == INSTRUCTION_LENGTH, "checks if all instruction are in instructions");
    TEST_ASSERT_MESSAGE(tests_length == INSTRUCTION_LENGTH, "checks if all instructions got a test function");

    TEST_END(NULL);

    return test_results;
}