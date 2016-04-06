#include <stdio.h>
#include <stdlib.h>

int main()
{
	char s[10];
	int n=666;
	fgets(s, sizeof(s), stdin);
	n=strtol(s, NULL, 10);
	printf("%d",n);
}