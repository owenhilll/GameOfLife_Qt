#ifndef GAMEPIECE_H
#define GAMEPIECE_H
#include <QColor>
#include <QGraphicsItem>
class gamepiece :  public QGraphicsTextItem {

    Q_OBJECT

public:
    gamepiece(std::string s, int x, int y){
        type = s;
        x_ = x;
        y_ = y;
    };
    void set_x(int x){ x_ = x; }
    void set_y(int y){y_ = y; }

private:
    std::string type;
    int x_;
    int y_;
    static const int width_ = 20;


};
#endif // GAMEPIECE_H
