#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int a[10],x[10],i,j=0,n,q,l=4,kr,bk; // ако l се въвежда от потребителя може да се избира колко дълго да е генерираното число (макс. 10 цифри)
	/**/printf("Kolko dalgo da e chisloto?\n");
	scanf("%d",&l);
	while(l>10 || l<1)
	{
		printf("Maksimalnata dalzina e 10 tsifri.\nKolko dalgo da e chisloto?");
		scanf("%d",&l);
	}/**/
	do
	{
		srand(time(NULL)+j);
		for(i=0;i<l;i++)
			a[i]=rand()%10;
		n=0;
		if(a[0]==0)
			n=1;
		for(i=0;i<l && n==0;i++)
			for(q=l-1;q>i && n==0;q--)
				if(a[i]==a[q])
					n=1;
		j++;
		for(i=0;i<l;i++)
			printf("%d",a[i]);
		printf("\n");
	}while(n==1);
	printf("Namislih si chislo. Opitai se da go poznaesh!\n");
	while(1)
	{
		for(i=0;i<l;i++)
			scanf("%1d",&x[i]);
		kr=0;
		bk=0;
		for(i=0;i<l;i++)
			if(x[i]==a[i])
				bk++;
		if(bk==l)
		{
			printf("Pozdravlenia, pozna!\n");
			break;
		}
		for(i=0;i<l;i++)
			for(j=0;j<l;j++)
				if(x[i]==a[j])
				{
					kr++;
					break;
				}
		kr-=bk;
		printf("%d bika i %d kravi.\n",bk,kr);
	}
}