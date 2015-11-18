#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i=0,a[4],x[4],n=1,j,z,y=0;
	do
	{
		srand(time(NULL)+y);
		for(i=0;i<4;i++)
			a[i]=rand() %10;
		y++;
		n=0;
		if(a[0]==0)
			n=1;
		for(j=0;n==0 && j<4;j++)
			for(z=1;n==0 && j+z<4;z++)
				if(a[j]==a[j+z])
					n=1;
	}while(n=1);
	for(i=0;i<4;i++)
		printf("\n%d",a[i]);
	while(a[0]!=x[0] && a[1]!=x[1] && a[2]!=x[2] && a[3]!=x[3])
	{
		scanf("%d",&n);
		for(i=0;i<4;i++)
		{
			x[3-i]=n%10;
			n/=10;
		}
		for(i=0;i<4;i++)		//zameni s broia na kravite i bikovete
		printf("\n%d",x[i]);
	}
	printf("\nBRAVO!");
}
