#include<iostream>
using namespace std;

typedef int DataType;
typedef struct LinkedQueue {
    DataType data;
    LinkedQueue* next;
}LinkedQueue;
typedef struct LinkedQueuePointer {
    LinkedQueue* front;
    LinkedQueue* rear;
}LinkedQueuePointer;

LinkedQueuePointer* CreateQueue();
int EmptyQueue(LinkedQueuePointer* pointer);
void ShowQueue(LinkedQueuePointer* pointer);
LinkedQueuePointer* EnQueue(LinkedQueuePointer* pointer, DataType data);
LinkedQueuePointer* DeQueue(LinkedQueuePointer* pointer, DataType* data);

int main() {
    LinkedQueuePointer* pointer = CreateQueue();
    pointer = EnQueue(pointer, 3);
    pointer = EnQueue(pointer, 4);
    pointer = EnQueue(pointer, 5);
    ShowQueue(pointer);

    DataType data;
    pointer = DeQueue(pointer, &data);
    cout << data << endl;
    ShowQueue(pointer);
    return 0;
}

/**
 * @brief 创建一个空队列
 * 
 * @return LinkedQueuePointer* :空队列
 */
LinkedQueuePointer* CreateQueue() {
    LinkedQueue* head = new LinkedQueue;
    LinkedQueuePointer* pointer = new LinkedQueuePointer;
    pointer->front = head;
    pointer->rear = head;
    return pointer;
}

/**
 * @brief 判断队列是否为空
 * 
 * @param pointer :要检查的队列
 * @return int :为1则队列为空，为0则队列为非空
 */
int EmptyQueue(LinkedQueuePointer* pointer) {
    if (pointer->front == pointer->rear) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief 打印队列中的全部数据
 * 
 * @param pointer :要打印的队列
 */
void ShowQueue(LinkedQueuePointer* pointer) {
    if (EmptyQueue(pointer)) {
        cout << "队列为空" << endl;
    } else {
        LinkedQueue* work;
        work = pointer->front;
        while (work != pointer->rear) {
            cout << work->data << endl;
            work = work->next;
        }
    }
}

/**
 * @brief 进队
 * 
 * @param pointer :队列
 * @param data :插入的数据
 * @return LinkedQueuePointer* :新的队列
 */
LinkedQueuePointer* EnQueue(LinkedQueuePointer* pointer, DataType data) {
    LinkedQueue* Node = new LinkedQueue;
    LinkedQueue* work;
    work = pointer->front;
    while (work != pointer->rear) {
        work = work->next;
    }
    work->next = Node;
    work->data = data;
    pointer->rear = Node;
    return pointer;
}

/**
 * @brief 出队
 * 
 * @param pointer :队列
 * @param data :出队的数据
 * @return LinkedQueuePointer* :新的队列
 */
LinkedQueuePointer* DeQueue(LinkedQueuePointer* pointer, DataType* data) {
    LinkedQueue* work;
    work = pointer->front;
    *data = work->data;
    pointer->front = work->next;
    work->next = NULL;
    free(work);
    return pointer;
}