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


void MainWindow::on_pbAdd_clicked()
{
    if(ui->leTask->text() == "")
    {
        QMessageBox msgBox;
        msgBox.setText("Can't add an empty task!");
        msgBox.exec();
        return;
    }
    QCheckBox *cb = new QCheckBox(ui->leTask->text());
//    ui->wgtTasks->layout()->addWidget(cb);
    ui->scrlATasks->widget()->layout()->addWidget(cb);
    ui->leTask->clear();
}

void MainWindow::on_pbRemove_clicked()
{
    // not implemented yet
}
