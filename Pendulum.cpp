#include <iostream>
#include <GL/glut.h>

using namespace std;
void call_back_display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glEnd();
    glFlush();
}

void createWindow(size_t width, size_t height){
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pendulum Clock");
    glutDisplayFunc(call_back_display);
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    createWindow(300,300);
    glutMainLoop();
    return 0;
}
