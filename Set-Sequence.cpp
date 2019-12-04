 //集合的顺序存储结构和操作实现
//集合中，数据没有逻辑关系
#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;

//固定大小的集合，集合和元素数目
const int Maxsize = 20;
struct SetS
{
	ElemType set[Maxsize];
	int len;
};

//对存储集合的数组空间采用动态分配，可以采用以下的数据结构
struct SetSq
{
	ElemType *set;
	int len;
	int MaxSize;
};

//************对集合的操作***************//
//1.初始化集合为空
void InitSet(SetSq& S)
{
	S.set = nullptr;
	S.len =S.MaxSize= 0;
}
void InitSet(SetSq& S, int ms)
{
	if (ms <= 0) { cout << "ms值非法" << endl;exit(1);}
	S.MaxSize = ms;
	S.set = new ElemType[ms];
	if (!S.set)
	{
		cout << "存储空间用光" << endl;
		exit(1);
	}
	S.len = 0;
}
//2.向集合中插入一个元素
//说明：向集合中添加一个元素，首先检查集合中有没有该元素；其次对集合可用空间进行检测（len==maxsize？）；对元素进行插入
bool InsertSet(SetSq& S, ElemType item)
{
	for (int i = 0;i < S.len;++i)
		if (item == S.set[i])return false;//集合中不能有重复的元素
	if (S.len == S.MaxSize)
	{
		ElemType *p = new ElemType[2*S.MaxSize+1];//空间增加1倍加1
		if (!p)
		{
			cout << "存储空间用光" << endl;
			exit(1);
		}
		for (int i = 0;i < S.len;++i)
			p[i] = S.set[i];
		delete []S.set;
		S.set = p;
		S.MaxSize = 2 * S.MaxSize + 1;
	}
	S.set[S.len] = item;
	S.len++;
	return true;
}
//从集合中删除一个元素
//说明：从集合中删除一个元素，遍历的过程中如果相等即退出循环；然后将集合中最后的那个元素覆盖找到的那个元素
bool DeleteSet(SetSq& S, ElemType item)
{
	int i;
	for ( i = 0;i < S.len;++i)
		if (item==S.len)break;
	if (i < S.len)
	{
		S.set[i] = S.set[S.len - 1];
		S.len--;
		return true;
	}
	else
		return false;
}
//从集合中查找元素
//说明：从集合中查找元素，找到后由传入参数的引用带回
bool FindSet(SetSq& S, ElemType& item)
{
	int i;
	for ( i = 0;i < S.len;++i)
		if (S.set[i] == item)break;
	if (i < S.len)
	{
		item = S.set[i];
		return true;
	}
	else 
		return false;
}
//修改集合中的一个指定元素
bool ModifySet(SetSq& S, const ElemType& item)
{
	int i;
	for ( i = 0;i < S.len;++i)
		if (item == S.set[i])break;
	if (i < S.len)
	{
		S.set[i] = item;
		return true;
	}
	else
		return false;
}
//判断一个元素是否属于集合
bool InSet(SetSq& S, const ElemType& item)
{
	for (int i = 0;i < S.len;++i)
		if (item == S.set[i])return true;
	return false;
}
//判断集合是否为空
bool EmptySet(SetSq& S)
{
	return S.len == 0;
}
//求出集合中元素的个数
int LengthSet(SetSq& S)
{
	return S.len;
}
//输出集合中所有的元素
void OutputSet(SetSq& S)
{
	for (int i = 0;i < S.len;++i)
		cout << S.set[i]<<"  ";
	cout << endl;
}
//求两个集合的并集
//说明：使用重载的初始化版本传入S1对S进行初始化，利用循环将S2中元素插入到S1中
SetSq UnionSet(SetSq& S1, SetSq& S2)
{
	SetSq S;
	InitSet(S, S1.len);
	for (int i = 0;i < S1.len;++i)
		S.set[i] = S1.set[i];
	S.len = S1.len;
	for (int i = 0;i < S2.len;++i)
		InsertSet(S, S2.set[i]);
	return S;
}
//求两个集合的交集
//说明：利用两个集合中较短的集合初始化一个新的集合，然后在循环中依次查找一个集合中元素是否在另一个集合中也存在
SetSq InterseSet(SetSq& S1, SetSq& S2)
{
	SetSq S;
	int len;
	if (S1.len < S2.len)len = S1.len;else len = S2.len;
	InitSet(S, len);
	for (int i = 0;i < S2.len;++i)
	{
		bool en = FindSet(S1, S2.set[i]);
		if (en)
		{
			InsertSet(S, S2.set[i]);
			S.len++;
		}
	}
	return S;
}
//按元素的值或关键字对集合排序
//说明：使用插入排序法
void SortSet(SetSq& S)
{
	int  j;
	ElemType x;
	for (int i = 1;i < S.len;++i)
	{
		x = S.set[i];
		for (int j = i - 1;j >= 0;j--)
		{
			if (x < S.set[j])
			{
				S.set[j + 1] = S.set[j];
				S.set[j] = x;
			}
			else break;

		}
	}
}
//清除集合中的所有元素
void ClearSrt(SetSq& S)
{
	if (S.set != nullptr)
	{
		delete[]S.set;
		S.set = nullptr;
		S.len = S.MaxSize = 0;
	}
}
int main()
{
	SetSq S;
	InitSet(S, 20);
	for (int i = 5;i >0;--i)
		InsertSet(S, (i*2+1));
	OutputSet(S);
	SortSet(S);
	OutputSet(S);
	system("pause");
	return 0;
}
