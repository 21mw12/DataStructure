#include "BinaryTree.h"

/**
 * @brief ������Ľ����
 * 
 * @param root :���ĸ����
 * @return int :�����
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
 * @brief �������
 * 
 * @param root :���ڵ�
 */
void ShowTreeMLR(BinaryTree* root) {
    if (root != NULL) {
        cout << root->data;
        ShowTreeMLR(root->Lchild);
        ShowTreeMLR(root->Rchild);
    }
}

/**
 * @brief �������
 * 
 * @param root :���ڵ�
 */
void ShowTreeLMR(BinaryTree* root) {
    if (root != NULL) {
        ShowTreeLMR(root->Lchild);
        cout << root->data;
        ShowTreeLMR(root->Rchild);
    }
}

/**
 * @brief �������
 * 
 * @param root :���ڵ�
 */
void ShowTreeLRM(BinaryTree* root) {
    if (root != NULL) {
        ShowTreeLRM(root->Lchild);
        ShowTreeLRM(root->Rchild);
        cout << root->data;
    }
}