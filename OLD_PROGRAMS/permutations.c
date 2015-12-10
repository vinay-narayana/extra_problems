//program to generate and store permutations
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
struct lnode
{
	int data;
	struct lnode *link;
};
typedef struct lnode *lptr;
lptr first=NULL;

lptr insertorder(lptr ,int );
void display(lptr );
void swap(int [],int ,int );
void perm(int [],int ,int );
int main()
 {
 	FILE *fp;
 	lptr t;
 	int a[25],i=0,n,tmp,len;
 	fp=fopen("sample.txt","w+");
 	printf("enter a number\t");
 	scanf("%d",&n);
 	while(n!=0)
 	{
 		a[i]=n%10;
 		n/=10;
 		i++;
	 }
 	len=i;
 	for(i=0;i<len/2;i++)
	{
		a[i]=a[i]+a[len-(i+1)];
		a[len-(i+1)]=a[i]-a[len-(i+1)];
		a[i]=a[i]-a[len-(i+1)];
	}
	printf("permutations are\n");
	perm (a, len, 0);
	t=first;
	while(t!=NULL)
	{
		fprintf(fp,"%d\n",t->data);
		t=t->link;
	}
	fclose(fp);
	getch();
}
void swap(int a[],int i,int j) 
{
	int	t;
	t=a[i];
	a[i]=a[j];
	a[j]=t;
}
void perm(int a[],int n,int i) 
{
	int	j,number;
	if(i==n) 
	{
		number=0;
		for (j=0;j<n;j++) 
		{
			number=(number*10)+a[j];	
		}
		printf("%d\n",number);
		first=insertorder(first,number);
	} 
	else
		for(j=i;j<n;j++) 
		{		
			swap(a,i,j);
			perm(a,n,i+1);
			swap(a,i,j);
		}
}

lptr insertorder(lptr first,int x)
{
	lptr t,p,prev;
	p=(lptr)malloc(sizeof(struct lnode));
	p->data=x;
	p->link=NULL;
	if(first==NULL)
	{
		first=p;
		return first;
	}
	if(x<first->data)
	{
		p->link=first;
		first=p;
		return first;
	}
	t=first;
	while(t!=NULL && x>=t->data)
	{
		prev=t;
		t=t->link;
	}
	prev->link=p;
	p->link=t;
	return first;
}
void display(lptr first)
{
	lptr t;
	t=first;
	while(t!=NULL)
	{
		printf("%d\n",t->data);
		t=t->link;
	}
}
