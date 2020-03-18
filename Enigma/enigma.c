#include <stdio.h>
#include <stdlib.h>

void kodirane(int kod_dekod);
void conf_rotors();
int conf_plugboard();

unsigned short int plugboard[256], rotors[5][256],
				   left_rotor = 0, center_rotor = 1, right_rotor = 2,
				   left_rotor_offset = 0, center_rotor_offset = 0, right_rotor_offset = 0,
				   initial_left_rotor_offset = 0, initial_center_rotor_offset = 0, initial_right_rotor_offset = 0;
FILE *rotors_conf_file, *plugboard_conf_file;

int main()
{
	unsigned short int i, j;
	int c, n;
	rotors_conf_file = fopen("rotors.ini", "r");
	for (j = 0; j < 5; j++)
		for (i = 0; i < 256; i++)
			fread(&rotors[j][i], sizeof(unsigned short int), 1, rotors_conf_file);
	fclose(rotors_conf_file);
	plugboard_conf_file = fopen("plugboard.ini", "r");
	for (i = 0; i < 256; i++)
		fread(&plugboard[i], sizeof(unsigned short int), 1, plugboard_conf_file);
	fclose(plugboard_conf_file);
	while(1)
	{
		printf("\nVavedi 'K' za kodirane, 'D' za dekodirane, 'R' za konfigurirane na rotorite,");
		printf("\n'P' za konfigurirane na panela ili 'I' za izhod: ");
		c = fgetc(stdin);
		fgetc(stdin);
		switch(c)
		{
			case 'K': case 'k': kodirane(0); break;
			case 'D': case 'd': kodirane(1); break;
			case 'R': case 'r': conf_rotors(); break;
			case 'P': case 'p': conf_plugboard(); break;
			case 'I': case 'i': return 0;
		}
	}
}

void kodirane(int kod_dekod)
{
	unsigned char current_letter;
	unsigned short int j, c;
	FILE *input, *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	left_rotor_offset = initial_left_rotor_offset;
	center_rotor_offset = initial_center_rotor_offset;
	right_rotor_offset = initial_right_rotor_offset;
	while (!feof(input))
	{
		if (!fread(&current_letter, sizeof(unsigned char), 1, input))
			continue;
		//printf("\n%d---", current_letter);
		if (kod_dekod == 0)
			current_letter = (unsigned char) rotors[left_rotor][(left_rotor_offset + rotors[center_rotor][(center_rotor_offset + rotors[right_rotor][(right_rotor_offset + plugboard[(int) current_letter]) % 256]) % 256]) % 256];
		else
		{
			c = (unsigned short int) current_letter;
			for (j = 0; rotors[left_rotor][(left_rotor_offset + j) % 256] != c; j++);
			c = j;
			for (j = 0; rotors[center_rotor][(center_rotor_offset + j) % 256] != c; j++);
			c = j;
			for (j = 0; rotors[right_rotor][(right_rotor_offset + j) % 256] != c; j++);
			c = j;
			for (j = 0; plugboard[j] != c; j++);
			c = j;
			current_letter = (unsigned char) c;
		}
		left_rotor_offset++;
		left_rotor_offset %= 256;
		center_rotor_offset++;
		center_rotor_offset %= 256;
		right_rotor_offset++;
		right_rotor_offset %= 256;
		//printf("%d", current_letter);
		fwrite(&current_letter, sizeof(unsigned char), 1, output);
	}
	fclose(input);
	fclose(output);
}

void conf_rotors()
{
	system("clear");
	do
	{
		printf("\nLiav rotor: ");
		scanf("%hu", &left_rotor);
	}
	while (left_rotor > 5);
	printf("Zavartian na: ");
	scanf("%hu", &initial_left_rotor_offset);
	initial_left_rotor_offset %= 256;
	left_rotor_offset = initial_left_rotor_offset;
	do
	{
		printf("Sreden rotor: ");
		scanf("%hu", &center_rotor);
	}
	while (center_rotor > 5 || center_rotor == left_rotor);
	printf("Zavartian na: ");
	scanf("%hu", &initial_center_rotor_offset);
	initial_center_rotor_offset %= 256;
	center_rotor_offset = initial_center_rotor_offset;
	do
	{
		printf("Desen rotor: ");
		scanf("%hu", &right_rotor);
	}
	while (right_rotor > 5 || right_rotor == left_rotor || right_rotor == center_rotor);
	printf("Zavartian na: ");
	scanf("%hu", &initial_right_rotor_offset);
	initial_right_rotor_offset %= 256;
	right_rotor_offset = initial_right_rotor_offset;
}

int conf_plugboard()
{
	unsigned short int symbol, q;
	int otg;
	system("clear");
	printf("\nVNIMANIE! Tova shte iztrie predishnata konfiguracia. Ako se vavede nevalidna konfiguracia, programata shte se preebe!");
	printf("\nSigurni li ste, che iskate da prodaljite?\nVavedete 'D' za da ili 'N' za ne: ");
	otg = fgetc(stdin);
	fgetc(stdin);
	if (otg == 'D' || otg == 'd')
	{
		for (q = 0; q < 256; q++)
			plugboard[q] = 1000;
		printf("\nSvurji panela:\n");
		for (q = 0; q < 256; q++)
			if (plugboard[q] == 1000)
			{
				do
				{
					printf("%hu-", q);
					scanf("%hu", &symbol);
				}
				while (symbol > 256);
				plugboard[q] = symbol;
				plugboard[symbol] = q;
			}
		plugboard_conf_file = fopen("plugboard.ini", "w");
		for (q = 0; q < 256; q++)
			fwrite(&plugboard[q], sizeof(unsigned short int), 1, plugboard_conf_file);
		fclose(plugboard_conf_file);
		return 1;
	}
	else
		return 0;
}