#include "Forest.h"

/**
 * @brief ��ʼ������һ�����
 * 
 * @param nodeData :�������
 * @param parentData :���ڵ�����
 * @return TreeNode* :���ṹ
 */
TreeNode* CreateTreeNode(char nodeData, int parentData) {
    TreeNode* newNode = new TreeNode;
    newNode->data = nodeData;
    newNode->parent = parentData;
    newNode->firstchild = -1;
    return newNode;
}

/**
 * @brief ��������˫�ױ�ʾ����
 * 
 * @param number :������
 * @param dataInfo :�����������
 * @param parentInfo :���������
 * @return Tree* :���ṹ
 */
Tree* CreatTree(int number,char dataInfo[], int parentInfo[]) {
    int farther = -1;
    Tree* tree = new Tree;
    // �Ƚ��������
    SortTreeNode(number, dataInfo, parentInfo);
    // �������н��������Ϣ
    for (int i = 0; i < number; i++) {
        // ����һ�����Ľ�㣬������¼��
        tree->nodes[i] = *CreateTreeNode(dataInfo[i], parentInfo[i]);
        // ����һ�γ��ֵ��ӽ���Ϊ���ڵ�ĵ�һ���ӽ�� 
        if (farther != parentInfo[i]) {
            farther = parentInfo[i];
            tree->nodes[farther].firstchild = tree->count;
        }
        tree->count++;
    }
    return tree;
}

/**
 * @brief �������ĳ��ȣ��������ţ�
 * 
 * @param num :��Ҫ�������
 * @return int :���ĳ���
 */
int numlen(int num) {
    int len = 0;
    // �����Ϊ0��ֱ�ӷ���1
    if (num == 0) return 1;
    // �����Ϊ�������򳤶ȼ�1�Ҷ���ȡ����ֵ
    if (num < 0) {
        len++;
        num = abs(num);
    }
    // ��������ĳ���
    for(; num > 0; ++len)
        num /= 10;
    return len;
}

/**
 * @brief ���ģ��
 * 
 * @param data :Ҫ���������
 * @param length :����������һ��վ����
 */
void PrintLayout(int data, int length) {
    int i;
    cout<< "| " << data;
    for (i = 0; i < length - numlen(data); i++) {
        cout<< ' ';
    }
}
void PrintLayout(char data, int length) {
    int i;
    cout<< "| " << data;
    for (i = 0; i < length - strlen(&data); i++) {
        cout<< ' ';
    }
}

/**
 * @brief ��ʾ�����������ݰ����±꣬���ݣ����ڵ�λ��
 * 
 * @param tree :���ṹ
 */
void ShowTree(Tree* tree) {
    int i, j;
    cout << "��������Ϊ:" << endl;
    cout << "==============================" << endl;
    cout << "|index| data|parent|fistchild|" << endl;
    for (i = 0; i < tree->count; i++) {
        PrintLayout(i, 4);
        PrintLayout(tree->nodes[i].data, 4);
        PrintLayout(tree->nodes[i].parent, 5);
        PrintLayout(tree->nodes[i].firstchild, 8);
        cout << "|" << endl;
    }
    cout << "==============================" << endl;
}

/**
 * @brief ��������Ϣ�͸������Ϣ�Ը��ڵ���˳������
 * 
 * @param number :������
 * @param dataInfo :�����������
 * @param parentInfo :���������
 */
void SortTreeNode(int number, char* dataInfo, int* parentInfo) {
    int i, j;
    int intTemp;
    char charTemp;
    // ð������
    for (i = 0; i < number; i++) {
        for(j = i; j < number - i - 1; j++){
            if (parentInfo[j] > parentInfo[j+1]) {
                charTemp = dataInfo[j + 1];
                dataInfo[j + 1] = dataInfo[j];
                dataInfo[j] = charTemp;

                intTemp = parentInfo[j + 1];
                parentInfo[j + 1] = parentInfo[j];
                parentInfo[j] = intTemp;
            }
        }
    }
}

/**
 * @brief ����������
 * 
 * @param tree :���ṹ
 * @return int :���
 */
int getTreeDeep(Tree* tree) {
    int i;
    int deep = 1;
    int tempDeep = 1;
    // �����������ṹ
    for (i = 0; i < tree->count; i++) {
        // �ҵ�����Ҷ�ӽ��
        if (tree->nodes[i].firstchild == -1) {
            // ��Ҷ�ӽ��ĸ��ڵ����
            int perantIndex = tree->nodes[i].parent;
            // ����Ҷ�ӽ��һֱ������㣬���������Ҷ�ӽ������
            while (perantIndex != -1) {
                perantIndex = tree->nodes[perantIndex].parent;
                tempDeep++;
            }
        }
        // ����¼����֮ǰ�����Ҫ������¸�ֵ
        if (tempDeep > deep) {
            deep = tempDeep;
        }
        tempDeep = 1;
    }
    return deep;
}