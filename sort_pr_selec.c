#include <stdio.h>

int main()
{
	int a[1000],i,n,j,max,max_id;
	do		//vavezdane
	{
		printf("Vavedi broi na chislata: ");
		scanf("%d",&n);
	}
	while(n>1000 || n<1);
	for(i=0;i<n;i++)
	{
		printf("Vavedi chislo: ");
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)		//sortirane
	{
		max=0;
		for(j=0;j<n-i;j++)
			if(a[j]>max)
			{
				max=a[j];
				max_id=j;
			}
		j=a[n-i-1];
		a[n-i-1]=max;
		a[max_id]=j;
	}
	for(i=0;i<n;i++)		//izvejdane
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
