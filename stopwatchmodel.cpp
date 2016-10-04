#include "stopwatchmodel.h"

StopwatchModel::StopwatchModel(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateDis()));
    elapsedTime = 0;
}

void StopwatchModel::startClock()
{
    timer->start(10);
    clock.start();
}

void StopwatchModel::restartClock()
{
    timer->start(10);
    clock.restart();
}

void StopwatchModel::pauseClock()
{
    elapsedTime = elapsedTime + clock.restart();
    timer->stop();
}

void StopwatchModel::resetClock()
{
    elapsedTime = 0;
    clock.restart();
    emit currentTime("00","00","00");
    timer->stop();
}

void StopwatchModel::updateDis()
{
    int time = clock.elapsed() + elapsedTime;
    int min = (time / 60000) % 60;
    int sec = (time / 1000) % 60;
    int hun = (time / 10) % 100;
    QString m,s,h;

    // When the times are less than 10 make sure there it is displayed as 2 digits
    if(min < 10)
    {
        m = "0"+QString::number(min);
    }
    else
    {
        m = QString::number(min);
    }

    if(sec < 10)
    {
        s = "0"+QString::number(sec);
    }
    else
    {
        s = QString::number(sec);
    }

    if(hun < 10)
    {
        h = "0"+QString::number(hun);
    }
    else
    {
        h = QString::number(hun);
    }

    emit currentTime(m,s,h);
}
