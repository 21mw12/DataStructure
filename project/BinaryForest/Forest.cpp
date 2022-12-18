#include "Forest.h"

/**
 * @brief 初始化树的一个结点
 * 
 * @param nodeData :结点数据
 * @param parentData :父节点数据
 * @return TreeNode* :树结构
 */
TreeNode* CreateTreeNode(char nodeData, int parentData) {
    TreeNode* newNode = new TreeNode;
    newNode->data = nodeData;
    newNode->parent = parentData;
    newNode->firstchild = -1;
    return newNode;
}

/**
 * @brief 创建树（双亲表示法）
 * 
 * @param number :结点个数
 * @param dataInfo :结点数据数组
 * @param parentInfo :父结点数组
 * @return Tree* :树结构
 */
Tree* CreatTree(int number,char dataInfo[], int parentInfo[]) {
    int farther = -1;
    Tree* tree = new Tree;
    // 先将结点排序
    SortTreeNode(number, dataInfo, parentInfo);
    // 遍历所有结点数组信息
    for (int i = 0; i < number; i++) {
        // 创建一个树的结点，将输入录入
        tree->nodes[i] = *CreateTreeNode(dataInfo[i], parentInfo[i]);
        // 将第一次出现的子结点记为父节点的第一孩子结点 
        if (farther != parentInfo[i]) {
            farther = parentInfo[i];
            tree->nodes[farther].firstchild = tree->count;
        }
        tree->count++;
    }
    return tree;
}

/**
 * @brief 计算数的长度（包括负号）
 * 
 * @param num :需要计算的数
 * @return int :数的长度
 */
int numlen(int num) {
    int len = 0;
    // 如果数为0则直接返回1
    if (num == 0) return 1;
    // 如果数为负数，则长度加1且对数取绝对值
    if (num < 0) {
        len++;
        num = abs(num);
    }
    // 计算出数的长度
    for(; num > 0; ++len)
        num /= 10;
    return len;
}

/**
 * @brief 输出模板
 * 
 * @param data :要输出的数据
 * @param length :包括数在内一共站几格
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
 * @brief 显示树的整个内容包含下标，数据，父节点位置
 * 
 * @param tree :树结构
 */
void ShowTree(Tree* tree) {
    int i, j;
    cout << "树的内容为:" << endl;
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
 * @brief 将数据信息和父结点信息以父节点升顺序排列
 * 
 * @param number :结点个数
 * @param dataInfo :结点数据数组
 * @param parentInfo :父结点数组
 */
void SortTreeNode(int number, char* dataInfo, int* parentInfo) {
    int i, j;
    int intTemp;
    char charTemp;
    // 冒泡排序
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
 * @brief 获得数的深度
 * 
 * @param tree :树结构
 * @return int :深度
 */
int getTreeDeep(Tree* tree) {
    int i;
    int deep = 1;
    int tempDeep = 1;
    // 遍历整个树结构
    for (i = 0; i < tree->count; i++) {
        // 找到所有叶子结点
        if (tree->nodes[i].firstchild == -1) {
            // 将叶子结点的父节点提出
            int perantIndex = tree->nodes[i].parent;
            // 沿着叶子结点一直到根结点，并计算这个叶子结点的深度
            while (perantIndex != -1) {
                perantIndex = tree->nodes[perantIndex].parent;
                tempDeep++;
            }
        }
        // 如果新计算比之前计算的要高则从新赋值
        if (tempDeep > deep) {
            deep = tempDeep;
        }
        tempDeep = 1;
    }
    return deep;
}