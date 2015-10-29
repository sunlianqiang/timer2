test: Timer.o Thread.o test.o
	g++ -o test Timer.o Thread.o test.o -lpthread 
test.o: test.cpp
	g++ -c test.cpp
Timer.o: Timer.h Timer.cpp
	g++ -c Timer.h Timer.cpp
Thread.o:Thread.h Thread.o
	g++ -c Thread.h Thread.cpp -lpthread

clean:
	rm test Timer.o Thread.o *.gch
ctags:
	ctags -R --c-types=+px
