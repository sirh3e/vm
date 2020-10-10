//
// Created by sirh3e on 10/5/2020.
//

#include <assert.h>

#include "../instructions.h"
#include "../registers.h"
#include "../macros.h"

int instruction_jmp(Vm* vm){

    assert(vm != NULL);
    VM_ASSERT_INSTRUCTION_INDEX(vm, 1);
    assert(VM_INSTRUCTION_GET(vm) <= 0);
    assert(VM_INSTRUCTION_GET_BY_INDEX(vm, VM_INSTRUCTION_GET(vm)) != INSTRUCTION_LABEL);
    
    vm->instruction_index = VM_INSTRUCTION_GET(vm);
    
    return 0;
}