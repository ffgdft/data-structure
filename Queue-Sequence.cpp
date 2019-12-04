//队列的顺序存储结构
//说明：这里需要注意的是，由于采用的是循环的队列，因此，不管是队列空还是队列满，Q.front==Q.rear 。插入时空间不足需要注意这一点
//Statement：队列的front是指向队首元素的前一个位置，rear直接指向队列的最后一个元素
#include<iostream>
#include<cstdlib>
using namespace std;
//对存储队列的数组空间采用动态分配
typedef int ElemType;
struct QueueSq
{
	ElemType* queue;
	int front, rear, len;
	int MaxSize;
};
//初始化队列
void InitQueue(QueueSq& Q)
{
	Q.queue = nullptr;
	Q.front = Q.rear = 0;
	Q.MaxSize = 0;
	Q.len = 0;
}
//带有动态存储分配的队列初始化
void InitQueue(QueueSq& Q,int ms)
{
	if (ms < 0)
	{
		cout << "ms值非法" << endl;
		exit(1);
	}
	Q.queue = new ElemType[ms];
	if (!Q.queue)
	{
		cout << "存储空间不足" << endl;
		exit(1);
	}
	Q.front = Q.rear = 0;
	Q.MaxSize = ms;
	Q.len = 0;
}
//向队列插入元素
void InsertQueue(QueueSq& Q, ElemType item)
{
	if (Q.len == Q.MaxSize)
	{
		cout << "队列空间不足，请稍等..." << endl;
	    ElemType* p = new ElemType[2 * Q.MaxSize + 1];
		if (!p)
		{
			cout << "存储空间不足" << endl;
			exit(1);
		}
		int j = 1;
		for (int i = Q.front + 1;i < Q.MaxSize;++i)
			p[j++] = Q.queue[i];         //队列的前半部分           
		for (int i = 0;i <= Q.rear;++i)
			p[j++] = Q.queue[i];         //队列的后半部分
		
		Q.front = 0;
		Q.rear = Q.len;
		Q.MaxSize = 2 * Q.MaxSize + 1;
		delete[] Q.queue;
		Q.queue = p;
	}
	Q.rear = (Q.rear + 1) % Q.MaxSize;
	Q.queue[Q.rear] = item;
	Q.len++;
}
//从队列中删除元素并返回
ElemType DeleteQueue(QueueSq& Q)
{
	if (Q.len == 0)
	{
		cerr << "队列已空，无法删除" << endl;
		exit(1);
	}
	Q.front = (Q.front + 1) % Q.MaxSize;
	Q.len--;
	return Q.queue[Q.front];
}
//读取队首元素，不改变队列状态
ElemType OutQueue(QueueSq& Q)
{
	if (Q.len == 0)
	{
		cerr << "队列已空，无法读取" << endl;
		exit(1);
	}
	return Q.queue[(Q.front + 1)%Q.MaxSize];
}
//检查一个队列是否为空
bool EmptyQueue(QueueSq& Q)
{
	return Q.len == 0;
}
//清除一个队列，并释放其存储空间
void ClearQueue(QueueSq& Q)
{
	if (Q.queue != nullptr)
	{
		delete[]Q.queue;
		Q.queue = nullptr;
		Q.len = Q.MaxSize = Q.rear = Q.front = 0;
	}
}
//自己加的测试插入的程序
void OutputQueue(QueueSq& Q)
{
	for (int i = 0;i < Q.MaxSize;++i)
		cout << Q.queue[i] << "  ";
	cout << endl;
}
//经过测试，当存储满时，分配更大的存储空间时，插入顺序又得到了矫正
int main()
{
	QueueSq k;
	InitQueue(k, 5);
	int a[4] = { 5,9,8,2 };
	int b[2] = { 11,13 };
	for (int i = 0;i < 4;++i)
		InsertQueue(k, a[i]);
	OutputQueue(k);
	for (int i = 0;i < 2;++i)
		InsertQueue(k, b[i]);
	OutputQueue(k);
	for (int i = 0;i < 2;++i)
		cout << DeleteQueue(k) << "  ";
	cout << endl;
	OutputQueue(k);//存储空间并不会真的被删除，而是我们的程序中使用不到而已；
	cout << k.queue[(k.front + 1) % k.MaxSize]<<"  "<<k.queue[k.rear]<<"  "<<k.len;
	cout << endl;
	InsertQueue(k, 52);
	OutputQueue(k); 
	system("pause");
	return 0;
}
