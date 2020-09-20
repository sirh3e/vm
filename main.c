#include "src/vm.h"
#include "src/instructions.h"
#include "src/registers.h"
#include "src/macros.h"

int main(){

    Vm* vm = vm_new();
    vm_init(vm);
    i32 program[] = {
            INSTRUCTION_ADD, 64, 2,
            INSTRUCTION_LOG, A,
            INSTRUCTION_LOG, B,

            INSTRUCTION_INC, A, 128,
            INSTRUCTION_LOG, A,

            INSTRUCTION_INC, B, 128,
            INSTRUCTION_INC, B, 128,
            INSTRUCTION_INC, B, 128,
            INSTRUCTION_INC, B, 128,
            INSTRUCTION_LOG, B,

            INSTRUCTION_PUSH, 1289,
            INSTRUCTION_POP,

            INSTRUCTION_LOAD, B,
            INSTRUCTION_SAVE, B,

            INSTRUCTION_POP,
            INSTRUCTION_LOAD, C,

            INSTRUCTION_LOG, C,

            INSTRUCTION_HALT
    };

    vm_program_set(vm, program, ARRAY_LENGTH(program));

    int instruction = INSTRUCTION_HALT, instruction_result = 0;

    while ((instruction = vm_instruction_fetch(vm)) != INSTRUCTION_HALT){
        instruction_result = vm_instruction_evaluate(vm, instruction);
    }

    return 0;
}