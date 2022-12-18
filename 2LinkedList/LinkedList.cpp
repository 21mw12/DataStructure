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
 * @brief 头插法创建链表
 * 
 * @param n :链表长度
 * @return LinkedList* :链表头
 */
LinkedList* CreateListH(int n) {
    if (n <= 0) {
        cout << "请输入正确的长度" << endl;
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
        cout << "请输入第" << i+1 << "位的数据：" ;
        cin >> work->data;
        work = work->next;
    }
    return head;
}

/**
 * @brief 尾插法创建链表
 * 
 * @param n :链表长度
 * @return LinkedList* ::链表头
 */
LinkedList* CreateListL(int n) {
    if (n <= 0) {
        cout << "请输入正确的长度" << endl;
        return 0;
    }
    // LinkedList* head;
    // LinkedList* work;
    // int i;
    // for (i = 0; i < n; i++) {
    //     cout << "请输入第" << i+1 << "位的数据：" ;
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
        cout << "请输入第" << i+1 << "位的数据：" ;
        if (i == 0) cin >> head->data;
        else cin >> temp->data;
        temp = CreateNewCode();
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
    cout << " 共" << --i << "个数据" << endl;
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
    work = L;
    while (work->next != NULL) {
        if (work->data == value) {
            cout << "第" << i << "个数据符合" << endl;
            number++;
        }
        work = work->next;
        i++;
    }
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
    work = L;
    while (work->next != NULL) {
        if (i == local) {
            cout << "第" << i << "个数据为：" << work->data << endl;
            break;
        }
        work = work->next;
        i++;
    }
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