//由于链表不需要指定其大小，只会动态地增加node，因此其数据结构比较简单
/************************ADT SET is****************************
Data:  
    集合S，假定使用sNode表示的存储类型
Operation:
    void InitSet(sNode*& Head);  //初始化
	void InsertSet(sNode*& Head,ElemType item);  //插入
	void DeleteSet(sNode*& Head,ElemType item);  //删除
	void FindSet(sNode* Head,ElemType& item);  //查找并带回
	bool ModifySet(sNode*& Head, ElemType item,cosnt ElemType later)  //修改
	bool InSet(sNode* Head,ElemType item);  /判断是否在集合中
	bool Empty(sNode* Head);  //判断集合是否为空
	int LengthSet(sNode* Head);  //集合的长度
	void OutputSet(sNode* Head);  //输出集合元素
	sNode* UnionSet(sNode* Head1,sNode* Head2);  //求集合的并集
	sNode* InterseSet(sNode* Head1,sNode* Head2);  //求集合的交集
	void SortSet(sNode* Head);  //排序
	void ClearSet(sNode* Head);  //清空集合
**************************end SET ****************************/

#include<iostream>
using namespace std;
typedef int ElemType;
//单链表中的存储节点定义如下：
struct sNode
{
	ElemType data;
	sNode* next;
};
//初始置空集合，即置表头指针为空
void InitSet(sNode*& Head)//需要带回对实参的修改
{
	Head = nullptr;
}
//向集合中插入一个元素
bool InsertSet(sNode*& Head, ElemType item)//可能修改头指针并且需要带回
{
	sNode* p = Head;
	while (p != nullptr)
	{
		if (p->data == item)return false;
		p = p->next;
	}
	if (p == nullptr)
	{
		sNode* np = new sNode;
		np->data = item;
		np->next = Head;
		Head = np;
	}
	return true;
}
//从集合中删除一个元素
bool DeleteSet(sNode*& Head, ElemType item)
{
	sNode *p = Head,*q=Head;
	while (p!=nullptr)
	{
		if (p->data == item)break;
		q = p;
		p = p->next;
	}
	if (p == nullptr)
	{
		cout << "无法删除 ！因为集合中没有该元素" << endl;
		return false;
	}
	else
	{
		q->next = p->next;
		delete p;
	}
	return true;
}
//从集合中查找一个元素
bool FindSet(sNode* Head, ElemType& item)
{
	sNode* p = Head;
	while (p != nullptr)
	{
		if (p->data == item)
		{
			p->data = item;
			return true;
		}
		p = p->next;
	}
		return false;
}
//修改集合中的一个指定元素
bool ModifySet(sNode*& Head, ElemType item, const ElemType later)
{
	sNode* p = Head;
	while (p != nullptr)
	{
		if (p->data == item)break;
		p=p->next;
	}
	if (p != nullptr)
	{ 
		p->data = later;
		return true;
	}
	return false;
}
//判断一个元素是否属于集合
bool InSet(sNode* Head, ElemType item)
{
	sNode* p = Head;
	while (p != nullptr)
	{
		if (p->data == item)return true;
		p = p->next;
	}
	return false;
}
//判断集合是否为空
bool EmptySet(sNode* Head)
{
	return Head == nullptr;
}
//求出集合中元素个数
int LengthSet(sNode* Head)
{
	int sum = 0;
	sNode* p = Head;
	while (p != nullptr)
	{
		sum++;
		p=p->next;
	}
	return sum;
}
//输出集合中的元素
void OutputSet(sNode* Head)
{
	sNode* p = Head;
	while (p != nullptr)
	{
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;
}
//求两个集合的并集
sNode* UnionSet(sNode* Head1, sNode* Head2)
{
	sNode* Head=nullptr;
	sNode* p = Head1;
	while (p != nullptr)
	{
		sNode* np = new sNode;
		np->data = p->data;
		np->next=Head;
		Head = np;
		p = p->next;
	}
	p = Head2;
	while (p != nullptr)
	{
		InsertSet(Head, p->data);
		p=p->next;
	}
	return Head;
}
//求两个集合的交集
//说明：由于链表在插入元素时才分配存储节点，因此，不需要提前分配长度
sNode* InterseSet(sNode* Head1, sNode* Head2)
{
	sNode* Head=nullptr;
	sNode* p = Head2;
	ElemType x;
	while (p != nullptr)
	{
		x = p->data;
		bool b = FindSet(Head1, x);
		if (b)InsertSet(Head, x);
		p = p->next;
	}
	return Head;
}
//按元素的值或关键字对集合进行排序
//说明：建立一个空的链表，首先判断头是否为空，为空则插入到头部；其次判断元素是否比头部元素小，是的话插入到头；最后，利用指针遍历的方式插入到合适的位置上
void SortSet(sNode* &Head)
{
	sNode* Headx = nullptr;
	sNode* p = Head;
	while (p != nullptr)
	{
		sNode *q = p;
		p = p->next;
		if (Headx == nullptr)
		{
			q->next = nullptr;
			Headx = q;
		}
		else if (q->data < Headx->data)
		{
			q->next=Headx;
			Headx = q;
		}
		else
		{
			sNode* ap = Headx, *np = ap->next;
			while (np != nullptr)
			{
				if (q->data < np->data)break;
				else {
					   ap = np;
					   np = np->next;
				     }
			}
			q->next = np;
			ap->next= q;
		}
	}
	Head = Headx;
}
//清除集合中所有元素，并释放内存
void ClearSet(sNode*& Head)
{
	sNode* p = Head, *q;
	while (p != nullptr)
	{
		q = p->next;
		delete p;
		p = q;
	}
	Head = nullptr;
}
int main()
{
	int a[5] = { 12,65,23,89,52 };
	sNode* Link;
	InitSet(Link);                 //初始化
	for (int i=0;i<5;++i)
		InsertSet(Link,a[i]);      //插入
	OutputSet(Link);               //输出
	SortSet(Link);                 //排序
	cout << "排序后输出为:  ";
	OutputSet(Link);               //输出
	int x = 2;
	FindSet(Link,x);               //查找
	DeleteSet(Link, 5);            //删除
	ModifySet(Link, 89, 77);       //修改
	if (InSet(Link, 77))           //查询
	   cout << "查询的元素在集合中" << endl;
	int num = LengthSet(Link);     //集合元素数目
	cout << "集合中元素数目为：  " << num << endl;
	cout << "集合中元素为:  ";
	OutputSet(Link);               //输出
	ClearSet(Link);                //清空
	if(EmptySet(Link))             //判断是否为空
		cout<<"集合元素为空"<<endl;

	sNode *a1, *a2;
	int b1[6] = { 12,65,23,89,52,56 };
	int b2[9] = { 30,65,44,91,52,56,0,0,0 };
	InitSet(a1);
	InitSet(a2);
	for (auto i : b1)
		InsertSet(a1, i);
	for (auto i : b2)
		InsertSet(a2, i);
	sNode* re1 = UnionSet(a1, a2);
	sNode* re2 = InterseSet(a1, a2);
	cout << "两个集合的并集为： ";
	OutputSet(re1);
	cout << "两个集合的交集为： ";
	OutputSet(re2);
	system("pause");
	return 0;
}
