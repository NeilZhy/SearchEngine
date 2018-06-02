.PHONY:all
all:read write
read:read.cpp pro.pb.cc
	g++ $^ -lprotobuf -std=c++11 -o $@
write:write.cpp pro.pb.cc
	g++ $^ -lprotobuf -std=c++11 -o $@
.PHONY:clean
clean:
	rm -f write
	rm -f read
