#objects = Timer.o Thread.o test.o
objects := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
test: $(objects) 
	g++ -g -o test $(objects) -lpthread 
test.o: 
Timer.o: Timer.h
Thread.o:Thread.h 

.PHONY: ctags clean 
ctags:
	ctags -R --c-types=+px
clean:
	$(RM) test $(objects) 
