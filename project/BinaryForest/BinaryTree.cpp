#include "BinaryTree.h"

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