//program to find given array size
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,50,49,0,0,0,0,0,0,0,0,0,0};
	int i=1,j=1,len;
	while(a[i]!=0 && a[i+1]!=0)
	{
		//printf("%d ",i);
		i*=2;
	}
	len=i;
	for(i=i/2;i<len;i++)
	{
		if(a[i]>a[i+1])
		{
			break;
		}
	}
	printf("array size is %d",i);
	getch();
	return 0;
}
