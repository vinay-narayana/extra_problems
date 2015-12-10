/*modulo opearation*/
#include<stdio.h>
#include<conio.h>
int mult(int ,int ,int );
void main()
{
	int x,y,z;
	printf("enter x,y,z values\t");
	scanf("%d%d%d",&x,&y,&z);
	printf("(pow(%d,%d)mod %d) is  %d",x,y,z,mult(x,y,z));
	getch();
}
int mult(int x,int y,int z)
{
	int res,s;
	res=1;
	s=x;
	if(y==0)
	 return 1;
	while(y!=0)
	{
		if(y%2)
        res=res*s;
		s=(s*s)%z;
		y=y/2;
		if(res>z)
			res=res%z;
	}
	return res;
}