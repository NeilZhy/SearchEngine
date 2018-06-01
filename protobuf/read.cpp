#include "pro.pb.h"
#include <iostream>
#include <fstream>

using namespace std;

void ListMsg(const lm::helloworld &msg)
{
    cout<< msg.id()<<endl;
    cout<< msg.str()<<endl;
}

int main()
{
    lm::alldex index;

    string path = "./log";

    ifstream file(path.c_str(), ios::binary);
    string content;


    file.seekg(0, file.end);
    int length = file.tellg();
    file.seekg(0, file.beg);
    content.resize(length + 1);
    file.read(const_cast<char*>(content.data()), length);
    file.close();

    if(index.ParseFromString(content))
    {
        cerr<<"Failed to parse address bool"<<endl;
    }

    for(int i = 0;i<index.index_size();++i)
    {
        auto msg = index.index(i);
        for(int j = 0;j<msg.info_size();++j)
        {
            ListMsg(msg.info(j));
        }
    }

    return 0;
}
