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
 * @brief ��ʼ������˫�ױ�ʾ����
 * 
 * @param rootData :���ĸ���������
 * @return PTree* :���ĸ����
 */
PTree* InitPTree(int rootData) {
    PTree* root = new PTree;
    root->nodes[0].data = rootData;
    root->nodes[0].parent = -1;
    root->local = 0;
    return root;
}

/**
 * @brief ��ʾ�����������ݰ����±꣬���ݣ����ڵ�λ��
 * 
 * @param root :���ĸ����
 */
void ShowPTree(PTree* root) {
    int i, j;
    int size;
    cout << "��������Ϊ:" << endl;
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
 * @brief �������������Ľ��
 * 
 * @param root :���ĸ����
 * @param number :�����������
 * @param content[][2] :��������ݵĶ�ά����
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
 * @brief ɾ�����Ľ��
 * 
 * @param root :���ĸ����
 * @param delNode :Ҫɾ���Ľ���±�
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
 * @brief ���Ľ���������Ϣ
 * 
 * @param root :���ĸ����
 * @param UpdNode :Ҫ���ĵĽ���±�
 * @param NewData :���ĺ�Ľ������
 */
void UpdPTreeNode(PTree* root, int UpdNode, int NewData) {
    root->nodes[UpdNode].data = NewData;
}