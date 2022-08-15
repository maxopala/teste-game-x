#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <mapa.h>

class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Sprite(Mapa* mapa, int margin_up = 20, int margin_left = 26, QObject *parent = 0);
    void move(int d);

signals:

public slots:

private slots:
    void nextFrame();   // Slot for turning images into QPixmap

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    QTimer *timer;      // Timer for turning images into QPixmap
    QPixmap *spriteImage;   // In this QPixmap object will be placed sprite
    int currentFrame;   // Coordinates X, which starts the next frame of the sprite

    int w = 44;
    int h = 74;
    int margin_up;
    int margin_left;
    int count = 3;

    bool parado;
    int movimento;

    int xPos;
    int yPos;

    int wCell = 100;
    int hCell = 100;

    Mapa* mapa;
};

#endif // SPRITE_H
