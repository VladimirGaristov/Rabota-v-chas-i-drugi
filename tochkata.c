#include <stdio.h>

struct Tochka
{
	int x;
	int y;
};

void sabirane(struct Tochka *a, struct Tochka *b, struct Tochka *c);
int sasedni(struct Tochka *a, struct Tochka *b);

int main()
{
	struct Tochka A, B, C;
	printf("Vavedi koordinati na tochka A: ");
	scanf("%d %d",&A.x, &A.y);
	printf("Vavedi koordinati na tochka B: ");
	scanf("%d %d",&B.x, &B.y);
	sabirane(&A, &B, &C);
	printf("A+B=C(x=%d, y=%d)\n",C.x, C.y);
	if(sasedni(&A, &B))
		printf("A i B sa sasedni.\n");
	else
		printf("A i B ne sa sasedni.\n");
	return 0;
}

void sabirane(struct Tochka *a, struct Tochka *b, struct Tochka *c)
{
	c->x=a->x+b->x;
	c->y=a->y+b->y;
}

int sasedni(struct Tochka *a, struct Tochka *b)
{
	if((a->x==b->x && (a->y==b->y+1 || a->y==b->y-1)) || (a->y==b->y && (a->x==b->x+1 || a->x==b->x-1)))
		return 1;
	else
		return 0;
}
