#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float x;
	float y;
}POINT;

typedef struct{
	POINT beg;
	POINT end;
}SEGMENT;

typedef struct{
	POINT p;
	float r;
}CIRCLE;
	
float dist_haus_line_circ(SEGMENT *s, CIRCLE *c){
	float ang_1, ang_2;
	float cbx,cby,cex,cey;
	cbx=c->p.x-s->beg.x; ///rozdiely suradnic
	cby=c->p.y-s->beg.y;
	cex=c->p.x-s->end.x;
	cey=c->p.y-s->end.y;
	ang_1=acos((cbx*cex+cby*cey)/(sqrt(pow(cbx,2)+pow(cby,2))*sqrt(pow(cex,2)+pow(cey,2))));
	return ang_1;
	
	
}

void main(void){
	CIRCLE c1;
	SEGMENT s;
	
	printf("Zadaj suradnice stredu kruznice: \n");
	scanf("%f%f", &c1.p.x, &c1.p.y);
	
	printf("Zadaj polomer kruznice: \n");
	scanf("%f", &c1.r);
	
	printf("Zadaj suradnice bodu A na usecke: \n");
	scanf("%f%f", &s.beg.x, &s.beg.y);
	
	printf("Zadaj suradnice bodu B na usecke: \n");
	scanf("%f%f", &s.end.x, &s.end.y);
	printf("%f",dist_haus_line_circ(&s,&c1));
	 
}
