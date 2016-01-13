#include <stdio.h>

struct tochka
{
	int x;
	int y;
} tochka;

tochka sabirane(tochka a, tochka b);
int sasedni(tochka a, tochka b);

int main()
{
	struct tochka A, B, C;
	printf("Vavedi koordinati na tochka A: ");
	scanf("%d %d",&A.x, &A.y);
	printf("Vavedi koordinati na tochka B: ");
	scanf("%d %d",&B.x, &B.y);
	C=sabirane(A, B);
	printf("A+B=C(x=%d, y=%d)\n",C.x, C.y);
	if(sasedni(A, B))
		printf("A i B sa sasedni.");
	else
		printf("A i B ne sa sasedni.");
	return 0;
}

tochka sabirane(tochka a, tochka b)
{
	tochka c;
	c.x=a.x+b.x;
	c.y=a.y+b.y;
	return c;
}

int sasedni(tochka a, tochka b)
{
	if((a.x==b.x && (a.y==b.y+1 || a.y==b.y-1)) || (a.y==b.y && (a.x==b.x+1 || a.x==b.x-1)))
		return 1;
	else
		return 0;
}
