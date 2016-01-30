#include <stdio.h>

int main()
{
	int *a;
	FILE *com_file;
	com_file=fopen("address.ini","r");
	fread(&a, sizeof(int *), 1, com_file);
	*a=10;
	fclose(com_file);
	return 0;
}