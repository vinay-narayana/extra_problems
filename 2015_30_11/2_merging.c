#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct lnode
{
	int data;
	struct lnode *link;
};
typedef struct lnode *lptr;
lptr insert(lptr, int );
void display(lptr );
lptr merge(lptr, lptr);
int main()
{
	lptr first = NULL,second=NULL,third=NULL;
	int x;
	printf("\nEnter first list elements\t");
	scanf_s("%d", &x);
	while (x != -1)
	{
		first = insert(first, x);
		scanf_s("%d", &x);
	}
	printf("\nEnter Second list elements\t");
	scanf_s("%d", &x);
	while (x != -1)
	{
		second = insert(second, x);
		scanf_s("%d", &x);
	}
	printf("\nFirst List elements   ");
	display(first);
	printf("\nSecond List elements   ");
	display(second);
	third = merge(first, second);
	printf("\nMerged List elements   ");
	display(third);
	getch();
   return 0;
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
	while (t->link != NULL)
	{
		printf("%d->", t->data);
		t = t->link;
	}
	printf("%d", t->data);
}
lptr merge(lptr first, lptr second)
{
	lptr third = NULL;
	if (first == NULL)
		return second;
	if (second == NULL)
		return first;
	while (first->link != NULL || second->link != NULL)
	{
		if (first->data <= second->data)
		{
			third = insert(third, first->data);
			first = first->link;
		}
		else
		{
			third = insert(third, second->data);
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
