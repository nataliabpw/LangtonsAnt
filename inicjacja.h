#ifndef _INICJACJA_H_IS_INCLUDED_
#define _INICJACJA_H_IS_INCLUDED_
#include <stdio.h>
typedef struct{
	int **s;
	int m;
	int n;
	int i;
	char *o;
	int d;
	char *l;
	double p;
	FILE  *out;
	int x;//n ant_location
	int y;//m ant_location
} mrowka;

int wczytaj(mrowka * ant);
int los(mrowka * ant);
#endif
