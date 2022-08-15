#include "tabuleiroscene.h"
#include <QPainter>

TabuleiroScene::TabuleiroScene(Mapa *mapa, QObject *parent) : QGraphicsScene(parent), mapa(mapa)
{
    w = 100;
    h = 100;

    imgFloor = QImage(":/board/grama.jpg");

    imgWall = QImage(":/board/wall.jpg");
    imgDoor = QImage(":/board/porta.png");
}

void TabuleiroScene::drawBackground(QPainter *painter, const QRectF &rect)
{
//    int wDesloc = (w * mapa->getCols()) / 2;
//    int hDesloc = (h * mapa->getLins()) / 2;

    int wDesloc = 1;
    int hDesloc = 0;

    for (int i = 0; i < mapa->getLins(); ++i) {
        for (int j = 0; j < mapa->getCols(); ++j) {
            painter->drawImage(j * w - wDesloc, i * h - hDesloc, imgFloor, w, h);
            if (mapa->parede(i, j)) {
                painter->drawImage(j * w - wDesloc, i * h - hDesloc, imgWall, w, h);
            } else if (mapa->saida(i, j)) {
                painter->drawImage(j * w - wDesloc, i * h - hDesloc, imgDoor, w, h);
            }
        }
    }
}
