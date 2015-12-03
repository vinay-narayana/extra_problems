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
lptr add(lptr, lptr);
lptr reverse(lptr);
void main()
{
	lptr first = NULL,second=NULL,third=NULL;
	int x;
	printf("\nEnter first list elements\t");
	scanf_s("%d", &x);
	while(x != -1)
	{
		first = insert(first, x);
		scanf_s("%d", &x);
	}
	printf("\nEnter second list elements\t");
	scanf_s("%d", &x);
	while (x != -1)
	{
		second = insert(second, x);
		scanf_s("%d", &x);
	}
	printf("\nFirst list elements are \t");
	display(first);
	printf("\nSecond list elements are \t");
	display(second);
	printf("\nThird list elements are \t");
	first=reverse(first);
	second=reverse(second);
	third = add(first, second);
	display(third);
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
	while (t->link != NULL)
	{
		printf("%d->", t->data);
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
lptr add(lptr first, lptr second)
{
	lptr list=NULL;
	int s = 0,flag=0,tmp=0;
	if (first == NULL)
		return second;
	if (second == NULL)
		return first;
	while (first != NULL && second != NULL)
	{
		if (first->data + second->data > 9)
		{
			tmp = (first->data + second->data) % 10;
			list = insert(list, tmp + flag);
			flag = (first->data + second->data) / 10;
		}
		else
		{
			list = insert(list, first->data + second->data + flag);
			flag = 0;
		}
		first = first->link;
		second = second->link;
	}
	if (first == NULL && second == NULL && flag != 0)
		list = insert(list, flag);
	while (first != NULL)
	{
		tmp = first->data + flag;
		if (tmp > 9)
		{
			flag = tmp % 10;
			list = insert(list, tmp + flag);
		}
		else
		{
			list = insert(list, tmp + flag);
			flag = 0;
		}
		first = first->link;
	}
	while (second != NULL)
	{
		tmp = second->data + flag;
		if (tmp > 9)
		{
			flag = tmp % 10;
			list = insert(list, tmp + flag);
		}
		else
		{
			list = insert(list, tmp + flag);
			flag = 0;
		}
		second = second->link;
	}
	return reverse(list);
}