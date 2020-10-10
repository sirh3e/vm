//
// Created by sirh3e on 9/20/2020.
//

#include <stdio.h>

#include "test.h"

int main(){

    test_vm_instruction_result test_result = 0;
    for(int i = 0; i < ARRAY_LENGTH(tests); i++){
        test_result |= tests[i]();
    }

    return test_result;
}

int test_assert(int expression, const char* message){

    char* color;
    char* status;

    color = expression ?  VM_TEST_COLOR_GREEN :  VM_TEST_COLOR_RED;
    status = expression ? "PASSED" : "FAILED";

    printf("[ %s%s%s ] %s\n", color, status, VM_TEST_COLOR_REST, message);

    return expression == 1 ? 0 : 1;
}