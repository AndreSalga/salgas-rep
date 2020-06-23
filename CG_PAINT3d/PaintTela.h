#ifndef PAINTTELA_H
#define PAINTTELA_H

/*#include <QWidget>
#include <QtOpenGL>
#include <GL/glu.h>
#include <QGLWidget>
#include <math.h>
#include <QSpinBox>*/

#include <QGLWidget>
#include <QSpinBox>

#define NUM 15
#define PI 3.1415926535898
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))

class PaintTela : public QGLWidget
{
    Q_OBJECT
public:
    explicit PaintTela(QWidget *parent = 0);
public slots:

    void criarFigura();

    void alterarR(int verm);
    void alterarG(int verde);
    void alterarB(int azul);

    void selecionar(int poligono);
    void escolherForma(int forma);

    void transladarX(double x);
    void transladarY(double y);
    void transladarZ(double z);

    void escalarX(double x);
    void escalarY(double y);
    void escalarZ(double z);

    void rotacionarX(double x);
    void rotacionarY(double y);
    void rotacionarZ(double z);

    //void cisalharX(double x);
    //void cisalharY(double y);

    void alterarCameraY(int Y);
    void alterarCameraE(int E);
    void alterarCameraD(int D);

    void excluirFigura ();
    void excluirTodos ();

    void tamanhoMalha(int t);
    void exibirMalha();
    void ativarIluminacao();

    void drawPiramide(int j);
    void drawCubo(int j);
    void drawCilindro(int j);
    void drawEsfera(int j);
    void drawCone(int j);
    void drawGrid();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
     void initializeIluminacao();
private:
    int i, p; //polígono
    int figura[NUM] = {0};
    int w, h;
    float cameraX = 10, cameraY = 10, cameraZ = 10, cameraR = 10, cameraP = 10;
    bool poligonos[NUM]= {FALSE};
    bool Grid, iluminacao = FALSE;
    double raio = 8.0;
    double eixoX[NUM], eixoY[NUM], eixoZ[NUM];
    double escalaX[NUM], escalaY[NUM], escalaZ[NUM];
    double anguloX[NUM], anguloY[NUM], anguloZ[NUM];
    double cisalhaXY[NUM], cisalhaXZ[NUM], cisalhaYX[NUM], cisalhaYZ[NUM], cisalhaZX[NUM], cisalhaZY[NUM];
    int red[NUM], green[NUM], blue[NUM];
    int tam;

};

#endif // PAINTTELA_H
