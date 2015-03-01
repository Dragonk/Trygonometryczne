#include "wykres.h"
#include "ui_wykres.h"

Wykres::Wykres(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wykres)
{
    ui->setupUi(this);
    QPixmap mapa;
    QPainter painter(mapa);
       painter.setPen(Qt::blue);
       painter.setFont(QFont("Arial", 30));
       painter.drawText(rect(), Qt::AlignCenter, "Qt");
}

Wykres::~Wykres()
{
    delete ui;
}
