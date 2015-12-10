
/*date printing in words*/
#include<stdio.h>
#include<conio.h>
void convert(int ,int ,int );
void divide(char *);

void main()
{
	char str[20];
	printf("Enter the date(day,month,year) ");
	gets(str);
	divide(str);
	getch();
}
void divide(char *str)
{
	int i,j,day=0,month=0,year=0;
	for(i=0;str[i]>='0' && str[i]<='9';i++)
			day=(day*10)+str[i]-'0';
	i++;
	for(j=i;str[j]>='0' && str[j]<='9';j++)
		month=(month*10)+str[j]-'0';
	j++;
	for(i=j;str[i]>='0' && str[i]<='9';i++)
		year=(year*10)+str[i]-'0';
	convert(day,month,year);

}
void convert(int day,int month,int year)
{
	int t,tmp,temp=0,flag=0;
	char a[10][10]={" ","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
	char b[15][15]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Ninteen"};
	char c[10][10]={" ","Ten","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninty"};
	char d[10][10]={" ","First","Second","Third"};
	char e[15][15]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	int	range[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	
	if(year%4==0)
		range[1]=29;
	
	if(day<=range[month-1] && year<9999 && year>999)
	{
		if(day>19 && day<=31)
		{
			t=day/10;
			day=day%10;
			printf("%s ",c[t]);
		}
		if(day>9 && day<20)
		{
			t=day%10;
			day=0;
			printf("%sth ",b[t]);
		}
		if(day>3 && day<=9)
			printf("%sth ",a[day]);
		else
			printf("%s ",d[day]);

		printf("%s of ",e[month-1]);
	
		if(year>1000)
		{
			t=year/100;
			temp=1;
			if((t>10)&&(t<20))
			{
				tmp=t%10;
				year=year%1000;
				printf("%s  ",b[tmp]);
			}
			else
			{
				t=year/1000;
				year=year%1000;
				printf("%s Thousand ",a[t]);
			}
		}
		if(year>100&&temp==0) 
		{
			t=year/100;
			year=year%100;
			printf("%s  ",a[t]);
		}
		else
			year=year%100;
		if(year>=10 && year<20)
		{
			t=year%10;  
			printf("%s ",b[t]);
		}
		if(year>19 && year<=100)
		{
			t=year/10;
			year=year%10;
			printf("%s ",c[t]);
		}
		if(year<10)
		{
			printf("%s ",a[year]);
		}
	}
	
	else
		printf("Invalid Date\n");
}
