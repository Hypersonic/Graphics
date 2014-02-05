MACHINE = $(shell uname -s)
INCLUDES = -Isrc/
DIRS = geometry canvas
OBJS = $(patsubst src/%.cpp,obj/%.o, $(wildcard src/*.cpp) $(foreach d, $(DIRS), $(wildcard src/$(d)/*.cpp)))

CXX = g++
PLATFORM_LIBS = 

ifeq ($(MACHINE), Darwin)
	CXX = clang++ -stdlib=libc++
	PLATFORM_LIBS = -framework Cocoa -framework OpenGL -framework SDL2
endif

LIBS = $(PLATFORM_LIBS)
EXEC = graphics.out

main: dirs $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LIBS)

obj/%.o: src/%.cpp
	$(CXX) -c -o $@ $< $(INCLUDES)

dirs:
	@test -d obj || mkdir obj
	@for DIRECTORY in $(DIRS) ; do \
		test -d obj/$$DIRECTORY || mkdir obj/$$DIRECTORY; \
	done

clean:
	rm -f $(EXEC) $(OBJS)

run: main
	$(EXEC)
