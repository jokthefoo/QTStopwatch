#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Stopwatch");
    ui->minDisplay->display("00");
    ui->secDisplay->display("00");
    ui->hunDisplay->display("00");
    connect(&stopwatchM, SIGNAL(currentTime(int)), this, SLOT(updateDisplay(int)));
    connect(this, SIGNAL(startClicked()), &stopwatchM, SLOT(startClock()));
    connect(this, SIGNAL(pauseClicked()), &stopwatchM, SLOT(pauseClock()));
    connect(this, SIGNAL(restartClicked()), &stopwatchM, SLOT(restartClock()));
    connect(this, SIGNAL(resetClicked()), &stopwatchM, SLOT(resetClock()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay(int time)
{
    int min = (time / 60000) % 60;
    int sec = (time / 1000) % 60;
    int hun = (time / 10) % 100;
    if(min < 10)
    {
        QString s = "0"+QString::number(min);
        ui->minDisplay->display(s);
    }else
    {
        ui->minDisplay->display(min);
    }
    if(sec < 10)
    {
        QString s = "0"+QString::number(sec);
        ui->secDisplay->display(s);
    }else
    {
        ui->secDisplay->display(sec);
    }
    if(hun < 10)
    {
        QString s = "0"+QString::number(hun);
        ui->hunDisplay->display(s);
    }else
    {
        ui->hunDisplay->display(hun);
    }
}

void MainWindow::on_startButton_clicked()
{
    if(ui->startButton->text() == "Start")
    {
        ui->startButton->setText("Pause");
        emit startClicked();
    }
    else if(ui->startButton->text() == "Pause")
    {
        ui->startButton->setText("Restart");
        emit pauseClicked();
    }
    else
    {
        ui->startButton->setText("Pause");
        emit restartClicked();
    }
}

void MainWindow::on_resetButton_clicked()
{
    ui->startButton->setText("Start");
    emit resetClicked();
}
