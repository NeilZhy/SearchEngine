httpd:main.cc httpd.cc
	g++ -g $^ -lpthread -lhtmlcxx -lctemplate -lprotobuf -std=c++11 -lboost_regex  -L../api -lindex -I /usr/local/src/cppjieba/include -I /usr/local/src/cppjieba/deps -o $@
.PHONY:clean
clean:
	rm -f httpd main.o httpd.o
