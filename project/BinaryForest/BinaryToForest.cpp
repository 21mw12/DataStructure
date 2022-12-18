#include "BinaryToForest.h"

/**
 * @brief ����һ�����������
 * 
 * @param data :����
 * @return BinaryTree* :���������
 */
BinaryTree* CreateBTreeNode(char data) {   
    BinaryTree* tree = new BinaryTree;
    tree->data = data;
    tree->Lchild = NULL;
    tree->Rchild = NULL;
    return tree;
}

/**
 * @brief ������
 * 
 * @param data :��������
 * @param length :��������ĳ���
 * @param i :��ǰ�ڵ�ֵ���±�
 * @return BinaryTree* :���ĸ��ڵ�
 */
BinaryTree* CreateBTree(Tree* tree, int i = 0) {
    // ������Ҷ�ӽ��
    if (i != -1) {
        // ��ʼ���ý��
        BinaryTree* root = CreateBTreeNode(tree->nodes[i].data);
        // �������ṹ
        for (int j = i; j < tree->count; j++) {
            // �ҵ��Ǹý��ĺ��ӽ��
            if (tree->nodes[j].parent == i) {
                //cout << root->data;
                if (tree->nodes[tree->nodes[j].parent].firstchild == j) {
                    // �������ڵ������ӽ��
                    if (root->Lchild == NULL) {
                        //cout << "L" << tree->nodes[j].data << endl;
                        root->Lchild = CreateBTree(tree, j);
                    }
                } else {
                    // �������ڵ����Һ��ӽ��
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
 * @brief ��ת��������˫�ױ�ʾ����
 * 
 * @param tree :���ṹ
 */
void TreeToBTree(Tree* tree) {
    int i;
    int index = 0;
    bool change = false;
    int nodeCount;
    for (i = 1; i < tree->count; i++) {
        if (index == tree->nodes[i].parent) {
            // ���ĵڶ��μ��Ժ������ͬ�ĸ����Ľ����Ϣ�������˵�һ���ӽ�㣩
            if (change) {
                // ���õ�ĸ����λ��ָ����һ����㣬����ߵ��ֵܽ��
                tree->nodes[i].parent = i-1;
                // ����������Ҷ�ӽ�㣬�ͽ���һ�����ĵ�һ���ӽ��ָ������
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
 * @brief ��ת������
 * 
 * @param tree :���ṹ
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