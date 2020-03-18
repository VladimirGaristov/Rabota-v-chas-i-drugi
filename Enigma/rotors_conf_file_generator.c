#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	unsigned short int a[256], i, b, j, q;
	FILE *rotors_conf_file;
	
	rotors_conf_file = fopen("rotors.ini", "w");
	srand(time(NULL));
	for (q = 0; q < 5; q++)
	{
		for (i = 0; i < 256; i++)
			a[i] = i;
		for ( i = 0; i < 256; i++)
		{
			b = a[i];
			j = rand() % 256;
			a[i] = a[j];
			a[j] = b;
		}
		for (i = 0; i < 256; i++)
			fwrite(&a[i], sizeof(unsigned short int), 1, rotors_conf_file);
	}
	fclose(rotors_conf_file);
	return 0;
}