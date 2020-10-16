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