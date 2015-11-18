#include <stdio.h>

void duma(int *br);

int main()
{
	int br_dumi=0;
	duma(&br_dumi);
	printf("%d\n",br_dumi);
	return br_dumi;
}

void duma(int *br)
{
	char a;
	int f=0;
	do
	{
		a=getchar();
		if((a<91 && a>64) || (a<123 && a>96))
		{
			if(f==0)
			{
				*br+=1;
				f=1;
			}
		}
		else
			if(f==1)
				f=0;
	}
	while(a!='\n');
}
