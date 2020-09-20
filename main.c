#include <assert.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

#define STACK_DEFAULT_ALLOCATED_SIZE 4096
#define INSTRUCTION_DEFAULT_ALLOCATED_SIZE 4096

#define VM_STACK_GET_BY_INDEX(vm, index) (vm->stack[index])
#define VM_STACK_GET(vm) (VM_STACK_GET_BY_INDEX(vm, vm->stack_index))

#define VM_STACK_SET_BY_INDEX(vm, index, value) (vm->stack[index] = value)
#define VM_STACK_SET(vm, value) (VM_STACK_SET_BY_INDEX(vm, vm->stack_index, value))

#define VM_INSTRUCTION_GET_BY_INDEX(vm, index) (vm->instructions[index])
#define VM_INSTRUCTION_GET(vm) (VM_INSTRUCTION_GET_BY_INDEX(vm, vm->instruction_index))

#define VM_INSTRUCTION_SET(vm, instruction) (vm->instructions[vm->instruction_index++] = instruction)

//ToDo https://www.cs.yale.edu/flint/cs421/papers/x86-asm/asm.html
//ToDo labels:
//  label

//ToDo simple:
//  not,

//ToDo flow:
//  je <label> (jump when equal)
//  jne <label> (jump when not equal)
//  jz <label> (jump when last result was zero)
//  jg <label> (jump when greater than)
//  jge <label> (jump when greater than or equal to)
//  jl <label> (jump when less than)
//  jle <label> (jump when less than or equal to)
//  cmp
//  call, ret | functions





int main(){

    Vm vm = {
            .registers = (i32*)malloc(sizeof(i32) * REGISTERS_LENGTH),

            .stack = (i32*)malloc(sizeof(i32) * STACK_DEFAULT_ALLOCATED_SIZE),
            .stack_allocated = STACK_DEFAULT_ALLOCATED_SIZE,
            .stack_length = 0,
            .stack_index = 0,

            .instructions = (i32*)malloc(sizeof(i32) * INSTRUCTION_DEFAULT_ALLOCATED_SIZE),
            .instruction_allocated = INSTRUCTION_DEFAULT_ALLOCATED_SIZE,
            .instruction_length = 0,
            .instruction_index = 0,
    };

    u32 program_length;
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
    program_length = ARRAY_LENGTH(program);

    vm.instruction_length = program_length;
    memcpy(vm.instructions, program, vm.instruction_length * sizeof(i32));

    int instruction = INSTRUCTION_HALT, instruction_result = 0;

    while ((instruction = vm_instruction_fetch(&vm)) != INSTRUCTION_HALT){
        instruction_result = instruction_evaluate(&vm, instruction);
    }

    return 0;
}

int vm_instruction_fetch(Vm* vm){

    assert(vm != NULL);

    return vm->instructions[vm->instruction_index++];
}

int instruction_evaluate(Vm* vm, int instruction){

    assert(vm != NULL);
    assert(instruction > 0);

    return instructions[instruction](vm);
}




int instruction_add(Vm* vm){

    assert(vm != NULL);

    vm->registers[A] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;
    vm->registers[B] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;

    vm->registers[C] = vm->registers[A] + vm->registers[B];
    vm->stack[vm->stack_index++] = vm->registers[C];

    return 0;
}

int instruction_sub(Vm* vm){

    assert(vm != NULL);

    vm->registers[A] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;
    vm->registers[B] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;

    vm->registers[C] = vm->registers[A] - vm->registers[B];
    vm->stack[vm->stack_index++] = vm->registers[C];

    return 0;
}

int instruction_mul(Vm* vm){

    assert(vm != NULL);

    vm->registers[A] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;
    vm->registers[B] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;

    vm->registers[C] = vm->registers[A] * vm->registers[B];
    vm->stack[vm->stack_index++] = vm->registers[C];

    return 0;
}

int instruction_div(Vm* vm){

    assert(vm != NULL);
    assert(VM_INSTRUCTION_GET_BY_INDEX(vm, vm->instruction_index + 1) == 0);

    vm->registers[A] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;
    vm->registers[B] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;

    vm->registers[C] = vm->registers[A] / vm->registers[B];
    vm->stack[vm->stack_index++] = vm->registers[C];

    return 0;
}

int instruction_dec(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH); //a tmp variable would be cheating

    vm->registers[vm->instructions[vm->instruction_index]] -= vm->instructions[vm->instruction_index++];
    vm->instruction_index++;

    return 0;
}

int instruction_inc(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH); //a tmp variable would be cheating

    vm->registers[vm->instructions[vm->instruction_index]] += vm->instructions[vm->instruction_index++];
    vm->instruction_index++;

    return 0;
}

int instruction_neg(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH);

    vm->registers[vm->instructions[vm->instruction_index]] *= -1;
    vm->instruction_index++;

    return 0;
}

int instruction_and(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH);

    vm->registers[A] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;
    vm->registers[B] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;

    vm->registers[C] = vm->registers[A] & vm->registers[B];

    return 0;
}

int instruction_or(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH);

    vm->registers[A] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;
    vm->registers[B] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;

    vm->registers[C] = vm->registers[A] | vm->registers[B];

    return 0;
}

int instruction_xor(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH);

    vm->registers[A] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;
    vm->registers[B] = VM_INSTRUCTION_GET(vm); vm->instruction_index++;

    vm->registers[C] = vm->registers[A] ^ vm->registers[B];

    return 0;
}

int instruction_shr(Vm* vm){ //right

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH);

    vm->registers[vm->instructions[vm->instruction_index]] >>= vm->instructions[vm->instruction_index++];
    vm->instruction_index++;

    return 0;
}

int instruction_shl(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH);

    vm->registers[vm->instructions[vm->instruction_index]] <<= vm->instructions[vm->instruction_index++];
    vm->instruction_index++;

    return 0;
}

int instruction_push(Vm* vm){

    assert(vm != NULL);

    VM_STACK_SET_BY_INDEX(vm, vm->stack_index++, VM_INSTRUCTION_GET_BY_INDEX(vm, vm->instruction_index++));

    return 0;
}

int instruction_pop(Vm* vm){

    assert(vm != NULL);

    vm->stack_index--;

    return 0;
}

int instruction_save(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < REGISTERS_LENGTH);

    vm->stack[vm->stack_index++] = vm->registers[vm->instructions[vm->instruction_index++]];

    return 0;
}

int instruction_load(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < REGISTERS_LENGTH);

    vm->registers[vm->instructions[vm->instruction_index++]] = vm->stack[vm->stack_index];

    return 0;
}

int instruction_log(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH); //a tmp variable would be cheating

    printf("%d\n", vm->registers[vm->instructions[vm->instruction_index++]]);

    return 0;
}