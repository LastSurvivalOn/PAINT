#include "plaster.h"
#include <QMouseEvent>
#include <QVBoxLayout>

Plaster::Plaster():QMainWindow()
{
    image = new QImage(800, 600, QImage::Format_RGB32);
    image->fill(Qt::white);
    lastPoint = nullptr;
    drawing = false;
    brushsize = 5;
    brushColor = new QColor(Qt::black);

    toolbar_a = new QToolBar(this);
    addToolBar(toolbar_a);

    shape = new QComboBox();
    shape->addItem("Круг");
    shape->addItem("Прямокутник");
    toolbar_a->addWidget(shape);

    instrument = new QComboBox();
    instrument->addItem("Фігура");
    instrument->addItem("Вибір");
    toolbar_a->addWidget(instrument);

    color = new QColorDialog(this);
    QAction *colorAction = new QAction("Змінити колір", this);
    connect(colorAction, &QAction::triggered, this, &Plaster::changeColorActionTriggered);
    toolbar_a->addAction(colorAction);

    width = new QSpinBox();
    width->setRange(1, 50);
    width->setValue(brushsize);
    toolbar_a->addWidget(width);

    connect(shape, SIGNAL(currentIndexChanged(int)), this, SLOT(changeShape(int)));
    connect(instrument, SIGNAL(currentIndexChanged(int)), this, SLOT(changeInstrument(int)));
    connect(color, SIGNAL(colorSelected(const QColor&)), this, SLOT(changeColor(const QColor&)));
    connect(width, SIGNAL(valueChanged(int)), this, SLOT(changeWidth(int)));
}

void Plaster::changeColorActionTriggered()
{
    QColor newColor = color->getColor(*brushColor, this, "Виберіть колір", QColorDialog::DontUseNativeDialog);
    if (newColor.isValid())
    {
        *brushColor = newColor;
    }
}

void Plaster::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        drawing = true;
        lastPoint = new QPoint(event->pos());
    }
}

void Plaster::mouseMoveEvent(QMouseEvent *event)
{
    if (drawing)
    {
        if (!lastPoint)
            return;

        QPainter painter(image);

        painter.setPen(QPen(*brushColor, brushsize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

        painter.drawLine(*lastPoint, event->pos());

        delete lastPoint;
        lastPoint = new QPoint(event->pos());

        update();
    }
}

void Plaster::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && drawing)
    {
        drawing = false;
        delete lastPoint;
        lastPoint = nullptr;
    }
}

void Plaster::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, *image);
}

/*void Plaster::changeShape(int index)
{
ФІГУУУРА
}

void Plaster::changeInstrument(int index)
{
РУЧКА ОЛІВЕЦЬ ЗАЛИВКА ТП
}

void Plaster::changeColor(const QColor &newColor)
{
ДОПИЛИТИ
}

void Plaster::changeWidth(int newWidth)
{
ізіч
}*/
