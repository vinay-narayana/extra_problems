#include<stdio.h>
#include<conio.h>
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
    int i,j=-1,temp=0,tmp=n,sum=0;
    char str1[1000];
    while(n!=0 && temp!=1)
    {
        for(i=0;str[i]!=NULL;i++)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                j++;
                str1[j]=str[i];
                sum+=str[i]-'0';
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
    {
        tmp=(sum%3==0)?1:0;
        if(tmp==0)
            printf("not divisible by 3");
        else
            printf("divisible by 3");
    }

}

