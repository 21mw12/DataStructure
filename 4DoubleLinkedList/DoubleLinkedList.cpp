#include <iostream>
using namespace std;

typedef int DataType;
typedef struct LinkedList {
    LinkedList *prior;
    DataType data;
    LinkedList *next;    
}LinkedList;

LinkedList* CreateList(int n);
void ShowList(LinkedList* L);
void InsList(LinkedList* L, DataType newData, int local);
void DelList(LinkedList* L, int local);

int main() {
    LinkedList* test = CreateList(3);
    ShowList(test);
    InsList(test, 4, 2);
    ShowList(test);
    DelList(test, 3);
    ShowList(test);
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
    tempNode->prior = NULL;
    tempNode->data = -1;
    tempNode->next = NULL;
    return tempNode;
}

/**
 * @brief ����˫������
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
        temp->prior = work;
        work = temp;
    }
    temp->next = head;
    head->prior = temp;
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
            newCode->prior = work;
            newCode->next = work->next;
            work->next->prior = newCode;
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
    LinkedList* Del;
    LinkedList* stop = L;
    work = L;
    do {
        if (i == local - 1) {
            Del = work->next;
            work->next = Del->next;
            Del->next->prior = work;
            Del->next = NULL;
            Del->prior = NULL;
            break;
        }
        work = work->next;
        i++;
    } while (work != stop);
}