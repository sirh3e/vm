//
// Created by sirh3e on 10/5/2020.
//

#include <assert.h>

#include "../instructions.h"
#include "../macros.h"

int instruction_nop(Vm* vm){

    assert(vm != NULL);
    VM_ASSERT_INSTRUCTION_INDEX(vm, 1);

    return 0;
}