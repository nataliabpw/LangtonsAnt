#include "ruch.h"
#include <stdio.h>

int move(mrowka *a, pole_m * p){
	int d=a->d;
	int t;
	t=p->s[a->y][a->x];
	if (t==0){
		a->d++;
		if (a->d>3)
			a->d-=4;
		p->s[a->y][a->x]=1;
	}else{
		a->d--;
		if (a->d<0)
			a->d+=4;
		p->s[a->y][a->x]=0;
	}
	switch (a->d){
		case 0:
			a->y--;
			if (a->y<0)
				a->y+=p->m;
			break;
		case 1:
			a->x=(a->x+1)%p->n;
			break;
		case 2:
			a->y=(a->y+1)%p->m;
			break;
		case 3:
			a->x--;
			if (a->x<0)
				a->x+=p->n;
			break;
	}
	return 0;
}
