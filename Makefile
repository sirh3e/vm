#project
VM_NAME := VM

# target macros
TARGET := tests
MAIN_SRC := test/test.c

# compile macros
DIRS := src test
OBJS := 

# intermedia compile macros
ALL_OBJS := 
CLEAN_FILES := $(TARGET) $(OBJS)
DIST_CLEAN_FILES := $(OBJS)

# recursive wildcard
rwildcard=$(foreach d,$(wildcard $(addsuffix *,$(1))),$(call rwildcard,$(d)/,$(2))$(filter $(subst *,%,$(2)),$(d)))

# default target
default: show-info all

# non-phony targets
$(TARGET): build-subdirs $(OBJS) find-all-objs
	@echo -e "\t" CC $(CFLAGS) $(AL_OBJS) $(MAIN_SRC) -o $@
	@$(CC) $(CFLAGS) $(ALL_OBJS) $(MAIN_SRC) -o $@

.PHONY: check
check: configure
	./$(TARGET)

# phony targets
.PHONY: all
all: configure $(TARGET)
	@echo Target $(TARGET) build finished.

.PHONY: clean
clean: clean-subdirs
	@echo CLEAN $(CLEAN_FILES)
	@rm -f $(CLEAN_FILES)

.PHONY: distclean
distclean: clean-subdirs
	@echo CLEAN $(DIST_CLEAN_FILES)
	@rm -f $(DIST_CLEAN_FILES)

# phony funcs
.PHONY: find-all-objs
find-all-objs:
	$(eval ALL_OBJS += $(call rwildcard,$(DIRS),*.o))

.PHONY: show-info
show-info:
	@echo Building Project

.PHONY: configure
configure: configure-config configure-format configure-version configure-prepare format

.PHONY: configure-config
configure-config:
	./scripts/configure_config.sh

.PHONY: format
format:
	find src/ test/ -type f -iname '*.c' -o -iname '*.h' | xargs clang-format -i

.PHONY: shellcheck
shellcheck:
	shellcheck -a ./scripts/*.sh

# need to be placed at the end of the file
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
export PROJECT_PATH := $(patsubst %/,%,$(dir $(mkfile_path)))
export MAKEFILES_DIR=$(PROJECT_PATH)/makefiles
export MAKE_INCLUDE=$(MAKEFILES_DIR)/make.global
export SUB_MAKE_INCLUDE=$(MAKEFILES_DIR)/submake.global
include $(MAKE_INCLUDE)

include $(MAKEFILES_DIR)/cicd.mk
include $(MAKEFILES_DIR)/container.mk
include $(MAKEFILES_DIR)/format.mk
include $(MAKEFILES_DIR)/version.mk