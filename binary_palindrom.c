#include <stdio.h>

int pal(int num);
int binary_lenght( int num);
int next_pal( int num);

int main()
{
	int n, i;
	scanf("%d",&n);
	if(n<0)
		n=-n;
	if(pal(n)==1)
		printf("YES\n");
	else
		printf("NO\n");
	i=n+1;
	while(pal(i)==0)
		i++;
	printf("%d\n",i);
}

int pal(int num)
{
	int lenght=binary_lenght(num);
	int front, back;
	for(front=0, back=lenght-1;front < back;front++, back--)
	{
		if(((num >> front)& 1)!=((num>>back)&1))
		{
			return 0;
		}
	}
	return 1;
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