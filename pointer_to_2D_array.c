#include <stdio.h>

void pointer_test(int (*p)[10][10]);

int main()
{
	int a[10][10];
	a[5][5]=777;
	pointer_test(&a);
	return 0;
}

void pointer_test(int (*p)[10][10])
{
	//printf("\n%d",*p[5][5]);
	//printf("\n%d",*(p[5][5]));
	//printf("\n%d",*(*(p+5)+5));
	printf("%d\n",(*p)[5][5]);
}