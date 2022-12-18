#include<iostream>
#include "BinaryTree.h"
#include "Forest.h"
using namespace std;


/* 树转二叉树的相关函数 */
void TreeToBTree(Tree* tree);
BinaryTree* ForestToBinaryTree(Tree* tree[], int count);
BinaryTree* CreateBTreeNode(char data);
BinaryTree* CreateBTree(Tree* tree, int i);