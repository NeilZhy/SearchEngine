.PHONY:all
all:set_inverted_index.o forward.o inverted.o libindex.a
set_inverted_index.o:set_inverted_index.cpp
	g++ -c $^ -std=c++11 -I /usr/local/src/cppjieba/include -I /usr/local/src/cppjieba/deps -lprotobuf -I ./proto -o $@
forward.o:./proto/forward.pb.cc
	g++ -c $^ -o $@
inverted.o:./proto/inverted.pb.cc
	g++ -c $^ -o $@
libindex.a: set_inverted_index.o forward.o inverted.o
	ar rc $@ $^

