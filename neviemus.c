#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RIGHT_ANGLE 1.570796

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
	float cbx, cby, cex, cey, segA, segB;

	segA=(s->beg.x)-(s->end.x);
	segB=(s->beg.y)-(s->end.y);
	
	cbx=(s->beg.x)-(c->p.x);  //rozdiely suradnic
	cby=(s->beg.y)-(c->p.y);
	cex=(c->p.x)-(s->end.x);
	cey=(c->p.y)-(s->end.y);
	
	//printf("%f %f %f %f %f %f\n", cbx, cby, cex, cey, segA, segB);
	//printf("%f %f\n",segA, segB);
	
	ang_1=cos((segA*cbx+segB*cby)/(sqrt(pow(segA,2)+pow(segB,2))*sqrt(pow(cbx,2)+pow(cby,2))));
	ang_2=cos((segA*cex+segB*cey)/(sqrt(pow(segA,2)+pow(segB,2))*sqrt(pow(cex,2)+pow(cey,2))));
	
	if(ang_1 < RIGHT_ANGLE && ang_2 < RIGHT_ANGLE){
	// VZDIALENOST BODU OD PRIAMKY
	} else {
		if(ang_1 >= RIGHT_ANGLE){
			cb = (sqrt(pow(cbx,2)+pow(cby,2)))+(c->r);
			printf("cb: %f\n", cb);
		} else{
			ca = (sqrt(pow(cex,2)+pow(cey,2)))+(c->r);
			printf("ca: %f\n", ca);
		}
	}	
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
