/*
 ============================================================================
 Name        : Bresenhm_Circle_draw.c
 Author      : MitulSRV
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
float xc,yc,r;
void putpixel(int x, int y){
	glBegin(GL_POINTS);
	glVertex2f(xc+x, yc+y);
	glVertex2f(xc-x, yc+y);
	glVertex2f(xc+x, yc-y);
	glVertex2f(xc-x, yc-y);

	glVertex2f(xc+y, yc+x);
	glVertex2f(xc-y, yc+x);
	glVertex2f(xc+y, yc-x);
	glVertex2f(xc-y, yc-x);
}
void circle(){
	float p;
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0);
	float x,y;
		x = 0;
		y = r;
	p = 3 - 2*r;
	while(x <= y){
		x++;
		if(p < 0){
			p = p + 4*x + 6;
			putpixel(x,y);
		}
		else{
			y--;
			p = p + 4*x - 4*y + 10;
			putpixel(x,y);
		}
	}
	glEnd();
	glFlush();
}
void Init(){
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}
void main(int argc, char **argv){
	printf("Enter value of Xcenter and Ycenter :-");
	scanf("%f%f", &xc, &yc);
	printf("Enter value of radius");
	scanf("%f", &r);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenham Circle Drawing");
	Init();
	glutDisplayFunc(circle);
	glutMainLoop();
}
