#include "inicjacja.h"
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int wczytaj(mrowka * ant, pole_m * pole, char *l){
	int mm, nn;
	FILE *in=fopen(l, "r");
	wint_t z;
	ant->x=-1;
	ant->y=-1;
	mm=nn=0;
	if (in!=NULL){
		while ((z=fgetwc(in)) !=WEOF){
			while (z==L'\n')
				z=fgetwc(in);
			if (nn==0 && mm==0){
				while (z!=L'┌')
					z=fgetwc(in);
			}
			if (z==WEOF)
				break;
			if (nn==pole->n+2){
				mm++;
				nn=0;
			}
			if (mm==pole->m+2)
				break;
			if (mm==0 || nn==0 || nn==pole->n+1 || mm==pole->m+1){
				nn++;
				continue;
			}else if (z==L'█'){
				pole->s[mm-1][nn-1]=1;
			}else if (z==L'▲' || z==L'▶' || z==L'▼' || z==L'◀'){
				ant->x=nn-1;
				ant->y=mm-1;
				pole->s[mm-1][nn-1]=1;
			}else if (z==L'△' || z==L'▷' || z==L'▽' || z==L'◁'){
				ant->x=nn-1;
				ant->y=mm-1;
				pole->s[mm-1][nn-1]=0;
			}else if(z==L' '){
					pole->s[mm-1][nn-1]=0;
			}else if (z==L'┌' || z==L'─' || z==L'┐' || z==L'│' || z==L'└' || z==L'┘'){
				fprintf(stderr, "Podane wartości m i n nie zgadzają się z wczytanym plikiem.\n");
				return 1;
			}else{
				fprintf(stderr, "Plik zawiera nieprawidłowy znak.\n");
				return 1;
			}
			nn++;	
		}
		
		if (ant->x==-1 || ant->y==-1){
			fprintf(stderr, "Nie mogę odczytać pozycji mrówki.\n");
			return 1;
		}
	}else{
		fprintf(stderr,"Błąd otwarcia pliku %s\n", l);
		return 1;
	}
	return 0;
}

int los(pole_m * pole){
	int i, j;
	int x=pole->m*pole->n*pole->p/100;
	int wylosowane[x];
	int k=pole->m*pole->n;
	int m,n;
	srand(time(NULL));
	for (i=0; i<x; i++){
		wylosowane[i]=rand() % k;
       		for (j=0; j<i; j++)
			if (wylosowane[i] == wylosowane[j]){
				i--;
				break;
			}
	}
	for (i=0; i<x; i++){
		m=wylosowane[i]/pole->n;
		n=wylosowane[i]%pole->n;
		pole->s[m][n]=1;
	}

	return 0;
}
