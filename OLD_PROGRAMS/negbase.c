//program to convert given number into negative base 2
#include<stdio.h>
#include<conio.h>
int main()
{
	float temp,n;
	int arr[20],i=0,len;
	printf("enter a number\t");
	scanf("%f",&n);
	printf("Base -2 value for the given number is \t");
	while(n!=0)
	{
		arr[i]=(int)n%2;
		if(i%2==1)
		{
			temp=n/2;
			n=ceil(temp);
		}
		else
		{
			temp=n/2;
			n=floor(temp);
		}
		i++;
	}
	len=i;
	for(i=0;i<len/2;i++)
	{
		arr[i]=arr[i]+arr[len-(i+1)];
		arr[len-(i+1)]=arr[i]-arr[len-(i+1)];
		arr[i]=arr[i]-arr[len-(i+1)];
	}
	for(i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
	temp=n/2.0f;
	getch();
	return 0;
}
