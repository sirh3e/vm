//
// Created by sirh3e on 10/5/2020.
//

#include <assert.h>

#include "../instructions.h"
#include "../registers.h"
#include "../macros.h"

int instruction_jmp(Vm* vm){

    assert(vm != NULL);
    VM_INSTRUCTION_INDEX_ASSERT(vm, 2);

    return 0;
}