#ifndef DRAWPANEL
#define DRAWPANEL

#include <GL/glut.h>

class DrawPanel{
private :
    int height, width;
    void (*f) (void);
    
public:
    DrawPanel (){
        height = 300;
        width = 300;
    }
    DrawPanel(void (*f) (void)){
        height = 300;
        width = 300;
        createWindow(height, width, f);
    }
    
    void display(){
        createWindow(height, width, f);
    }
    void createWindow(size_t height, size_t width, void (*f) (void)){
        
        glutInitWindowSize(width, height);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("Pendulum");
        glutDisplayFunc(f);
    }
    
    void drawRect(float x,float y ,float length, float width, float angle){
        glRotatef(angle, 0.0,0.0,1.0);
        glRectf(x, y,x+length,y-width);
        glRotatef(-angle, 0.0,0.0,1.0);
    }
    
    void setCallBack(void (*function)(void)){
        f = (*function);
    }
    
};
#endif
