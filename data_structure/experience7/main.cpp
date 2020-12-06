#include"function.cpp"


int main(){
    string s;
    int n=0,i;
    cin>>s;
    create_w(s);
    HuffmanTree HT;
    HuffmanCode HC;
    for(i=0;w[i].weight!=0;i++)
        n++;
    Init(HT,w,n);
    CreateTable(HC,HT,n);
    cout<<"编码表为："<<endl; 
    for(i=1;i<=n;i++)
        cout<<w[i-1].c<<":"<<HC[i]<<" ";
    cout<<endl;
    cout<<"编码为："<<endl;
    Encoding(s,n,HC); 
    cout<<S1<<endl; 
    cout<<"译码为："<<endl;
    Decoding(HT,HC,n);
    return 0;	
 } 