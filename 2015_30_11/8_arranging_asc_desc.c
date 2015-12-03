#include<stdio.h>
#include<conio.h>
#include<malloc.h> 
struct lnode
{
	int data;
	struct lnode *link;
};
typedef struct lnode *lptr;
lptr insert(lptr, int);
void display(lptr);
lptr arrage(lptr);
lptr reverse(lptr);
void main()
{
	int x;
	lptr first = NULL;
	printf("\nEnter list elements\t");
	scanf_s("%d", &x);
	while (x != -1)
	{
		first = insert(first, x);
		scanf_s("%d", &x);
	}
	printf("\nList elements are\t");
	display(first);
	first = arrage(first);
	printf("\nSorted list is \t");
	display(first);
	_getch();
}
lptr arrage(lptr first)
{
	lptr t = first, prev=NULL, l1=NULL,list=NULL;
	int count = 0;
	if (first == NULL)
		return first;
	while (t->link != NULL)
	{
		l1 = prev;
		prev = t;
		t = t->link;
		if (t->data < prev->data)
		{
			list = reverse(l1->link);
			break;
		}
	}
		l1->link = list;
	return first;
}
lptr reverse(lptr first)
{
	lptr list;
	if (first == NULL)
		return NULL;
	if (first->link == NULL)
		return first;
	list = reverse(first->link);
	first->link->link = first;
	first->link = NULL;
	return list;
}
lptr insert(lptr first, int x)
{
	lptr p, t;
	p = (lptr)malloc(sizeof(struct lnode));
	p->data = x;
	p->link = NULL;
	if (first == NULL)
	{
		first = p;
		return first;
	}
	t = first;
	while (t->link != NULL)
		t = t->link;
	t->link = p;
	return first;
}
void display(lptr first)
{
	lptr t = first;
	if (first == NULL)
		return;
	while (t->link != NULL)
	{
		printf("%d->", t->data);
		t = t->link;
	}
	printf("%d\n", t->data);
}