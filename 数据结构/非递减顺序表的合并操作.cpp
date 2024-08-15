#include<iostream>
using namespace std;
#define MAXSIZE 1000
#define ERROR -1
#define NotFind -1

typedef struct
{
	int *data;
	int length;
}SqList;

void InitList(SqList& L)
{
	L.data = new int[MAXSIZE];
	L.length = 0;
}

bool IsEmptyList(SqList L)
{
	if (!L.length)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ClearList(SqList& L)
{
	L.length = 0;
}

int GetElemList(SqList L, int i)
{
	if (i < 1||i>L.length)
	{
		return ERROR;
	}
	int& e = L.data[i-1];
	return e;
}

int LocateList(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			cout << "Elem Exist" << endl;
			return i+1;
		}
	}
	return NotFind;
}

void ChangeElemValList(SqList& L, int i, int e)
{
	L.data[i - 1] = e;
}

void InsertList(SqList& L, int i, int e)
{

	if (L.length == MAXSIZE || i < 1||i>L.length+1)
	{
		cout << "fail to insert" << endl;
	}
	else
	{ 
		for (int j = L.length - 1; j >= i-1; j--)
		{
			L.data[j+1] = L.data[j];
		}
		L.length++;
		L.data[i - 1] = e;
	}
}

void DeleteList(SqList& L, int i)
{
	if (!IsEmptyList(L)&&i>=1&&i<=L.length)
	{
		for (int j = i; j< L.length; j++)
		{
			L.data[j - 1] = L.data[j];
		}
		L.length--;
	}
	else
	{
		cout << "cannot delete" << endl;
	}
}

void CreateList(SqList& L,int len)
{
	L.length = len;
	if(len>0)
	{ 
		cout << "请输入你要加入的" << len << "个数据" << endl;
		for (int i = 0; i < len; i++)
		{
			cin >> L.data[i];
		}
	}
	else
	{
		cout << "error" << endl;
	}
}

void PrintList(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		cout << L.data[i] << " ";
	}
	cout << endl;
}

void Sort(int* arr, int size)
{
	int tmp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void MergeList(SqList L1, SqList L2,SqList &L3)
{
	int* p1 = L1.data;
	int* p2 = L2.data;
	L3.length = L1.length + L2.length;
	L3.data = new int[L3.length];
	int* p3 = L3.data;
	int* p1_Last = L1.data + L1.length-1;
	int* p2_Last = L2.data + L2.length-1;
	while (p1 <= p1_Last && p2 <= p2_Last)
	{
		if (*p1 <= *p2)
		{
			*p3++ = *p1++;
		}
		else
		{
			*p3++ = *p2++;
		}
	}
	while (p1 <=p1_Last)
	{
		*p3++ = *p1++;
	}
	while (p2 <=p2_Last)
	{
		*p3++ = *p2++;
	}
}

int main()
{
	SqList L1, L2,L3;
	InitList(L1);
	InitList(L2);
	InitList(L3);
	CreateList(L1, 3);
	CreateList(L2, 6);
	int len1 = L1.length;
	int len2=L2.length;
	Sort(L1.data, len1);
	Sort(L2.data, len2);
	PrintList(L1);
	PrintList(L2);
	MergeList(L1, L2, L3);
	PrintList(L3);
	return 0;
}