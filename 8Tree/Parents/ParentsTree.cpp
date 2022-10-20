#include <iostream>
using namespace std; 

#define MAX_TREE_SIZE 20
typedef struct PTNode{
	int data;
	int parent;
    // int firstchild;
    // int rightlib;
}PTNode;
typedef struct{
	PTNode nodes[MAX_TREE_SIZE];
    int local;
}PTree;

PTree* InitPTree(int rootData);
void ShowPTree(PTree* root);
void InsPTreeNode(PTree* root, int number, int content[][2]);
void DelPTreeNode(PTree* root, int delNode);
void UpdPTreeNode(PTree* root, int UpdNode, int NewData);

int main() {
    int info[5][2] = {
        {0,1},{1,1},{2,1},{3,1},{4,1}
    };
    int size = sizeof(info) / sizeof(info[0]);
    PTree* root = InitPTree(0);
    InsPTreeNode(root, size, info);
    ShowPTree(root);
    // DelPTreeNode(root, 1);
    // //UpdPTreeNode(root);
    // ShowPTree(root);
    return 0;
}

/**
 * @brief 初始化树（双亲表示法）
 * 
 * @param rootData :树的根结点的数据
 * @return PTree* :树的根结点
 */
PTree* InitPTree(int rootData) {
    PTree* root = new PTree;
    root->nodes[0].data = rootData;
    root->nodes[0].parent = -1;
    root->local = 0;
    return root;
}

/**
 * @brief 显示树的整个内容包含下标，数据，父节点位置
 * 
 * @param root :树的根结点
 */
void ShowPTree(PTree* root) {
    int i, j;
    int size;
    cout << "树的内容为:" << endl;
    cout << "--------------------" << endl;
    cout << "|index| data|parent|" << endl;
    for (i = 0; i <= root->local; i++) {
        cout << "| " << i;
        cout << "   | " << root->nodes[i].data;
        cout << "   | " << root->nodes[i].parent;
        cout << "   |" << endl;
    }
    cout << "--------------------" << endl;
}

/**
 * @brief 插入任意数量的结点
 * 
 * @param root :树的根结点
 * @param number :插入结点的数量
 * @param content[][2] :插入的内容的二维数组
 */
void InsPTreeNode(PTree* root, int number, int content[][2]) {
    int i;
    for (i = 0; i < number; i++) {
        root->local++;
        root->nodes[root->local].data = content[i][0];
        root->nodes[root->local].parent = content[i][1];
    }
}

/**
 * @brief 删除树的结点
 * 
 * @param root :树的根结点
 * @param delNode :要删除的结点下标
 */
void DelPTreeNode(PTree* root, int delNode) {
    int i;
    int temp;
    for (i = delNode; i < root->local; i++) {
        temp = root->nodes[i].data;
        root->nodes[i].data = root->nodes[i+1].data;
        temp = root->nodes[i].parent;
        root->nodes[i].parent = root->nodes[i+1].parent;
    }
    root->local--;
    for (i = delNode; i <= root->local; i++) {
        if (root->nodes[i].parent == delNode) {
            DelPTreeNode(root, i);
        }
    }
}

/**
 * @brief 更改结点的数据信息
 * 
 * @param root :树的根结点
 * @param UpdNode :要更改的结点下标
 * @param NewData :更改后的结点数据
 */
void UpdPTreeNode(PTree* root, int UpdNode, int NewData) {
    root->nodes[UpdNode].data = NewData;
}