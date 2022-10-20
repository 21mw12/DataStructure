#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX_TREE_SIZE 20 // 一棵树最多可以拥有的结点数
int nodeNumber = 0;
/* 树的结点 */
typedef struct PTNode{
	char data;
	int parent;
    int firstchild;
}TreeNode;
/* 树 */
typedef struct{
	TreeNode nodes[MAX_TREE_SIZE];
    int count = 0;
}Tree;
/* 二叉树 */
typedef struct BinaryTree {
    char data;
    BinaryTree *Lchild, *Rchild;
}BinaryTree;

/* 树的相关函数 */
TreeNode* CreateTreeNode(char nodeData, int parentData);
Tree* CreatTree(int number,char dataInfo[], int parentInfo[]);
void SortTreeNode(int number, char* dataInfo, int* parentInfo);
int getTreeDeep(Tree* tree);
int numlen(int num);
void PrintLayout(int data, int length);
void PrintLayout(char data, int length);
void ShowTree(Tree* tree);
/* 树转二叉树的相关函数 */
void TreeToBTree(Tree* tree);
BinaryTree* ForestToBinaryTree(Tree* tree[], int count);
/* 二叉树的相关函数 */
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

/**
 * @brief 初始化树的一个结点
 * 
 * @param nodeData :结点数据
 * @param parentData :父节点数据
 * @return TreeNode* :树结构
 */
TreeNode* CreateTreeNode(char nodeData, int parentData) {
    TreeNode* newNode = new TreeNode;
    newNode->data = nodeData;
    newNode->parent = parentData;
    newNode->firstchild = -1;
    return newNode;
}

/**
 * @brief 创建树（双亲表示法）
 * 
 * @param number :结点个数
 * @param dataInfo :结点数据数组
 * @param parentInfo :父结点数组
 * @return Tree* :树结构
 */
Tree* CreatTree(int number,char dataInfo[], int parentInfo[]) {
    int farther = -1;
    Tree* tree = new Tree;
    // 先将结点排序
    SortTreeNode(number, dataInfo, parentInfo);
    // 遍历所有结点数组信息
    for (int i = 0; i < number; i++) {
        // 创建一个树的结点，将输入录入
        tree->nodes[i] = *CreateTreeNode(dataInfo[i], parentInfo[i]);
        // 将第一次出现的子结点记为父节点的第一孩子结点 
        if (farther != parentInfo[i]) {
            farther = parentInfo[i];
            tree->nodes[farther].firstchild = tree->count;
        }
        tree->count++;
    }
    return tree;
}

/**
 * @brief 计算数的长度（包括负号）
 * 
 * @param num :需要计算的数
 * @return int :数的长度
 */
int numlen(int num) {
    int len = 0;
    // 如果数为0则直接返回1
    if (num == 0) return 1;
    // 如果数为负数，则长度加1且对数取绝对值
    if (num < 0) {
        len++;
        num = abs(num);
    }
    // 计算出数的长度
    for(; num > 0; ++len)
        num /= 10;
    return len;
}

/**
 * @brief 输出模板
 * 
 * @param data :要输出的数据
 * @param length :包括数在内一共站几格
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
 * @brief 显示树的整个内容包含下标，数据，父节点位置
 * 
 * @param tree :树结构
 */
void ShowTree(Tree* tree) {
    int i, j;
    cout << "树的内容为:" << endl;
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
 * @brief 将数据信息和父结点信息以父节点升顺序排列
 * 
 * @param number :结点个数
 * @param dataInfo :结点数据数组
 * @param parentInfo :父结点数组
 */
void SortTreeNode(int number, char* dataInfo, int* parentInfo) {
    int i, j;
    int intTemp;
    char charTemp;
    // 冒泡排序
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
 * @brief 获得数的深度
 * 
 * @param tree :树结构
 * @return int :深度
 */
int getTreeDeep(Tree* tree) {
    int i;
    int deep = 1;
    int tempDeep = 1;
    // 遍历整个树结构
    for (i = 0; i < tree->count; i++) {
        // 找到所有叶子结点
        if (tree->nodes[i].firstchild == -1) {
            // 将叶子结点的父节点提出
            int perantIndex = tree->nodes[i].parent;
            // 沿着叶子结点一直到根结点，并计算这个叶子结点的深度
            while (perantIndex != -1) {
                perantIndex = tree->nodes[perantIndex].parent;
                tempDeep++;
            }
        }
        // 如果新计算比之前计算的要高则从新赋值
        if (tempDeep > deep) {
            deep = tempDeep;
        }
        tempDeep = 1;
    }
    return deep;
}

/**
 * @brief 树转二叉树（双亲表示法）
 * 
 * @param tree :树结构
 */
void TreeToBTree(Tree* tree) {
    int i;
    int index = 0;
    bool change = false;
    int nodeCount;
    for (i = 1; i < tree->count; i++) {
        if (index == tree->nodes[i].parent) {
            // 更改第二次及以后出现相同的父结点的结点信息（即除了第一孩子结点）
            if (change) {
                // 将该点的父结点位置指向上一个结点，即左边的兄弟结点
                tree->nodes[i].parent = i-1;
                // 如果这个点是叶子结点，就将上一个结点的第一孩子结点指向这里
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
 * @brief 创建一个二叉树结点
 * 
 * @param data :数据
 * @return BinaryTree* :二叉树结点
 */
BinaryTree* CreateTreeNode(char data) {   
    BinaryTree* tree = new BinaryTree;
    tree->data = data;
    tree->Lchild = NULL;
    tree->Rchild = NULL;
    return tree;
}

/**
 * @brief 创建树
 * 
 * @param data :数据数组
 * @param length :数据数组的长度
 * @param i :当前节点值的下标
 * @return BinaryTree* :树的根节点
 */
BinaryTree* CreateTree(Tree* tree, int i = 0) {
    // 不能是叶子结点
    if (i != -1) {
        // 初始化该结点
        BinaryTree* root = CreateTreeNode(tree->nodes[i].data);
        // 遍历数结构
        for (int j = i; j < tree->count; j++) {
            // 找到是该结点的孩子结点
            if (tree->nodes[j].parent == i) {
                //cout << root->data;
                if (tree->nodes[tree->nodes[j].parent].firstchild == j) {
                    // 如果这个节点是左孩子结点
                    if (root->Lchild == NULL) {
                        //cout << "L" << tree->nodes[j].data << endl;
                        root->Lchild = CreateTree(tree, j);
                    }
                } else {
                    // 如果这个节点是右孩子结点
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
 * @brief 树转二叉树
 * 
 * @param tree :树结构
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
 * @brief 获得树的结点数
 * 
 * @param root :树的根结点
 * @return int :结点数
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
 * @brief 先序遍历
 * 
 * @param root :根节点
 */
void ShowTreeMLR(BinaryTree* root) {
    if (root != NULL) {
        cout << root->data;
        ShowTreeMLR(root->Lchild);
        ShowTreeMLR(root->Rchild);
    }
}

/**
 * @brief 中序遍历
 * 
 * @param root :根节点
 */
void ShowTreeLMR(BinaryTree* root) {
    if (root != NULL) {
        ShowTreeLMR(root->Lchild);
        cout << root->data;
        ShowTreeLMR(root->Rchild);
    }
}

/**
 * @brief 后序遍历
 * 
 * @param root :根节点
 */
void ShowTreeLRM(BinaryTree* root) {
    if (root != NULL) {
        ShowTreeLRM(root->Lchild);
        ShowTreeLRM(root->Rchild);
        cout << root->data;
    }
}