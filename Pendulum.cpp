#include <iostream>
#include <GL/glut.h>
#include "DrawPanel.cpp"
#include <tgmath.h>
using namespace std;
class Color{
public :
    GLfloat red;
    GLfloat green;
    GLfloat blue;
    Color(){}
    Color(float r, float g, float b){
        tranform(r,g,b);
    }
    void tranform(float r, float g, float b){
        red = float(r/255.0000);
        green = float(g/255.0000);
        blue = float(b/255.0000);
    } 
    void setColor(float r, float g, float b){
         tranform(r,g,b);
    }
};

Color c;
DrawPanel panel;

void drawBob(double angle){
    
}
void call_back_display(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    c.setColor(12,0,100);
    glColor3f(c.red, c.green,c.blue);
    glClear(GL_COLOR_BUFFER_BIT);
    
    panel.drawRect(0,0, .5,.02, 60);
    
    glEnd();
    glutSwapBuffers();
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    //DrawPanel panel(call_back_display);
    panel.setCallBack(call_back_display);
    panel.display();
    glutMainLoop();
    return 0;
}
