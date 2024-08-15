#include<iostream>
#define OK 1
#define NO 0
#define ERROR -1
using namespace std;
typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode,*LinkList;

void InitList(LinkList& L)//初始化
{
	L = new Lnode;
	L->next = NULL;
	cout << "单链表初始化已完成" << endl;
}

int IsEmptyList(LinkList& L)//判空
{
	if (!L->next)
	{
		cout << "单链表为空" << endl;
		return OK;
	}
	return NO;
}

void DestroyList(LinkList& L)//销毁
{
	LinkList p;
	while (L)
	{
		p = L;
		L = L->next;
		delete p;
	}
	if (!L)
	{
		cout << "已销毁单链表" << endl;
	}
}

void ClearListOriginalDebug(LinkList& L)//清空
{
	Lnode* p, * q;
	p = L->next;
	while (L->next)
	{
		p = L->next;
		q = p->next;
		L->next = q;
		delete p;
	}
	if (!L->next)
	{
		cout << "已清空" << endl;
	}
}

//void ClearList(LinkList& L)清空
//{
//	Lnode* p, * q;
//	p = L->next;
//	q = NULL;
//	while (p)
//	{
//		q = p->next;
//		delete p;
//		p = q;
//	}
//	L->next = NULL;
//	if (!L->next)
//	{
//		cout << "已清空单链表" << endl;
//	}
//}

int GetElemList(LinkList L,int i)//获取指定位置元素
{
	Lnode* p;
	p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	int &e = p->data;
	return e;
}

int SearchList(LinkList L, int e)//查找指定值元素
{
	Lnode* p;
	p = L->next;
	int j = 1;
	while (p && p->data != e)
	{
		p = p->next;
		++j;
	}
	if (!p) return ERROR;
	return j;
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

void BackInsertList(LinkList& L,int e,int pos)//后面插入
{
	Lnode* p, * q;
	q = new Lnode;
	q->data = e;
	q->next = NULL;
	p = L->next;
	int j = 1;
	while (p && j < pos)
	{
		p = p->next;
		++j;
	}
	q->next = p->next;
	p->next = q;
}

void FrontInsertList(LinkList& L, int e, int pos)//前面插入
{
	Lnode* p, * q;
	q = new Lnode;
	q->data = e;
	q->next = NULL;
	p = L;
	int j = 0;
	while (p && j < pos - 1)
	{
		p = p->next;
		++j;
	}
	q->next = p->next;
	p->next = q;
}

void DeleteList(LinkList& L, int pos)//删除元素
{
	Lnode* p, * q;
	p = L->next;
	int j = 1;
	while (p && j < pos)
	{
		p = p->next;
		++j;
	}
	q = p->next;
	p = q->next;
	q->next = NULL;
}

//void CreateList(LinkList& L,int j)
//{
//	L = new Lnode;
//	L->next = NULL;
//	Lnode* p;
//	p = L;
//	for (int i = 1; i <= j; i++)
//	{
//		p->next = new Lnode;
//		p = p->next;
//		p->data = i;
//		p->next = NULL;
//	}
//}

void FrontCreateList(LinkList& L, int j)//前插法创建链表
{
	L = new Lnode;
	L->next = NULL;
	Lnode* p;
	cout << "请使用头插法插入" << j << "个元素" << endl;
	for (int i = j; i > 0; i--)
	{
		p = new Lnode;
		p->next = NULL;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

void BackCreateList(LinkList& L, int j)//尾插法创建链表
{
	L = new Lnode;
	L->next = NULL;
	Lnode* p;
	p = L;
	cout << "请使用尾插法插入" << j << "个元素" << endl;
	for (int i = 0; i < j; i++)
	{
		p->next = new Lnode;
		cin>>p->next->data;
		p->next->next = NULL;
		p = p->next;
	}
}

void PrintList(LinkList L)//打印链表
{
	Lnode* p;
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
	LinkList L;
	int times = 0;
	InitList(L);
	IsEmptyList(L);
	/*CreateList(L, 10);*/
	/*PrintList(L);
	BackInsertList(L, 100, 5);
	PrintList(L);
	FrontInsertList(L, 1000, 3);
	PrintList(L);
	cout << ListLength(L) << endl;
	cout << SearchList(L, 1000) << endl;
	cout << GetElemList(L, 5) << endl;*/
	/*ClearList(L);*/
	cout << "输入插入元素的个数" << endl;
	cin >> times;
	FrontCreateList(L, times);
	PrintList(L);
	ClearListOriginalDebug(L);

	cout << "输入插入元素的个数" << endl;
	cin >> times;
	BackCreateList(L,times);
	PrintList(L);
	ClearListOriginalDebug(L);
	DestroyList(L);
	return 0;
}