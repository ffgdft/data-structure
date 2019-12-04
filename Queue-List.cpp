//队列的链式存储结构也是通过由节点构成的单链表实现的；
#include<iostream>
using namespace std;
typedef int ElemType;
struct sNode
{
	ElemType data;
	sNode* next;
};
struct QueueLk
{
	sNode* front;
	sNode* rear;
};
//初始化队列
void InitQueue(QueueLk& HQ)
{
	HQ.front = HQ.rear = nullptr;
}
//向链队中插入一个元素
void InsertQueue(QueueLk& HQ, ElemType item)
{
	sNode* np = new sNode;
	if (!np)
	{
		cout << "存储空间不足" << endl;
		exit(1);
	}
	np->data = item;
	np->next = nullptr;
	if (HQ.rear == nullptr)
		HQ.front = HQ.rear = np;
	else
		HQ.rear=HQ.rear->next = np;
}
//从链队中删除一个元素
ElemType DeleteQueue(QueueLk& HQ)
{
	if (HQ.front == nullptr)
	{
		cout << "队列中无元素，删除失败" << endl;
		exit(1);
	}
	ElemType temp = HQ.front->data;
	sNode* p = HQ.front;
	HQ.front = p->next;
	if (HQ.front == nullptr)HQ.rear = nullptr;
	delete p;
	return temp;
}
//读取队首元素
ElemType PeekQueue(QueueLk& HQ)
{
	if (HQ.front == nullptr)
	{
		cout << "队列中无元素，无法读取" << endl;
		exit(1);
	}
	return HQ.front->data;
}
//检查链表是否为空
bool EmptyQueue(QueueLk& HQ)
{
	return HQ.front == nullptr;  //队尾也可以
}
//清除链队的所有元素，使之为空
void ClearQueue(QueueLk& HQ)
{
	sNode* p = HQ.front;
		while(p!= nullptr)
		{
			HQ.front = p->next;
			delete p;
			p = p->next;
		}
		HQ.rear = nullptr;
}

int  main()
{
	system("pause");
	return 0;
}
