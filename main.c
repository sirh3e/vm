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

typedef int int_t;
typedef int_t i32;

typedef unsigned int uint_t;
typedef uint_t u32;

enum Register{
    A,
    B,
    C,
    REGISTERS_LENGTH
};

typedef struct{
    i32* registers;

    i32* stack;
    u32 stack_allocated;
    u32 stack_length;
    u32 stack_index;

    i32* instructions; // program
    u32 instruction_allocated;
    u32 instruction_length;
    u32 instruction_index;
}Vm;

int vm_instruction_fetch(Vm*);

int instruction_evaluate(Vm*, int instruction);

int instruction_halt(Vm*);

int instruction_add(Vm*);
int instruction_sub(Vm*);
int instruction_mul(Vm*);

int instruction_inc(Vm*);

int instruction_log(Vm*);

enum Instruction{
    INSTRUCTION_HALT = 0,   //ToDo

    INSTRUCTION_ADD,        //register c = register a + register b; and store it on the stack
    INSTRUCTION_SUB,        //register c = register a - register b; and store it on the stack
    INSTRUCTION_MUL,        //register c = register a * register b; and store it on the stack

    INSTRUCTION_INC,        //

    INSTRUCTION_LOG,        //

    INSTRUCTION_LENGTH
};

int (*instructions[])(Vm*) ={
        [INSTRUCTION_HALT] = instruction_halt, //ToDo

        [INSTRUCTION_ADD] = instruction_add,
        [INSTRUCTION_SUB] = instruction_sub,
        [INSTRUCTION_MUL] = instruction_mul,

        [INSTRUCTION_INC] = instruction_inc,

        [INSTRUCTION_LOG] = instruction_log,
};

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


int instruction_halt(Vm* vm){

    assert(vm != NULL);

    return 0;
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

int instruction_inc(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH); //a tmp variable would be cheating

    vm->registers[vm->instructions[vm->instruction_index]] = vm->registers[vm->instructions[vm->instruction_index]] + vm->instructions[vm->instruction_index + 1];

    vm->instruction_index++;
    vm->instruction_index++;

    return 0;
}

int instruction_log(Vm* vm){

    assert(vm != NULL);
    assert(vm->instructions[vm->instruction_index] < INSTRUCTION_LENGTH); //a tmp variable would be cheating

    printf("%d\n", vm->registers[vm->instructions[vm->instruction_index++]]);

    return 0;
}