#include<iostream>
using namespace std;
//˫���ѭ������
typedef struct DULnode
{
	int data;
	struct DULnode* prior, * next;
}DULnode,*DULinkList;

void FrontCreateDUList(DULinkList& L,int j)
{
	L = new DULnode;
	L->prior = NULL;
	L->next = NULL;

	DULnode* p;
	cout << "������" << j << "������" << endl;
	for (int i = j; i>0; i--)
	{
		p = new DULnode;
		cin >> p->data;
		p->prior = NULL;
		p->next = NULL;

		p->next = L->next;
		L->next = p;
		p->prior = L;
	}
}

void BackCreateDUList(DULinkList& L, int j)
{
	L = new DULnode;
	L->prior = NULL;
	L->next = NULL;

	DULnode* p, * q;
	p = L;

	cout << "������" << j << "������" << endl;
	for (int i = 0; i < j; i++)
	{
		q = new DULnode;
		cin >> q->data;
		q->next = NULL;
		q->prior = NULL;

		p->next = q;
		q->prior = p;
		p = q;
	}
}

void PrintDUList(DULinkList& L)
{
	DULnode* p;
	p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	DULinkList L;
	/*BackCreateDUList(L,5);*/
	FrontCreateDUList(L, 5);
	PrintDUList(L);
	return 0;
}