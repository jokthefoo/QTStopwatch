#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize display
    this->setWindowTitle("Stopwatch");
    ui->minDisplay->display("00");
    ui->secDisplay->display("00");
    ui->hunDisplay->display("00");

    // Connect signals and slots between model and view
    connect(&stopwatchM, SIGNAL(currentTime(QString,QString,QString)), this, SLOT(updateDisplay(QString,QString,QString)));
    connect(this, SIGNAL(startClicked()), &stopwatchM, SLOT(startClock()));
    connect(this, SIGNAL(pauseClicked()), &stopwatchM, SLOT(pauseClock()));
    connect(this, SIGNAL(restartClicked()), &stopwatchM, SLOT(restartClock()));
    connect(this, SIGNAL(resetClicked()), &stopwatchM, SLOT(resetClock()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay(QString min, QString sec, QString hun)
{
    ui->minDisplay->display(min);
    ui->secDisplay->display(sec);
    ui->hunDisplay->display(hun);
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
