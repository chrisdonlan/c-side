include mk/project.mk
include mk/targets.mk

run-ocr-memtest-c: ocr-memtest-c
	./ocr-memtest-c foo/foo.png
