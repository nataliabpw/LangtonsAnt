#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include "inicjacja.h"

// LINE_VERTICAL:│
// LINE_HORIZONTAL:─
// LINE_DOWN_RIGHT:┌
// LINE_DOWN_LEFT:┐
// LINE_UP_RIGHT:└
// LINE_UP_LEFT:┘
// SQUARE_WHITE: 
// SQUARE_BLACK:█
// ARROW_NORTH_WHITE:△
// ARROW_NORTH_BLACK:▲
// ARROW_EAST_WHITE:▷
// ARROW_EAST_BLACK:▶
// ARROW_SOUTH_WHITE:▽
// ARROW_SOUTH_BLACK:▼
// ARROW_WEST_WHITE:◁
// ARROW_WEST_BLACK:◀


int main( int argc, char **argv){
	int i, j;
	int opt;
	char pom_d='x';
	mrowka ant;
	ant.o=NULL;
	ant.l=NULL;
	ant.p=0;
	ant.m=ant.n=ant.i=0;
	setlocale(LC_ALL, "");
	while ((opt=getopt(argc, argv, "m:n:i:o:d:l:p:")) != -1){
		switch (opt){
			case 'm':
				ant.m=atoi(optarg);
				break;
			case 'n':
				ant.n=atoi(optarg);
				break;
			case 'i':
				ant.i=atoi(optarg);
				break;
			case 'o':
				ant.o=optarg;
				break;
			case 'd':
				pom_d=optarg[0];
				break;
			case 'l':
				ant.l=optarg;
				break;
			case 'p':
				ant.p=atof(optarg);
				break;
			default:
				fprintf(stderr, "Użycie ./a.out -m <wiersze> -n <kolumn> -i <iteracje> -o <plik> -d <kierunek> -l(opcjonalny) <mapa do wczytania> -r(opcjonalny) <procentowe zapełnienie>\n");
				return EXIT_FAILURE;
		}
	}
	//Obsługa błędów
	if (ant.m<=0 && ant.n<=0){
		fprintf(stderr, "Należy podać dodatnią liczbę wierszy i kolumn.\n");
		return 1;
	}
	if (ant.i<=0){
		fprintf(stderr, "Należy podać dodatnią liczbę iteracji.\n");
		return 1;
	}
	if (ant.p<0){
		fprintf(stderr, "Procentowe zapełnienie planszy nie może być ujemne.\n");
		return 1;
	}
	if (ant.l!=NULL && ant.p>0){
		fprintf(stderr, "Proszę wybrać jedną z dwóch dodatkowych opcji.\n");
		return 1;
	}

	ant.s=malloc(ant.m*sizeof(int*));
	for (i=0; i<ant.m; i++)
		ant.s[i]=malloc(ant.n*sizeof(int));
	
	if (ant.l!=NULL)
		wczytaj(&ant);
	else{
		switch (pom_d){
			case 'N':
				ant.d=0;
				break;
			case 'E':
				ant.d=1;
				break;
			case 'S':
				ant.d=2;
				break;
			case 'W':
				ant.d=3;
				break;
			default:
				fprintf(stderr, "Podaj kierunek mrówki jako N E S lub W.\n");
				return 1;
		}

		
		
		ant.y=(ant.m-1)/2;
		ant.x=(ant.n-1)/2;
		
		for (i=0; i<ant.m; i++)
			for (j=0; j<ant.n; j++)
				ant.s[i][j]=0;
		if (ant.p>0){
			los(&ant);
		}
	}
	return 0;
}
