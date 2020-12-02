typedef struct{
    unsigned int weight;
    unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

typedef char * *HuffmanCode;

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n);
void Select(HuffmanTree HT, int n, int &s1, int &s2);//在HT 1-n中选择parent为0且weight最小的两个下表记为s1,s2