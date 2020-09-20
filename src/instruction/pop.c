//
// Created by sirh3e on 9/20/2020.
//

#include <assert.h>

#include "../instructions.h"

int instruction_pop(Vm* vm){

    assert(vm != NULL);

    vm->stack_index--;

    return 0;
}