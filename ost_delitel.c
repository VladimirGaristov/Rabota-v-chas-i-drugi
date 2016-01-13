#include <stdio.h>

int main()
{
	int a, b, ostatak, delitel, i;
	printf("Vavedi dve chisla: ");
	scanf("%d %d",&a, &b);
	for(i=1;i<=a && i<=b;i++)
		if(a%i==0 && b%i==0)
		{
			delitel=i;
		}
	ostatak=delitel%6;
	printf("%d\n",ostatak);
	return 0;
}
