#include "BinaryToForest.h"
#include "BinaryTree.h"
#include "Forest.h"

#define  TREECOUNT 3

int main() {
    Tree* tree[TREECOUNT];
    int size;
    // 数据，父节点
    char dataInfo1[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int parentInfo1[] = {-1, 0, 0, 1, 2, 2, 3, 3, 3, 4};
    size = sizeof(dataInfo1) / sizeof(dataInfo1[0]);
    tree[0] = CreatTree(size, dataInfo1, parentInfo1);
    //ShowTree(tree[0]);

    char dataInfo2[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    int parentInfo2[] = {-1, 0, 0, 0, 2, 2, 3, 3, 3, 4};
    size = sizeof(dataInfo2) / sizeof(dataInfo2[0]);
    tree[1] = CreatTree(size, dataInfo2, parentInfo2);
    //ShowTree(tree[1]);

    char dataInfo3[] = {'a', 'b'};
    int parentInfo3[] = {-1, 0};
    size = sizeof(dataInfo3) / sizeof(dataInfo3[0]);
    tree[2] = CreatTree(size, dataInfo3, parentInfo3);
    //ShowTree(tree[2]);
    
    BinaryTree* root = ForestToBinaryTree(tree, TREECOUNT);
    cout << GetNodeNumber(root);
    cout << endl;
    ShowTreeMLR(root);
    cout << endl;
    ShowTreeLMR(root);
    return 0;
}
