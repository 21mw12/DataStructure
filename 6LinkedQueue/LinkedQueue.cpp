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
 * @brief ����һ���ն���
 * 
 * @return LinkedQueuePointer* :�ն���
 */
LinkedQueuePointer* CreateQueue() {
    LinkedQueue* head = new LinkedQueue;
    LinkedQueuePointer* pointer = new LinkedQueuePointer;
    pointer->front = head;
    pointer->rear = head;
    return pointer;
}

/**
 * @brief �ж϶����Ƿ�Ϊ��
 * 
 * @param pointer :Ҫ���Ķ���
 * @return int :Ϊ1�����Ϊ�գ�Ϊ0�����Ϊ�ǿ�
 */
int EmptyQueue(LinkedQueuePointer* pointer) {
    if (pointer->front == pointer->rear) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief ��ӡ�����е�ȫ������
 * 
 * @param pointer :Ҫ��ӡ�Ķ���
 */
void ShowQueue(LinkedQueuePointer* pointer) {
    if (EmptyQueue(pointer)) {
        cout << "����Ϊ��" << endl;
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
 * @brief ����
 * 
 * @param pointer :����
 * @param data :���������
 * @return LinkedQueuePointer* :�µĶ���
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
 * @brief ����
 * 
 * @param pointer :����
 * @param data :���ӵ�����
 * @return LinkedQueuePointer* :�µĶ���
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