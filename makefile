iLeap = -I/usr/include/leap/

all: pong

run: pong
	./pong

pong: main.cpp world.o player.o ball.o vector.o
	g++ main.cpp -o pong /usr/lib/leap/libLeap.dylib $(iLeap) vector.o ball.o world.o player.o -lncurses

world.o: world.h world.cpp player.o
	g++ -c world.cpp $(iLeap)

player.o: player.h player.cpp world.h vector.o
	g++ -c player.cpp $(iLeap)

ball.o: ball.h ball.cpp world.h vector.o
	g++ -c ball.cpp $(iLeap)

vector.o: vector.cpp vector.h
	g++ -c vector.cpp

clean:
	rm pong *.o