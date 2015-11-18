#include <stdio.h>

void main()
{
	int n=5,a;
	printf("%d\n",n);
	int *ptr;
	ptr=&n;
	printf("%p\n",ptr);
	scanf("%d",&a);
	for(n=0;n<a;n++)
	{
		printf("\n%d",ptr[n]);
	}
}
