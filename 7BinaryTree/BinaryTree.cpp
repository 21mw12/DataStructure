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
    
    cout << "共有" << GetNodeNumber(tree) << "个结点" << endl;
    cout << "共有" << GetLeafNumber(tree) << "个叶子结点" << endl;
    cout << "树结构有" << GetLeafNumber(tree) << "层" << endl;

    cout << "先序遍历：";
    ShowTreeMLR(tree);
    cout << endl;

    cout << "中序遍历：";
    ShowTreeLMR(tree);
    cout << endl;

    cout << "后序遍历为：";
    ShowTreeLRM(tree);
    cout << endl;
    
    cout << "层序遍历为：";
    ShowTreeOrder(tree, size);
    cout << endl;
    return 0;
}

/**
 * @brief 创建一个二叉树结点
 * 
 * @param data :数据
 * @return BinaryTree* :二叉树结点
 */
BinaryTree* CreateTreeNode(DataType data) {
    BinaryTree* tree = new BinaryTree;
    tree->data = data;
    tree->Lchild = NULL;
    tree->Rchild = NULL;
    return tree;
}

/**
 * @brief 为结点添加一个左孩子
 * 
 * @param data :数据
 * @return BinaryTree* :二叉树
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
 * @brief 为结点添加一个右孩子
 * 
 * @param data :数据
 * @return BinaryTree* :二叉树
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
 * @brief 创建树
 * 
 * @param data :数据数组
 * @param length :数据数组的长度
 * @param i :当前节点值的下标
 * @return BinaryTree* :树的根节点
 */
BinaryTree* CreateTree(char data[], int length, int i) {
    //当根节点为空，即空树
    if (data[i] == ' ') return NULL;

	BinaryTree* root = new BinaryTree;
	root->data = data[i] - 48;
	root->Lchild = NULL;
	root->Rchild = NULL;

	int Lnode = 2 * i + 1;//用根节点确定左节点的位置
	int Rnode = 2 * i + 2;//用根节点确定右节点的位置

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

/**
 * @brief 按层依次遍历结点
 * 
 * @param root :数的根结点
 * @param length :数的长度
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
 * @brief 获得树的叶子数
 * 
 * @param root :树的根结点
 * @return int :叶子结点数
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
 * @brief 获得树的结点数
 * 
 * @param root :树的根结点
 * @return int :结点数
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
 * @brief 获得数的深度
 * 
 * @param root :树的根结点
 * @return int :深度
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
