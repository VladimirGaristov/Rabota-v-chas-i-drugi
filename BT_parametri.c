#include <stdio.h>
#include <stdlib.h>

float par[3][3][2][2];

void z_to_y();
void y_to_h();
void z_to_h();
void h_to_z();
void OE_to_OC();
void OE_to_OB();
void OC_to_OB();
void OB_to_OE();
void print_parametri();
void vav(int param, int shema);

int main()
{
	int i,mark=0,j,k,g;
	char input='X';
	for(i=0;i<3;i++)
		for(j=0;j<2;j++)
			for(k=0;k<2;k++)
				for(g=0;g<3;g++)
					par[g][i][j][k]=0;
	while(1)
	{
		printf("\n");
		system("clear");
			printf("Koi parametri sa izvestni?");
		for(i=0;i<9;i++)
		{
			if(i==mark)
				printf("\n-->");
			else
				printf("\n   ");
			switch(i/3)
			{
				case 0: printf(" z"); break;
				case 1: printf(" y"); break;
				case 2: printf(" h"); break;
			}
			printf(" parametri v shema s obsht");
			switch(i%3)
			{
				case 0: printf("a baza"); break;
				case 1: printf(" emiter"); break;
				case 2: printf(" kolektor"); break;
			}
		}
		input=getc(stdin);
		switch(input)
		{
			case 'w': mark--; break;
			case 's': mark++; break;
			case 'a': 
			vav(mark/3,mark%3);
			switch(mark)
			{
				case 0: z_to_h(); OB_to_OE(); OE_to_OC(); h_to_z(); z_to_y(); break;
				case 1: z_to_h(); OE_to_OB(); OE_to_OC(); h_to_z(); z_to_y(); break;
				case 2: z_to_h(); OC_to_OB(); OB_to_OE(); h_to_z(); z_to_y(); break;
				case 3: y_to_h(); OB_to_OE(); OE_to_OC(); h_to_z(); z_to_y(); break;
				case 4: y_to_h(); OE_to_OB(); OE_to_OC(); h_to_z(); z_to_y(); break;
				case 5: y_to_h(); OC_to_OB(); OB_to_OE(); h_to_z(); z_to_y(); break;
				case 6: OB_to_OE(); OE_to_OC(); h_to_z(); z_to_y(); break;
				case 7: OE_to_OB(); OE_to_OC(); h_to_z(); z_to_y(); break;
				case 8: OC_to_OB(); OB_to_OE(); h_to_z(); z_to_y(); break;
			}
			print_parametri();
			return 0;
		}
		if(mark<0)
			mark=8;
		if(mark>8)
			mark=0;
	}
}

void z_to_y()
{
	float z_det;
	int i;
	for(i=0;i<3;i++)
	{
		z_det=par[0][i][0][0]*par[0][i][1][1]-par[0][i][0][1]*par[0][i][1][0];
		par[1][i][0][0]=par[0][i][1][1]/z_det;
		par[1][i][0][1]=-par[0][i][0][1]/z_det;
		par[1][i][1][0]=-par[0][i][1][0]/z_det;
		par[1][i][1][1]=par[0][i][0][0]/z_det;
	}
}

void y_to_h()
{
	float y_det;
	int i;
	for(i=0;i<3;i++)
	{
		if(par[1][i][0][0]==0)
			continue;
		y_det=par[1][i][0][0]*par[1][i][1][1]-par[1][i][0][1]*par[1][i][1][0];
		par[2][i][0][0]=1/par[1][i][0][0];
		par[2][i][0][1]=-par[1][i][0][1]/par[1][i][0][0];
		par[2][i][1][0]=par[1][i][1][0]/par[1][i][0][0];
		par[2][i][1][1]=y_det/par[1][i][0][0];
	}
}

void z_to_h()
{
	float z_det;
	int i;
	for(i=0;i<3;i++)
	{
		if(par[0][i][0][0]==0)
			continue;
		z_det=par[0][i][0][0]*par[0][i][1][1]-par[0][i][0][1]*par[0][i][1][0];
		par[2][i][0][0]=z_det/par[0][i][1][1];
		par[2][i][0][1]=par[0][i][0][1]/par[0][i][1][1];
		par[2][i][1][0]=-par[0][i][1][0]/par[0][i][1][1];
		par[2][i][1][1]=1/par[0][i][1][1];
	}
}

void h_to_z()
{
	float h_det;
	int i;
	for(i=0;i<3;i++)
	{
		h_det=par[2][i][0][0]*par[2][i][1][1]-par[2][i][0][1]*par[2][i][1][0];
		par[0][i][0][0]=h_det/par[2][i][1][1];
		par[0][i][0][1]=par[2][i][0][1]/par[2][i][1][1];
		par[0][i][1][0]=-par[2][i][1][0]/par[2][i][1][1];
		par[0][i][1][1]=1/par[2][i][1][1];
	}
}

