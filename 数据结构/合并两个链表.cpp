#include<iostream>
#define ERROR -1
using namespace std;

typedef struct Lnode
{
	int data;
	struct Lnode* next;
}Lnode,*LinkList;

void CreateList(LinkList& L, int n)
{
	Lnode* p, * q;
	L = new Lnode;
	p = L;
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
	Lnode* p;
	p = L->next;
	int j = 1;
	for (j = 1; j <i; j++)
	{
		p = p->next;
	}
	if (j > i || !p)
	{
		return ERROR;
	}
	int e = p->data;
	return e;
}

int LocateElem(LinkList L, int e)
{
	Lnode* p = L->next;
	int i = 1;
	while (p && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p) {
		return i;
	}
	return 0;
}

int ListLength(LinkList L)//获取表长
{
	Lnode* p;
	p = L->next;
	int j = 0;
	while (p)
	{
		p = p->next;
		++j;
	}
	return j;
}

void PrintList(LinkList L)
{
	int len = ListLength(L);
	Lnode* p = L->next;
	for (int i = 1; i <=len; i++)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void BackInsert(LinkList& L, int e)
{
	Lnode* p = L->next;
	while (p->next)
	{
		p = p->next;
	}
	p->next = new Lnode;
	Lnode* q = p->next;
	q->data = e;
	q->next = NULL;
}

int main()
{
	LinkList a, b;
	CreateList(a, 4);
	CreateList(b, 5);
	int lena = ListLength(a);
	int lenb = ListLength(b);
	for (int i = 1; i <= lenb; i++)
	{
		int e = GetElem(b, i);
		if (!LocateElem(a, e))
		{
			BackInsert(a, e);
		}
	}
	PrintList(a);
	return 0;
}