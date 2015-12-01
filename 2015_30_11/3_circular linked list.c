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
void main()
{
	lptr first = NULL;
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
	printf("\nEnter an element to be inserted in list \t");
	scanf_s("%d", &x);
	first = insert(first, x);
	printf("\nList Elements are\t");
	display(first);
	_getch();
}
lptr insert(lptr first, int x)
{
	lptr p, t;
	p = (lptr)malloc(sizeof(struct lnode));
	if (first == NULL)
	{
		p->data = x;
		p->link = p;
		first = p;
		return first;
	}
	else
	{
		p->data = x;
		p->link = first;
		t = first;
		while (t->link != first)
			t = t->link;
		t->link = p;
		return first;
	}
}
void display(lptr first)
{
	lptr t = first;
	while (t->link != first)
	{
		printf("%d->",t->data);
		t = t->link;
	}
	printf("%d", t->data);
}