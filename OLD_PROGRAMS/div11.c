/*program to check given number divisible by11 or not */
#include<stdio.h>
#include<conio.h>
void div11(char *);
void main()
{
	char str[100];
	int valid;
	printf("enter string\t");
	gets(str);
	div11(str);
	getch();

}
void div11(char *str)
{
	int i,n1=0,n2=0,tmp=0,temp;
	for(i=0;str[i]!=NULL;i++)
	{
		if(str[i]>='0' && str[i]<='9' && tmp==0)
		{
			if(i%2==0)
				n1+=str[i]-'0';
			else
				n2+=str[i]-'0';
		}
		else
		{
			tmp=1;
			break;
		}
	}
	temp=(n1-n2)%11==0?1:0;
	if(tmp==1)
		printf("invalid number");
	else
		if(temp==1)
			printf("divisible by 11");
		else
			printf("not divisible by 11");	
}