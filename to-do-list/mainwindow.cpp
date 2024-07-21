#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Add Task with Checkbox Example");

    QLineEdit *lineEdit = new QLineEdit();
    QLineEdit *lineEditTime = new QLineEdit();
    QListWidget *listWidget = new QListWidget();
    QPushButton *button = new QPushButton("Add Task");
    QDateTime dateTime = QDateTime::fromString("1.30.1", "M.d.s");
    dateTime = QDateTime::fromString("12", "yy");

    QString dateTimeString = dateTime.toString()

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(lineEdit);
    layout->addWidget(button);
    layout->addWidget(listWidget);
    layout->addWidget(lineEditTime);

    connect(button, &QPushButton::clicked, [=]() {
        QString task = lineEdit->text();
        lineEditTime->setText(date);
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

