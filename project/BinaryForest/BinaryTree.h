#include<iostream>
using namespace std;

int nodeNumber = 0;

/* ������ */
typedef struct BinaryTree {
    char data;
    BinaryTree *Lchild, *Rchild;
}BinaryTree;

/* ����������غ��� */
int GetNodeNumber(BinaryTree* root);
void ShowTreeMLR(BinaryTree* root);
void ShowTreeLMR(BinaryTree* root);
void ShowTreeLRM(BinaryTree* root);