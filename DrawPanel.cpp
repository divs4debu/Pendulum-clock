#ifndef DRAWPANEL
#define DRAWPANEL

#include <GL/glut.h>

class DrawPanel{
private :
    int height, width;
    
public:
    DrawPanel(void (*f) (void)){
        height = 300;
        width = 300;
        createWindow(height, width, f);
    }
    
    void createWindow(size_t height, size_t width, void f (void)){
        
        glutInitWindowSize(width, height);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("Pendulum");
        glutDisplayFunc(f);
    
    
};
#endif
