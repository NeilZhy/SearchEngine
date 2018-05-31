index:set_inverted_index.cpp ./proto/forward.pb.cc ./proto/inverted.pb.cc
	g++ -g $^ -lprotobuf -std=c++11 -lboost_regex -I /usr/local/src/cppjieba/include -I /usr/local/src/cppjieba/deps -o $@
