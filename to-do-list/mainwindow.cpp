#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QCheckBox>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Add Task with Checkbox Example");

        QLineEdit *lineEdit = new QLineEdit();
        QListWidget *listWidget = new QListWidget();
        QPushButton *button = new QPushButton("Add Task");

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(lineEdit);
        layout->addWidget(button);
        layout->addWidget(listWidget);

        connect(button, &QPushButton::clicked, [=]() {
            QString task = lineEdit->text();
            if (!task.isEmpty()) {
                QCheckBox *checkBox = new QCheckBox(task);
                listWidget->addItem("");
                QListWidgetItem *item = listWidget->item(listWidget->count() - 1);
                listWidget->setItemWidget(item, checkBox);
                lineEdit->clear();
            }
        });

        QWidget *centralWidget = new QWidget();
        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

