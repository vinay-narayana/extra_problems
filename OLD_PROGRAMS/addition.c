//programto perform addition from left side 
#include<stdio.h>
#include<conio.h>
void adder_leftside(char *,char *);
int main()
{
	char str[20],str1[20];
	printf("enter first number\t");
	scanf("%s",&str);
	printf("\nenter second number\t");
	scanf("%s",&str1);
	adder_leftside(str,str1);
	getch();
	return 0;
}
void adder_leftside(char *str,char *str1)
{
	int i,j=0,ans[30],sum=0;
	for(i=0;str[i]!='\0';i++)
	{
		sum=str[i]-'0'+str1[i]-'0';
		if(sum>9)
		{
			j=i-1;
			while(ans[j]==9)
			{
				ans[j]=0;
				j--;
			}
				ans[j]+=1;			
		}
		ans[i]=sum%10;
	}
	printf("\nsum is ");
	for(j=0;j<i;j++)
		printf("%d",ans[j]);	
}
