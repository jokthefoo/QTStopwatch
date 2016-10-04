#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatchmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    StopwatchModel stopwatchM;
    ~MainWindow();

signals:
    void startClicked();
    void pauseClicked();
    void restartClicked();
    void resetClicked();
private slots:
    void on_startButton_clicked();

    void on_resetButton_clicked();

    void updateDisplay(int time);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
