//
// Created by sirh3e on 10/17/2020.
//

#ifndef VM_STATUS_CODES_H
#define VM_STATUS_CODES_H

#include "vm.h"
#include "types.h"

vm_instruction_result status_code_handler_successful(Vm *, vm_instruction_result);

vm_instruction_result status_code_handler_failed(Vm *, vm_instruction_result);

enum StatusCode {
    STATUS_CODE_SUCCESSFUL,
    STATUS_CODE_FAILED,
};

static vm_instruction_result (*status_code_handlers[])(Vm *, vm_instruction_result) = {
        [STATUS_CODE_SUCCESSFUL] = status_code_handler_successful,
        [STATUS_CODE_FAILED] = status_code_handler_failed,
};

#endif //VM_STATUS_CODES_H