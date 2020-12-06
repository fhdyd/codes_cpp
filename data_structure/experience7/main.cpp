#include<iostream>
#include"function.cpp"

using namespace std;

int main()
{
    char a[]={'a','b','c','d','e'};
    unsigned int b[]={1,2,3,4,5};
    HuffmanTree HT;
    HuffmanCode HC;
    HuffmanCoding(HT,HC,b,5);
    for(int j=1;j<=5;j++)
    {
        cout<<a[j-1]<<" "<<HC[j]<<endl;
    }
    return 0;
}