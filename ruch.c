#include "ruch.h"
#include <stdio.h>

int move(mrowka *a){
	int d=a->d;
	int t;
	t=a->s[a->y][a->x];
	if (t==0){
		a->d++;
		if (a->d>3)
			a->d-=4;
		a->s[a->y][a->x]=1;
	}else{
		a->d--;
		if (a->d<0)
			a->d+=4;
		a->s[a->y][a->x]=0;
	}
	switch (a->d){
		case 0:
			a->y--;
			if (a->y<0)
				a->y+=a->m;
			break;
		case 1:
			a->x=(a->x+1)%a->n;
			break;
		case 2:
			a->y=(a->y+1)%a->m;
			break;
		case 3:
			a->x--;
			if (a->x<0)
				a->x+=a->n;
			break;
		default:
			fprintf(stderr, "Błąd: nie mogę iść w kierunku %d\n", a->d);
			return 1;
	}
	return 0;
}
