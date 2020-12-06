//main.cpp
#include"function.cpp"

int main(){
    W2[0] = {5, 'A'};
    W2[1] = {29, 'B'};
    W2[2] = {7, 'C'};
    W2[3] = {8, 'D'};
    W2[4] = {14, 'E'};
    W2[5] = {23, 'F'};
    W2[6] = {3, 'G'};
    W2[7] = {11, 'H'};
    HuffmanTree HT;
    HuffmanCode HC;
    Init(HT, W2, 8);
    CreateTable(HC, HT, 8);
    for(int i = 0; i <= 7; i++){
        cout << "字符为" << " " << W2[i].c << " " << "编码为" << " " << HC[i + 1] << endl; 
    }
    string S = "ACABHGF";
    string s = "";
    cout << "编码为：" << endl;
    for(int i = 0; i < S.length(); i++)
        for(int j = 0; j <= 7; j++){
            if(S[i] == W2[j].c){
                s = s + HC[j + 1];
                break;
            }
        }
    cout << s << endl;
    cout << "译码为：" << endl;
    decoding(s, HC, 8);
    cout << endl;
}