.SECONDEXPANSION:
hello-world-cxx: $$@.o
ocr-memtest-cxx: $$@.o
	$(CXX) $(LDFLAGS) -o $@ $^
ocr-memtest-c: $$@.o
