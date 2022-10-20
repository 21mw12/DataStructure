#include <iostream>
using namespace std; 

#define MAX_TREE_SIZE 20
typedef int DataType;
typedef struct CTNode{
	DataType data;
	CTNode* child;
}CTNode;
typedef struct{
	CTNode nodes[MAX_TREE_SIZE];
    int local = 0;
}CTree;

CTree* InitCTree(int rootData);

int main() {
    CTree* tree = InitCTree(0);
    
    return 0;
}

CTree* InitCTree(int rootData){
    CTree* root = new CTree;
    root->nodes[0].data = rootData;
    root->nodes[0].child = NULL;
    return root;
}


