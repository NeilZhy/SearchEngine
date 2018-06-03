#include<stdlib.h>
#include<string>
#include<iostream>
#include<ctemplate/template.h>



int main(int argc,char** argv)
{
    ctemplate::TemplateDictionary dict(" ");
    dict.SetValue("NAME","John Smith");
    int winnings = rand()%100000;
    dict.SetIntValue("VALUE", winnings);
    dict.SetFormattedValue("TAXED_VALUE","%.2f", winnings *0.83);
    // For now, assume everyone lives in CA.
    // (Try running the program with a 0 here instead!)
    if(1) 
    {
        dict.ShowSection("IN_CA");
    }
    std::string output;
    ctemplate::ExpandTemplate("./example.html", ctemplate::DO_NOT_STRIP, &dict, &output);
    std::cout << output;
    return 0;
}
