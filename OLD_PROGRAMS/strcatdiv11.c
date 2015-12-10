#include<stdio.h>
#include<conio.h>
void div11(char *);
void oper(char *,int );
void main()
{
	char str[100];
	int n;
	printf("enter string\t");
	gets(str);
	printf("enter a number\t");
	scanf("%d",&n);
	oper(str,n);
	getch();

}
void oper(char *str,int n)
{
    int i,j=-1,temp=0,tmp=n;
    char str1[100];
    while(n!=0 && temp!=1)
    {
        for(i=0;str[i]!=NULL;i++)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                j++;
                str1[j]=str[i];
            }
            else
                temp=1;
        }
        n--;
    }
    str1[tmp*i]=NULL;
    if(temp==1)
    printf("invalid number");
    else
        div11(str1);

}


void div11(char *str)
{
	int i,n1=0,n2=0,tmp=0,temp;
	for(i=0;str[i]!=NULL;i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			if(i%2==0)
				n1+=str[i]-'0';
			else
				n2+=str[i]-'0';
		}
	}
	temp=(n1-n2)%11==0?1:0;
		if(temp==1)
			printf("divisible by 11");
		else
			printf("not divisible by 11");
}
