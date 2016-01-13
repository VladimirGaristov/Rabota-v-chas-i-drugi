#include <stdio.h>

int main()
{
	int n, reversed=0;
	printf("Vavedi chislo: ");
	scanf("%d",&n);
	while(n!=0)
	{
		reversed*=10;
		reversed+=n%10;
		n/=10;
	}
	reversed*=3;
	printf("%d\n",reversed);
	return 0;
}
