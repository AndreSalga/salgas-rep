
#include "PaintTela.h"
#include "JanelaPrincipal.h"
#include "GL/glu.h"
#include "math.h"
//#include <stdlib.h>

PaintTela::PaintTela(QWidget *parent) : QGLWidget(parent)
{
    setFormat(QGL::DoubleBuffer | QGL::DepthBuffer);
    Grid = 0;
    tam = 30;
    p = 0;
}

void PaintTela::initializeGL() {
    glShadeModel(GL_SMOOTH);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void PaintTela::selecionar(int poligono) {
    if (p!=poligono && poligono>= 0 && poligono<15) {
        p = poligono;
    }
    updateGL();
}

void PaintTela::escolherForma(int forma) {
    if (forma!=figura[p] && forma>=0 && forma<=4) {
        figura[p] = forma;
    }
    updateGL();
}

void PaintTela::criarFigura() {
    srand(time(NULL));
    if(poligonos[p]==FALSE) {
        red[p] = (rand()%256);
        green[p] = (rand()%256);
        blue[p] = (rand()%256);
        eixoX[p] = 0.0;
        eixoY[p] = 1.0;
        eixoZ[p] = -4.0;
        escalaX[p] = 1.0;
        escalaY[p] = 1.0;
        escalaZ[p] = 1.0;
        anguloX[p] = 0.0;
        anguloY[p] = 0.0;
        anguloZ[p] = 0.0;
        //cisalhaX[p] = 0.0;
        //cisalhaY[p] = 0.0;
        poligonos[p]= 1;
    }
    updateGL();
}

void PaintTela::alterarR(int verm) {
    if (red[p] != verm && verm >= 0 && verm <= 255) {
        red[p] = verm;
    }
    updateGL();
}

void PaintTela::alterarG(int verde) {
    if (green[p] != verde && verde >= 0 && verde <= 255) {
        green[p] = verde;
    }
    updateGL();
}

void PaintTela::alterarB(int azul) {
    if (blue[p] != azul && azul >= 0 && azul <= 255) {
        blue[p] = azul;
    }
    updateGL();
}

void PaintTela::transladarX(double x) {
    if(x!=eixoX[p] && eixoX[p] >= -20.0 && eixoX[p] <=20.0)
        eixoX[p] = x;
    updateGL();
}

void PaintTela::transladarY(double y) {
    eixoY[p] = y;
    updateGL();
}

void PaintTela::transladarZ(double z) {
    if(z!=eixoZ[p] && eixoZ[p] >= -20.0 && eixoZ[p] <=20.0)
        eixoZ[p] = z;
    updateGL();
}

void PaintTela::escalarX(double x) {
    if (x!= escalaX[p] && escalaX[p]>= 1.0 && escalaX[p] <= 20.0)
        escalaX[p] = x;
    updateGL();
}

void PaintTela::escalarY(double y){
    if (y!= escalaY[p] && escalaY[p]>= 1.0 && escalaY[p]<= 20.0)
        escalaY[p] = y;
    updateGL();
}

void PaintTela::escalarZ(double z){
    if (z!= escalaZ[p] && escalaZ[p]>= 1.0 && escalaZ[p]<= 20.0)
        escalaZ[p] = z;
    updateGL();
}


void PaintTela::rotacionarX(double x) {
    if (x != anguloX[p] && anguloX[p] >= -360 && anguloX[p] <= 360.0)
        anguloX[p] = x;
    updateGL();
}
void PaintTela::rotacionarY(double y) {
    if (y!= anguloY[p] && anguloY[p] >= -360 && anguloY[p] <= 360.0)
        anguloY[p] = y;
    updateGL();
}
void PaintTela::rotacionarZ(double z) {
    if (z!= anguloZ[p] && anguloZ[p] >= -360 && anguloZ[p] <= 360.0)
        anguloZ[p] = z;
    updateGL();
}

/*
void PaintTela::cisalharX(double x) {
    if (x!= cisalhaX[p] && cisalhaX[p]>= 0.0 && cisalhaX[p]<= 3.0)
        cisalhaX[p] = x;
    updateGL();
}

void PaintTela::cisalharY(double y) {
    if (y!= cisalhaY[p] && cisalhaY[p]>= 0.0 && cisalhaY[p]<= 3.0)
        cisalhaY[p] = y;
    updateGL();
}*/

void PaintTela::excluirFigura () {
    if (poligonos[p] == TRUE) { //se o polígono existir, desativar
        poligonos[p] = FALSE;
    }
    updateGL();
}

void PaintTela::excluirTodos () {
    for(int i=0; i<15; i++) {
        if (poligonos[i] == TRUE) { //se o polígono existir, desativa ele
            poligonos[i] = FALSE;
        }
    }
    updateGL();
}
void PaintTela::tamanhoMalha(int t) {
    tam = t;
    updateGL();
}

void PaintTela::exibirMalha() {
    if (Grid == FALSE) {
        Grid = TRUE;
    }
    else {
        Grid = FALSE;
    }
    updateGL();
}

void PaintTela::ativarIluminacao() {
    if (iluminacao == FALSE) {
        iluminacao = TRUE;
    }
    else {
        iluminacao = FALSE;
    }
    updateGL();
}

void PaintTela::alterarCameraY(int Y){
    cameraP = Y;
    cameraX = cameraR*cos(Y*2*3.14159265/180);
    cameraZ = cameraR*sin(Y*2*3.14159265/180);
    updateGL();
}
void PaintTela::alterarCameraE(int E){
    cameraY = E;
    updateGL();
}
void PaintTela::alterarCameraD(int D){
    cameraR = D;
    cameraX = cameraR*cos(cameraP*2*3.14159265/180);
    cameraZ = cameraR*sin(cameraP*2*3.14159265/180);
    updateGL();
}


void PaintTela:: drawGrid(){
    glLoadIdentity();
    float i=-50;
    float incremento = (100/float(tam)); //O range do tamanho divido pela quantidade desejada
    do {
        glLineWidth(1);
        glColor3f(0.4,0.4,0.4);
        glBegin(GL_LINES);
        glVertex3f(50,0,i);
        glVertex3f(-50,0,i);
        glEnd();
        glColor3f(0.4,0.4,0.4);
        glBegin(GL_LINES);
        glVertex3f(i,0,50);
        glVertex3f(i,0,-50);
        glEnd();
        i=i+incremento;
    }while(i<=50);
}

void PaintTela:: drawPiramide(int j){
    glTranslated(eixoX[j], eixoY[j], eixoZ[j]);
    glRotated(anguloX[j], 1, 0, 0);
    glRotated(anguloY[j], 0, 1, 0);
    glRotated(anguloZ[j], 0, 0, 1);
    glScaled(escalaX[j], escalaY[j], escalaZ[j]);

    glBegin(GL_TRIANGLES);
     //glColor3f(0.7,0.7,0.7);


      glColor3ub(red[j],green[j],blue[j]);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3ub(red[j],green[j],blue[j]);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3ub(red[j],green[j],blue[j]);
      glVertex3f(1.0f, -1.0f, 1.0f);

      glColor3ub(red[j],green[j],blue[j]);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3ub(red[j],green[j],blue[j]);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3ub(red[j],green[j],blue[j]);
      glVertex3f(1.0f, -1.0f, -1.0f);

      glColor3ub(red[j],green[j],blue[j]);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3ub(red[j],green[j],blue[j]);
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3ub(red[j],green[j],blue[j]);
      glVertex3f(-1.0f, -1.0f, -1.0f);

      glColor3ub(red[j],green[j],blue[j]);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3ub(red[j],green[j],blue[j]);
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3ub(red[j],green[j],blue[j]);
      glVertex3f(-1.0f,-1.0f, 1.0f);
      glLineWidth(2);
// glEnd();
   glEnd();
   glColor3f(1,0,0);
   glBegin(GL_LINES);
       glVertex3f(raio,0,0);
       glVertex3f(0,0,0);
   glEnd();

   glColor3f(0,1,0);
   glBegin(GL_LINES);
       glVertex3f(0,raio,0);
       glVertex3f(0,0,0);
   glEnd();

   glColor3f(0,0,1);
   glBegin(GL_LINES);
       glVertex3f(0,0,raio);
       glVertex3f(0,0,0);
   glEnd();
}

void PaintTela:: drawCubo(int j){
    glTranslated(eixoX[j], eixoY[j], eixoZ[j]);
    glRotated(anguloX[j], 1, 0, 0);
    glRotated(anguloY[j], 0, 1, 0);
    glRotated(anguloZ[j], 0, 0, 1);
    glScaled(escalaX[j], escalaY[j], escalaZ[j]);
       glBegin(GL_QUADS);
          glColor3ub(red[j],green[j],blue[j]);
          glVertex3f( 1.0f, 1.0f, -1.0f);
          glVertex3f(-1.0f, 1.0f, -1.0f);
          glVertex3f(-1.0f, 1.0f,  1.0f);
          glVertex3f( 1.0f, 1.0f,  1.0f);

          glColor3ub(red[j],green[j],blue[j]);
          glVertex3f( 1.0f, -1.0f,  1.0f);
          glVertex3f(-1.0f, -1.0f,  1.0f);
          glVertex3f(-1.0f, -1.0f, -1.0f);
          glVertex3f( 1.0f, -1.0f, -1.0f);

          glColor3ub(red[j],green[j],blue[j]);
          glVertex3f( 1.0f,  1.0f, 1.0f);
          glVertex3f(-1.0f,  1.0f, 1.0f);
          glVertex3f(-1.0f, -1.0f, 1.0f);
          glVertex3f( 1.0f, -1.0f, 1.0f);

          glColor3ub(red[j],green[j],blue[j]);
          glVertex3f( 1.0f, -1.0f, -1.0f);
          glVertex3f(-1.0f, -1.0f, -1.0f);
          glVertex3f(-1.0f,  1.0f, -1.0f);
          glVertex3f( 1.0f,  1.0f, -1.0f);

          glColor3ub(red[j],green[j],blue[j]);
          glVertex3f(-1.0f,  1.0f,  1.0f);
          glVertex3f(-1.0f,  1.0f, -1.0f);
          glVertex3f(-1.0f, -1.0f, -1.0f);
          glVertex3f(-1.0f, -1.0f,  1.0f);

          glColor3ub(red[j],green[j],blue[j]);
          glVertex3f(1.0f,  1.0f, -1.0f);
          glVertex3f(1.0f,  1.0f,  1.0f);
          glVertex3f(1.0f, -1.0f,  1.0f);
          glVertex3f(1.0f, -1.0f, -1.0f);
       glEnd();
       glColor3f(1,0,0);
       glBegin(GL_LINES);
           glVertex3f(raio,0,0);
           glVertex3f(0,0,0);
       glEnd();

       glColor3f(0,1,0);
       glBegin(GL_LINES);
           glVertex3f(0,raio,0);
           glVertex3f(0,0,0);
       glEnd();

       glColor3f(0,0,1);
       glBegin(GL_LINES);
           glVertex3f(0,0,raio);
           glVertex3f(0,0,0);
       glEnd();
}
void PaintTela::drawEsfera(int j){
    glTranslated(eixoX[j], eixoY[j], eixoZ[j]);
    glRotated(anguloX[j], 1, 0, 0);
    glRotated(anguloY[j], 0, 1, 0);
    glRotated(anguloZ[j], 0, 0, 1);
    glScaled(escalaX[j], escalaY[j], escalaZ[j]);

    for (int ph2=-90;ph2<90;ph2+=5) {
          glBegin(GL_QUAD_STRIP);
          for (int th2=0;th2<=360;th2+=10) {
            glColor3ub(red[j],green[j],blue[j]);
            double x1 = Sin(th2)*Cos(ph2);
            double y1 = Cos(th2)*Cos(ph2);
            double z1 =          Sin(ph2);
            glVertex3d(x1,y1,z1);
            glColor3ub(red[j],green[j],blue[j]);
            double x2 = Sin(th2)*Cos(ph2+5);
            double y2 = Cos(th2)*Cos(ph2+5);
            double z2 =          Sin(ph2+5);
             glVertex3d(x2,y2,z2);
          }
          glEnd();
     }

    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex3f(raio,0,0);
        glVertex3f(0,0,0);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_LINES);
        glVertex3f(0,raio,0);
        glVertex3f(0,0,0);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_LINES);
        glVertex3f(0,0,raio);
        glVertex3f(0,0,0);
    glEnd();
}
//


