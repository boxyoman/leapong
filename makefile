all: pong

run: pong
	./pong

pong: main.cpp world.o
	g++ -g main.cpp /usr/lib/leap/libLeap.dylib -I/usr/include/leap/

world.o: world.cpp world.h
	g++ -c world.cpp /usr/lib/leap/libLeap.dylib -I/usr/include/leap/

clean:
	rm pong *.o