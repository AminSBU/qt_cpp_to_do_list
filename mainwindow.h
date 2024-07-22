#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbAdd_clicked();

    void on_pbRemove_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QCheckBox> _remainingTasks;
    QVector<QCheckBox> _removedTasks;

};
#endif // MAINWINDOW_H
