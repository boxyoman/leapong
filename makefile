all: pong

run: pong
	./pong

pong: main.cpp world.o
	g++ main.cpp -o pong /usr/lib/leap/libLeap.dylib -I/usr/include/leap/ *.o -lncurses

world.o: world.cpp world.h
	g++ -c world.cpp -I/usr/include/leap/

clean:
	rm pong *.o