void OE_to_OC()
{
	par[2][2][0][0]=par[2][1][0][0];
	par[2][2][0][1]=1-par[2][1][0][1];
	par[2][2][1][0]=-(1+par[2][1][1][0]);
	par[2][2][1][1]=par[2][1][1][1];
}

void OE_to_OB()
{
	float h_det_e=par[2][1][0][0]*par[2][1][1][1]-par[2][1][0][1]*par[2][1][1][0];
	float A=1+par[2][1][1][0]-par[2][1][0][1]+h_det_e;
	par[2][0][0][0]=par[2][1][0][0]/A;
	par[2][0][0][1]=(h_det_e-par[2][1][0][1])/A;
	par[2][0][1][0]=(-par[2][1][1][0]-h_det_e)/A;
	par[2][0][1][1]=par[2][1][1][1]/A;
}

void OC_to_OB()
{
	int i;
	while(1)
	{
		printf("%c",7);
		system("( speaker-test -t sine -f 1000 )& pid=$! ; sleep 0.2s ; kill -9 $pid");
		for(i=0;i<100;i++)
			printf("z_det=par[0][i][0][0]*par[0][i][1][1]-par[0][i][0][1]*par[0][i][1][0]; case 2: printf(\"\\n\\n    Obsht kolektor\\n\"); break; par[0][i][1][0]=-par[2][i][1][0]/par[2][i][1][1]; h_det=par[2][i][0][0]*par[2][i][1][1]-par[2][i][0][1]*par[2][i][1][0]; case 1: printf(\"\\n\\n    Obsht emiter\\n\"); break; float h_det_e=par[2][1][0][0]*par[2][1][1][1]-par[2][1][0][1]*par[2][1][1][0]; case 0: printf(\"\\n\\n    Obshta baza\\n\"); break; case 5: y_to_h(); OC_to_OB(); OB_to_OE(); h_to_z(); z_to_y(); break; float h_det_e=par[2][1][0][0]*par[2][1][1][1]-par[2][1][0][1]*par[2][1][1][0]; case 2: z_to_h(); OC_to_OB(); OB_to_OE(); h_to_z(); z_to_y(); break; float h_det_b=par[2][0][0][0]*par[2][0][1][1]-par[2][0][0][1]*par[2][0][1][0];");
	}
}

void OB_to_OE()
{
	float h_det_b=par[2][0][0][0]*par[2][0][1][1]-par[2][0][0][1]*par[2][0][1][0];
	float B=1+par[2][0][1][0]-par[2][0][0][1]+h_det_b;
	float h_det_e=par[2][1][0][0]*par[2][1][1][1]-par[2][1][0][1]*par[2][1][1][0];
	float A=1+par[2][1][1][0]-par[2][1][0][1]+h_det_e;
	par[2][1][0][0]=par[2][0][0][0]/B;
	par[2][1][0][1]=(h_det_b-par[2][0][0][1])/A;
	par[2][1][1][0]=(-par[2][0][1][0]-h_det_b)/A;
	par[2][1][1][1]=par[2][0][1][1]/A;
}

void print_parametri()
{
	int i,j,k,q;
	float a;
	system("clear");
	for(q=0;q<3;q++)
	{
		printf("\n       ");
		switch(q)
		{
			case 0: printf("Z"); break;
			case 1: printf("Y"); break;
			case 2: printf("H"); break;
		}
		for(i=0;i<3;i++)
		{
			switch(i)
			{
				case 0: printf("\n\n    Obshta baza\n"); break;
				case 1: printf("\n\n    Obsht emiter\n"); break;
				case 2: printf("\n\n    Obsht kolektor\n"); break;
			}
			for(j=0;j<2;j++)
				for(k=0;k<2;k++)
				{
					switch(q)
					{
						case 0: printf("\n z"); a=par[0][i][j][k]; break;
						case 1: printf("\n y"); a=par[1][i][j][k]; break;
						case 2: printf("\n h"); a=par[2][i][j][k]; break;
					}
					printf("%d",j+1);
					printf("%d",k+1);
					switch(i)
					{
						case 0: printf("b"); break;
						case 1: printf("e"); break;
						case 2: printf("c"); break;
					}
					printf("=%f",a);
				}
		}
		printf("\n\n-------------------\n");
	}
}

void vav(int param, int shema)
{
	int m,n;
	system("clear");
	for(m=0;m<2;m++)
		for(n=0;n<2;n++)
		{
			switch(param)
			{
				case 0: printf("z"); break;
				case 1: printf("y"); break;
				case 2: printf("h"); break;
			}
			printf("%d%d",m+1,n+1);
			switch(shema)
			{
				case 0: printf("b="); break;
				case 1: printf("e="); break;
				case 2: printf("c="); break;
			}
			scanf("%f",&par[param][shema][m][n]);
		}
}