#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "GameModel.h"
#include "GameView.h"

namespace Ui {
class MainWindow;
}

/*!
 * \brief The MainWindow class - главное окно игры
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /// демонстраця - загрузка начальной карты
    void loadMap();

private slots:
    /// запуск игры
    void onPlayClicked();

private:
    Ui::MainWindow *ui;

    GameModel *ptr_model;   //!< модель игры
    GameView *ptr_view;     //!< представление

};

#endif // MAINWINDOW_H
