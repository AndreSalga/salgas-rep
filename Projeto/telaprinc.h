#ifndef TELAPRINC_H
#define TELAPRINC_H
#include <QGLWidget>
#include <QSpinBox>
class TelaPrinc : public QGLWidget
{
    Q_OBJECT
public:
    explicit TelaPrinc(QWidget *parent = 0);
    void construirGrid();
    void desenharReta();
    void desenharDDA();
    void desenharPM();
    void desenharPixel(int x, int y);
    void desenharEE();
    float valor(float v);
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
signals:

public slots:

    void alterarX1(int i);
    void alterarY1(int i);
    void alterarX2(int i);
    void alterarY2(int i);
    void exibGrid(bool b);
    void tamGrid(int i);
    void moReta(bool r);
    void checkDAA(bool c);
    void moFronteira(bool f);
    void especReta(int i);
    void checkPM(bool c);
    void checkEE(bool c);

private:
    int x1,x2,y1,y2,tgrid,tgrid_aux,espessura;
    bool showGrid,showReta,showDDA,showFront,showPM,showEE;
    float rvalue,rv1,rv2;

};

#endif // TELAPRINC_H
