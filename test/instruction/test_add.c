//
// Created by sirh3e on 9/20/2020.
//

#include "../test.h"

test_vm_result test_vm_instruction_add()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	i32 program[] = {
		INSTRUCTION_ADD, 64, 2, INSTRUCTION_ADD, 64, -36,
	};

	Vm *vm = vm_new();

	vm_init(vm);
	vm_program_set(vm, program, ARRAY_LENGTH(program));

	TEST_BEGIN();

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 64);
	TEST_ASSERT(vm->registers[B] == 02);
	TEST_ASSERT(vm->registers[C] == 66);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == 64);
	TEST_ASSERT(vm->registers[B] == -36);
	TEST_ASSERT(vm->registers[C] == 28);

	TEST_END(vm, test_results);

	return test_results;
}