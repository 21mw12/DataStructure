#include "BinaryToForest.h"

/**
 * @brief 创建一个二叉树结点
 * 
 * @param data :数据
 * @return BinaryTree* :二叉树结点
 */
BinaryTree* CreateBTreeNode(char data) {   
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
BinaryTree* CreateBTree(Tree* tree, int i = 0) {
    // 不能是叶子结点
    if (i != -1) {
        // 初始化该结点
        BinaryTree* root = CreateBTreeNode(tree->nodes[i].data);
        // 遍历数结构
        for (int j = i; j < tree->count; j++) {
            // 找到是该结点的孩子结点
            if (tree->nodes[j].parent == i) {
                //cout << root->data;
                if (tree->nodes[tree->nodes[j].parent].firstchild == j) {
                    // 如果这个节点是左孩子结点
                    if (root->Lchild == NULL) {
                        //cout << "L" << tree->nodes[j].data << endl;
                        root->Lchild = CreateBTree(tree, j);
                    }
                } else {
                    // 如果这个节点是右孩子结点
                    if (root->Rchild == NULL) {
                        //cout << "R" << tree->nodes[j].data << endl;
                        root->Rchild = CreateBTree(tree, j);
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
        Btree[i] = CreateBTree(tree[i], 0);
    }
    for (int i = 0; i < count-1; i++) {
        Btree[i]->Rchild = Btree[i+1];
    }
    return Btree[0];
}