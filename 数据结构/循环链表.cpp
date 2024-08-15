#include<iostream>
using namespace std;

typedef struct Lnode
{
	int data;
	struct Lnode* next;
}Lnode,*LinkList;

void CreateList(LinkList& L,int j)
{
	L = new Lnode;
	L->next = NULL;
	Lnode* r, * s;
	r = L;
	cout << "����������" << j << "������" << endl;
	for (int i = 0; i < j; i++)
	{
		s = new Lnode;
		cin >> s->data;
		s->next = NULL;
		s->next = r->next;
		r->next = s;
		r = s;
	}
	r->next = L;
}

void PrintList(LinkList L)
{
	Lnode* p;
	p = L->next;
	while (p!=L)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void PrintSpecialNode(LinkList L, int ind)
{
	Lnode* p;
	p = L->next;
	int j = 1;
	while (p != L && j < ind)
	{
		p = p->next;
		j++;
	}
	cout << p->data << endl;
}

void CreateTailPointer(LinkList& L,Lnode*(&s))//����βָ��
{
	Lnode* q;
	q = L->next;
	while (q->next != L)
	{
		q = q->next;
	}
	s = q;
	//delete q;��䲻�ܼ��ϣ���Ϊ�ͷ�q֮���������ٴ��ͷ�q����������ͷ�ָ�룡��
}

Lnode* CombineList(LinkList T1, LinkList T2)//βָ�뷨�ϲ���������
{
	Lnode* p;
	p = T1->next;
	T1->next = T2->next->next;
	delete T2->next;
	T2->next = p;
	return p;//�����µ�������ֹ�������н���֮��ָ�뱻�ͷ�
}

int main()
{
	LinkList L1,L2;
	CreateList(L1, 5);
	CreateList(L2, 6);
	Lnode* T1,*T2;
	
	CreateTailPointer(L1, T1);
	CreateTailPointer(L2, T2);
	
	LinkList L=CombineList(T1, T2);
	PrintList(L);

	return 0;
}