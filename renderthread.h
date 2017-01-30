#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include <QSize>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>

#include "recseqbrot.h"

class RenderThread : public QThread
{
    Q_OBJECT

public:
    RenderThread(QObject *parent = 0);
    ~RenderThread();

    void render(double centerX, double centerY, double scaleFactor, QSize resultSize, int powerValue);

signals:
    void renderedImage(const QImage &image, double scaleFactor);

protected:
    void run() Q_DECL_OVERRIDE;

private:
    uint rgbFromWaveLength(double wave);
    int getIterations(double& ax, double& ay, int MaxIterations);
    int getIterationsUsingComplex(double& ax, double& ay, int MaxIterations, int nPower);  // Version via Complex
    int getIterations1(double& ax, double& ay, int MaxIterations);  // Version originale
    void SetCValue(double& ax, double& ay);
    void SetMaxIterationsValue(int MaxIterations);

    QMutex mutex;
    QWaitCondition condition;
    double centerX;
    double centerY;
    double scaleFactor;
    int powerValue;
    QSize resultSize;
    bool restart;
    bool abort;

    enum { ColormapSize = 512 };
    uint colormap[ColormapSize];
};



#endif // RENDERTHREAD_H
