//
// Created by sirh3e on 9/21/2020.
//

#include "../test.h"

test_vm_result test_vm_instruction_dec()
{
	test_vm_result TEST_RESULTS_INIT(test_results);
	i32 program[] = {
		INSTRUCTION_DEC, A, 2,	 INSTRUCTION_DEC, A, 2,
		INSTRUCTION_DEC, B, 128, INSTRUCTION_DEC, C, 0,
	};

	VM_INIT(program);
	TEST_BEGIN();

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == -2);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[A] == -4);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[B] == -128);

	TEST_INSTRUCTION_EXECUTE_NEXT(vm);
	TEST_ASSERT(vm->registers[C] == 0);

	TEST_END(vm, test_results);

	return test_results;
}