//
// Created by sirh3e on 10/18/2020.
//

#include "../assert.h"
#include "../defaults.h"
#include "../statuscode.h"
#include "../stats.h"

vm_instruction_result status_code_handler_failed(Vm *vm, vm_instruction_result result) {

    if (VM_DEFAULT_DEBUG)
        vm_stats(vm);

    return result;
}
