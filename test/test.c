//
// Created by sirh3e on 9/20/2020.
//

#include <stdio.h>

#include "test.h"
#include "test_instructions.h"
#include "../src/types.h"
#include "../src/macros.h"

int main(){

    i32 test_result = 0;

    int (*tests[])() = {
            test_instruction_add,
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

    for(int i = 0; i < ARRAY_LENGTH(tests); i++){
        test_result |= tests[i]();
    }

    return test_result;
}

int test_assert(int expression, const char* message){

    char* color;
    char* status;

    color = expression ? COLOR_GREEN : COLOR_RED;
    status = expression ? "PASSED" : "FAILED";

    printf("[ %s%s%s ] %s\n", color, status, COLOR_REST, message);

    return expression == 1 ? 0 : 1;
}