//
// Created by sirh3e on 9/20/2020.
//

#include <stdio.h>

#include "test.h"
#include "test_instructions.h"
#include "../src/types.h"

int main(){

    i32 test_result = 0;

    test_result |= test_instruction_add();
    test_result |= test_instruction_and();
    test_result |= test_instruction_dec();
    test_result |= test_instruction_div();
    test_result |= test_instruction_halt();
    test_result |= test_instruction_inc();
    test_result |= test_instruction_load();
    test_result |= test_instruction_log();
    test_result |= test_instruction_mul();
    test_result |= test_instruction_neg();

    return test_result;
}

int test_assert(int expression, const char* message){

    char* color;
    char* status;

    color = expression ? COLOR_GREEN : COLOR_RED;
    status = expression ? "PASSED" : "FAILED";

    printf("[ %s%s%s ] %s\n", color, status , COLOR_REST, message);

    return expression == 1 ? 0 : 1;
}