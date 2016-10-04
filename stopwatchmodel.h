#ifndef STOPWATCHMODEL_H
#define STOPWATCHMODEL_H

#include <QObject>
#include <QTime>
#include <QTimer>

class StopwatchModel : public QObject
{
    Q_OBJECT
public:
    explicit StopwatchModel(QObject *parent = 0);
    QTime clock;
    QTimer* timer;
signals:
    void currentTime(int time);
public slots:
    void startClock();
    void restartClock();
    void pauseClock();
    void resetClock();
    void updateDis();
};

#endif // STOPWATCHMODEL_H
