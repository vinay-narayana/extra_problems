/* Given two strings which are unsigned integer numbers (in string format) write an adder to add the numbers. Lenghts of both can be different.*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
char* getAdd(char*, char*);
int getLen(char*);
main(){
	char *n1, *n2;
	n1 = (char *)malloc(sizeof(char));
	n2 = (char *)malloc(sizeof(char));
	fflush(stdin);
	gets(n1);
	gets(n2);
	printf("%s", getAdd(n1, n2));
	fflush(stdin);
	getchar();
}

char* getAdd(char n1[], char n2[]){
	int i = 0, carry = 0, n1_size, n2_size,res_size;
	char *res;
	n1_size = getLen(n1)-1;
	n2_size = getLen(n2)-1;
	res_size = (n1_size > n2_size) ? n1_size+1 : n2_size+1;
	res = (char *)malloc((res_size + 1)*sizeof(char));
	res[res_size+1] = '\0';
	while (n1_size>=0&&n2_size>=0){
		if (carry == 0)
			carry = (n1[n1_size--] - 48) + (n2[n2_size--] - 48);
		else
			carry = (n1[n1_size--] - 48) + (n2[n2_size--] - 48) + 1;
		res[res_size--] = (carry % 10)+48;
		carry /= 10;
	}
	if (n1_size >= 0){
		while (n1_size>=0){
			if (carry == 0)
				res[res_size--] = n1[n1_size--];
			else{
				carry = (n1[n1_size--] - 48) + 1;
				res[res_size--] = (carry % 10) + 48;
				carry /= 10;
			}
		}
	}
	else if (n2_size>=0){
		while (n2_size >= 0){
			if (carry == 0)
				res[res_size--] = n2[n2_size--];
			else{
				carry = (n2[n2_size--] - 48) + 1;
				res[res_size--] = (carry % 10) + 48;
				carry /= 10;
			}
		}
	}
	if (carry == 1)
		res[0] = '1';
	else
		res[0] = '\r';
	return res;
}

int getLen(char s[]){
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}