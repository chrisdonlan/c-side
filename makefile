include mk/project.mk
include mk/targets.mk
include mk/runners.mk

run-ocr-memtest-c: ocr-memtest-c
	$(run)$< foo/foo.png
valgrind-ocr-memtest-c: ocr-memtest-c
ifeq ($(N),)
	@echo "Usage: make $@ [N=<iteration-count>]"
endif
	$(valgrind-memory)$< foo/foo.png $(N)
