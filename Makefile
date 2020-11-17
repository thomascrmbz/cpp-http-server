all: mkdir library

mkdir:
	mkdir -p bin

library: mkdir bin/http.o bin/response.o bin/request.o bin/header.o
	ar -r bin/libHTTP.a bin/http.o bin/response.o bin/request.o bin/header.o

example: all
	g++ -c --std=c++11 example.cpp -I./src -o bin/example.o
	g++ --std=c++11 bin/example.o -L./bin -lHTTP -o example.out

bin/http.o:
	c++ --std=c++11 -c src/http.cpp -o bin/http.o
bin/response.o:
	c++ --std=c++11 -c src/response.cpp -o bin/response.o
bin/request.o:
	c++ --std=c++11 -c src/request.cpp -o bin/request.o
bin/header.o:
	c++ --std=c++11 -c src/header.cpp -o bin/header.o

clean:
	rm -rf bin/*