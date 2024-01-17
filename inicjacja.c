#include "inicjacja.h"
#include <wchar.h>
#include <stdio.h>

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
			if (z==WEOF)
				break;
			wprintf(L"Wczytano symbol: %lc\n", z);
			if (nn==ant->n){
				mm++;
				nn=0;
			}
			if (mm==ant->m)
				break;
			if (z==L'█')
				ant->s[mm][nn]=1;
			else if (z!=L' ' && nn!=0 && nn!=ant->n-1 && mm!=0 && mm!=ant->m-1){
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
	return 0;
}
