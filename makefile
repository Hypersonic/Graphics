INCLUDES = -Isrc/
LIBS = 
DIRS = 
OBJS = $(patsubst src/%.cpp,obj/%.o, $(wildcard src/*.cpp) $(foreach d, $(DIRS), $(wildcard src/$(d)/*.cpp)))
EXEC = graphics.out

main: dirs $(OBJS)
	g++ -o $(EXEC) $(OBJS) $(LIBS)

obj/%.o: src/%.cpp
	g++ -c -o $@ $<

dirs:
	@test -d obj || mkdir obj
	@for DIRECTORY in $(DIRS) ; do \
		test -d obj/$$DIRECTORY || mkdir obj/$$DIRECTORY; \
	done

clean:
	rm -f $(EXEC) $(OBJS)

run: main
	$(EXEC)
