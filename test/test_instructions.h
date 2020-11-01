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

#ifndef VM_TEST_INSTRUCTIONS_H
#define VM_TEST_INSTRUCTIONS_H

#include "test_types.h"

test_vm_result test_vm_instruction_add();

test_vm_result test_vm_instruction_and();

test_vm_result test_vm_instruction_dec();

test_vm_result test_vm_instruction_div();

test_vm_result test_vm_instruction_halt();

test_vm_result test_vm_instruction_inc();

test_vm_result test_vm_instruction_je();

test_vm_result test_vm_instruction_jg();

test_vm_result test_vm_instruction_jge();

test_vm_result test_vm_instruction_jl();

test_vm_result test_vm_instruction_jle();

test_vm_result test_vm_instruction_jmp();

test_vm_result test_vm_instruction_jne();

test_vm_result test_vm_instruction_label();

test_vm_result test_vm_instruction_load();

test_vm_result test_vm_instruction_log();

test_vm_result test_vm_instruction_mul();

test_vm_result test_vm_instruction_neg();

test_vm_result test_vm_instruction_nop();

test_vm_result test_vm_instruction_or();

test_vm_result test_vm_instruction_pop();

test_vm_result test_vm_instruction_push();

test_vm_result test_vm_instruction_save();

test_vm_result test_vm_instruction_shl();

test_vm_result test_vm_instruction_shr();

test_vm_result test_vm_instruction_sub();

test_vm_result test_vm_instruction_xor();

#define TEST_INSTRUCTION_MAP(test_instruction_func)                            \
	test_vm_instruction_##test_instruction_func

static test_vm_result (*const test_instructions[])() = {
	TEST_INSTRUCTION_MAP(add),  TEST_INSTRUCTION_MAP(and),
	TEST_INSTRUCTION_MAP(dec),  TEST_INSTRUCTION_MAP(div),
	TEST_INSTRUCTION_MAP(halt), TEST_INSTRUCTION_MAP(inc),
	TEST_INSTRUCTION_MAP(je),   TEST_INSTRUCTION_MAP(jg),
	TEST_INSTRUCTION_MAP(jge),  TEST_INSTRUCTION_MAP(jl),
	TEST_INSTRUCTION_MAP(jle),  TEST_INSTRUCTION_MAP(jmp),
	TEST_INSTRUCTION_MAP(jne),  TEST_INSTRUCTION_MAP(label),
	TEST_INSTRUCTION_MAP(load), TEST_INSTRUCTION_MAP(log),
	TEST_INSTRUCTION_MAP(mul),  TEST_INSTRUCTION_MAP(neg),
	TEST_INSTRUCTION_MAP(nop),  TEST_INSTRUCTION_MAP(or),
	TEST_INSTRUCTION_MAP(pop),  TEST_INSTRUCTION_MAP(push),
	TEST_INSTRUCTION_MAP(save), TEST_INSTRUCTION_MAP(shl),
	TEST_INSTRUCTION_MAP(shr),  TEST_INSTRUCTION_MAP(sub),
	TEST_INSTRUCTION_MAP(xor),
};

#endif // VM_TEST_INSTRUCTIONS_H
