#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QEvent>

/*!
 * \brief The GameView class - отрисовка игрового процесса
 */
class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    /*!
     * \brief GameView - конструктор касса
     * \param parent - родительский объект
     */
    GameView(QWidget *parent = nullptr);

    /*!
     * \brief setTouchScreenEnabled - задать поддержку сенсорнго экрана
     * \param enabled - признак разрешения
     */
    void setTouchScreenEnabled(bool enabled);

protected:
    /*!
     * \brief viewportEvent - обработка собыий сенсорного экрана
     * \param event - событие
     * \return - признак игнорирования
     */
    bool viewportEvent(QEvent *event) override;

    /*!
     * \brief eventFilter - обработка событий курсора
     * \param object - объект-источник
     * \param event - событие
     * \return - признак игнорирования
     */
    bool eventFilter(QObject *object, QEvent *event) override;

public slots:
    /*!
     * \brief onCellWasRisen - клетка была оживлена
     * \param point - координаты клетки
     */
    void onCellWasRisen(const QPoint &point);

    /*!
     * \brief onCellWasKilled - клетка была убита
     * \param point - координаты клетки
     */
    void onCellWasKilled(const QPoint &point);

signals:
    /*!
     * \brief riseCell - оживить клетку
     * \param point - координаты клетки
     */
    void riseCell(const QPoint &point);

private:
    QGraphicsScene mm_scene;        //!< графическая сцена
    qreal mm_totalScaleFactor;      //!< масштаб (для сенсорных экранов)

    QHash<QPoint, QGraphicsRectItem*> mm_items; //!< список живых клеток

    QGraphicsRectItem *ptr_greenCellCursor;     //!< указатель курсора
    bool mm_mouseButtonPressed;                 //!< зажата клавиша мыши

};

#endif // GAMEVIEW_H
