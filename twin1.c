#include <stdio.h>

int main()
{
	int a=5, *adr;
	char w;
	FILE *com_file;
	adr=&a;
	com_file=fopen("address.ini","w");
	fwrite(&adr, sizeof(int *), 1, com_file);
	fclose(com_file);
	w=getchar();
	printf("%d\n", a);
	return 0;
}