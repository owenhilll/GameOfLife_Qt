#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <Qcolor>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Cell.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gameWindow; }
QT_END_NAMESPACE

class gameWindow : public QMainWindow
{
    Q_OBJECT

public:
    gameWindow(QWidget *parent = nullptr);
    void DisplayGame();
    ~gameWindow();
    void updateGame();
    bool updateHelper(int, int, bool);
    void copyArr(Cell * arr[20][10]);

private slots:
    void on_pushButton_clicked();

    void CellSelectedSlot(Cell *c);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_horizontalSlider_sliderMoved(int position);



protected:

    void TimerEvent(QTimerEvent * event);

private:
    int time_interval = 0;
    int population = 0;
    int turn = 0;
    Ui::gameWindow *ui;

     QTimer* timer;

    Cell * arr_[20][10];

    QGraphicsScene * scene;
    QGraphicsScene * scene2;
};
#endif // GAMEWINDOW_H
