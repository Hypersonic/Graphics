MACHINE = $(shell uname -s)
INCLUDES = -Isrc/
DIRS = geometry canvas math dw
OBJS = $(patsubst src/%.cpp,obj/%.o, $(wildcard src/*.cpp) $(foreach d, $(DIRS), $(wildcard src/$(d)/*.cpp)))
TESTS = $(patsubst src/%.cpp,test_objs/%.o, $(wildcard src/*.cpp) $(foreach d, $(DIRS), $(wildcard src/$(d)/*.cpp)))

CXX = g++
PLATFORM_LIBS = 
WARNINGS = -Wall -Wextra -Werror -Weffc++ -Wfloat-equal -Winit-self -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings -Wunreachable-code -Wold-style-definition -Wstrict-prototypes -Wmissing-prototypes -Wstrict-overflow=2 --pedantic
FEATURES = -fno-builtin -ffunction-sections
CFLAGS = -std=c++11 -O -g -march=native $(WARNINGS) $(FEATURES)

ifeq ($(MACHINE), Darwin)
	CXX = clang++ -stdlib=libc++
	PLATFORM_LIBS = -framework Cocoa -framework OpenGL $(shell sdl2-config --libs)
endif

LIBS = $(PLATFORM_LIBS)
EXEC = graphics.out
TEST_EXEC = graphics_test.out

main: dirs $(OBJS)
	$(CXX) $(CFLAGS) -o $(EXEC) $(OBJS) $(LIBS)

test: dirs $(TESTS)
	$(CXX) $(CFLAGS) -o $(TEST_EXEC) $(TESTS) $(LIBS)
	$(TEST_EXEC)

analyze: dirs $(OBJS)
	$(CXX) $(CFLAGS) --analyze src/main.cpp $(INCLUDES)

obj/%.o: src/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $< $(INCLUDES)

test_objs/%.o: src/%.cpp
	$(CXX) $(CFLAGS) -DUNIT_TESTS -c -o $@ $< $(INCLUDES)

dirs:
	@test -d obj || mkdir obj
	@for DIRECTORY in $(DIRS) ; do \
		test -d obj/$$DIRECTORY || mkdir obj/$$DIRECTORY; \
	done
	@test -d test_objs || mkdir test_objs
	@for DIRECTORY in $(DIRS) ; do \
		test -d test_objs/$$DIRECTORY || mkdir test_objs/$$DIRECTORY; \
	done

clean:
	rm -f $(EXEC) $(OBJS) $(EXEC_TEST) $(TESTS)

run: main
	$(EXEC)
