.PHONY: cicd-clean
cicd-clean: clean

.PHONY: cicd-all
cicd-all: $(TARGET)
	@echo Target $(TARGET) build finished.

.PHONY: cicd-check
cicd-check: check