#include<iostream>
using namespace std;

int nodeNumber = 0;

/* 二叉树 */
typedef struct BinaryTree {
    char data;
    BinaryTree *Lchild, *Rchild;
}BinaryTree;

/* 二叉树的相关函数 */
int GetNodeNumber(BinaryTree* root);
void ShowTreeMLR(BinaryTree* root);
void ShowTreeLMR(BinaryTree* root);
void ShowTreeLRM(BinaryTree* root);