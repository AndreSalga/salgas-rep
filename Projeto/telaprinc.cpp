#include "telaprinc.h"
#include "GL/glu.h"
#include "math.h"

TelaPrinc::TelaPrinc(QWidget *parent) : QGLWidget(parent)
{
        setFormat(QGL::DoubleBuffer | QGL::DepthBuffer);
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
        tgrid = 24;
        tgrid_aux = 25;
        showGrid = true;
        showReta = true;
}


void TelaPrinc::alterarX1(int i)
{
        x1 = i;
        updateGL();
}

void TelaPrinc::alterarY1(int i)
{
        y1 = i;
        updateGL();
}

void TelaPrinc::alterarX2(int i)
{
        x2 = i;
        updateGL();
}

void TelaPrinc::alterarY2(int i)
{
        y2 = i;
        updateGL();
}

void TelaPrinc::exibGrid(bool b)
{
    showGrid = b;
    updateGL();
}

void TelaPrinc::tamGrid(int i)
{
    tgrid = i;
    tgrid_aux= tgrid+1;
    updateGL();
}

void TelaPrinc::moReta(bool r)
{
    showReta = r;
    updateGL();
}

void TelaPrinc::checkDAA(bool c)
{
    showDDA = c;
    updateGL();
}

void TelaPrinc::moFronteira(bool f)
{
    showFront = f;
    updateGL();
}

void TelaPrinc::especReta(int i)
{
    espessura = i;
    updateGL();
}

void TelaPrinc::checkPM(bool c)
{
    showPM = c;
    updateGL();
}

void TelaPrinc::checkEE(bool c)
{
    showEE = c;
    updateGL();
}

void TelaPrinc::construirGrid(){
          glLineWidth(1); // Defina a espessura da malha
          glColor3f(0, 0,0); // Define a cor da malha

          glBegin(GL_LINES);
              /* Horizontal lines. */
              for (int i=0; i<=tgrid; i++) {
                glVertex2f(0, i);
                glVertex2f(tgrid, i);
              }
              /* Vertical lines. */
              for (int i=0; i<=tgrid; i++) {
                glVertex2f(i, 0);
                glVertex2f(i, tgrid);
              }
              glEnd();
}

void TelaPrinc::desenharReta()
{
    glLineWidth(espessura);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glEnd();
}

void TelaPrinc::desenharDDA()
{

      float dx=(x2-x1);
      float dy=(y2-y1);
      int steps;
      float xInc,yInc,x=x1,y=y1;

      glLineWidth(1);
      glColor3f(0, 0, 1);

      if (std::abs(dx) > std::abs(dy))
         steps = std::abs(dx);
      else
         steps = std::abs(dy);


      xInc=dx/(float)steps;
      yInc=dy/(float)steps;

      for(int v=0; v < steps; v++)
      {
         x = x + xInc;
         y = y + yInc;
         desenharPixel(round(x), round(y));
      }
      desenharPixel(x2,y2);
}

void TelaPrinc::desenharPM()
{

    float dx, dy, d, incE, incNE, x=0, y;
     glColor3f(0, 0, 0);
    dx = x2 - x1;
    dy = y2 - y1;
    d = 2*dy - dx;
    incE = 2*dy;
    incNE = 2*(dy - dx);
    y = y1;

    for (x=x1; x<=x2; x++) {
      desenharPixel(x, y);
      if (d>0) {
        d = d + incNE;
        y = y + 1;
      } else {
        d = d + incE;
      }
    }

}


void TelaPrinc::desenharEE()
{
        float dy = y2 - y1;
        float dx = x2 - x1;
        float Y;
        float a = (dy / dx);

        glColor3f(0,1,0);

        for (float x = x1; x <= abs(x2); x++) {
            Y = (y1 + a * (x - x1));
            desenharPixel(x, round(Y));
        }
}


void TelaPrinc::desenharPixel(int x, int y)
{
    if(showFront){
        glBegin(GL_POLYGON);
                        glVertex2f(x, y);
                        glVertex2f(x+1, y);
                        glVertex2f(x+1, y+1);
                        glVertex2f(x, y+1);
                glEnd();
    }
    else{
    glBegin(GL_POLYGON);
    for(int k=0;k<10;++k)
    {
      glVertex2f(x + 0.1*cos(k*2*3.14159265/10), y + 0.1*sin(k*2*3.14159265/10));
    }
    glEnd();
    }
}



float TelaPrinc::valor(float v)
{
    return floor(v + 0.5);
}


void TelaPrinc::initializeGL()
{
       glShadeModel(GL_SMOOTH);

        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
        glClearDepth(1.0f);

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);

        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void TelaPrinc::resizeGL(int width, int height)
{
    double menorX = 0, maiorX = tgrid, menorY = 0, maiorY = tgrid;
    glViewport( 0, 0, (GLint)width, (GLint)height );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);

    if (width > height)
    {
        height = height?height:1;
        double novaLargura = (maiorX - menorX) * width / height;
        double difLargura = novaLargura - (maiorX - menorX);
        menorX = 0.0 - difLargura / 2.0;
        maiorX = tgrid_aux + difLargura / 2.0;
    }
    else
    {
        width = width?width:1;
        double novaAltura = (maiorY - menorY) * height / width;
        double difAltura = novaAltura - (maiorY - menorY);
        menorY = 0.0 - difAltura / 2.0;
        maiorY = tgrid_aux + difAltura / 2.0;
    }
    gluOrtho2D(menorX, maiorX, menorY, maiorY);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void TelaPrinc::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

   if(showGrid){
        construirGrid();
   }
   if (showReta){
        desenharReta();
   }

   if (showDDA){
       desenharDDA();
   }

   if(showPM){
       desenharPM();
   }

   if(showEE){
       desenharEE();
   }

}


