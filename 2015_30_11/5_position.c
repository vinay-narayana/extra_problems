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
lptr createlist(lptr, int, int);
lptr mergelist(lptr, lptr);
int find(lptr, int);
void main()
{
	lptr first = NULL, second = NULL, third = NULL;
	int n1, n2, r,pos;
	printf("Enter first number\t");
	scanf_s("%d", &n1);
	printf("\nEnter second number \t");
	scanf_s("%d", &n2);
	printf("\nEnter position \t");
	scanf_s("%d", &r);
	first = createlist(first, n1, r + 1);
	second = createlist(second, n2, r + 1);
	third = mergelist(first, second);
	printf("\nFirst list is \t");
	display(first);
	printf("\nSecond list is \t");
	display(second);
	printf("\nMerged list is\t");
	display(third);
	pos = find(third, r);
	printf("\nNumber at position %d is %d ",r, pos);
	_getch();
}
int find(lptr list, int r)
{
	int i = 0;
	lptr t = list;
	while (i < r)
	{
		t = t->link;
		i++;
	}
	return t->data;
}
lptr mergelist(lptr first, lptr second)
{
	lptr third = NULL;
	if (first == NULL)
		return second;
	if (second == NULL)
		return first;
	while (first->link!= NULL && second->link!= NULL)
	{
		if (first->data < second->data)
		{
			third = insert(third, first->data);
			first = first->link;
		}
		else if (second->data < first->data)
		{
			third = insert(third, second->data);
			second = second->link;
		}
		else
		{
			third = insert(third, first->data);
			first = first->link;
			second = second->link;
		}
	}
	while (first != NULL)
	{
		third = insert(third, first->data);
		first = first->link;
	}
	while (second != NULL)
	{
		third = insert(third, second->data);
		second = second->link;
	}
	return third;
}
lptr createlist(lptr list, int num, int len)
{
	lptr p, t;
	int i = 0;
	if (len < 0)
		return NULL;
	while (i < len)
	{
		p = (lptr)malloc(sizeof(struct lnode));
		p->data = (i + 1)*num;
		p->link = NULL;
		if (list == NULL)
			list = p;
		else
		{
			t = list;
			while (t->link != NULL)
				t = t->link;
			t->link = p;
		}
		i++;
	}
	return list;
}
lptr insert(lptr first, int x)
{
	lptr t, p, prev = NULL;
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
	printf("%d", t->data);
}
