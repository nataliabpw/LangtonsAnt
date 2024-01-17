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
			if (nn==ant->n){
				mm++;
				nn=0;
			}
			if (mm==ant->m)
				break;
			if (z==L'█'){
				ant->s[mm][nn]=1;
				printf("%d %d \n", nn, mm);
			}else if (z!=L' ' && nn!=0 && nn!=ant->n-1 && mm!=0 && mm!=ant->m-1){
				ant->x=nn;
				ant->y=mm;
				if (z==L'△'){
					ant->d=0;
					ant->s[mm][nn]=0;
				} else if (z==L'▲'){
					ant->d=0;
					ant->s[mm][nn]=1;
				} else if (z==L'▷'){
					ant->d=1;
					ant->s[mm][nn]=0;
				} else if (z==L'▶'){
					ant->d=1;
					ant->s[mm][nn]=1;
				} else if (z==L'▽'){
					ant->d=2;
					ant->s[mm][nn]=0;
				} else if (z==L'▼'){
					ant->d=2;
					ant->s[mm][nn]=1;	
				} else if (z==L'◁'){
					ant->d=3;
					ant->s[mm][nn]=0;
				} else if (z==L'◀'){
					ant->d=3;
					ant->s[mm][nn]=1;
				}
			}else
				ant->s[mm][nn]=0;
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
