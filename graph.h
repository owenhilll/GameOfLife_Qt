#ifndef GRAPH_H
#define GRAPH_H
#include <Qcolor>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Cell.h"
QT_BEGIN_NAMESPACE
namespace Ui { class graph; }
QT_END_NAMESPACE

class graph : public QMainWindow
{
    Q_OBJECT

public:
    graph(QWidget *parent = nullptr);


};
#endif // GRAPH_H
