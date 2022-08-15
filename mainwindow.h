#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <sprite.h>
#include <QPushButton>
#include <QMessageBox>
#include <QSignalMapper>
#include <tabuleiroscene.h>
#include <mapa.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

signals:
    void trocarCharSig(const QString &c);

private:
    void trocarChar(const QString &c);
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Sprite* sprite;
    Mapa* mapa;
};
#endif // MAINWINDOW_H
