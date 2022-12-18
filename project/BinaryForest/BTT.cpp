#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX_TREE_SIZE 20 // ?????????????
int nodeNumber = 0;
/* ???? */
typedef struct PTNode{
	char data;
	int parent;
    int firstchild;
}TreeNode;
/* ? */
typedef struct{
	TreeNode nodes[MAX_TREE_SIZE];
    int count = 0;
}Tree;
/* ??? */
typedef struct BinaryTree {
    char data;
    BinaryTree *Lchild, *Rchild;
}BinaryTree;

/* ?????? */
TreeNode* CreateTreeNode(char nodeData, int parentData);
Tree* CreatTree(int number,char dataInfo[], int parentInfo[]);
void SortTreeNode(int number, char* dataInfo, int* parentInfo);
int getTreeDeep(Tree* tree);
int numlen(int num);
void PrintLayout(int data, int length);
void PrintLayout(char data, int length);
void ShowTree(Tree* tree);
/* ?????????? */
void TreeToBTree(Tree* tree);
BinaryTree* ForestToBinaryTree(Tree* tree[], int count);
/* ???????? */
BinaryTree* CreateTreeNode(char data);
BinaryTree* CreateTree(Tree* tree, int i);
int GetNodeNumber(BinaryTree* root);
void ShowTreeMLR(BinaryTree* root);
void ShowTreeLMR(BinaryTree* root);
void ShowTreeLRM(BinaryTree* root);

int main() {
    Tree* tree[4];
    int TREECOUNT = 3;
    int size;
    // ??????
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
    cout << "二叉树的总结点个数：";
    cout << GetNodeNumber(root);
    cout << endl;
    cout << "二叉树的前序遍历结果：";
    ShowTreeMLR(root);
    cout << endl;
    cout << "二叉树的中序遍历结果：";
    ShowTreeLMR(root);
    return 0;
}

/**
 * @brief ?????????
 * 
 * @param nodeData :????
 * @param parentData :?????
 * @return TreeNode* :???
 */
TreeNode* CreateTreeNode(char nodeData, int parentData) {
    TreeNode* newNode = new TreeNode;
    newNode->data = nodeData;
    newNode->parent = parentData;
    newNode->firstchild = -1;
    return newNode;
}

/**
 * @brief ??????????
 * 
 * @param number :????
 * @param dataInfo :??????
 * @param parentInfo :?????
 * @return Tree* :???
 */
Tree* CreatTree(int number,char dataInfo[], int parentInfo[]) {
    int farther = -1;
    Tree* tree = new Tree;
    // ??????
    SortTreeNode(number, dataInfo, parentInfo);
    // ??????????
    for (int i = 0; i < number; i++) {
        // ??????????????
        tree->nodes[i] = *CreateTreeNode(dataInfo[i], parentInfo[i]);
        // ?????????????????????? 
        if (farther != parentInfo[i]) {
            farther = parentInfo[i];
            tree->nodes[farther].firstchild = tree->count;
        }
        tree->count++;
    }
    return tree;
}

/**
 * @brief ????????????
 * 
 * @param num :??????
 * @return int :????
 */
int numlen(int num) {
    int len = 0;
    // ????0?????1
    if (num == 0) return 1;
    // ???????????1???????
    if (num < 0) {
        len++;
        num = abs(num);
    }
    // ???????
    for(; num > 0; ++len)
        num /= 10;
    return len;
}

/**
 * @brief ????
 * 
 * @param data :??????
 * @param length :??????????
 */
void PrintLayout(int data, int length) {
    int i;
    cout<< "| " << data;
    for (i = 0; i < length - numlen(data); i++) {
        cout<< ' ';
    }
}
void PrintLayout(char data, int length) {
    int i;
    cout<< "| " << data;
    for (i = 0; i < length - strlen(&data); i++) {
        cout<< ' ';
    }
}

/**
 * @brief ?????????????????????
 * 
 * @param tree :???
 */
void ShowTree(Tree* tree) {
    int i, j;
    cout << "?????:" << endl;
    cout << "==============================" << endl;
    cout << "|index| data|parent|fistchild|" << endl;
    for (i = 0; i < tree->count; i++) {
        PrintLayout(i, 4);
        PrintLayout(tree->nodes[i].data, 4);
        PrintLayout(tree->nodes[i].parent, 5);
        PrintLayout(tree->nodes[i].firstchild, 8);
        cout << "|" << endl;
    }
    cout << "==============================" << endl;
}

/**
 * @brief ????????????????????
 * 
 * @param number :????
 * @param dataInfo :??????
 * @param parentInfo :?????
 */
