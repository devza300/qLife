#include "GameModel.h"
#include "qforeach.h"

#include <QDateTime>

GameModel::GameModel(QObject *parent) :
    QObject(parent),
    mm_timerEpoch(this),
    mm_gameSpeed(1000),
    mm_epoch(0)
{
    // обработка эпохи
    connect(&mm_timerEpoch, &QTimer::timeout,
            this, &GameModel::timeoutEpoch);
}

int GameModel::speed() const
{
    return mm_gameSpeed;
}

int GameModel::epoch() const
{
    return mm_epoch;
}

void GameModel::start()
{
    mm_timerEpoch.start(mm_gameSpeed);
}

void GameModel::pause()
{
    mm_timerEpoch.stop();
}

void GameModel::setSpeed(int msec)
{
    mm_gameSpeed = msec;

    if (mm_timerEpoch.isActive())
        mm_timerEpoch.setInterval(msec);
}

void GameModel::clearModel()
{
    foreach (auto point, mm_data)
        killCell(point);
}

void GameModel::manualAppendPoint(const QPoint &point)
{
    riseCell(point);
}

void GameModel::timeoutEpoch()
{
    emit newEpoch(mm_epoch++);

    // initialize kill list
    QList<QPoint> checkToRise;
    QList<QPoint> killList;

    auto analyze = [&](const QPoint &point, int x, int y)
    {
        QPoint seek = point + QPoint(x, y);

        if (mm_data.contains(seek))
            return 1;

        checkToRise.append(seek);
        return 0;
    };

    foreach (auto point, mm_data)
    {
        int count_alive = 0;
        count_alive += analyze(point, 1, 0);
        count_alive += analyze(point, 1, 1);
        count_alive += analyze(point, 0, 1);
        count_alive += analyze(point, -1, 1);
        count_alive += analyze(point, -1, 0);
        count_alive += analyze(point, -1, -1);
        count_alive += analyze(point, 0, -1);
        count_alive += analyze(point, 1, -1);

        if (count_alive == 2 || count_alive == 3)
            continue;

        killList.append(point);
    }

    // rise
    foreach (auto point, checkToRise)
    {
        if (checkToRise.count(point) != 3)
        {
            checkToRise.removeAll(point);
            continue;
        }

        riseCell(point);
        checkToRise.removeAll(point);
    }

    // kill
    foreach (auto point, killList)
        killCell(point);
}

void GameModel::riseCell(const QPoint &point)
{
    if (mm_data.contains(point))
        return;

    mm_data.insert(point);
    emit cellWasRisen(point);
}

void GameModel::killCell(const QPoint &point)
{
    if (!mm_data.contains(point))
        return;

    mm_data.remove(point);
    emit cellWasKilled(point);
}
