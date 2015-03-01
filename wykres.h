#ifndef WYKRES_H
#define WYKRES_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

namespace Ui {
class Wykres;
}

class Wykres : public QWidget
{
    Q_OBJECT

public:
    explicit Wykres(QWidget *parent = 0);
    ~Wykres();

private slots:

private:
    Ui::Wykres *ui;
};

#endif // WYKRES_H
