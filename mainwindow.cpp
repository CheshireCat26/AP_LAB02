#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QString>
#include <QRegExp>
#include <QMessageBox>

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

void MainWindow::on_ButtonCalc_clicked()
{
    QString Sx = ui->lineEditX->text();
    QString Sy = ui->lineEditY->text();
    QString Sz = ui->lineEditZ->text();

    QRegExp re("\\d*\\.?");
    if (re.exactMatch(Sx) && re.exactMatch(Sy) && re.exactMatch(Sz))
    {
        double x = Sx.toDouble();
        double y = Sy.toDouble();
        double z = Sz.toDouble();

        double buff = -sqrt(fabs(x));
        buff = pow(y, buff);
        double first = log(buff);

        double second = x - y/2;

        buff = atan(z);
        buff = sin(buff);
        double third = pow(buff, 2);

        double a = first*second+third;

        ui->labelA->setText("A: " + QString::number(a));
    }
    else
    {
        QMessageBox eb;
        eb.setText("Введены не числа");
        eb.exec();
    }
}
