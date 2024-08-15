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
	cout << "请输入插入的" << j << "个数据" << endl;
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

void CreateTailPointer(LinkList& L,Lnode*(&s))//创建尾指针
{
	Lnode* q;
	q = L->next;
	while (q->next != L)
	{
		q = q->next;
	}
	s = q;
	//delete q;这句不能加上，因为释放q之后函数还会再次释放q，造成两次释放指针！！
}

Lnode* CombineList(LinkList T1, LinkList T2)//尾指针法合并两个链表
{
	Lnode* p;
	p = T1->next;
	T1->next = T2->next->next;
	delete T2->next;
	T2->next = p;
	return p;//返回新的链表，防止函数运行结束之后指针被释放
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