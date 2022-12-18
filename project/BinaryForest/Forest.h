#include<iostream>
#include <cstring>
using namespace std;

#define MAX_TREE_SIZE 20 // 一棵树最多可以拥有的结点数
/* 树的结点 */
typedef struct TreeNode {
	char data;
	int parent;
    int firstchild;
}TreeNode;
/* 树 */
typedef struct Tree {
	TreeNode nodes[MAX_TREE_SIZE];
    int count = 0;
}Tree;

/* 树的相关函数 */
TreeNode* CreateTreeNode(char nodeData, int parentData);
Tree* CreatTree(int number,char dataInfo[], int parentInfo[]);
void SortTreeNode(int number, char* dataInfo, int* parentInfo);
int getTreeDeep(Tree* tree);
int numlen(int num);
void PrintLayout(int data, int length);
void PrintLayout(char data, int length);
void ShowTree(Tree* tree);