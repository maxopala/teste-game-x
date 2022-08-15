#include "sprite.h"

Sprite::Sprite(Mapa* mapa, int margin_up, int margin_left, QObject *parent) :
    QObject(parent), QGraphicsItem(), margin_up(margin_up), margin_left(margin_left), mapa(mapa)
{
    currentFrame = 0;   // Sets the coordinates of the current frame of the sprite
    //    spriteImage = new QPixmap(":/chars/explosion.png"); // Load the sprite image QPixmap
    spriteImage = new QPixmap(":/chars/game-chars.png"); // Load the sprite image QPixmap

    timer = new QTimer();   // Create a timer for sprite animation
    connect(timer, &QTimer::timeout, this, &Sprite::nextFrame);
    timer->start(10);   // Run the sprite on the signal generation with a frequency of 25 ms

    currentFrame = 0;
    movimento = 0;
    parado = true;
}

void Sprite::move(int d)
{
    if (d < 0) {
        parado = true;
    } else {
        parado = false;
        movimento = d % 4;
    }
}

QRectF Sprite::boundingRect() const
{
    return QRectF(0,0,w,h);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* In the graphic renderer we draw the sprite
     * The first two arguments - is the X and Y coordinates of where to put QPixmap
     * The third argument - a pointer to QPixmap
     * 4 and 5 of the arguments - The coordinates in the image QPixmap, where the image is displayed
     * By setting the X coordinate with the variable currentFrame we would like to move the camera on the sprite
     * and the last two arguments - the width and height of the displayed area, that is, the frame
     * */
    if (parado) {
        painter->drawPixmap(0,0, *spriteImage, (1 * w) + margin_left, (movimento * h) + margin_up, w,h);
    } else {
        painter->drawPixmap(0,0, *spriteImage, (currentFrame * w) + margin_left, (movimento * h) + margin_up, w,h);
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Sprite::nextFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */
    currentFrame = (currentFrame + 1) % count;

    xPos = x();
    yPos = y();
    if (!parado) {
        switch (movimento) {
            case 0:
                yPos += 10;
                break;
            case 1:
                xPos -= 10;
                break;
            case 2:
                xPos += 10;
                break;
            case 3:
                yPos -= 10;
                break;
        }
        setPos(xPos, yPos);
    }

    if (xPos / 100.0 - 100 * mapa->getCols()) {

    }

    this->update(0,0,w,h);
}
