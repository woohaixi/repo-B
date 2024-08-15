#include<iostream>
using namespace std;
#define MAXSIZE 1000
#define ERROR -1
#define NotFind -1

typedef struct
{
	int* data;
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
	if (i < 1 || i>L.length)
	{
		return ERROR;
	}
	int& e = L.data[i - 1];
	return e;
}

int LocateList(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			cout << "Elem Exist" << endl;
			return i + 1;
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

	if (L.length == MAXSIZE || i < 1 || i>L.length + 1)
	{
		cout << "fail to insert" << endl;
	}
	else
	{
		for (int j = L.length - 1; j >= i - 1; j--)
		{
			L.data[j + 1] = L.data[j];
		}
		L.length++;
		L.data[i - 1] = e;
	}
}

void DeleteList(SqList& L, int i)
{
	if (!IsEmptyList(L) && i >= 1 && i <= L.length)
	{
		for (int j = i; j < L.length; j++)
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

void CreateList(SqList& L, int len)
{
	L.length = len;
	if (len > 0)
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

void Plus(SqList &La, SqList &Lb, SqList& Lc)
{
	int* pa, * pb, * pc;
	pa = La.data;
	pb = Lb.data;
	pc = Lc.data;
	int lena = La.length;
	int lenb = Lb.length;
	Lc.length = lena > lenb ? lena : lenb;//取最长的多项式
	int* pa_last = La.data + lena-1;
	int* pb_last = Lb.data + lenb-1;
	while (pa<=pa_last && pb<= pb_last)//等号一定要取到，不是!=
	{
		*pc++ =( *pa ++)+ (*pb++);
	}
	while (pa<= pa_last)
	{
		*pc++ = *pa++;
	}
	while (pb<=pb_last)
	{
		*pc++ = *pb++;
	}
}

void Minus(SqList& La, SqList& Lb, SqList& Lc)
{
	int* pa, * pb, * pc;
	pa = La.data;
	pb = Lb.data;
	pc = Lc.data;
	int lena = La.length;
	int lenb = Lb.length;
	Lc.length = lena > lenb ? lena : lenb;//取最长的多项式
	int* pa_last = La.data + lena - 1;
	int* pb_last = Lb.data + lenb - 1;
	while (pa <= pa_last && pb <= pb_last)//等号一定要取到，不是!=
	{
		*pc++ = (*pa++)-(*pb++);
	}
	while (pa <= pa_last)
	{
		*pc++ = *pa++;
	}
	while (pb <= pb_last)
	{
		*pc++ = *pb++;
	}
}

void Multiply(SqList La, SqList Lb, SqList& Lc)
{

}

int main()
{
	SqList La,Lb,Lc,Ld;

	InitList(La);
	InitList(Lb);
	InitList(Lc);
	InitList (Ld);

	CreateList(La,5);
	CreateList(Lb,7);

	Plus(La, Lb, Lc);
	Minus(La, Lb, Ld);

	PrintList(Lc);
	PrintList(Ld);
	return 0;
}