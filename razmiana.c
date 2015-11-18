#include <stdio.h>

void swap(int *a, int *b);

int main()
{
	int a,b;
	printf("Vavedi a: ");
	scanf("%d",&a);
	printf("Vavedi b: ");
	scanf("%d",&b);
	swap(&a,&b);
	printf("a=%d, b=%d\n",a,b);
	return 0;
}

void swap(int *a, int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
