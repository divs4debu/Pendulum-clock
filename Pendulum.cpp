#include <iostream>
#include <GL/glut.h>
#include "DrawPanel.cpp"

using namespace std;
class Color{
public :
    GLfloat red;
    GLfloat green;
    GLfloat blue;
    Color(float r, float g, float b){
        red = float(r/255.0000);
        green = float(g/255.0000);
        blue = float(b/255.0000);
    }
};


void call_back_display(){
    Color c(0,121,107);
    GLfloat color[] = {c.red, c.green, c.blue};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glClearColor(color[0], color[1], color[2], 1.0f);
    //glutPostRedisplay();
    glRectf(-.01f, .75f, .01f, -.75f);
    glEnd();
    glutSwapBuffers();
}

    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pendulum Clock");
    glutDisplayFunc(call_back_display);
}*/
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    DrawPanel panel(call_back_display);
    glutMainLoop();
    return 0;
}
