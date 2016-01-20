#include <stdio.h>

int main()
{
	int input, position=1, digit, output=0;
	printf("Vavedi chislo: ");
	scanf("%d",&input);
	while(input!=0)
	{
		digit=input%8;
		output+=digit*position;
		position*=10;
		input/=8;
	}
	printf("%d\n",output);
	return 0;
}