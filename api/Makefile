.PHONY:all
all:set_inverted_index.o inverted.o libindex.a main_set_inverted_index
set_inverted_index.o:set_inverted_index.cpp
	g++ -c $^ -std=c++11 -I /usr/local/src/cppjieba/include -I /usr/local/src/cppjieba/deps -lprotobuf -I ./proto -o $@
inverted.o:./proto/inverted.pb.cc
	g++ -c $^ -o $@
libindex.a: set_inverted_index.o inverted.o
	ar rc $@ $^
main_set_inverted_index:main_set_inverted_index.cpp
	g++  $^ -I /usr/local/src/cppjieba/include -I /usr/local/src/cppjieba/deps -lprotobuf -I ./proto -std=c++11  -L. -lindex -o $@
.PHONY:clean
clean:
	rm -f *.o *.a main_set_inverted_index
