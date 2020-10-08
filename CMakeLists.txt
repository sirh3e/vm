cmake_minimum_required(VERSION 3.16)
project(vm C)

set(CMAKE_C_STANDARD 99)
add_executable(main
./main.c
./src/vm.c
./src/instruction/jmp.c
./src/instruction/log.c
./src/instruction/or.c
./src/instruction/mul.c
./src/instruction/inc.c
./src/instruction/pop.c
./src/instruction/push.c
./src/instruction/shr.c
./src/instruction/neg.c
./src/instruction/div.c
./src/instruction/xor.c
./src/instruction/and.c
./src/instruction/label.c
./src/instruction/dec.c
./src/instruction/halt.c
./src/instruction/add.c
./src/instruction/sub.c
./src/instruction/save.c
./src/instruction/load.c
./src/instruction/je.c
./src/instruction/nop.c
./src/instruction/shl.c
./src/instruction/xor.c src/instruction/nop.c src/instruction/jmp.c
./src/instruction/xor.c src/instruction/label.c src/instruction/jg.c)
