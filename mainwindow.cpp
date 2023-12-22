#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int height = ui->height->text().toInt();
    int weight = ui->weight->text().toInt();

    double temp = static_cast<double>(height) / 100.0;
    temp = temp * temp;
    double imt = static_cast<double>(weight) / temp;

    QString result = QString::number(imt);
    ui->result_num->setText("ИМТ: " + result);

    QString interpretation;
    double imtValue = result.toDouble();
    if (imtValue <= 16.0) {
        interpretation = "Выраженный дефицит массы тела";
    } else if (imtValue <= 18.5) {
        interpretation = "Недостаточная масса тела (дефицит)";
    } else if (imtValue <= 25.0) {
        interpretation = "Норма";
    } else if (imtValue <= 30.0) {
        interpretation = "Избыточная масса тела";
    } else if (imtValue <= 35.0) {
        interpretation = "Ожирение 1-й степени";
    } else if (imtValue <= 40.0) {
        interpretation = "Ожирение 2-й степени";
    } else {
        interpretation = "Ожирение 3-й степени";
    }
    //простите за вермишель...
    ui->result_text->setText(interpretation);
}
