#include<iostream>
using namespace std;

typedef int DataType;
typedef struct LinkedList {
    DataType data;
    LinkedList *next;    
}LinkedList;

LinkedList* CreateNewCode();
LinkedList* CreateList(DataType data[], int size);
void ShowList(LinkedList* L);
int SearchValue(LinkedList* L, DataType value);
LinkedList* Intersection(LinkedList* CalcuateL1, LinkedList* CalcuateL2);
LinkedList* Union(LinkedList* CalcuateL1, LinkedList* CalcuateL2);
LinkedList* Substract(LinkedList* CalcuateL1, LinkedList* CalcuateL2);
int isSubset(LinkedList* CalcuateL1, LinkedList* CalcuateL2);


int main() {
    int size;
    DataType data1[] = {1, 2, 3, 4};
    DataType data2[] = {3, 3, 4, 5};
    LinkedList* result;
    LinkedList* List1 = CreateList(data1, sizeof(data1) / sizeof(data1[0]));
    LinkedList* List2 = CreateList(data2, sizeof(data2) / sizeof(data2[0]));


    cout << "==============" << endl;
    cout << "交运算的结果为：" << endl;
    result = Intersection(List1, List2);
    ShowList(result);
    cout << "==============" << endl;

    cout << "==============" << endl;
    cout << "并运算的结果为：" << endl;
    result = Union(List1, List2);
    ShowList(result);
    cout << "==============" << endl;

    cout << "==============" << endl;
    cout << "差运算的结果为：" << endl;
    result = Substract(List1, List2);
    ShowList(result);
    cout << "==============" << endl;

    cout << "==============" << endl;
    if (isSubset(List1, List2)) {
        cout << "List2是List1的子集" << endl;
    } else {
        cout << "List2不是List1的子集" << endl;
    }
    cout << "==============" << endl;
    return 0;
}

/**
 * @brief 创建一个新的结点
 * 
 * @return LinkedList* :结点
 */
LinkedList* CreateNewCode() {
    LinkedList* tempNode;
    tempNode = new LinkedList;
    tempNode->data = -1;
    tempNode->next = NULL;
    return tempNode;
}

/**
 * @brief 尾插法创建链表
 * 
 * @param n :链表长度
 * @return LinkedList* ::链表头
 */
LinkedList* CreateList(DataType data[], int size) {
    LinkedList* head = CreateNewCode();
    LinkedList* work;
    LinkedList* temp;
    work = head;
    head->data = data[0];
    head->next = temp;
    int i;
    for (i = 1; i <= size; i++) {
        temp = CreateNewCode();
        temp->data = data[i];
        work->next = temp;
        work = temp;
    }
    return head;
}

/**
 * @brief 打印所有的链表元素
 * 
 * @param L :链表头
 */
void ShowList(LinkedList* L) {
    int i = 1;
    LinkedList* work;
    work = L;
    while (work->next != NULL) {
        cout << "第" << i << "个数据为：" << work->data << endl;
        work = work->next;
        i++;
    }
}

/**
 * @brief 按值查找数据
 * 
 * @param L :链表头
 * @param value :要查找的值
 * @return int :符合的值的数量
 */
int SearchValue(LinkedList* L, DataType value) {
    LinkedList* work;
    work = L;
    while (work->next != NULL) {
        if (work->data == value) {
            return 1;
        }
        work = work->next;
    }
    return 0;
}

/**
 * @brief 集合的交集
 * 
 * @param CalcuateL1 
 * @param CalcuateL2 
 * @return LinkedList* 
 */
LinkedList* Intersection(LinkedList* CalcuateL1, LinkedList* CalcuateL2) {
    int number = 0;
    DataType data[20];
    LinkedList* work;
    work = CalcuateL1;
    while (work->next != NULL) {
        if (SearchValue(CalcuateL2, work->data)) {
            data[number] = work->data;
            number++;
        }
        work = work->next;
    }
    return CreateList(data, number);
}

/**
 * @brief 集合的并集
 * 
 * @param CalcuateL1 
 * @param CalcuateL2 
 * @return LinkedList* 
 */
LinkedList* Union(LinkedList* CalcuateL1, LinkedList* CalcuateL2) {
    int number = 0;
    DataType data[20];
    LinkedList* work;
    work = CalcuateL1;
    while (work->next != NULL) {
        data[number] = work->data;
        number++;
        work = work->next;
    }
    work = CalcuateL2;
    while (work->next != NULL) {
        data[number] = work->data;
        number++;
        work = work->next;
    }
    return CreateList(data, number);
}

/**
 * @brief 集合的差运算，L1-L2
 * 
 * @param CalcuateL1 
 * @param CalcuateL2 
 * @return LinkedList* 
 */
LinkedList* Substract(LinkedList* CalcuateL1, LinkedList* CalcuateL2) {
    int number = 0;
    DataType data[20];
    LinkedList* work;
    work = CalcuateL1;
    while (work->next != NULL) {
        if (!SearchValue(CalcuateL2, work->data)) {
            data[number] = work->data;
            number++;
        }
        work = work->next;
    }
    return CreateList(data, number);
}

/**
 * @brief 判断L2是否是L1的子集
 * 
 * @param CalcuateL1 
 * @param CalcuateL2 
 * @return int 
 */
int isSubset(LinkedList* CalcuateL1, LinkedList* CalcuateL2) {
    int number = 0;
    LinkedList* work;
    work = CalcuateL2;
    while (work->next != NULL) {
        if (!SearchValue(CalcuateL1, work->data)) {
            return 0;
        }
        work = work->next;
    }
    return 1;
}