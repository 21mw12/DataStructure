#include <iostream>
using namespace std;

typedef int DataType;
typedef struct LinkedList {
    DataType data;
    LinkedList *next;    
}LinkedList;

LinkedList* CreateNewCode();
LinkedList* CreateList(int n);
void ShowList(LinkedList* L);
int SearchValue(LinkedList* L, DataType value);
DataType SearchLocal(LinkedList* L, int local);
void InsList(LinkedList* L, DataType newData, int local);
void DelList(LinkedList* L, int local);

int main() {
    LinkedList* test = CreateList(3);
    ShowList(test);
    // SearchValue(test, 2);
    // SearchLocal(test, 1);
    // InsList(test, 4, 4);
    // ShowList(test);
    // DelList(test, 2);
    // ShowList(test);
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
 * @brief ����ѭ������
 * 
 * @param n :������
 * @return LinkedList* ::����ͷ
 */
LinkedList* CreateList(int n) {
    if (n <= 0) {
        cout << "��������ȷ�ĳ���" << endl;
        return 0;
    }
    LinkedList* head = CreateNewCode();
    LinkedList* work;
    LinkedList* temp;
    work = head;
    int i = 0;
    cout << "�������" << i+1 << "λ�����ݣ�" ;
    cin >> head->data;
    for (i = 1; i < n; i++) {
        temp = CreateNewCode();
        cout << "�������" << i+1 << "λ�����ݣ�" ;
        cin >> temp->data;
        work->next = temp;
        work = temp;
    }
    temp->next = head;
    return head;
}

/**
 * @brief ��ӡ���е�����Ԫ��
 * 
 * @param L :����ͷ
 */
void ShowList(LinkedList* L) {
    int i = 0;
    LinkedList* work;
    LinkedList* stop = L;
    work = L;
    do {
        cout << "��" << i+1 << "������Ϊ��" << work->data << endl;
        work = work->next;
        i++;
    } while (work != stop);
    cout << " ��" << i << "������" << endl;
}

/**
 * @brief ��ֵ��������
 * 
 * @param L :����ͷ
 * @param value :Ҫ���ҵ�ֵ
 * @return int :���ϵ�ֵ������
 */
int SearchValue(LinkedList* L, DataType value) {
    int i = 1;
    int number = 0;
    LinkedList* work;
    LinkedList* stop = L;
    work = L;
    do {
        if (work->data == value) {
            cout << "��" << i << "�����ݷ���" << endl;
            number++;
        }
        work = work->next;
        i++;
    } while (work != stop);
    cout << "����" << number << "�����ݷ���" << endl;
    return number;
}

/**
 * @brief ��λ�ò�������
 * 
 * @param L :����ͷ
 * @param local :Ҫ���ҵ�λ��
 * @return DataType :��һλ��ֵ
 */
DataType SearchLocal(LinkedList* L, int local) {
    int i = 1;
    LinkedList* work;
    LinkedList* stop = L;
    work = L;
    do {
        if (i == local) {
            cout << "��" << i << "������Ϊ��" << work->data << endl;
            break;
        }
        work = work->next;
        i++;
    } while (work != stop);
    return work->data;
}

/**
 * @brief ����һ�����
 * 
 * @param L :����ͷ
 * @param newData :���������
 * @param local :Ҫ�����λ��
 */
void InsList(LinkedList* L, DataType newData, int local) {
    int i = 1;
    LinkedList* work;
    LinkedList* stop = L;
    work = L;
    do {
        if (i == local - 1) {
            LinkedList* newCode = CreateNewCode();
            newCode->data = newData;
            newCode->next = work->next;
            work->next = newCode;
            break;
        }
        work = work->next;
        i++;
    } while (work != stop);
}

/**
 * @brief ɾ��һ�����
 * 
 * @param L :����ͷ
 * @param local :ɾ�����λ�� 
 */
void DelList(LinkedList* L, int local) {
    int i = 1;
    LinkedList* work;
    LinkedList* stop = L;
    LinkedList* DelFornt;
    LinkedList* Del;
    LinkedList* DelBack;
    work = L;
    do {
        if (i == local - 1) DelFornt = work;
        if (i == local) Del = work;
        if (i == local + 1) DelBack = work;
        work = work->next;
        i++;
    } while (work != stop);
    DelFornt->next = DelBack;
    Del->next = NULL;
}