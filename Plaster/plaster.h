#ifndef PLASTER_H
#define PLASTER_H
#include <QMainWindow>
#include <QWidget>
#include <QColor>
#include <QImage>
#include <QPoint>
#include <QBrush>
#include <QPainter>
#include <QToolBar>
#include <QAction>
#include <QComboBox>
#include <QColorDialog>
#include <QSpinBox>

class Plaster: public QMainWindow {
    Q_OBJECT
public:
    Plaster();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void changeColorActionTriggered();
private:
    QImage *image;
    bool drawing;
    QPoint *lastPoint;
    int brushsize;
    QColor *brushColor;

    QToolBar *toolbar_a;
    QComboBox *shape;
    QComboBox *instrument;
    QColorDialog *color;
    QSpinBox *width;
};

#endif // PLASTER_H
