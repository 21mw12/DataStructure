#include<iostream>
#include<math.h>
using namespace std;

typedef int DataType;
typedef struct BinaryTree {
    DataType data;
    BinaryTree *Lchild, *Rchild;
}BinaryTree;

BinaryTree* CreateTreeNode(DataType data);
BinaryTree* AddLchild(BinaryTree* tree, DataType data);
BinaryTree* AddRchild(BinaryTree* tree, DataType data);
BinaryTree* CreateTree(char data[], int length, int i = 0);
void ShowTreeMLR(BinaryTree* root);
void ShowTreeLMR(BinaryTree* root);
void ShowTreeLRM(BinaryTree* root);
void ShowTreeOrder(BinaryTree* root, int length);
int GetLeafNumber(BinaryTree* root);
int GetNodeNumber(BinaryTree* root);
int GetTreeDepth(BinaryTree* root);

void temp(BinaryTree* root);

int main() {
    char data[] = {'1', '2', '3', ' ', ' ', '6', '7'};
    int size = sizeof(data) / sizeof(data[0]);
    BinaryTree* tree = CreateTree(data, size);
    
    cout << "����" << GetNodeNumber(tree) << "�����" << endl;
    cout << "����" << GetLeafNumber(tree) << "��Ҷ�ӽ��" << endl;
    cout << "���ṹ��" << GetLeafNumber(tree) << "��" << endl;

    cout << "���������";
    ShowTreeMLR(tree);
    cout << endl;

    cout << "���������";
    ShowTreeLMR(tree);
    cout << endl;

    cout << "�������Ϊ��";
    ShowTreeLRM(tree);
    cout << endl;
    
    cout << "�������Ϊ��";
    ShowTreeOrder(tree, size);
    cout << endl;
    return 0;
}

/**
 * @brief ����һ�����������
 * 
 * @param data :����
 * @return BinaryTree* :���������
 */
BinaryTree* CreateTreeNode(DataType data) {
    BinaryTree* tree = new BinaryTree;
    tree->data = data;
    tree->Lchild = NULL;
    tree->Rchild = NULL;
    return tree;
}

/**
 * @brief Ϊ������һ������
 * 
 * @param data :����
 * @return BinaryTree* :������
 */
BinaryTree* AddLchild(BinaryTree* tree, DataType data) {
    BinaryTree* newNode = new BinaryTree;
    newNode->data = data;
    tree->Lchild = newNode;
    newNode->Lchild = NULL;
    newNode->Rchild = NULL;
    return tree;
}

/**
 * @brief Ϊ������һ���Һ���
 * 
 * @param data :����
 * @return BinaryTree* :������
 */
BinaryTree* AddRchild(BinaryTree* tree, DataType data) {
    BinaryTree* newNode = new BinaryTree;
    newNode->data = data;
    tree->Rchild = newNode;
    newNode->Lchild = NULL;
    newNode->Rchild = NULL;
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
BinaryTree* CreateTree(char data[], int length, int i) {
    //�����ڵ�Ϊ�գ�������
    if (data[i] == ' ') return NULL;

	BinaryTree* root = new BinaryTree;
	root->data = data[i] - 48;
	root->Lchild = NULL;
	root->Rchild = NULL;

	int Lnode = 2 * i + 1;//�ø��ڵ�ȷ����ڵ��λ��
	int Rnode = 2 * i + 2;//�ø��ڵ�ȷ���ҽڵ��λ��

	if (Lnode > length - 1) {
        root->Lchild = NULL;
    } else {
        root->Lchild = CreateTree(data, length, Lnode);
    }

	if (Rnode > length - 1) {
        root->Rchild = NULL;
    } else {
        root->Rchild = CreateTree(data, length, Rnode);
    }

	return root;
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

/**
 * @brief �������α������
 * 
 * @param root :���ĸ����
 * @param length :���ĳ���
 */
void ShowTreeOrder(BinaryTree* root, int length) {
    int front, rear;
    BinaryTree* p, * q[10];
    p = root;
    if (p != NULL) {
        front = 1;
        q[front] = p;
        rear = 2;
    }
    while (front != rear) {
        p = q[front];
        cout << p->data;
        if (p->Lchild != NULL) {
            q[rear] = p->Lchild;
            rear = (rear + 1) % length;
        }
        if (p->Rchild != NULL) {
            q[rear] = p->Rchild;
            rear = (rear + 1) % length;
            cout << "|";
        }
        front = (front + 1) % length;
    }
}

/**
 * @brief �������Ҷ����
 * 
 * @param root :���ĸ����
 * @return int :Ҷ�ӽ����
 */
int GetLeafNumber(BinaryTree* root) {
    static int  number = 0;
    if (root != NULL) {
        if (root->Lchild == NULL && root->Rchild == NULL) {
            number++;
        } else {
            GetLeafNumber(root->Lchild);
            GetLeafNumber(root->Rchild);
        }
    }
    return number;
}

/**
 * @brief ������Ľ����
 * 
 * @param root :���ĸ����
 * @return int :�����
 */
int GetNodeNumber(BinaryTree* root) {
    static int  number = 0;
    if (root != NULL) {
        number++;
        GetNodeNumber(root->Lchild);
        GetNodeNumber(root->Rchild);
    }
    return number;
}

/**
 * @brief ����������
 * 
 * @param root :���ĸ����
 * @return int :���
 */
int GetTreeDepth(BinaryTree* root) {
    int Ldepth, Rdepth;
    if (root == NULL) {
        return 0;
    } else {
        Ldepth = GetTreeDepth(root->Lchild);
        Rdepth = GetTreeDepth(root->Rchild);
        if (Ldepth > Rdepth) {
            return Ldepth + 1;
        } else {
            return Rdepth + 1;
        }
    }
}
