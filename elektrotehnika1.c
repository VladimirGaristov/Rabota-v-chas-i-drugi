#include <stdio.h>

void main()
{
	float a,b,c,d;
	int i;
	printf("Zadacha 1:\n");
	for(i=0;i<6;i++)
	{
		printf("Vavedi Ie: ");
		scanf("%f",&a);
		printf("Vavedi Ix: ");
		scanf("%f",&b);
		c=40.4*(a/b);
		printf("Rx=%f\n",c);
		d=(a/b)*(40.4+6.2)-6.2;
		printf("Rx\'=%f\n",d);
	}
	printf("Zadacha 2:\n");
	for(i=0;i<6;i++)
	{
		printf("Vavedi Ux: ");
		scanf("%f",&a);
		printf("Vavedi Ue: ");
		scanf("%f",&b);
		c=40.4*(a/b);
		printf("Rx=%f\n",c);
	}
	printf("Zadacha 3:\n");
	for(i=0;i<3;i++)
	{
		printf("Vavedi a2: ");
		scanf("%f",&a);
		printf("Vavedi U1: ");
		scanf("%f",&b);
		c=a*0.4;
		printf("U2=%f\n",c);
		d=200.4*((b-c)/c);
		printf("Rx=%f\n",d);
	}
}