cmake_minimum_required(VERSION 3.16)
project(vm C)

set(CMAKE_C_STANDARD 99)
add_executable(tests ./test/test.c
./src/instruction/add.c
./src/instruction/and.c
./src/instruction/dec.c
./src/instruction/div.c
./src/instruction/halt.c
./src/instruction/inc.c
./src/instruction/je.c
./src/instruction/jg.c
./src/instruction/jge.c
./src/instruction/jl.c
./src/instruction/jle.c
./src/instruction/jmp.c
./src/instruction/jne.c
./src/instruction/label.c
./src/instruction/load.c
./src/instruction/log.c
./src/instruction/mul.c
./src/instruction/neg.c
./src/instruction/nop.c
./src/instruction/or.c
./src/instruction/pop.c
./src/instruction/push.c
./src/instruction/save.c
./src/instruction/shl.c
./src/instruction/shr.c
./src/instruction/sub.c
./src/instruction/xor.c
./src/vm.c
./test/instruction/test_add.c
./test/instruction/test_and.c
./test/instruction/test_dec.c
./test/instruction/test_div.c
./test/instruction/test_halt.c
./test/instruction/test_inc.c
./test/instruction/test_load.c
./test/instruction/test_log.c
./test/instruction/test_mul.c
./test/instruction/test_neg.c
./test/instruction/test_or.c
./test/instruction/test_pop.c
./test/instruction/test_push.c
./test/instruction/test_save.c
./test/instruction/test_shl.c
./test/instruction/test_shr.c
./test/instruction/test_sub.c
./test/instruction/test_xor.c test/test_types.h test/test_color.h test/test_assert.h test/test_util.h src/defaults.h src/util.h test/instruction/test_jmp.c test/instruction/test_jne.c)
