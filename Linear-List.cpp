//线性表的链式存储结构

#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;
struct sNode
{
	ElemType data;
	sNode* next;
};
//初始化链表
void InitList(sNode*& HL)
{
	HL = nullptr;
}
//得到线性表中的pos个位置上元素的值
ElemType GetElemList(sNode* HL, int pos)
{
	sNode* p = HL;
	int i = 0;
	while (p != nullptr)
	{
		i++;
		if (i == pos)break;
		p = p->next;
	}
	if (p != nullptr)return p->data;
	cout << "pos不在有效范围内" << endl;
	exit(1);
}
//在线性表中查找第一个满足条件的元素，该元素值由引用返回
bool FindFirstList(sNode* HL, ElemType& item)
{
	sNode* p = HL;
	while (p != nullptr)
	{
		if (p->data == item)
		{
			item = p->data;
			return true;
		}
		p = p->next;
	}
	if (p == nullptr)
		cout << "您所找的元素不在范围内" << endl;
	return false;
}
//修改线性表中的第一个指定元素
void ModifyList(sNode*& HL, ElemType item1,ElemType item2)
{
	sNode* p = HL;
	while (p != nullptr)
	{
		if (p->data == item1)
		{
			p->data = item2;
			break;
		}
		p = p->next;
	}
	if (p == nullptr)
		cout << "您所查找的元素不在范围内" << endl;
}
//向链表中插入一个元素
//说明：下面是在有序单链表中进行的插入
void OrderInsertList(sNode*& HL, ElemType item)
{
	sNode* np = new sNode;
	if (!np)
	{
		cout << "存储空间不足" << endl;
		exit(1);
	}
	np->data = item;
	if (HL == nullptr || item < HL->data)
	{
		np->next = HL;
		HL = np;
		return;
	}
	sNode *fp = HL, *lp = nullptr;
	while (fp != nullptr)
	{
		if (item < fp->data)break;
		lp = fp;
		fp = fp->next;
	}
	np->next = fp;
	lp->next = np;
}
//从线性表中删除一个元素
void DeleteList(sNode*& HL, ElemType item)
{
	sNode* p = HL ,*q=nullptr;
	while (p != nullptr)
	{
		if (p->data == item)break;
		q = p;
		p = p->next;
	}
	if (p != nullptr)
	{
		q->next = p->next;
		delete p;
	}
	cout << "欲删除的元素不在范围内" << endl;
}
//判断线性表是否为空
bool EmptyList(sNode* HL)
{
	return HL == nullptr;
}
//求出线性表的长度
int LengthList(sNode* HL)
{
	int i = 0;
	sNode* p = HL;
	while (p != nullptr)
	{
		i++;
		p = p->next;
	}
	return i;
}
//遍历输出线性表
void OutputList(sNode* HL)
{
	sNode* p = HL;
	while (p != nullptr)
	{
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;
}
//对线性表的值进行排序
sNode* SortList(sNode* HL)
{
	sNode* HLX;
	InitList(HLX);
	sNode* p = HL;
	while (p != nullptr)
	{
		OrderInsertList(HLX, p->data);
		p = p->next;
	}
	return HLX;
}
//清除线性表中的所有元素
void ClearList(sNode*& HL)
{
	sNode* p = HL,*q=nullptr;
	while (p != nullptr)
	{
		q = p->next;
		delete p;
		p = q;
	}
	HL = nullptr;
}


int main()
{
	sNode* ffg;
	InitList(ffg);
    int	a[6] = { 56,45,85,23,112,12,};
	for(int i=0;i<6;++i)
	   OrderInsertList(ffg, a[i]);
	OutputList(ffg);
	DeleteList(ffg, 45);
	OutputList(ffg);
	cout<<LengthList(ffg)<<endl;
	ModifyList(ffg, 85, 850);
	OutputList(ffg);
	a[0]=GetElemList(ffg, 3);
	cout << a[0]<<endlS;
	system("pause");
	return 0;
}
