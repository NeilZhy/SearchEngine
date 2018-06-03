#include "../api/set_inverted_index.h"


int main()
{
    InvertedIndex index;
    index.make_url_to_vector("/root/git/SearchEngine/data/www.boost.org");
    index.forward_index();

    cout<<"请输入单词"<<endl;
    string word;
    cin>>word;
    index.get_docid(word);

    return 0;
}
