#include "inicjacja.h"
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int wczytaj(mrowka * ant){
	int mm, nn;
	FILE *in=fopen(ant->l, "r");
	wint_t z;
	mm=nn=0;
	ant->d=-1;
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
			if (nn==ant->n+2){
				mm++;
				nn=0;
			}
			if (mm==ant->m+2)
				break;
			if (mm==0 || nn==0 || nn==ant->n+1 || mm==ant->m+1){
				nn++;
				continue;
			}else if (z==L'█'){
				ant->s[mm-1][nn-1]=1;
			}else if (z==L'▲' || z==L'△' || z==L'▷'|| z==L'▶' || z==L'▽' || z==L'▼' || z==L'◁' || z==L'◀'){
				ant->x=nn-1;
				ant->y=mm-1;
				if (z==L'△'){
					ant->d=0;
					ant->s[mm-1][nn-1]=0;
				} else if (z==L'▲'){
					ant->d=0;
					ant->s[mm-1][nn-1]=1;
				} else if (z==L'▷'){
					ant->d=1;
					ant->s[mm-1][nn-1]=0;
				} else if (z==L'▶'){
					ant->d=1;
					ant->s[mm-1][nn-1]=1;
				} else if (z==L'▽'){
					ant->d=2;
					ant->s[mm-1][nn-1]=0;
				} else if (z==L'▼'){
					ant->d=2;
					ant->s[mm-1][nn-1]=1;	
				} else if (z==L'◁'){
					ant->d=3;
					ant->s[mm-1][nn-1]=0;
				} else if (z==L'◀'){
					ant->d=3;
					ant->s[mm-1][nn-1]=1;
				}
			}else if(z==L' '){
				ant->s[mm-1][nn-1]=0;
			}else if (z==L'┌' || z==L'─' || z==L'┐' || z==L'│' || z==L'└' || z==L'┘'){
				fprintf(stderr, "Podane wartości m i n nie zgadzają się z wczytanym plikiem.\n");
				return 1;
			}else{
				fprintf(stderr, "Plik zawiera nieprawidłowy znak.\n");
				return 1;
			}
			nn++;	
		}
		
		if (ant->d==-1){
			fprintf(stderr, "Nie mogę odczytać pozycji mrówki.\n");
			return 1;
		}
	}else{
		fprintf(stderr,"Błąd otwarcia pliku %s\n", ant->l);
		return 1;
	}
	return 0;
}

int los(mrowka * ant){
	int i, j;
	int x=ant->m*ant->n*ant->p/100;
	int wylosowane[x];
	int k=ant->m*ant->n;
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
		m=wylosowane[i]/ant->n;
		n=wylosowane[i]%ant->n;
		ant->s[m][n]=1;
	}

	return 0;
}
