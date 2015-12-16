#include <stdio.h>

void print_binary(int number);

void main()
{
	int a=42, b=404, i;
	printf("42 & 404 = %d\n",42 & 404);
	printf("42 | 404 = %d\n",42 | 404);
	print_binary(404);
	print_binary(0);
	print_binary(-0);
	print_binary(1);
	print_binary(-1);
	print_binary(2);
	print_binary(-2);
}

void print_binary(int number)
{
	int i;
	printf("%d = ",number);
	for(i=sizeof(int)*8-1;i>=0;i--)
	{
		if(number & (1 << i))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}
