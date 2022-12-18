#include <iostream>
using namespace std;

typedef int DataType;
typedef struct LinkedList {
    DataType data;
    LinkedList *next;    
}LinkedList;

LinkedList* CreateNewCode();
LinkedList* CreateListH(int n);
LinkedList* CreateListL(int n);
void ShowList(LinkedList* L);
int SearchValue(LinkedList* L, DataType value);
DataType SearchLocal(LinkedList* L, int local);
void InsList(LinkedList* L, DataType newData, int local);
void DelList(LinkedList* L, int local);

int main() {
    LinkedList* test = CreateListL(3);
    ShowList(test);
    // InsList(test, 2, 2);
    // ShowList(test);
    // DelList(test, 4);
    // ShowList(test);
    //SearchValue(test, 2);
    //SearchLocal(test, 2);
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
 * @brief ͷ�巨��������
 * 
 * @param n :������
 * @return LinkedList* :����ͷ
 */
LinkedList* CreateListH(int n) {
    if (n <= 0) {
        cout << "��������ȷ�ĳ���" << endl;
        return 0;
    }
    LinkedList* head;
    int i;
    for (i = 0; i < n; i++) {
        LinkedList* work = CreateNewCode();
        work->next = head;
        head = work;
    }
    LinkedList* work = head;
    for (i = 0; i < n; i++) {
        cout << "�������" << i+1 << "λ�����ݣ�" ;
        cin >> work->data;
        work = work->next;
    }
    return head;
}

/**
 * @brief β�巨��������
 * 
 * @param n :������
 * @return LinkedList* ::����ͷ
 */
LinkedList* CreateListL(int n) {
    if (n <= 0) {
        cout << "��������ȷ�ĳ���" << endl;
        return 0;
    }
    // LinkedList* head;
    // LinkedList* work;
    // int i;
    // for (i = 0; i < n; i++) {
    //     cout << "�������" << i+1 << "λ�����ݣ�" ;
    //     if (i == 0) {
    //         head = CreateNewCode();
    //         work = CreateNewCode();
    //         cin >> head->data;
    //         head->next = work;
    //     } else {
    //         cin >> work->data;
    //         LinkedList* temp = CreateNewCode();
    //         work->next = temp;
    //         work = temp;
    //     }
    // }
    LinkedList* head = CreateNewCode();
    LinkedList* work;
    LinkedList* temp;
    work = head;
    int i;
    for (i = 0; i < n; i++) {
        cout << "�������" << i+1 << "λ�����ݣ�" ;
        if (i == 0) cin >> head->data;
        else cin >> temp->data;
        temp = CreateNewCode();
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
    cout << " ��" << --i << "������" << endl;
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
    work = L;
    while (work->next != NULL) {
        if (work->data == value) {
            cout << "��" << i << "�����ݷ���" << endl;
            number++;
        }
        work = work->next;
        i++;
    }
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
    work = L;
    while (work->next != NULL) {
        if (i == local) {
            cout << "��" << i << "������Ϊ��" << work->data << endl;
            break;
        }
        work = work->next;
        i++;
    }
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
    work = L;
    while (work->next != NULL) {
        if (i == local - 1) {
            LinkedList* newCode = CreateNewCode();
            newCode->data = newData;
            newCode->next = work->next;
            work->next = newCode;
            break;
        }
        work = work->next;
        i++;
    }
}

void DelList(LinkedList* L, int local) {
    int i = 1;
    LinkedList* work;
    work = L;
    while (work->next != NULL) {
        if (i == local - 1) {
            work->next = work->next->next;
            work->next->next = NULL;
            break;
        }
        work = work->next;
        i++;
    }
}