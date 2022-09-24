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
 * @brief 创建一个空栈
 *
 * @return LinkedStack* :栈顶指针
 */
LinkedStack* CreateStack() {
    LinkedStack* head = new LinkedStack;
    head->data = -1;
    head->next = NULL;
    return head;
}

/**
 * @brief 打印栈内所有数据
 * 
 * @param stack :要打印的栈
 */
void ShowStack(LinkedStack* stack) {
    if (EmptyStack(stack)) {
        cout << "栈为空" << endl;
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
 * @brief 判断栈是否为空
 *
 * @param stack :要判断的栈
 * @return int :为1则栈空，为0则栈非空
 */
int EmptyStack(LinkedStack* stack) {
    if (stack->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief 进栈
 *
 * @param stack :要进的栈
 * @param data :进栈的数据
 * @return LinkedStack* :新的栈顶指针
 */
LinkedStack* Push(LinkedStack* stack, DataType data) {
    LinkedStack* newTop = new LinkedStack;
    newTop->data = data;
    newTop->next = stack;
    return newTop;
}

/**
 * @brief 出栈
 *
 * @param stack :要进的栈
 * @param data :进栈的数据
 * @return LinkedStack* :新的栈顶指针
 */
LinkedStack* Pop(LinkedStack* stack, DataType* data) {
    if (EmptyStack(stack)) {
        cout << "栈为空" << endl;
        return stack;
    } else {
        *data = stack->data;
        LinkedStack* newTop = stack->next;
        stack->next = NULL;
        return newTop;
    }
}
