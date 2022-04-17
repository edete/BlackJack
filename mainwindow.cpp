#include "mainwindow.h"
#include "ui_mainwindow.h"

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



void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->setText("Stop Game");
}




void MainWindow::on_pushButton_clicked()
{
    ui->label->setPixmap(QPixmap(":/CardImages/svg-cards/9_of_clubs.svg") );
}

