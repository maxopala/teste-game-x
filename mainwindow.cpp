#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mapa = new Mapa();
    this->scene = new TabuleiroScene(mapa, this);
    this->ui->view->setScene(this->scene);

    QSignalMapper* mapper = new QSignalMapper(this);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (j < 4 || i == 1) {
                QPushButton* btn = new QPushButton("Char " + QString::number(i * 4 + j), this);
                connect(btn, SIGNAL(clicked()), mapper, SLOT(map()));
                mapper->setMapping(btn, QString::number(i) + "-" + QString::number(j));
                this->ui->charsChoice->addWidget(btn);
            }
        }
    }
    connect(mapper, SIGNAL(mapped(const QString&)), this, SIGNAL(trocarCharSig(const QString&)));
    connect(this, &MainWindow::trocarCharSig, this, &MainWindow::trocarChar);

    sprite = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (sprite) {
        switch(event->key()) {
            case Qt::Key_W:
                sprite->move(3);
                break;
            case Qt::Key_A:
                sprite->move(1);
                break;
            case Qt::Key_S:
                sprite->move(0);
                break;
            case Qt::Key_D:
                sprite->move(2);
                break;
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (sprite) {
        sprite->move(-1);
    }
}

void MainWindow::trocarChar(const QString &c)
{
    int i = c.split("-")[0].toInt();
    int j = c.split("-")[1].toInt();

    Sprite* oldSprite = sprite;
    Sprite* newSprite = new Sprite(mapa, 20 + 74 * 4 * i, 26 + 44 * 3 * j);

    if (oldSprite != nullptr) {
        newSprite->setPos(oldSprite->pos());
        scene->removeItem(oldSprite);
        delete oldSprite;
    } else {
        int i, j;
        do {
            i = rand() % mapa->getLins();
            j = rand() % mapa->getCols();
            i = j = 11;
        } while (!mapa->acessivel(i, j) || mapa->saida(i, j));

        newSprite->setPos(i * 100, j * 100);
    }
    scene->addItem(sprite = newSprite);
    ui->view->ensureVisible(sprite);
    ui->view->scroll(i * 100, j * 100);
    ui->view->centerOn(sprite);
}

