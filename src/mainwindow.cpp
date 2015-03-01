#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/dialog.h"
#include "headers/wyniki.h"
#include "headers/qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionZamknij_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionO_programie_triggered()
{
    Dialog o_programie;
    o_programie.exec();
}

void MainWindow::on_actionO_Qt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_pushOblicz_clicked()
{
    double A = ui->textKatA->toPlainText().toDouble();
    double B = ui->textKatB->toPlainText().toDouble();
    int C = ui->textPodzialy->toPlainText().toInt();
    int D = ui->comboBox->currentIndex()+1;
    if (C<1)
    {
        ui->textBrowser->clear();
        ui->textBrowser->insertHtml("Ilość przedziałów musi być liczbą naturalną, większą od 0.");
    }
    else
    {
        wyniki obliczenia(A, B, C);
        ui->textBrowser->clear();
        ui->textBrowser->insertHtml(obliczenia.generateHTML());
        QVector<double> x(C), y(C);
        for (int i=0; i<C; ++i)
        {
          x[i] = obliczenia.macierz_wyniki[0][i];
          y[i] = obliczenia.macierz_wyniki[D][i];
        }
        ui->widget->clearGraphs();
        ui->widget->addGraph();
        ui->widget->graph()->setData(x, y);
        ui->widget->xAxis->setLabel("Kąt w stopniach");
        ui->widget->yAxis->setLabel(ui->comboBox->currentText());
        ui->widget->xAxis->setRange(A, B);
        ui->widget->yAxis->setRange(obliczenia.najmniejszaWartosc(D), obliczenia.najwiekszaWartosc(D));
        ui->widget->replot();

    }
}

void MainWindow::on_actionEksportuj_wyniki_triggered()
{
    QString nazwa = QFileDialog::getSaveFileName();
    ui->widget->toPixmap(800,400,1.0).toImage().save(nazwa+".png", "png", 1);
    QFile html;
    html.setFileName(nazwa+".html");
    if (!html.open(QFile::WriteOnly | QFile::Text)) return;
    QTextStream zapisz(&html);
    zapisz << ui->textBrowser->toHtml() << "<html><body></br><img src='" << nazwa+".png" << "' alt='Tutaj powinien byc wykres' /></body></html>";
    html.close();
}
