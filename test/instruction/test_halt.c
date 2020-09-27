//
// Created by sirh3e on 9/27/2020.
//

#include "../test.h"

#include "../../src/vm.h"
#include "../../src/instructions.h"
#include "../../src/registers.h"
#include "../../src/macros.h"


int test_instruction_halt_0();

int test_instruction_halt(){

    i32 test_results = 0;

    test_results |= test_instruction_halt_0();

    return test_results;
}

int test_instruction_halt_0(){
    return 0; //ToDo
}