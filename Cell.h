#ifndef CELL_H
#define CELL_H
#include <QColor>
#include <QGraphicsItem>
class Cell : public QObject, public QGraphicsItem {

    Q_OBJECT

public:
    Cell(QColor color, bool alive){
        color_ = color;
        alive_ = alive;
    }
    QColor getColor() { return color_; }
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    void set_x(int x){ x_ = x; }
    void set_y(int y){y_ = y; }

    int get_x(){return x_; }
    int get_y(){return y_; }

    void setColor(QColor c){color_ = c; }
    void set_alive(bool c){ alive_ = c;}
    bool get_alive(){ return alive_; }

    Cell * change(QColor c, bool a){
        color_ = c;
        alive_ = a;
        return this;
    }
signals:
    void CellSelected(Cell *c);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;



private:
    QColor color_;
    bool alive_;

    int x_;
    int y_;

    static const int width_ = 20;

    friend bool operator==(const Cell &first, const Cell &other);

};

#endif // CELL_H
