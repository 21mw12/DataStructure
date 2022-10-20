#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*  
	(1)���һ���㷨����һ���������ʽת��Ϊ�沨�����ʽ�������沨�����ʽ��ֵ��
        ���� #30*(40+20)/2-50#  #Ϊ�������޷�
*/
const int StackSize = 30;
char result[30];//����ת�����������ӿո�
char num;//����result����ļ���

//����һ��ջ�ṹ��
typedef struct Stack
{
	char data[StackSize];
	int top;
}StackType;


//��ջ�������룺ջ�ṹ��
char Pop(StackType *p)
{
	char x;
	if(p->top == -1) 
	{
		printf("under flow\n");
		exit(0);
	}
	x = p->data[p->top--];
	return x;
}
//��ջ����
void Push(StackType *p, char dat)
{
	if(p->top == StackSize -1)
	{
		printf("over flow\n");
		exit(0);
	}
	p->data[++p->top] = dat;
}

//Ϊ��ʱ����1����Ϊ���򷵻�0
bool Emtry(StackType *p)
{
	if(p->top == -1)
		return 1;
	return 0;
} 
//��ȡջ��������
char GetTop(StackType *p)
{
	if(p->top != -1)
		return p->data[p->top];
	return 0;
}

//�ж�������������������
bool isNumber(char op)
{
	switch(op)
	{ 	
		case ' ':
		case '(':
		case ')':
		case '+':    	
		case '-':    	
		case '*':    	
		case '/':
		case '#':		return 0;    
		default :       return 1;	 
	}
}
//��ȡ����������ȼ���1Ϊ��ߣ���ͳ�����ȼ�
int priority (char ch) {
	int value= 10; 
	switch(ch)
	{
		case '(':
		case ')':	value = 4;	break;//������������ʱ�����еķ��Ŷ��������ջ����ֱ�����������ţ������ڲ��������
		case '*':	value = 2;	break;
		case '/':	value = 2;	break;
		case '+':	value = 3;  break;
		case '-':	value = 3;	break;
		case '#':	value = 5;	break;
		default:  break;
	}
	return value;
}

/*
��������Nifix2Postfix	
��  �룺����
��  �أ���
��  �ܣ�����׺���ʽת���ɺ�׺���ʽ�����
*/
void Nifix2Postfix(char arr[])
{
	StackType* pStack = new StackType;
	pStack->top = -1;
	int i = 0;
	char ch;
	for(i=0;arr[i] != '\0';i++)
	{
		if(isNumber(arr[i]))
		{
			result[num++] = arr[i];
		}
		//���Ƕ���ʱ����Ϊ�����
		else
		{
			//�����ж��Ƿ�Ϊ�գ����Ϊ�գ�����ջ
			if(Emtry(pStack) || arr[i] == '(')
			{
				Push(pStack, arr[i]);
				continue;
			}
			if(arr[i] == '#')//��������
				break;
			if(arr[i] == ')')//��ջֱ������(
			{
				result[num++] = ' ';
				while((ch = Pop(pStack)) != '(' )//��ʼ��ջ������'('
				{
					result[num++] = ch;
					result[num++] = ' ';
				}
				continue;
			}
			result[num++] = ' ';
			//���ȼ��Ƚ�
			ch = priority(GetTop(pStack)) - priority(arr[i]);//��ȡ���ȼ��ȽϺ�Ľ������ch>0ʱ����������ȼ�����ջ����=0��ȣ�<0С��
			//���ȼ�����ջ��
			if(ch > 0)
			{
				//���ȼ������ջ
				Push(pStack, arr[i]);
			}
			//���ȼ�С�ڻ����ջ��
			else if(ch <= 0)
			{
				//Ӧ���ǳ�ջһ����Ȼ���ж����ȼ������粻Ϊ��ջ�������ж����ȼ���Ȼ��arr[i]��ջ
				while( priority(arr[i]) >= priority(GetTop(pStack)))//����������ȼ�С�ڵ���ջ��ʱ��һֱ���
				{
//					printf("%c",ch = Pop(pStack));
					result[num++] = Pop(pStack);
//					printf(" ");
					result[num++] = ' ';
				}
				Push(pStack, arr[i]);							
			}
		}
	}
	while(GetTop(pStack) != '#')
	{
		result[num++] = ' ';
		result[num++] = Pop(pStack);
	}
	for(i=0;i<num;i++)
		printf("%c",result[i]);
}

/*
�������ܣ������׺���ʽ��ֵ
���룺һ����׺���ʽ
��������
*/
int Calculate(char arr[])
{
	int i, cal[10],top=-1;
	memset(cal,0,sizeof(cal));
	for(i=0;i<num;i++)
	{
		if(isNumber(arr[i]))//�ж��Ƿ��ǲ�����������1���ǣ�������ֻ��������
		{
			//ģ����ջ
			top++;
			while(arr[i] != ' ')//��ȡһ������������ջ
			{
				cal[top] = cal[top]*10 + arr[i++]-48;
			}
		}
		else
		{
			switch(arr[i])
			{
				//ģ���ջ
				case '+':	cal[top-1] = cal[top-1] + cal[top]; cal[top--] = 0; break;
				case '-':	cal[top-1] = cal[top-1] - cal[top]; cal[top--] = 0; break;
				case '*':	cal[top-1] = cal[top-1] * cal[top]; cal[top--] = 0; break;
				case '/':	cal[top-1] = cal[top-1] / cal[top]; cal[top--] = 0; break;
				default: break;
			}
		}
	}
	return cal[0];
}


int main(void)
{
	char  express[] = "#3+1*1-3/2#";	// 30*(40+20)/2-50
	
	printf("��׺���ʽ��");
	printf("%s\n", express);
	printf("��׺���ʽ��");
	Nifix2Postfix(express);
	printf("\n");
	printf("������Ϊ��%d\n", Calculate(result));

	return 0;
}