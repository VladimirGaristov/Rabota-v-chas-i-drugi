#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	unsigned short int a[256], i, j;
	FILE *plugboard_conf_file;
	srand(time(NULL));
	for(i=0;i<256;i++)
		a[i]=1000;
	for(i=0;i<256;i++)
		if(a[i]==1000)
		{
			do
			{
				j=rand()%256;
			}
			while(a[j]!=1000);
			a[i]=j;
			a[j]=i;
		}
	plugboard_conf_file=fopen("plugboard.ini","w");
	for(i=0;i<256;i++)
		fwrite(&a[i], sizeof(unsigned short int), 1, plugboard_conf_file);
	fclose(plugboard_conf_file);
	return 0;
}