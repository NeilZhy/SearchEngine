#include "./set_inverted_index.h"
#include<iostream>

using namespace std;

int main()
{
   InvertedIndex index;
   index.make_url_to_vector("/root/git/SearchEngine/data/www.boost.org");
   index.forward_index();
   return 0;
}

