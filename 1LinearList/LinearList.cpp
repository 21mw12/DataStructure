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
        cout << "         ˳���" << endl;
        cout << "***************************" << endl;
        cout << "1.�½�˳���" << endl;
        cout << "2.��ӡ����˳���Ԫ��" << endl;
        cout << "3.��λ���˳���Ԫ��" << endl;
        cout << "4.����˳���Ԫ��" << endl;
        cout << "5.ɾ��˳���Ԫ��" << endl;
        cout << "6.�˳�ϵͳ" << endl;
        cout << "***************************" << endl;
        if (KeyCode < 1 || KeyCode > 6) {
            cout << "  ��������ȷ�Ĳ�����";
        } else {
            cout << "  �����������";
        }
        cin >> KeyCode;

        if (KeyCode == 6) {
            break;
        }

        switch (KeyCode) {
        case 1:
            system("cls");
            cout << "***************************" << endl;
            cout << "������˳���ĳ��ȣ�";
            cin >> number;
            while (number <= 0 || number > MAXLEN) {
                system("cls");
                cout << "***************************" << endl;
                cout << "��������ȷ��˳���ĳ��ȣ�";
                cin >> number;
            }
            CreateList(&L, number);

            do {
                system("cls");
                cout << "***************************" << endl;
                cout << " ��1����: ";
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
                cout << " ��1����: ";
                cin >> number;
            } while (number != 1);
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "***************************" << endl;
            cout << "������Ҫ���ҵ�λ�ã�";
            cin >> number;
            while (number <= 0 || number > L.Length) {
                system("cls");
                cout << "***************************" << endl;
                cout << "��������ȷ��λ�ã�";
                cin >> number;
            }
            Elem = GetElem(&L, number);
            
            do {
                system("cls");
                cout << "***************************" << endl;
                cout << "��" << number << "λ��Ԫ���ǣ�" << Elem << endl;
                cout << "***************************" << endl;
                cout << " ��1����: ";
                cin >> number;
            } while (number != 1);
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "***************************" << endl;
            cout << "������Ҫ�����λ�ã�";
            cin >> local;
            while (local <= 0 || local > L.Length) {
                system("cls");
                cout << "***************************" << endl;
                cout << "��������ȷ��Ҫ�����λ�ã�";
                cin >> local;
            }

            system("cls");
            cout << "***************************" << endl;
            cout << "�����������ݣ�";
            cin >> data;
            InsElem(&L, data, local);
            
            do {
                system("cls");
                cout << "***************************" << endl;
                cout << " ��1����: ";
                cin >> number;
            } while (number != 1);
            system("cls");
            break;

        case 5:
            system("cls");
            cout << "***************************" << endl;
            cout << "������Ҫɾ����λ�ã�";
            cin >> local;
            while (local <= 0 || local > L.Length) {
                system("cls");
                cout << "***************************" << endl;
                cout << "��������ȷ��Ҫɾ����λ�ã�";
                cin >> local;
            }
            DelElem(&L, local);
            
            do {
                system("cls");
                cout << "***************************" << endl;
                cout << " ��1����: ";
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
 * @brief ����һ��˳���
 * 
 * @param L :˳���
 * @param n :������
 */
void CreateList (LinearList* L, int n) {
    if (n <= 0 || n > MAXLEN) {
        cout << "��������ȷ��������" << endl;
        return;
    } else {
        int i = 0;
        for (i = 0; i < n; i++) {
            cout << "�������" << i+1 << "������:";
            cin >> L->data[i];
        }
        L->Length = n;
    }
}

/**
 * @brief ���˳����ȫ������
 * 
 * @param L :˳���
 */
void ShowList (LinearList* L) {
    int i = 0;
    for (i = 0; i < L->Length; i++) {
        cout << "��" << i+1 << "������Ϊ:" << L->data[i] << endl;
    }
}

/**
 * @brief ���˳����nλ������
 * 
 * @param L :˳���
 * @param n :λ��
 * @return int ��Ӧλ������
 */
DataType GetElem (LinearList* L, int n) {
    if (n <= 0 || n > L->Length) {
        cout << "��������ȷ��������" << endl;
        return -999;
    } else {
        return L->data[n-1];
    }
}

/**
 * @brief ָ��λ�ò���һ������
 * 
 * @param L :˳���
 * @param newdata :�µ�����
 * @param n :���뵽��һλ
 */
void InsElem (LinearList* L, DataType NewData, int n) {
    if (L->Length >= MAXLEN) {
        cout << "˳�������" << endl;
        return;
    }
    if (n <= 0 || n > L->Length + 1) {
        cout << "��������ȷ��������" << endl;
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
 * @brief ɾ��ָ��λ�õ�����
 * 
 * @param L :˳���
 * @param n :ɾ����һλ
 */
void DelElem (LinearList* L, int n) {
    if (n <= 0 || n > L->Length) {
        cout << "��������ȷ��������" << endl;
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