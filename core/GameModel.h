#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include <QTimer>
#include <QSet>
#include <QPoint>

/*!
 * \brief The GameModel class - игровая модель
 */
class GameModel : public QObject
{
    Q_OBJECT

public:
    /*!
     * \brief GameModel - конструктор класса
     * \param parent - родительский объект
     */
    GameModel(QObject *parent = nullptr);

    /// текущая скорось игры
    int speed() const;

    /// текущая эпоха
    int epoch() const;

public slots:
    /// запустить игру
    void start();

    /// остановить игру
    void pause();

    /*!
     * \brief setSpeed - задать скорость игры
     * \param msec - продолжительность игровой эпохи в миллисекундах
     */
    void setSpeed(int msec);

    /// очистить игровое поле
    void clearModel();

    /*!
     * \brief manualAppendPoint - оживить клетку по заданной координате
     * \param point - координата клетки
     */
    void manualAppendPoint(const QPoint &point);

signals:
    /*!
     * \brief cellWasRisen - клетка была оживлена
     * \param point - координаты клетки
     */
    void cellWasRisen(const QPoint &point);

    /*!
     * \brief cellWasKilled - клетка была убита
     * \param point - координаты клетки
     */
    void cellWasKilled(const QPoint &point);

    /*!
     * \brief newEpoch - наступила новая эпоха
     * \param epoch - номер эпохи
     */
    void newEpoch(int epoch);

private slots:
    /// новая эпоха - вычисление оживлямых и убиваемых клеток
    void timeoutEpoch();

private:
    /*!
     * \brief riseCell - оживление клетки
     * \param point - координаты клетки
     */
    void riseCell(const QPoint &point);

    /*!
     * \brief killCell - убийство клетки
     * \param point - координаты клетки
     */
    void killCell(const QPoint &point);

private:
    QTimer mm_timerEpoch;   //!< таймер игровой эпохи
    int mm_gameSpeed;       //!< скорость игры (длина эпохи)
    int mm_epoch;           //!< количество прожитых эпох

    QSet<QPoint> mm_data;   //!< живые клетки

};

#endif // GAMEMODEL_H
