//栈的顺序存储结构，对存储栈的数组空间进行动态分配
#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;
//栈的数据结构类型，top的初值为-1，压入加1，弹出减1
struct StackSq
{
	ElemType* stack;
	int top;
	int MaxSize;
};
//初始化栈S为空
void InitStack(StackSq& S)
{
	S.stack = nullptr;
	S.MaxSize = 0;
	S.top = -1;
}
//带有动态内存分配的初始化栈
void InitStack(StackSq& S, int ms)
{
	if (ms < 0)
	{
		cout << "栈大小值非法" << endl;
		exit(1);
	}
	S.stack = new ElemType[ms];
	if (!S.stack)
	{
		cout << "存储空间不足" << endl;
		exit(1);
	}
	S.MaxSize = ms;
	S.top = -1;
}
//元素item进栈，即插入到栈顶
void Push(StackSq& S, ElemType item)
{
	if (S.top == S.MaxSize - 1)
	{
		cout << "栈空间不足,稍等..." << endl;
		ElemType* p = new ElemType[2 * S.MaxSize + 1];
		if (!p)
		{
			cout << "存储空间不足" << endl;
			exit(1);
		}
		for (int i = 0;i <= S.top;i++)
			p[i] = S.stack[i];
		delete[]S.stack;
		S.stack = p;
		S.MaxSize = 2 * S.MaxSize + 1;
	}
	S.top++;
	S.stack[S.top] = item;
}
//删除栈顶元素并但返回
ElemType Pop(StackSq& S)
{
	ElemType i;
	if (S.top == -1)
	{
		cout << "栈中无元素" << endl;
		exit(1);
	}
	i = S.stack[S.top];
	S.top--;
	return i;
}
//读取栈顶元素的值
ElemType Peek(StackSq& S)
{
	if (S.top == -1)
	{
		cout << "栈中无元素" << endl;
		exit(1);
	}
	return S.stack[S.top];
}
//判断栈是否为空
bool EmptyStack(StackSq& S)
{
	return S.top == -1;
}
//清除栈中所有元素
void ClearStack(StackSq& S)
{
	if (S.top != -1)
	{
		delete[]S.stack;
		S.stack = nullptr;
		S.MaxSize = 0;
		S.top = -1;
	}
}
int main()
{
	StackSq s;
	InitStack(s, 5);
	int a[8] = { 3,8,5,17,9,30,15,22 };
	for (int i = 0;i < 8;++i)
		Push(s, a[i]);
	cout << Pop(s)<<"  ";
	Push(s, 68);
	cout << Peek(s)<<"  ";
	cout << Pop(s)<<"  ";
	while (!EmptyStack(s))
		cout <<Pop(s)<<" ";
	ClearStack(s);
	if (EmptyStack)
		cout << "栈中元素已空" << endl;
	system("pause");
	return 0;
}






