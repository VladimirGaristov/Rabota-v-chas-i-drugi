#include <stdio.h>

int main()
{
	int n, i, j=0;
	short unsigned octal[50];
	printf("Vavedi chislo: \n");
	scanf("%d",&n);
	for(i=0;n!=0;i++)
	{
		octal[i]=n%8;
		n/=8;
	}
	i--;
	while(i>j)
	{
		if(octal[i]!=octal[j])
		{
			printf("Tova chislo ne e palindrom.\n");
			return 0;
		}
		i--;
		j++;
	}
	printf("Tova chislo e palindrom.\n");
	return 1;
}