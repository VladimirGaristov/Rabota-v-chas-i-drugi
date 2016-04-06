#include <stdio.h>

int main()
{
	char input[100], a='f';
	int b=42;
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%c %d", &a, &b);
	printf("\n%c %d\n",a, b);
	scanf("%d   %c", &b, &a);
	printf("\n%c %d\n",a, b);
	return 0;
}