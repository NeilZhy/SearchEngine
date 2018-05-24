index:set_inverted_index.cpp
	g++ -g $^ -std=c++11 -lboost_regex -I /usr/local/src/cppjieba/include -I /usr/local/src/cppjieba/deps -o $@
