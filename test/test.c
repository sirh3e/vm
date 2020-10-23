//
// Created by sirh3e on 9/20/2020.
//

#include <stdio.h>

#include "test.h"

int main() {

    test_vm_result TEST_RESULTS_INIT(test_result);
    test_vm_result TEST_RESULTS_INIT(test_results);

    u32 instruction_length = ARRAY_LENGTH(instructions);
    u32 tests_length = ARRAY_LENGTH(tests);

    for (u32 i = 0; i < tests_length; i++) {
        test_result = tests[i]();

        test_results.failed += test_result.failed;
        test_results.passed += test_result.passed;
    }

    TEST_BEGIN();

    TEST_ASSERT_MESSAGE(instruction_length == INSTRUCTION_LENGTH, "checks if all instruction are in instructions");
    TEST_ASSERT_MESSAGE(tests_length == INSTRUCTION_LENGTH, "checks if all instructions got a test function");

    TEST_END(NULL, test_results);

    return test_results.failed;
}