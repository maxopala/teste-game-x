#ifndef TABULEIROSCENE_H
#define TABULEIROSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QImage>
#include <mapa.h>

class TabuleiroScene: public QGraphicsScene
{
public:
    TabuleiroScene(Mapa *mapa, QObject *parent = nullptr);
    void drawBackground(QPainter *painter, const QRectF &rect) override;

private:
    Mapa *mapa;
    int w;
    int h;
    QImage imgWall;
    QImage imgFloor;
    QImage imgDoor;
};

#endif // TABULEIROSCENE_H
