//binary to octal conversion
 #include <stdio.h>
 #include<conio.h>
int main()
{
    long int n,n1= 0,i=1,temp,tmp=0;
 
    printf("Enter binary number ");
    scanf("%ld", &n);
    while (n != 0 && tmp==0)
    {
        temp=n%10;
        n1+=temp*i;
        i*=2;
        n/=10;
        if(temp!=0 && temp!=1)
        	tmp=1;
    }
    if(tmp==1)
    	printf("\ninvalid binary number");
    else
   		 printf("octal value is %lo",n1);
    getch();
    return 0;
}
