//栈的链接存储结构
#include <iostream>
using namespace std;
typedef int ElemType;
struct sNode
{
	ElemType data;
	sNode* next;
};
//初始化堆栈
void InitStack(sNode*& HS)
{
	HS->next = nullptr;
}
//向链栈中插入一个元素
void Push(sNode*& HS,const ElemType& item)
{
	sNode* np = new sNode;
	if (!np)
	{
		cout << "存储空间不足" << endl;
		exit(1);
	}
	np->data = item;
	np->next = HS->next;
	HS = np;
}
//从链栈中删除一个元素并返回它
ElemType Pop(sNode*& HS)
{
	if (HS == nullptr)
	{
		cout << "堆栈中没有元素" << endl;
		exit(1);
	}
	sNode* p = HS;
	HS = HS->next;
	ElemType temp = p->data;
	delete p;
	return temp;
}
//读取栈顶元素
ElemType Peek(sNode* HS)
{
	if (HS == nullptr)
	{
		cout << "栈中没有元素" << endl;
		exit(1);
	}
	return HS->data;
}
//检查链栈是否为空
bool EmptyStack(sNode* HS)
{
	return HS == nullptr;
}
//清除链栈为空
void ClearStack(sNode*& HS)
{
	sNode* p = HS,*q=nullptr;
	while (p != nullptr)
	{
		q = p->next;
		delete p;
		p = q;
	}
	HS = nullptr;
}
int main()
{
	system("pause");
	return 0;
}
