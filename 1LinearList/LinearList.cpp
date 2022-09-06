#include <iostream>
using namespace std;

#define MAXLEN 100
typedef double DataType;
typedef struct LinearList
{
    DataType data[MAXLEN];
    int Length;
}LinearList;

LinearList L;

void CreateList (LinearList* L, int n);
void ShowList (LinearList* L);
DataType GetElem (LinearList* L, int n);
void InsElem (LinearList* L, DataType NewData, int n);
void DelElem (LinearList* L, int n);

int main() {
    int KeyCode = 1;
    int local = -1;
    DataType data = -1;
    int number = -1;
    int Elem = 0;

    while (true) {
        cout << "***************************" << endl;
        cout << "         顺序表" << endl;
        cout << "***************************" << endl;
        cout << "1.新建顺序表" << endl;
        cout << "2.打印所有顺序表元素" << endl;
        cout << "3.按位获得顺序表元素" << endl;
        cout << "4.插入顺序表元素" << endl;
        cout << "5.删除顺序表元素" << endl;
        cout << "6.退出系统" << endl;
        cout << "***************************" << endl;
        if (KeyCode < 1 || KeyCode > 6) {
            cout << "  请输入正确的操作：";
        } else {
            cout << "  请输入操作：";
        }
        cin >> KeyCode;

        if (KeyCode == 6) {
            break;
        }

        switch (KeyCode) {
        case 1:
            system("cls");
            cout << "***************************" << endl;
            cout << "请输入顺序表的长度：";
            cin >> number;
            while (number <= 0 || number > MAXLEN) {
                system("cls");
                cout << "***************************" << endl;
                cout << "请输入正确的顺序表的长度：";
                cin >> number;
            }
            CreateList(&L, number);

            do {
                system("cls");
                cout << "***************************" << endl;
                cout << " 按1返回: ";
                cin >> number;
            } while (number != 1);
        system("cls");
            break;
        case 2:
            do {
                system("cls");
                cout << "***************************" << endl;
                ShowList (&L);
                cout << "***************************" << endl;
                cout << " 按1返回: ";
                cin >> number;
            } while (number != 1);
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "***************************" << endl;
            cout << "请输入要查找的位置：";
            cin >> number;
            while (number <= 0 || number > L.Length) {
                system("cls");
                cout << "***************************" << endl;
                cout << "请输入正确的位置：";
                cin >> number;
            }
            Elem = GetElem(&L, number);
            
            do {
                system("cls");
                cout << "***************************" << endl;
                cout << "第" << number << "位的元素是：" << Elem << endl;
                cout << "***************************" << endl;
                cout << " 按1返回: ";
                cin >> number;
            } while (number != 1);
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "***************************" << endl;
            cout << "请输入要插入的位置：";
            cin >> local;
            while (local <= 0 || local > L.Length) {
                system("cls");
                cout << "***************************" << endl;
                cout << "请输入正确的要插入的位置：";
                cin >> local;
            }

            system("cls");
            cout << "***************************" << endl;
            cout << "请输入新数据：";
            cin >> data;
            InsElem(&L, data, local);
            
            do {
                system("cls");
                cout << "***************************" << endl;
                cout << " 按1返回: ";
                cin >> number;
            } while (number != 1);
            system("cls");
            break;

        case 5:
            system("cls");
            cout << "***************************" << endl;
            cout << "请输入要删除的位置：";
            cin >> local;
            while (local <= 0 || local > L.Length) {
                system("cls");
                cout << "***************************" << endl;
                cout << "请输入正确的要删除的位置：";
                cin >> local;
            }
            DelElem(&L, local);
            
            do {
                system("cls");
                cout << "***************************" << endl;
                cout << " 按1返回: ";
                cin >> number;
            } while (number != 1);
            system("cls");
            break;
        default:
            system("cls");
            break;
        }
    }

    //cout << GetElem (&L, 3);
    // InsElem(&L, 4, 4);
    // ShowList (&L);
    // DelElem(&L, 3);
    // ShowList (&L);
    return 0;
}

/**
 * @brief 创建一个顺序表
 * 
 * @param L :顺序表
 * @param n :数据量
 */
void CreateList (LinearList* L, int n) {
    if (n <= 0 || n > MAXLEN) {
        cout << "请输入正确的数据量" << endl;
        return;
    } else {
        int i = 0;
        for (i = 0; i < n; i++) {
            cout << "请输入第" << i+1 << "个数据:";
            cin >> L->data[i];
        }
        L->Length = n;
    }
}

/**
 * @brief 输出顺序表的全部数据
 * 
 * @param L :顺序表
 */
void ShowList (LinearList* L) {
    int i = 0;
    for (i = 0; i < L->Length; i++) {
        cout << "第" << i+1 << "个数据为:" << L->data[i] << endl;
    }
}

/**
 * @brief 获得顺序表第n位的数据
 * 
 * @param L :顺序表
 * @param n :位数
 * @return int 对应位的数据
 */
DataType GetElem (LinearList* L, int n) {
    if (n <= 0 || n > L->Length) {
        cout << "请输入正确的数据量" << endl;
        return -999;
    } else {
        return L->data[n-1];
    }
}

/**
 * @brief 指定位置插入一个数据
 * 
 * @param L :顺序表
 * @param newdata :新的数据
 * @param n :插入到哪一位
 */
void InsElem (LinearList* L, DataType NewData, int n) {
    if (L->Length >= MAXLEN) {
        cout << "顺序表已满" << endl;
        return;
    }
    if (n <= 0 || n > L->Length + 1) {
        cout << "请输入正确的数据量" << endl;
        return;
    } else {
        int i;
        DataType TempData;
        L->Length++;
        for (i = 0; i <= L->Length; i++) {
            if (i >= n - 1) {
                TempData = L->data[i];
                L->data[i] = NewData;
                NewData = TempData;
            }
        }
    }
}

/**
 * @brief 删除指定位置的数据
 * 
 * @param L :顺序表
 * @param n :删除哪一位
 */
void DelElem (LinearList* L, int n) {
    if (n <= 0 || n > L->Length) {
        cout << "请输入正确的数据量" << endl;
        return;
    } else {
        int i;
        for (i = 0; i <= L->Length; i++) {
            if (i >= n - 1) {
                L->data[i] = L->data[i + 1];
            }
        }
        L->Length--;
    }
}