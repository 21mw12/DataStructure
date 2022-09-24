#include<iostream>
using namespace std;

typedef int DataType;
typedef struct LinkedStack {
    DataType data;
    LinkedStack *next;
}LinkedStack;

LinkedStack* CreateStack();
void ShowStack(LinkedStack* stack);
int EmptyStack(LinkedStack* stack);
LinkedStack* Push(LinkedStack* stack, DataType data);
LinkedStack* Pop(LinkedStack* stack, DataType* data);

int main() {
    LinkedStack* stack = CreateStack();
    // cout << EmptyStack(stack) << endl;
    stack = Push(stack, 3);
    stack = Push(stack, 4);
    stack = Push(stack, 5);
    ShowStack(stack);
    
    DataType newData;
    stack = Pop(stack, &newData);
    cout << newData << endl;
    ShowStack(stack);
    return 0;
}

/**
 * @brief ����һ����ջ
 *
 * @return LinkedStack* :ջ��ָ��
 */
LinkedStack* CreateStack() {
    LinkedStack* head = new LinkedStack;
    head->data = -1;
    head->next = NULL;
    return head;
}

/**
 * @brief ��ӡջ����������
 * 
 * @param stack :Ҫ��ӡ��ջ
 */
void ShowStack(LinkedStack* stack) {
    if (EmptyStack(stack)) {
        cout << "ջΪ��" << endl;
    } else {
        LinkedStack* work;
        work = stack;
        while (work->next != NULL) {
            cout << work->data << endl;
            work = work->next;
        }
    }
}

/**
 * @brief �ж�ջ�Ƿ�Ϊ��
 *
 * @param stack :Ҫ�жϵ�ջ
 * @return int :Ϊ1��ջ�գ�Ϊ0��ջ�ǿ�
 */
int EmptyStack(LinkedStack* stack) {
    if (stack->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief ��ջ
 *
 * @param stack :Ҫ����ջ
 * @param data :��ջ������
 * @return LinkedStack* :�µ�ջ��ָ��
 */
LinkedStack* Push(LinkedStack* stack, DataType data) {
    LinkedStack* newTop = new LinkedStack;
    newTop->data = data;
    newTop->next = stack;
    return newTop;
}

/**
 * @brief ��ջ
 *
 * @param stack :Ҫ����ջ
 * @param data :��ջ������
 * @return LinkedStack* :�µ�ջ��ָ��
 */
LinkedStack* Pop(LinkedStack* stack, DataType* data) {
    if (EmptyStack(stack)) {
        cout << "ջΪ��" << endl;
        return stack;
    } else {
        *data = stack->data;
        LinkedStack* newTop = stack->next;
        stack->next = NULL;
        return newTop;
    }
}
