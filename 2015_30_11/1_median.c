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
int median(lptr );
void main()
{
	lptr first = NULL;
	int x,med;
	printf("Enter elements\t");
	scanf_s("%d", &x);
	while (x != -1)
	{
		first = insert(first, x);
		scanf_s("%d", &x);
	}
	display(first);
	med = median(first);
	printf("\nMedian is %d", med);
	_getch();
}
lptr insert(lptr first, int x)
{
	lptr t, p,prev=NULL;
	p = (lptr)malloc(sizeof(struct lnode));
	p->data = x;
	p->link = NULL;
	if (first == NULL)
	{
		first = p;
		return first;
	}
	if (x<first->data)
	{
		p->link = first;
		first = p;
		return first;
	}
	t = first;
	while (t != NULL && x >= t->data)
	{
		prev = t;
		t = t->link;
	}
	prev->link = p;
	p->link = t;
	return first;
}
void display(lptr first)
{
	lptr t = first;
	while (t->link != NULL)
	{
		printf("%d->", t->data);
		t = t->link;
	}
	printf("%d", t->data);
}
int median(lptr first)
{
	lptr t = first;
	int c,i=0,med;
	for (c = 0; t->link != NULL; t = t->link, c++);
	t = first;
	while (i != c / 2)
	{
		t = t->link;
		i++;
	}
	if (c % 2 == 1)
		med = t->data;
	else
	{
		med = (t->data + (t->link)->data) / 2;
	}
	return med;
}