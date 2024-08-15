#include<iostream>
using namespace std;
typedef struct Lnode
{
	int data;
	struct Lnode* next;
}Lnode,*LinkList;

void CreateList(LinkList& L,int n)
{
	L = new Lnode;
	L->next = NULL;
	Lnode* p = L;
	Lnode* q;
	for (int i = 1; i <= n; i++)
	{
		p->next = new Lnode;
		q = p->next;
		cin >> q->data;
		q->next = NULL;
		p = q;
	}
}

int GetElem(LinkList L, int i)
{
	Lnode* p = L->next;
	int j = 1;
	while (p&&j<i)
	{
		j++;
		p = p->next;
	}
	if (!p || j > i)
	{
		return -1;
	}
	int e = p->data;
	return e;
}

int LocateElem(LinkList L, int e)
{
	Lnode* p=L->next;
	int j = 1;
	while (p && p->data != e)
	{
		j++;
		p = p->next;
	}
	if (p)
	{
		return j;
	}
	return -1;
}

int ListLength(LinkList L)
{
	Lnode* p = L->next;
	int j = 0;
	while (p)
	{
		j++;
		p = p->next;
	}
	return j;
}

void PrintList(LinkList L)
{
	Lnode* p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void sort(int* arr,int size)
{
	int temp;
	for (int i = 0; i <size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void CreateListArr(LinkList& L,int*arr,int size)
{
	L = new Lnode;
	L->next = NULL;
	Lnode* p = L;
	Lnode* q;
	for (int i = 0; i <size; i++)
	{
		p->next = new Lnode;
		q = p->next;
		q->data = arr[i];
		q->next = NULL;
		p = p->next;
	}
}

void PrintArr(int* arr,int size)
{
	for (int i = 0; i <size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	LinkList a, b;
	CreateList(a, 5);
	CreateList(b, 4);
	Lnode* p = a->next;
	Lnode* q = b->next;
	int lena = ListLength(a);
	int lenb = ListLength(b);
	int sum = lena + lenb;
	int k = 0;
	int* arr = new int[sum];
	for (int i = 1; i <=lena; i++)
	{
		arr[k] = p->data;
		k++;
		p = p->next;
	}

	for (int j = 1; j <=lenb; j++)
	{
		arr[k] = q->data;
		k++;
		q = q->next;
	}
	sort(arr,sum);
	PrintArr(arr,sum);
    LinkList c;
	CreateListArr(c, arr,sum);
	PrintList(c);
	cout << k << endl;
	return 0;
}