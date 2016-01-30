#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void kodirane();

char current_letter;
unsigned short int kod_dekod, plugboard[26], left_rotor, center_rotor, right_rotor,
				   left_rotor_offset, center_rotor_offset, right_rotor_offset,
				   rotors[5][26]={{5, 8, 3 ,9, 11, 21, 13, 22, 0, 1, 17, 14, 2, 16, 4, 25, 6, 23, 7, 10, 15, 20, 12, 18, 24, 19},
				   				  {22, 4, 25, 6, 23, 7, 10, 15, 20, 12, 18, 8, 3, 1, 24, 19, 2, 16, 21, 13, 5, 0 ,9, 11, 17, 14},
				   				  {11, 17, 14, 25, 6, 8, 3, 4, 2, 16, 22, 0, 9, 21, 23, 15, 20, 12, 18, 1, 24, 7, 10, 19, 13, 5},
				   				  {14, 3, 4, 2, 16, 11, 17, 8, 19, 13, 5, 20, 22, 15, 12, 18, 1, 24, 7, 0, 25, 6, 9, 21, 23, 10},
				   				  {16, 11, 15, 12, 9, 21, 17, 20, 24, 7, 0, 25, 6, 22, 23, 10, 14, 3, 18, 1, 4, 8, 19, 13, 5, 2}};

int main()
{
	unsigned short int i;
	for(i=0;i<26;i++)
		plugboard[i]=1000;
	do
	{
	printf("\nLiav rotor: ");
	scanf("%hu", &left_rotor);
	}
	while(left_rotor>5);
	printf("Zavartian na: ");
	scanf("%hu", &left_rotor_offset);
	left_rotor_offset=left_rotor_offset%26;
	do
	{
	printf("Sreden rotor: ");
	scanf("%hu", &center_rotor);
	}
	while(center_rotor>5 || center_rotor==left_rotor);
	printf("Zavartian na: ");
	scanf("%hu", &center_rotor_offset);
	center_rotor_offset=center_rotor_offset%26;
	do
	{
	printf("Desen rotor: ");
	scanf("%hu", &right_rotor);
	}
	while(right_rotor>5 || right_rotor==left_rotor || right_rotor==center_rotor);
	printf("Zavartian na: ");
	scanf("%hu", &right_rotor_offset);
	right_rotor_offset=right_rotor_offset%26;
	printf("\nSvurji panela:\n");
	for(i=0;i<27;i++)
		if(plugboard[i]==1000)
		{
			printf("%c-",i+65);
			current_letter=getchar();
			current_letter=getchar();
			plugboard[i]=(int)current_letter-65;
			plugboard[(int)current_letter-65]=i;
		}
	while(1)
	{
		printf("\nVavedi 'K' za kodirane, 'D' za dekodirane ili 'I' za izhod: ");
		current_letter=getchar();
		current_letter=getchar();
		if(current_letter=='K')
		{
			kod_dekod=0;
			kodirane();
		}
		if(current_letter=='D')
		{
			kod_dekod=1;
			kodirane();
		}
		if(current_letter=='I')
			exit(0);
	}
}

void kodirane()
{
	unsigned short int j, c;
	FILE *input, *output;
	input=fopen("input.txt","r");
	output=fopen("output.txt","w");
	while(!feof(input))
	{
		fread(&current_letter, sizeof(char), 1, input);
		if(kod_dekod==0)
			current_letter=rotors[left_rotor][(left_rotor_offset+rotors[center_rotor][(center_rotor_offset+rotors[right_rotor][(right_rotor_offset+plugboard[(int)current_letter-65])%26])%26])%26]+65;
		else
		{
			c=(int)current_letter-65;
			for(j=0;rotors[left_rotor][(left_rotor_offset+j)%26]!=c;j++);
			c=j;
			for(j=0;rotors[center_rotor][(center_rotor_offset+j)%26]!=c;j++);
			c=j;
			for(j=0;rotors[right_rotor][(right_rotor_offset+j)%26]!=c;j++);
			c=j;
			for(j=0;plugboard[j]!=c;j++);
			c=j;
			current_letter=c+65;
		}
		left_rotor_offset++;
		left_rotor_offset%=26;
		center_rotor_offset++;
		center_rotor_offset%=26;
		right_rotor_offset++;
		right_rotor_offset%=26;
		fwrite(&current_letter, sizeof(char), 1, output);
	}
	truncate(output, sizeof(char));
	fclose(input);
	fclose(output);
}