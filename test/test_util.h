/*
* BSD 3-Clause License
* 
* Copyright (c) 2020, Huber Marvin <marvin dot huber at protonmail dot com>
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 
* * Redistributions of source code must retain the above copyright notice, this
*   list of conditions and the following disclaimer.
* 
* * Redistributions in binary form must reproduce the above copyright notice,
*   this list of conditions and the following disclaimer in the documentation
*   and/or other materials provided with the distribution.
* 
* * Neither the name of the copyright holder nor the names of its
*   contributors may be used to endorse or promote products derived from
*   this software without specific prior written permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef VM_TEST_UTIL_H
#define VM_TEST_UTIL_H

#include "../src/util.h"
#include "../src/vm.h"
#include "test_color.h"

#define RESULTS_ADD_RESULT(test_results, test_result)                          \
	test_results.failed += test_result.failed;                             \
	test_results.passed += test_result.passed

#define TEST_RESULTS_INIT(test_result)                                         \
	test_result = {                                                        \
		.failed = 0,                                                   \
		.passed = 0,                                                   \
	}

#define VM_INIT(program)                                                       \
	Vm *vm = vm_new();                                                     \
	vm_init(vm);                                                           \
	vm_program_set(vm, program, ARRAY_LENGTH(program))

#define TEST_BEGIN() printf("[ BEGIN  ] %s\n", __func__)

#define TEST_VM_BEGIN() TEST_BEGIN()

#define TEST_END(test_results)                                                 \
	printf("[ END    ] %s tests: %s%u%s passed: %s%u%s failed: %s%u%s\n",  \
	       __func__,                                                       \
	       test_results.failed ? VM_TEST_COLOR_RED : VM_TEST_COLOR_GREEN,  \
	       test_results.failed + test_results.passed,                      \
	       VM_TEST_COLOR_REST,                                             \
	       test_results.failed ? VM_TEST_COLOR_RED : VM_TEST_COLOR_GREEN,  \
	       test_results.passed,                                            \
	       VM_TEST_COLOR_REST,                                             \
	       test_results.failed ? VM_TEST_COLOR_RED : VM_TEST_COLOR_GREEN,  \
	       test_results.failed,                                            \
	       VM_TEST_COLOR_REST)

#define TEST_VM_END(vm, test_results)                                          \
	TEST_END(test_results);                                                \
	vm_free(vm)

#define TEST_INSTRUCTION_EXECUTE_NEXT(vm)                                      \
	vm_instruction_evaluate(vm, vm_instruction_fetch(vm))

#endif // VM_TEST_UTIL_H