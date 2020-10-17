//
// Created by sirh3e on 9/20/2020.
//

#include <stdio.h>

#include "test.h"

int main() {

    u32 test_length = ARRAY_LENGTH(tests);
    u32 instructions_amount = ARRAY_LENGTH(instructions);
    test_vm_instruction_result test_results = 0;
    for (u32 i = 0; i < test_length; i++) {
        test_results |= tests[i]();
    }
    printf("%d\n", test_length);
    printf("%d\n", instructions_amount);
    TEST_ASSERT_MESSAGE(test_length == instructions_amount, "checks if all instructions got a test function");

    return test_results;
}