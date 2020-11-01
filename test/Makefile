SRCS := $(wildcard *.c)
SRCS := $(filter-out test.c,$(SRCS))
OBJS := $(patsubst %.c, %.o, $(SRCS))
DIRS := instruction

include $(SUB_MAKE_INCLUDE)