std=c++17
deps=$(shell cat deps)

CXX=c++
CXXFLAGS+=-std=$(std)
CXXFLAGS+=$(shell pkg-config --cflags $(deps))
CFLAGS+=$(shell pkg-config --cflags $(deps))
LDFLAGS+=$(shell pkg-config --libs $(deps))

proj-config:
	@echo deps: $(deps)
	@echo CXXFLAGS: $(CXXFLAGS)
	@echo CFLAGS: $(CFLAGS)
	@echo LDFLAGS: $(LDFLAGS)

