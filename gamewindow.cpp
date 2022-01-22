#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QColor>
#include <QTimer>
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "QtMath"
#include "Cell.h"

int xScene = 1;
int yScene = 1;

int pop = 0;

QColor colorBlack(255, 255, 255);

gameWindow::gameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gameWindow)
{
    //UI is now setup
    ui->setupUi(this);
    //creates the scene for to draw on
    QGraphicsView * view = ui->graphicsView;
    //
    scene = new QGraphicsScene;
    view->setScene(scene);



//    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            if(rand() % 2 == 0){
                QColor color(255, 16, 240);
                Cell * c = new Cell(color, true);
                c->set_x(i*20);
                c->set_y(j*20);
                population++;
                arr_[i][j] = c;
                connect(c, &Cell::CellSelected, this, &gameWindow::CellSelectedSlot);

            } else {
                QColor color(255, 255, 255);
                Cell * c = new Cell(color, false);
                population--;
                c->set_x(i*20);
                c->set_y(j*20);
                arr_[i][j] = c;
                connect(c, &Cell::CellSelected, this, &gameWindow::CellSelectedSlot);

            }
        }
    }

    QGraphicsView * view2 = ui->graphicsView_2;
    scene2 = new QGraphicsScene;
    view2->setScene(scene2);


}

gameWindow::~gameWindow()
{
    delete ui;
}

void gameWindow::copyArr(Cell * arr[20][10]){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            arr_[i][j] = arr[i][j];
            arr_[i][j]->setColor(arr[i][j]->getColor());
            arr_[i][j]->set_alive(arr[i][j]->get_alive());

        }
    }

}

bool gameWindow::updateHelper(int x, int y, bool aORd){
    int cell_count = 0;
    qDebug() << x << ":" << y;;
    y--;
    x--;
    if(y < 0){
        y = 9;
    }
    qDebug() << x << ":" << y;;
    if(x < 0){
        x = 19;
    }
    if(arr_[x][y]->get_alive() == true){
        cell_count++;
    }
    x++;
    if(x > 19){
        x = 0;
    }
    qDebug() << x << ":" << y;
    if(arr_[x][y]->get_alive() == true){
        cell_count++;
    }
    x++;
    if(x > 19){
        x = 0;
    }
    qDebug() << x << ":" << y;
    if(arr_[x][y]->get_alive() == true){
        cell_count++;
    }
    y++;
    if(y > 9){
        y = 0;
    }
    qDebug() << x << ":" << y;
    if(arr_[x][y]->get_alive() == true){
        cell_count++;
    }
    y++;

    if(y > 9){
        y = 0;
    }
    if(arr_[x][y]->get_alive() == true){
        cell_count++;
    }
    qDebug() << x << ":" << y;
    x--;
    if(x < 0){
        x = 19;
    }
    qDebug() << x << ":" << y;
    if(arr_[x][y]->get_alive() == true){
        cell_count++;
    }
    x--;
    qDebug() << x << ":" << y;
    if(x < 0){
        x = 19;
    }
    if(arr_[x][y]->get_alive() == true){
        cell_count++;
    }
    y--;
    qDebug() << x << ":" << y;
    if(y < 0){
        y = 9;
    }
    if(arr_[x][y]->get_alive() == true){
        cell_count++;
    }
    qDebug() << "cell count for " << x+1 << "," << y << "=" << cell_count;
   if(aORd == true){
        if(cell_count == 2 || cell_count == 3){
            return true;
        }
        else{
            return false;
        }
    }
   else if(aORd == false){
        if(cell_count == 3){
            return true;
        }
        else{
            return false;
        }
    }
}

void gameWindow::updateGame(){
    Cell * arr2[20][10];
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            qDebug() << "updateGame() test: Should be 15";
            bool check = updateHelper(i, j, arr_[i][j]->get_alive());
            if(!check){
               qDebug() << "Value returned false";
               arr2[i][j] = arr_[i][j]->change(colorBlack, false);
               pop--;
            } else {
                arr2[i][j] = arr_[i][j]->change(QColor(255, 16, 240),true);
                pop++;
            }

            qDebug() << "Exited first test";
        }
    }
    copyArr(arr2);
}

void gameWindow::DisplayGame(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            scene->addItem(arr_[i][j]);

        }
    }

}

void gameWindow::on_pushButton_clicked()
{
    turn++;
    updateGame();
    scene->update();

    std::string t = "TURN: " + std::to_string(turn);
    ui->label->setText(QString(t.c_str()));

    int pop2 = 0;
    for(int i = 0; i < 20; i++){

        for(int j = 0; j < 10; j++){
            if(arr_[i][j]->get_alive() == true){
                pop2++;
            }
        }
    }
    scene2->addRect(-20 * xScene,yScene,20,pop2/2);
    xScene++;


    std::string ds = "POPULATION: " + std::to_string(pop2);
    ui->label_2->setText(QString(ds.c_str()));
}

void gameWindow::CellSelectedSlot(Cell * c){
    qDebug() << c->get_alive();
}




void gameWindow::on_pushButton_2_clicked()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton_clicked()));
    timer->start(1000);
    std::string speed = "Speed: " + std::to_string(1.000000);
    ui->speedlabel->setText(QString(speed.c_str()));
}


void gameWindow::on_pushButton_3_clicked()
{
    timer->stop();
    std::string speed = "Speed: " + std::to_string(0);
    ui->speedlabel->setText(QString(speed.c_str()));
}


void gameWindow::on_horizontalSlider_sliderMoved(int position)
{


    timer->start(1000 / position);
    std::string speed = "Speed: " + std::to_string(1000/position);
    ui->speedlabel->setText(QString(speed.c_str()));
}


