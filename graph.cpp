#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QColor>
#include <QTimer>
#include "graph.h"
#include "ui_gamewindow.h"
#include "QtMath"
#include "Cell.h"

QColor colorBlack(255, 255, 255);

graph::graph(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::graph)
{
    //UI is now setup
    ui->setupUi(this);
    //creates the scene for to draw on
    QGraphicsView * view = ui->graphicsView;
    //
    scene = new QGraphicsScene;
    view->setScene(scene);

}
