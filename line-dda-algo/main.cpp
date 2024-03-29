#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void myInit()
{
  glClearColor(1.0,1.0,1.0,0); /* Set clear color to white */
  glColor3f(0.0,0.0,0.0);      /* Set fill color to black */
  gluOrtho2D(0 , 640 , 0 , 480);
}

float round_value(float v)
{
  return floor(v + 0.5);
}
void draw_line(double X1, double Y1, double X2, double Y2)
{
  double dx=(X2-X1);
  double dy=(Y2-Y1);
  double steps;
  float xInc,yInc,x=X1,y=Y1;
  /* Find out whether to increment x or y */
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;

  /* Clears buffers to preset values */
  glClear(GL_COLOR_BUFFER_BIT);

  /* Plot the points */
  glBegin(GL_POINTS);
  /* Plot the first point */
  glVertex2d(x,y);
  int k;
  /* For every step, find an intermediate vertex */
  for(k=0;k<steps;k++)
  {
    x+=xInc;
    y+=yInc;
    /* printf("%0.6lf %0.6lf\n",floor(x), floor(y)); */
    glVertex2d(round_value(x), round_value(y));
  }
  glEnd();

  glFlush();
}

void myDisplay() {
	draw_line(100,0,100,100);
	glFlush();
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
	glutCreateWindow("DDA Line Drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;

}








