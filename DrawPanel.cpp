#ifndef DRAWPANEL
#define DRAWPANEL

#include <GL/glut.h>
void reshape(GLsizei width, GLsizei height) {
        if (height == 0) height = 1;
        GLfloat aspect = (GLfloat)width / (GLfloat)height;

        glViewport(0, 0, width, height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        
        if (width >= height)
            gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
        else
            gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }

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
        glutIdleFunc(f);
        glutReshapeFunc(reshape);
    }
    
    void drawRect(float x,float y ,float length, float width, float angle){
        
        glRectf(x, y,x+length,y-width);
        
    }
    
    void setCallBack(void (*function)(void)){
        f = (*function);
    }
    
};
#endif
