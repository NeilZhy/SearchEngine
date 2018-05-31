#include "pro.pb.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
int main(void)
{
    vector<lm::helloworld> hello_vector;  //这里定义了一个小的protobuf结构体数组，用来存放一个一个信息
    vector<lm::helloworld> hello_vector2;  //这里定义了一个小的protobuf结构体数组，用来存放一个一个信息
    lm::alldex index;   //这个是定义的包含小的结构体的一个大的结构体，因为使用小的结构体只能一次存放一个数据
                        //使用大的结构体包含小的结构体，这样子一个大的结构体就可以包含多个小的结构体了

    ofstream file("./log", ios::binary);
    lm::helloworld msg1;
    msg1.set_id(101);
    msg1.set_str("hello");
    lm::helloworld msg2;
    msg2.set_id(102);
    msg2.set_str("hello222222222222");


    hello_vector.push_back(msg1);
    hello_vector.push_back(msg2);

    hello_vector2.push_back(msg1);
    hello_vector2.push_back(msg2);

    auto* msg = index.add_index();

    for(auto& item : hello_vector)    //遍历小结构体数组
    {
        auto* im = msg->add_info();   //遍历过程中，每次add大结构体中的一个小结构体
        *im = item;                    //再将小结构加入到大结构体中就好了    最后进行序列化的时候，只需要序列化大结构体就好了
        msg->set_key(1);
    }




    string str;
    if (!index.SerializeToString(&str))    //序列化结构体的时候，只需要序列化大的就OK了
    {
        cerr << "Failed to write msg." << endl;
        return -1;
    }
    file.write(str.data(),str.size());
    file.close();
    return 0;
 }
