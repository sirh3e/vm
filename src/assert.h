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

#ifndef VM_ASSERT_H
#define VM_ASSERT_H

#include "registers.h"

#include <assert.h>
#include <stdio.h>

#define ASSERT(expression) assert(expression)

#define VM_ASSERT(vm) ASSERT(vm != NULL)

#define VM_ASSERT_STACK(vm, index) ASSERT(index <= vm->stack_length)

#define VM_ASSERT_STACK_INDEX(vm, amount)                                      \
	VM_ASSERT_STACK(vm, vm->stack_index + amount)

#define VM_ASSERT_INSTRUCTION(instruction)                                     \
	ASSERT(instruction < INSTRUCTION_LENGTH)

#define VM_ASSERT_INSTRUCTION_INDEX(vm, amount)                                \
	ASSERT(vm->instruction_index + amount <= vm->instruction_length)

#define VM_ASSERT_REGISTER(register_index)                                     \
	ASSERT(register_index < REGISTERS_LENGTH)

#endif // VM_ASSERT_H
