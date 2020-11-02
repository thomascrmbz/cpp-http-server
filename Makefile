all: test.o http.o response.o request.o header.o
	c++ test.o http.o response.o request.o header.o

test.o: test.cpp
	c++ -c test.cpp

http.o: src/http.cpp
	c++ --std=c++11 -c src/http.cpp

response.o: src/response.cpp
	c++ --std=c++11 -c src/response.cpp

request.o: src/request.cpp
	c++ --std=c++11 -c src/request.cpp

header.o: src/header.cpp
	c++ --std=c++11 -c src/header.cpp

clean:
	rm *.o a.out