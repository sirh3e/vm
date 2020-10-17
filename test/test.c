//
// Created by sirh3e on 9/20/2020.
//

#include <stdio.h>

#include "test.h"

int main() {

    u32 test_length = ARRAY_LENGTH(tests);
    test_vm_instruction_result test_result = 0;
    for (u32 i = 0; i < test_length; i++) {
        test_result |= tests[i]();
    }
    TEST_ASSERT_MESSAGE(test_length == INSTRUCTION_LENGTH, "checks if all instructions got a test function");

    return test_result;
}