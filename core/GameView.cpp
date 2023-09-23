#include "GameView.h"

#include <QApplication>
#include <QTouchEvent>
#include <QMouseEvent>

GameView::GameView(QWidget *parent) :
    QGraphicsView(parent),
    mm_scene(this),
    mm_totalScaleFactor(1),
    mm_mouseButtonPressed(false)
{
    this->setScene(&mm_scene);

    // обработка событий сенсорного экрана
    viewport()->setAttribute(Qt::WA_AcceptTouchEvents);

    // игровой фон черный
    mm_scene.setBackgroundBrush(QBrush(Qt::black));
    mm_scene.setSceneRect(this->rect());

    // убрать скроллы
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // зеленый указатель
    mm_scene.installEventFilter(this);
    this->setMouseTracking(true);
}

void GameView::setTouchScreenEnabled(bool enabled)
{
    this->setDragMode(enabled ? QGraphicsView::ScrollHandDrag : QGraphicsView::NoDrag);
}

bool GameView::viewportEvent(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::TouchBegin:
    case QEvent::TouchUpdate:
    case QEvent::TouchEnd:
    {
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
        QList<QTouchEvent::TouchPoint> touchPoints = touchEvent->points();

        if (touchPoints.count() == 2)
        {
            // determine scale factor
            const QTouchEvent::TouchPoint &touchPoint0 = touchPoints.first();
            const QTouchEvent::TouchPoint &touchPoint1 = touchPoints.last();

            qreal currentScaleFactor =
                QLineF(touchPoint0.position(), touchPoint1.position()).length() /
                                       QLineF(touchPoint0.pressPosition(), touchPoint1.pressPosition()).length();

            if (touchEvent->touchPointStates() & Qt::TouchPointReleased)
            {
                // if one of the fingers is released, remember the current scale
                // factor so that adding another finger later will continue zooming
                // by adding new scale factor to the existing remembered value.
                mm_totalScaleFactor *= currentScaleFactor;
                currentScaleFactor = 1;
            }

            setTransform(QTransform::fromScale(mm_totalScaleFactor * currentScaleFactor,
                                               mm_totalScaleFactor * currentScaleFactor));
        }
        return true;
    }

    default:
        break;

    }

    return QGraphicsView::viewportEvent(event);
}

bool GameView::eventFilter(QObject *object, QEvent *event)
{
    switch (event->type())
    {
    case QEvent::Enter:
        QApplication::setOverrideCursor(QCursor(Qt::BlankCursor));
        break;

    case QEvent::GraphicsSceneLeave:
        QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
        break;

    case QEvent::GraphicsSceneMousePress:
    {
        mm_mouseButtonPressed = true;

        QPointF pos = this->mapToScene(this->viewport()->mapFromGlobal(QCursor::pos()));
        QPoint point(pos.x() / 10, pos.y() / 10);

        emit riseCell(point);

        break;
    }

    case QEvent::GraphicsSceneMouseRelease:
        mm_mouseButtonPressed = false;
        break;

    case QEvent::GraphicsSceneMouseMove:
    {
        if (mm_scene.items().contains(ptr_greenCellCursor))
            mm_scene.removeItem(ptr_greenCellCursor);

        QPointF pos = this->mapToScene(this->viewport()->mapFromGlobal(QCursor::pos()));
        QPoint point(pos.x() / 10, pos.y() / 10);

        QPen outlinePen(Qt::green);
        outlinePen.setWidth(1);

        ptr_greenCellCursor = mm_scene.addRect(point.x() * 10, point.y() * 10, 8, 8, outlinePen, QBrush(Qt::green));

        if (mm_mouseButtonPressed)
            emit riseCell(point);

        break;
    }

    default:
        break;
    }

    event->accept();

    return QObject::eventFilter(object, event);
}

void GameView::onCellWasRisen(const QPoint &point)
{
    QGraphicsRectItem *item = new QGraphicsRectItem(point.x() * 10, point.y() * 10, 8, 8);
    QPen outlinePen(Qt::white);
    outlinePen.setWidth(1);
    item->setPen(outlinePen);
    item->setBrush(QBrush(Qt::white));

    mm_scene.addItem(item);
    mm_items.insert(point, item);
}

void GameView::onCellWasKilled(const QPoint &point)
{
    auto item = mm_items.value(point);
    mm_scene.removeItem(item);
    mm_items.remove(point);
    delete item;
}
