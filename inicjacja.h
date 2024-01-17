#ifndef _INICJACJA_H_IS_INCLUDED_
#define _INICJACJA_H_IS_INCLUDED_

typedef struct{
	int d;
	int x;//n ant_location
	int y;//m ant_location
} mrowka;

typedef struct{
	int **s;
	int m;
	int n;
	double p;
} pole_m;

int wczytaj(mrowka * ant, pole_m * pole, char *l);
int los(pole_m * pole);
#endif
