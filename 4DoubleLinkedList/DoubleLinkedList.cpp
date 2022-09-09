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
 * @brief 创建一个新的结点
 * 
 * @return LinkedList* :结点
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
 * @brief 创建双向链表
 * 
 * @param n :链表长度
 * @return LinkedList* ::链表头
 */
LinkedList* CreateList(int n) {
    if (n <= 0) {
        cout << "请输入正确的长度" << endl;
        return 0;
    }
    LinkedList* head = CreateNewCode();
    LinkedList* work;
    LinkedList* temp;
    work = head;
    int i = 0;
    cout << "请输入第" << i+1 << "位的数据：" ;
    cin >> head->data;
    for (i = 1; i < n; i++) {
        temp = CreateNewCode();
        cout << "请输入第" << i+1 << "位的数据：" ;
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
 * @brief 打印所有的链表元素
 * 
 * @param L :链表头
 */
void ShowList(LinkedList* L) {
    int i = 0;
    LinkedList* work;
    LinkedList* stop = L;
    work = L;
    do {
        cout << "第" << i+1 << "个数据为：" << work->data << endl;
        work = work->next;
        i++;
    } while (work != stop);
    cout << " 共" << i << "个数据" << endl;
}

/**
 * @brief 插入一个结点
 * 
 * @param L :链表头
 * @param newData :插入的数据
 * @param local :要插入的位置
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
 * @brief 删除一个结点
 * 
 * @param L :链表头
 * @param local :删除结点位置 
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