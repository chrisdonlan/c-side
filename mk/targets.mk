.SECONDEXPANSION:
hello-world-cxx: $$@.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)
ocr-memtest-cxx: $$@.o
	$(CXX) -o $@ $^  $(CXXFLAGS) $(LDFLAGS)
ocr-memtest-c: $$@.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
