#include "wypisywanie.h"
#include "inicjacja.h"
#include <stdio.h>
#include <string.h>

char *mr( mrowka * ant){
	int d=ant->d;
	int t=ant->s[ant->y][ant->x];
	if (d==0)
		if (t==1)
			return "▲";
		else
			return "△";
	if (d==2)
		if (t==1)
			return "▼";
		else
			return "▽";
	if (d==1)
		if (t==1)
			return "▶";
		else
			return "▷";
	if (d==3)
		if (t==1)
			return "◀";
		else
			return "◁";
}

int wypisz(mrowka * ant, int nr){
	int i, j, m, n;
	char *x;
	FILE *out;
	int len=1;
	x=mr(ant);
	m=ant->m;
	n=ant->n;	

	if (ant->o!=NULL){
		for (i=10; (nr/i)>=1; i*=10)
			len++;
		char numer[len];
		len+=strlen(ant->o)+1;
		char nazwa[len];
		sprintf(numer, "%d", nr);
		strcpy(nazwa, "");
		strcat(nazwa, ant->o);
		strcat(nazwa, "_");
		strcat(nazwa, numer);
		out = fopen(nazwa,"w");
	}else
		out = stdout;

	if (out==NULL){
		fprintf(stderr, "Nie moge pisać do %s_%d\n", ant->o, nr);
		return 1;
	}
	for(i=0; i<m+2; i++){
		for(j=0; j<n+2; j++)
			if (i-1==ant->y && j-1==ant->x)
				fprintf(out,"%s", x);
			else if (i>0 && j>0 && i-1<m && j-1<n && ant->s[i-1][j-1]==1)
				fprintf(out, "█");
			else if (i==0 && j==0)
				fprintf(out, "┌");
			else if (i==0 && j==n+1)
				fprintf(out, "┐");
			else if (i==m+1 && j==0)
				fprintf(out, "└");
			else if (i==m+1 && j==n+1)
				fprintf(out, "┘");
			else if (j==0 || j==n+1)
				fprintf(out, "│");
			else if (i==0 || i==m+1)
				fprintf(out, "─");
			else if (i>0 && j>0 && i-1<m && j-1<n && ant->s[i-1][j-1]==0)
				fprintf(out, " ");
		fprintf(out,"\n");
	}
	fclose(out);
	return 0;
}
