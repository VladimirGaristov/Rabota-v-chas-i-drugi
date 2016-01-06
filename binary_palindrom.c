#include<stdio.h>

int binary_lenght( int);

int main()
{
	int num;
	scanf("%d",&num);
	int lenght=binary_lenght(num);
	int front, back;
	for(front=0, back=lenght-1;front!=back;front++, back--)
	{
		if(((num >> front)& 1)!=((num>>back)&1))	
		{
			printf("Not\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}

int binary_lenght( int num)
{
	int counter=0;
	while(num!=0)
	{
		num/=2;
		counter++;
	}
	return counter;
}
