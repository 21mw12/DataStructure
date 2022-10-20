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
    cout << "������Ľ��Ϊ��" << endl;
    result = Intersection(List1, List2);
    ShowList(result);
    cout << "==============" << endl;

    cout << "==============" << endl;
    cout << "������Ľ��Ϊ��" << endl;
    result = Union(List1, List2);
    ShowList(result);
    cout << "==============" << endl;

    cout << "==============" << endl;
    cout << "������Ľ��Ϊ��" << endl;
    result = Substract(List1, List2);
    ShowList(result);
    cout << "==============" << endl;

    cout << "==============" << endl;
    if (isSubset(List1, List2)) {
        cout << "List2��List1���Ӽ�" << endl;
    } else {
        cout << "List2����List1���Ӽ�" << endl;
    }
    cout << "==============" << endl;
    return 0;
}

/**
 * @brief ����һ���µĽ��
 * 
 * @return LinkedList* :���
 */
LinkedList* CreateNewCode() {
    LinkedList* tempNode;
    tempNode = new LinkedList;
    tempNode->data = -1;
    tempNode->next = NULL;
    return tempNode;
}

/**
 * @brief β�巨��������
 * 
 * @param n :������
 * @return LinkedList* ::����ͷ
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
 * @brief ��ӡ���е�����Ԫ��
 * 
 * @param L :����ͷ
 */
void ShowList(LinkedList* L) {
    int i = 1;
    LinkedList* work;
    work = L;
    while (work->next != NULL) {
        cout << "��" << i << "������Ϊ��" << work->data << endl;
        work = work->next;
        i++;
    }
}

/**
 * @brief ��ֵ��������
 * 
 * @param L :����ͷ
 * @param value :Ҫ���ҵ�ֵ
 * @return int :���ϵ�ֵ������
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
 * @brief ���ϵĽ���
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
 * @brief ���ϵĲ���
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
 * @brief ���ϵĲ����㣬L1-L2
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
 * @brief �ж�L2�Ƿ���L1���Ӽ�
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