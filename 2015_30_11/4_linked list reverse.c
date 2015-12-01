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
lptr reverse(lptr);
void main()
{
	lptr first = NULL,second=NULL;
	int x;
	printf("Enter list elements\t");
	scanf_s("%d", &x);
	while (x != -1)
	{
		first = insert(first, x);
		scanf_s("%d", &x);
	}
	printf("\nList Elements are\t");
	display(first);
	second = reverse(first);
	printf("\nReversed list is \t");
	display(second);
	_getch();
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
		return first;
	while (t->link != NULL)
	{
		printf("%d->",t->data);
		t = t->link;
	}
	printf("%d", t->data);
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