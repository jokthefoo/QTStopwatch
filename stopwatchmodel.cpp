#include "stopwatchmodel.h"

StopwatchModel::StopwatchModel(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateDis()));
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
    clock.restart();
    timer->stop();
}

void StopwatchModel::resetClock()
{
    clock.restart();
    emit currentTime(0);
    timer->stop();
}

void StopwatchModel::updateDis()
{
    emit currentTime(clock.elapsed());
}
