#include<iostream>
#include<string>
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
LinkedStack* Calculate(LinkedStack* stack);
LinkedStack* exchange(string str);
int isSymob(int content);

int main() {
    LinkedStack* stack = CreateStack();
    string str;
    int result;
    // 示例："9+(3-1)*3+10/2"
    cout << "请输入计算表达式；";
    cin >> str;
    stack = Calculate(exchange(str));
    stack = Pop(stack, &result);
    cout << "结果为：" << result << endl;
    // ShowStack(stack);
    
    cin >> str;
    return 0;
}

int isSymob(int content) {
    switch (content) {
        case (int)'+':
        case (int)'-':
            return 1;
            break;
        case (int)'*':
        case (int)'/':
        case (int)'(':
        case (int)')':
            return 2;
            break; 
        default:
            return 0;
            break;
    }
}

LinkedStack* exchange(string str) {
    int data[30];
    int i, j = 0;
    int result = 0;
    bool lock = false;
    LinkedStack* stack = CreateStack();
    LinkedStack* temp = CreateStack();
    for (i = 0; i <= str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (int)str[i] - 48;
            lock = true;
        } else {
            if (lock) {
                data[j] = result;
                j++;
                lock = false;
            }
            data[j] = str[i];
            j++;
            result = 0;
        }
    }
    for (i = 0; i < j-1; i++) {
        if (!isSymob(data[i])) {
            temp = Push(temp, data[i]);
        } else {
            switch (data[i]) {
                case (int)'+':
                case (int)'-':
                    if (stack->data == '*' || stack->data == '/') {
                        while (!EmptyStack(stack)) {
                            stack = Pop(stack, &result);
                            temp = Push(temp, result);
                        }
                    }
                    stack = Push(stack, data[i]);
                    break;
                case (int)'*':
                case (int)'/':
                case (int)'(':
                    stack = Push(stack, data[i]);
                    break;
                case (int)')':
                    while (stack->data != (int)'(') {
                        stack = Pop(stack, &result);
                        temp = Push(temp, result);
                    }
                    stack = Pop(stack, &result);
                    break;  
                default:
                    break;
            }
        }
    }    
    while (!EmptyStack(stack)) {
        stack = Pop(stack, &result);
        temp = Push(temp, result);
    }
    while (!EmptyStack(temp)) {
        temp = Pop(temp, &result);
        stack = Push(stack, result);
    }
    return stack;
}

LinkedStack* Calculate(LinkedStack* stack) {
    int front, end;
    int result;
    int temp;
    LinkedStack* resultStack = CreateStack();
    while (!EmptyStack(stack)) {
        stack = Pop(stack, &temp);
        if (isSymob(temp)) {
            resultStack = Pop(resultStack, &end);
            resultStack = Pop(resultStack, &front);
            switch (temp) {
                case (int)'+':
                    result = front + end;
                    break;
                case (int)'-':
                    result = front - end;
                    break;
                case (int)'*':
                    result = front * end;
                    break;
                case (int)'/':
                    result = front / end;
                    break;
                default:
                    break;
            }
            resultStack = Push(resultStack, result);
        } else {
            resultStack = Push(resultStack, temp);
        }
    }
    return resultStack;
}

LinkedStack* CreateStack() {
    LinkedStack* head = new LinkedStack;
    head->data = -1;
    head->next = NULL;
    return head;
}

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

int EmptyStack(LinkedStack* stack) {
    if (stack->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

LinkedStack* Push(LinkedStack* stack, DataType data) {
    LinkedStack* newTop = new LinkedStack;
    newTop->data = data;
    newTop->next = stack;
    return newTop;
}

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