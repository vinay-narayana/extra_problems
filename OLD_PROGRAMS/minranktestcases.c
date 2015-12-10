#include<stdio.h>
#include<conio.h>
void bsort(int [],int );
int fact(int );
void testing();
struct tester
{
	int input;
	int output;
}test[3]={
	{1234,0},
	{4321,23},
	{10,1}
};
void testing()
{
	int i,ans;
	for(i=0;i<3;i++)
	{
		ans=operation(test[i].input);
		if(ans==test[i].output)
			printf("test passed\n");
		else
			printf("test failed\n");
	}
}
void main()
{
	testing();
	getch();
}
void bsort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
}
int fact(int no)
{
	if(no==0)
		return 1;
	else
		return no*fact(no-1);
}
int operation(int no)
{
	int a[20],b[20],n,i,j,k,fac=0;
	for(i=0;no!=0;i++)
	{
		b[i]=a[i]=no%10;
		no=no/10;
	}
	n=i;
	for(i=0;i<n/2;i++)
	{
		a[i]=a[i]+a[n-(i+1)];
		a[n-(i+1)]=a[i]-a[n-(i+1)];
		a[i]=a[i]-a[n-(i+1)];
	}
	bsort(b,n);
	for(i=0;i<n;i++)
		for(j=0;j<n-i;j++)
			if(a[i]==b[j])
			{
				fac=fac+j*fact(n-(i+1));
				for(k=j;k<n;k++)
					b[k]=b[k+1];
			}
	return fac;

}