void SortTreeNode(int number, char* dataInfo, int* parentInfo) {
    int i, j;
    int intTemp;
    char charTemp;
    // ????
    for (i = 0; i < number; i++) {
        for(j = i; j < number - i - 1; j++){
            if (parentInfo[j] > parentInfo[j+1]) {
                charTemp = dataInfo[j + 1];
                dataInfo[j + 1] = dataInfo[j];
                dataInfo[j] = charTemp;

                intTemp = parentInfo[j + 1];
                parentInfo[j + 1] = parentInfo[j];
                parentInfo[j] = intTemp;
            }
        }
    }
}

/**
 * @brief ??????
 * 
 * @param tree :???
 * @return int :??
 */
int getTreeDeep(Tree* tree) {
    int i;
    int deep = 1;
    int tempDeep = 1;
    // ???????
    for (i = 0; i < tree->count; i++) {
        // ????????
        if (tree->nodes[i].firstchild == -1) {
            // ???????????
            int perantIndex = tree->nodes[i].parent;
            // ?????????????????????????
            while (perantIndex != -1) {
                perantIndex = tree->nodes[perantIndex].parent;
                tempDeep++;
            }
        }
        // ??????????????????
        if (tempDeep > deep) {
            deep = tempDeep;
        }
        tempDeep = 1;
    }
    return deep;
}

/**
 * @brief ????????????
 * 
 * @param tree :???
 */
void TreeToBTree(Tree* tree) {
    int i;
    int index = 0;
    bool change = false;
    int nodeCount;
    for (i = 1; i < tree->count; i++) {
        if (index == tree->nodes[i].parent) {
            // ????????????????????????????????
            if (change) {
                // ?????????????????????????
                tree->nodes[i].parent = i-1;
                // ?????????????????????????????
                if (tree->nodes[i-1].firstchild == -1) {
                    tree->nodes[i-1].firstchild = i;
                }
            } else {
                change = true;
            }
        } else {
            index = tree->nodes[i].parent;
        }
    }
}

/**
 * @brief ?????????
 * 
 * @param data :??
 * @return BinaryTree* :?????
 */
BinaryTree* CreateTreeNode(char data) {   
    BinaryTree* tree = new BinaryTree;
    tree->data = data;
    tree->Lchild = NULL;
    tree->Rchild = NULL;
    return tree;
}

/**
 * @brief ???
 * 
 * @param data :????
 * @param length :???????
 * @param i :????????
 * @return BinaryTree* :?????
 */
BinaryTree* CreateTree(Tree* tree, int i = 0) {
    // ???????
    if (i != -1) {
        // ??????
        BinaryTree* root = CreateTreeNode(tree->nodes[i].data);
        // ?????
        for (int j = i; j < tree->count; j++) {
            // ???????????
            if (tree->nodes[j].parent == i) {
                //cout << root->data;
                if (tree->nodes[tree->nodes[j].parent].firstchild == j) {
                    // ????????????
                    if (root->Lchild == NULL) {
                        //cout << "L" << tree->nodes[j].data << endl;
                        root->Lchild = CreateTree(tree, j);
                    }
                } else {
                    // ????????????
                    if (root->Rchild == NULL) {
                        //cout << "R" << tree->nodes[j].data << endl;
                        root->Rchild = CreateTree(tree, j);
                    }
                }
            }
        }
        return root;
    } else {
        return NULL;
    }
}

/**
 * @brief ?????
 * 
 * @param tree :???
 */
BinaryTree* ForestToBinaryTree(Tree* tree[], int count) {
    BinaryTree* Btree[count];
    for (int i = 0; i < count; i++) {
        //ShowTree(tree[i]);
        TreeToBTree(tree[i]);
        //ShowTree(tree[i]);
        Btree[i] = CreateTree(tree[i]);
    }
    for (int i = 0; i < count-1; i++) {
        Btree[i]->Rchild = Btree[i+1];
    }
    return Btree[0];
}

/**
 * @brief ???????
 * 
 * @param root :?????
 * @return int :???
 */
int GetNodeNumber(BinaryTree* root) {
    if (root != NULL) {
        nodeNumber++;
        GetNodeNumber(root->Lchild);
        GetNodeNumber(root->Rchild);
    }
    return nodeNumber;
}

/**
 * @brief ????
 * 
 * @param root :???
 */
void ShowTreeMLR(BinaryTree* root) {
    if (root != NULL) {
        cout << root->data;
        ShowTreeMLR(root->Lchild);
        ShowTreeMLR(root->Rchild);
    }
}

/**
 * @brief ????
 * 
 * @param root :???
 */
void ShowTreeLMR(BinaryTree* root) {
    if (root != NULL) {
        ShowTreeLMR(root->Lchild);
        cout << root->data;
        ShowTreeLMR(root->Rchild);
    }
}

/**
 * @brief ????
 * 
 * @param root :???
 */
void ShowTreeLRM(BinaryTree* root) {
    if (root != NULL) {
        ShowTreeLRM(root->Lchild);
        ShowTreeLRM(root->Rchild);
        cout << root->data;
    }
}