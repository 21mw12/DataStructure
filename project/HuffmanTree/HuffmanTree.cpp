#include<iostream>
#include<math.h>
using namespace std;

typedef struct BinaryTree {
    int data;
    BinaryTree *Lchild, *Rchild;
}BinaryTree;

BinaryTree* CreateTreeNode(int data);
BinaryTree* CreateHuffmanTree(int data[], int size);
void ShowTreeMLR(BinaryTree* root);
void ShowTreeLMR(BinaryTree* root);
void ShowTreeLRM(BinaryTree* root);
void GetLeafNumber(BinaryTree* root, int number = 0);

int main() {
    int i;
    int data[] = {1, 5, 3, 2, 7};
    int size = sizeof(data) / sizeof(data[0]);
    BinaryTree* HuffmanTree = CreateHuffmanTree(data, size);
    //ShowTreeMLR(HuffmanTree);
    GetLeafNumber(HuffmanTree);
    cin >> i;
    return 0;
}

BinaryTree* CreateTreeNode(int data) {
    BinaryTree* tree = new BinaryTree;
    tree->data = data;
    tree->Lchild = NULL;
    tree->Rchild = NULL;
    return tree;
}

BinaryTree* CreateHuffmanTree(int data[], int size) {
    int i, j;
    BinaryTree* HuffmanNode[size];
    BinaryTree* temp = CreateTreeNode(-1);
    BinaryTree exchangeTemp;
    for (i = 0; i < size; i++) {
        HuffmanNode[i] = CreateTreeNode(data[i]);
    }

    while (size != 1) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < size - 1 - i; j++) {
                if (HuffmanNode[j]->data < HuffmanNode[j+1]->data) {
                    exchangeTemp = *HuffmanNode[j];
                    *HuffmanNode[j] = *HuffmanNode[j+1];
                    *HuffmanNode[j+1] = exchangeTemp;
                }
            }
        }
        temp = CreateTreeNode(HuffmanNode[size-1]->data + HuffmanNode[size-2]->data);
        temp->Lchild = HuffmanNode[size-1];
        temp->Rchild = HuffmanNode[size-2];
        HuffmanNode[size-2] = temp;
        size--;
    }
    return HuffmanNode[0];
}

void ShowTreeMLR(BinaryTree* root) {
    if (root != NULL) {
        cout << root->data;
        cout << '|';
        ShowTreeMLR(root->Lchild);
        ShowTreeMLR(root->Rchild);
    }
}

void ShowTreeLMR(BinaryTree* root) {
    if (root != NULL) {
        ShowTreeLMR(root->Lchild);
        cout << root->data;
        cout << '|';
        ShowTreeLMR(root->Rchild);
    }
}

void ShowTreeLRM(BinaryTree* root) {
    if (root != NULL) {
        ShowTreeLRM(root->Lchild);
        ShowTreeLRM(root->Rchild);
        cout << root->data;
        cout << '|';
    }
}

void GetLeafNumber(BinaryTree* root, int number) {
    if (root != NULL) {
        if (root->Lchild == NULL && root->Rchild == NULL) {
            cout << "数据" << root->data << "的哈夫曼码为：";
            cout << number << endl;
        } else {
            GetLeafNumber(root->Lchild, number*10 + 0);
            GetLeafNumber(root->Rchild, number*10 + 1);
        }
    }
}