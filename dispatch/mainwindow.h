#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <pcb.h>
#include "QTimer"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_addButton_clicked();

    void on_startButton_clicked();

    void updateTime();

    void on_clearButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_fileButton_clicked();

private:
    QTimer *timer;
    int second;
    Ui::MainWindow *ui;
    PCB pcbArr[20];
    PCB temp[20];
    float fcfsAverageTurnaroundTime;
    float sjfAverageTurnaroundTime;
    float rrAverageTurnaroundTime;
    float pfAverageTurnaroundTime;
    float hrrnAverageTurnaroundTime;
    void init();
    void initPcb();
    void clearPcb(int rows);
    void sort();
    void copyPcb();
    void fcfs();
    void sjf();
    void rr();
    void pf();
    void hrrn();
};

#endif // MAINWINDOW_H
