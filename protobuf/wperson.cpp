#include <iostream>  
#include<fstream>  
#include "person.pb.h"  

using namespace std;


void PromptForAddress(tutorial::Person*);

int main(int argc,char* argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    if( 2 != argc)
    {
        //必须指定电话本名称才能执行程序
        cerr<<"Usage" <<argv[0] << "ADDRESS_BOOK_FILE"<<endl;
        return -1;
    }
    tutorial::AddressBook address_book;

    fstream in("ADDRESS_BOOK_FILE",ios::binary |ios::in);
    if(!in)
    {
        cerr<<"open file ADDRESS_BOOK_FILE failed\n";
        return -1;
    }

    if(!address_book.ParseFromIstrem(&in))
    {
        cerr<<"Parse File ADDRESS_BOOK_FILE failed\n";
        return -1;
    }

    in.close();
}


