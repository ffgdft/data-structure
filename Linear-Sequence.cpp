//线性表的顺序存储结构
#include <iostream>
using namespace std;
typedef int ElemType;
//线性表的存储结构
//Statement:线性表的存储结构包含数组表头指针，当前长度和最大长度；
struct ListSq
{
	ElemType *list;
	int len;
	int MaxSize;
};
//初始化线性表
void InitList(ListSq& L)
{
	L.list = nullptr;
	L.len = L.MaxSize = 0;
}
//初始化重载的版本，带有动态存储分配
//Statement：线性表带动态存储分配的初始化根据提供的最大长度在内存中分配存储，之前检验所给最大值是否合法，之后检验动态内存分配是否成功；
void InitList(ListSq& L,int ms)
{
	if (ms <= 0) { cout << "ms为非法值！" << endl;exit(1); }
	L.MaxSize = ms;
	L.list = new ElemType[ms];
	if(!L.list)
	{
		cerr << "动态内存分配失败" << endl;exit(1);
	}
	L.len = 0;
}
//得到线性表第pos个元素的值
//Statement：得到线性表某个位置的值其实就是利用下标操作，之前检验下标是否有效；
ElemType GetElemList(ListSq& L, int pos)
{
	if (pos<1 || pos>L.len)
	{
		cout << "所给元素下标无效！" << endl;
		exit(1);
	}
	return L.list[pos - 1];
}
//从线性表中查找第一个元素，返回该元素位置
//1.顺序查找 2.二分查找法
//Stetement:这里仅说明二分查找法，定义high、low和mid，每次判断所查找数据是否与mid值相等，不等则判断相对大小并修改high或low的值；
int BinFindList(ListSq& L, ElemType item)
{
	int low = 0, high = L.len - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (item == L.list[mid])return mid;
		else if (item < L.list[mid])high = mid-1;
		else low = mid+1;
	}
	return -1;
}
//修改线性表中的第一个指定元素
//Statement：首先遍历查找，找到后即修改；
bool ModifyList(ListSq&L, const ElemType& item)
{
	for(int i=0;i<L.len;++i)
		if (L.list[i] == item)
		{
			L.list[i] = item;
			return true;
		}
	return false;
}
//向线性表中插入一个元素
//说明：1.按所给元素位置插入
//Statement：首先判断所给位置是否合法，其次判断空间是否用光，是则重新分配两倍大小的内存，判断内存分配是否成功，成功则将原来空间中的元素放入新空间中并销毁原空间，最后按照逆序将待插入后的数据后移一个，最终插入；
void NumberInsertList(ListSq& L, int num, ElemType item)
{
	if (num<1 || num>L.len + 1)
	{
		cout << "所给插入元素的位置编号无效" << endl;
		exit(1);
	}
	if (L.len == L.MaxSize)
	{
		ElemType *p = new ElemType[2 * L.MaxSize + 1];
		if (!p)
		{
			cout << "存储空间用光" << endl;
			exit(1);
		}
		for (int i = 0;i < L.len;++i)
			p[i] = L.list[i];
		delete[]L.list;
		L.list = p;
		L.MaxSize = 2 * L.MaxSize + 1;
	}
	for (int i = L.len - 1;i >= num - 1;--i)
		L.list[i + 1] = L.list[i];
	L.list[num - 1] = item;
	L.len++;
}
//说明：2.按照元素值进行有序插入
//Statement：按照元素值进行有序插入，首先判断空间是否已满...，查询有序表中可插入的位置，后移其后的元素，最后插入；
void OrderIndertList(ListSq& L, ElemType item)
{
	if (L.len == L.MaxSize)
	{
		cout << "线性表空间满" << endl;
		exit(1);
	}
	int i, j;
	for ( i = 0;i < L.len;++i)
		if (L.list[i] > item)break;
	for (j = L.len - 1;j >= i;--j)
		L.list[j + 1] = L.list[j];
	L.list[i] = item;
	L.len++;
}
//从线性表中删除满足条件的第一个元素
//Statement：从线性表中删除满足条件的第一个元素，遍历后，若存在，则将其后位置的元素向前覆盖即可；
bool DeleteList(ListSq& L, ElemType item)
{
	int i, j;
	for (i = 0;i < L.len;++i)
		if (item == L.list[i])break;
	if (i == L.len)return false;
	for (j = i+1 ;j < L.len;++j)
		L.list[j-1] = L.list[j];
	L.len--;
	return true;
}
//判断线性表是否为空
bool EmptyList(ListSq& L)
{
	return L.len == 0;
}
//求出线性表的长度
int LengthList(ListSq& L)
{
	return L.len;
}
//遍历输出线性表
void OutputList(ListSq& L)
{
	for (int i = 0;i < L.len;++i)
		cout << L.list[i] << "  ";
	cout << endl;
}
//清除线性表中的所有元素
//Statement：判断线性表是否为空，不为空则删除其中的数组并置空指针，最后令数据元素为0；
void ClearList(ListSq& L)
{
	if (L.list != nullptr)
	{
		delete[]L.list;
		L.list = nullptr;
		L.len = L.MaxSize = 0;
	}
}
int main()
{
	system("pause");
	return 0;
}
