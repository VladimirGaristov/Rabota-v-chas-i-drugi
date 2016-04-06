#include <stdio.h>
#include <string.h>

int main()
{
	int j, num=1, l;
	char s[10];
	fgets(s, sizeof(s), stdin);
	l=strlen(s)-1;
	for(j=0; j<l; j++)
		if(s[j]<'0' || s[j]>'9')
		{
			num=0;
			break;
		}
	printf("%d\n",num);
	return 0;
}