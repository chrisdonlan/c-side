std=c++17
deps=$(shell cat deps)

CXX=c++
CXXFLAGS+=-std=$(std)
CXXFLAGS+=$(shell pkg-config --cflags $(deps))
CFLAGS+=$(shell pkg-config --cflags $(deps))
LDFLAGS+=$(shell pkg-config --libs $(deps))

vars:
	@echo deps: $(deps)
	@echo CXXFLAGS: $(CXXFLAGS)
	@echo CFLAGS: $(CFLAGS)
	@echo LDFLAGS: $(LDFLAGS)

.SECONDEXPANSION:
hello-world-cxx: $$@.o
ocr-memtest-cxx: $$@.o
	$(CXX) $(LDFLAGS) -o $@ $^
ocr-memtest-c: $$@.o
