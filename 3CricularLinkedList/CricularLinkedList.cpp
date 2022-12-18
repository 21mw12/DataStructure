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
 * @brief 创建循环链表
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
        work = temp;
    }
    temp->next = head;
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
 * @brief 按值查找数据
 * 
 * @param L :链表头
 * @param value :要查找的值
 * @return int :符合的值的数量
 */
int SearchValue(LinkedList* L, DataType value) {
    int i = 1;
    int number = 0;
    LinkedList* work;
    LinkedList* stop = L;
    work = L;
    do {
        if (work->data == value) {
            cout << "第" << i << "个数据符合" << endl;
            number++;
        }
        work = work->next;
        i++;
    } while (work != stop);
    cout << "共有" << number << "个数据符合" << endl;
    return number;
}

/**
 * @brief 按位置查找数据
 * 
 * @param L :链表头
 * @param local :要查找的位置
 * @return DataType :那一位的值
 */
DataType SearchLocal(LinkedList* L, int local) {
    int i = 1;
    LinkedList* work;
    LinkedList* stop = L;
    work = L;
    do {
        if (i == local) {
            cout << "第" << i << "个数据为：" << work->data << endl;
            break;
        }
        work = work->next;
        i++;
    } while (work != stop);
    return work->data;
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
            newCode->next = work->next;
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