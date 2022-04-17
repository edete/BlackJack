#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

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
    //std::string filename = ":/CardImages/svg-cards/";
    //std::string suit[] = ["clubs", "hearts", "spades", "diamonds"];
    //std:string card[] = ["2","3","4","5","6","7","8","9","10","jack","queen","king","ace"];
    //std::string totalfile;
    //totalfile = filename + card[5] + "_" + suit[3]
    ui->label->setPixmap(QPixmap(":/CardImages/svg-cards/9_of_clubs.svg") );
}