void PaintTela:: drawCilindro(int j){

    glColor3ub(red[j],green[j],blue[j]);
    glTranslated(eixoX[j], eixoY[j], eixoZ[j]);
    glRotated(anguloX[j], 1, 0, 0);
    glRotated(anguloY[j], 0, 1, 0);
    glRotated(anguloZ[j], 0, 0, 1);
    glScaled(escalaX[j], escalaY[j], escalaZ[j]);

    glBegin(GL_QUAD_STRIP);
        for (int l=0;l<=360;l+=5) {
          glColor3ub(red[j],green[j],blue[j]);
          glVertex3f(Cos(l),+1,Sin(l));
          glColor3ub(red[j],green[j],blue[j]);
          glVertex3f(Cos(l),-1,Sin(l));
        }
        glEnd();


        for (int i=1;i>=-1;i-=2) {
          glBegin(GL_TRIANGLE_FAN);
          glColor3ub(red[j],green[j],blue[j]);
          glVertex3f(0,i,0);
          for (int k=0;k<=360;k+=5) {
            glColor3ub(red[j],green[j],blue[j]);
            glVertex3f(i*Cos(k),i,Sin(k));
          }
          glEnd();
        }


    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex3f(raio,0,0);
        glVertex3f(0,0,0);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_LINES);
        glVertex3f(0,raio,0);
        glVertex3f(0,0,0);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_LINES);
        glVertex3f(0,0,raio);
        glVertex3f(0,0,0);
    glEnd();
}
void PaintTela::drawCone(int j){

    glTranslated(eixoX[j], eixoY[j], eixoZ[j]);
    //glScaled(escalaX[j], escalaY[j], escalaZ[j]);
    glRotated(anguloX[j], 1, 0, 0);
    glRotated(anguloY[j], 0, 1, 0);
    glRotated(anguloZ[j], 0, 0, 1);
    glScaled(escalaX[j], escalaY[j], escalaZ[j]);

    glBegin(GL_TRIANGLES);
       for (int k=0;k<=360;k+=5){
         glColor3ub(red[j],green[j],blue[j]);
         glVertex3f(0,0,1);
         glColor3ub(red[j],green[j],blue[j]);
         glVertex3f(Cos(k),Sin(k),0);
         glColor3ub(red[j],green[j],blue[j]);
         glVertex3f(Cos(k+5),Sin(k+5),0);
       }
       glEnd();


       glRotated(90,1,0,0);
       glBegin(GL_TRIANGLES);
       for (int k=0;k<=360;k+=5) {
         glColor3ub(red[j],green[j],blue[j]);
         glVertex3f(0,0,0);
         glColor3ub(red[j],green[j],blue[j]);
         glVertex3f(Cos(k),0,Sin(k));
         glColor3ub(red[j],green[j],blue[j]);
         glVertex3f(Cos(k+5),0,Sin(k+5));
       }
       glEnd();

    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex3f(raio,0,0);
        glVertex3f(0,0,0);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_LINES);
        glVertex3f(0,raio,0);
        glVertex3f(0,0,0);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_LINES);
        glVertex3f(0,0,raio);
        glVertex3f(0,0,0);
    glEnd();
}
void PaintTela::resizeGL(int width, int height) {
    static int G = 0;
    w = width;
    h = height;
    if(G == 0) {
        i = 20;
    }
    G = 1;
    double menorX = 0, maiorX = 10, menorY = 0, maiorY = 10;
    glViewport( 0, 0, (GLint)width, (GLint)height );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (width > height)
    {
        height = height?height:1;
        double novaLargura = (maiorX - menorX) * width / height;
        double difLargura = novaLargura - (maiorX - menorX);
        menorX = 0.0 - difLargura / 2.0;
        maiorX = 10 + difLargura / 2.0;
    }
    else
    {
        width = width?width:1;
        double novaAltura = (maiorY - menorY) * height / width;
        double difAltura = novaAltura - (maiorY - menorY);
        menorY = 0.0 - difAltura / 2.0;
        maiorY = 10 + difAltura / 2.0;
    }


    initializeIluminacao();

    gluPerspective(75,(width/height), 0.01, 100);
    gluLookAt(cameraX,cameraY,cameraZ,0,0,0,0,1,0);
    glFrustum(menorX, maiorX, menorY, maiorY,1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
void PaintTela:: initializeIluminacao(){

    GLfloat light0PosType[] = {cameraX,cameraY,cameraZ, 1.0};
    GLfloat light1PosType[] = {0.0,0.0,1.0, 0.0};
    GLfloat branco[] = {1.0,1.0,1.0, 1.0};
    GLfloat preto[] = {0.0,0.0,0.0, 1.0};
    GLfloat dir[] = {0.0,0.0,0.0};
    GLfloat mEmiss[] = {0.1,0.1,0.1, 1.0};
    GLfloat mDiffuse[] = {0.2,0.2,0.2, 1.0};
    GLfloat mSpec[] = {0.2,0.2,0.2, 1.0};

    glMaterialfv(GL_FRONT,GL_EMISSION, mEmiss);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE, mDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR, mSpec);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS, 1.0);

    glLightfv(GL_LIGHT0, GL_POSITION, light0PosType);

    glLightfv(GL_LIGHT0, GL_AMBIENT, branco);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, preto);
    glLightfv(GL_LIGHT0, GL_SPECULAR, preto);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION,0.001);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION,0.001);

    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT,2);
    //glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 50.0f);

    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT1, GL_POSITION, light1PosType);
    glLightfv(GL_LIGHT1, GL_AMBIENT,branco);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, preto);
    glLightfv(GL_LIGHT1, GL_SPECULAR, preto);

    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION,0.04);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION,0.05);


    if (iluminacao) {
        glEnable(GL_LIGHTING);
    }else {
        glDisable(GL_LIGHTING);
    }

}

void PaintTela::paintGL() {

    resizeGL(w,h);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glEnable(GL_RESCALE_NORMAL);
    for (int j=0; j<NUM; j++) {
        if(poligonos[j]==TRUE) {
            glLoadIdentity();
            switch (figura[j]) {
            case 0:
                 drawPiramide(j);
                break;
            case 1:
                drawCubo(j);
                break;
            case 2:
                drawEsfera(j);
                break;
            case 3:
                drawCilindro(j);
            break;
            case 4:
                 drawCone(j);
            break;
            default:
            break;
            }

        }
    }

    if (Grid==TRUE) { //Ativa Grid
       drawGrid();
    }

}
