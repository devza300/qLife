#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ptr_model(nullptr),
    ptr_view(nullptr)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/icons/resources/logo.svg"));
    this->setWindowTitle("qLife");

    // обработка запуска игры
    connect(ui->commandLinkButtonPlay, &QPushButton::clicked,
            this, &MainWindow::onPlayClicked);

    // возврат в меню
    connect(ui->pushButtonMenu, &QPushButton::clicked,
            this, [this]() {
        ui->lcdNumber->display(0);

        ui->pageScene->layout()->removeWidget(ptr_view);
        ptr_model->pause();
        delete ptr_view;
        delete ptr_model;

        ui->stackedWidget->setCurrentWidget(ui->pageMenu);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadMap()
{
    // Сад Эдема
    if (ui->radioButton_1->isChecked())
    {
        ptr_model->manualAppendPoint({0, 6});
        ptr_model->manualAppendPoint({1, 2});
        ptr_model->manualAppendPoint({1, 4});
        ptr_model->manualAppendPoint({2, 1});
        ptr_model->manualAppendPoint({2, 7});
        ptr_model->manualAppendPoint({3, 2});
        ptr_model->manualAppendPoint({3, 4});
        ptr_model->manualAppendPoint({3, 6});
        ptr_model->manualAppendPoint({4, 1});
        ptr_model->manualAppendPoint({4, 5});
        ptr_model->manualAppendPoint({5, 3});
        ptr_model->manualAppendPoint({5, 7});
        ptr_model->manualAppendPoint({6, 4});
        ptr_model->manualAppendPoint({7, 3});
        ptr_model->manualAppendPoint({7, 6});
        ptr_model->manualAppendPoint({8, 1});
        ptr_model->manualAppendPoint({8, 5});
        ptr_model->manualAppendPoint({9, 3});
        ptr_model->manualAppendPoint({9, 7});
        ptr_model->manualAppendPoint({10, 4});
        ptr_model->manualAppendPoint({11, 3});
        ptr_model->manualAppendPoint({11, 6});
        ptr_model->manualAppendPoint({12, 1});
        ptr_model->manualAppendPoint({12, 5});
        ptr_model->manualAppendPoint({13, 3});
        ptr_model->manualAppendPoint({13, 7});
        ptr_model->manualAppendPoint({14, 4});
        ptr_model->manualAppendPoint({15, 1});
        ptr_model->manualAppendPoint({15, 5});
        ptr_model->manualAppendPoint({16, 2});
        ptr_model->manualAppendPoint({16, 4});
        ptr_model->manualAppendPoint({16, 7});
        ptr_model->manualAppendPoint({17, 1});
        ptr_model->manualAppendPoint({17, 6});
        ptr_model->manualAppendPoint({18, 3});
        ptr_model->manualAppendPoint({18, 5});
        ptr_model->manualAppendPoint({18, 8});
        ptr_model->manualAppendPoint({19, 1});
        ptr_model->manualAppendPoint({19, 6});

        ptr_model->manualAppendPoint({20, 2});
        ptr_model->manualAppendPoint({20, 4});
        ptr_model->manualAppendPoint({21, 1});
        ptr_model->manualAppendPoint({21, 5});
        ptr_model->manualAppendPoint({21, 7});

        ptr_model->manualAppendPoint({22, 2});
        ptr_model->manualAppendPoint({22, 4});
        ptr_model->manualAppendPoint({23, 1});
        ptr_model->manualAppendPoint({23, 5});
        ptr_model->manualAppendPoint({23, 7});

        ptr_model->manualAppendPoint({24, 2});
        ptr_model->manualAppendPoint({24, 4});
        ptr_model->manualAppendPoint({25, 1});
        ptr_model->manualAppendPoint({25, 5});
        ptr_model->manualAppendPoint({25, 7});

        ptr_model->manualAppendPoint({26, 2});
        ptr_model->manualAppendPoint({26, 4});
        ptr_model->manualAppendPoint({27, 1});
        ptr_model->manualAppendPoint({27, 5});
        ptr_model->manualAppendPoint({27, 7});

        ptr_model->manualAppendPoint({28, 2});
        ptr_model->manualAppendPoint({28, 4});
        ptr_model->manualAppendPoint({29, 1});
        ptr_model->manualAppendPoint({29, 5});
        ptr_model->manualAppendPoint({29, 7});

        ptr_model->manualAppendPoint({30, 2});
        ptr_model->manualAppendPoint({30, 4});
        ptr_model->manualAppendPoint({31, 1});
        ptr_model->manualAppendPoint({31, 5});
        ptr_model->manualAppendPoint({31, 7});

        ptr_model->manualAppendPoint({32, 2});
        ptr_model->manualAppendPoint({32, 4});
    }

    // R-пентамино
    if (ui->radioButton_2->isChecked())
    {
        ptr_model->manualAppendPoint({0, 2});
        ptr_model->manualAppendPoint({1, 0});
        ptr_model->manualAppendPoint({1, 1});
        ptr_model->manualAppendPoint({1, 2});
        ptr_model->manualAppendPoint({2, 1});
    }

    // Галактика Кока
    if (ui->radioButton_3->isChecked())
    {
        ptr_model->manualAppendPoint({0, 0});
        ptr_model->manualAppendPoint({0, 1});
        ptr_model->manualAppendPoint({0, 2});
        ptr_model->manualAppendPoint({0, 3});
        ptr_model->manualAppendPoint({0, 4});
        ptr_model->manualAppendPoint({0, 5});
        ptr_model->manualAppendPoint({1, 0});
        ptr_model->manualAppendPoint({1, 1});
        ptr_model->manualAppendPoint({1, 2});
        ptr_model->manualAppendPoint({1, 3});
        ptr_model->manualAppendPoint({1, 4});
        ptr_model->manualAppendPoint({1, 5});

        ptr_model->manualAppendPoint({3, 0});
        ptr_model->manualAppendPoint({4, 0});
        ptr_model->manualAppendPoint({5, 0});
        ptr_model->manualAppendPoint({6, 0});
        ptr_model->manualAppendPoint({7, 0});
        ptr_model->manualAppendPoint({8, 0});
        ptr_model->manualAppendPoint({3, 1});
        ptr_model->manualAppendPoint({4, 1});
        ptr_model->manualAppendPoint({5, 1});
        ptr_model->manualAppendPoint({6, 1});
        ptr_model->manualAppendPoint({7, 1});
        ptr_model->manualAppendPoint({8, 1});

        ptr_model->manualAppendPoint({7, 3});
        ptr_model->manualAppendPoint({7, 4});
        ptr_model->manualAppendPoint({7, 5});
        ptr_model->manualAppendPoint({7, 6});
        ptr_model->manualAppendPoint({7, 7});
        ptr_model->manualAppendPoint({7, 8});
        ptr_model->manualAppendPoint({8, 3});
        ptr_model->manualAppendPoint({8, 4});
        ptr_model->manualAppendPoint({8, 5});
        ptr_model->manualAppendPoint({8, 6});
        ptr_model->manualAppendPoint({8, 7});
        ptr_model->manualAppendPoint({8, 8});

        ptr_model->manualAppendPoint({0, 7});
        ptr_model->manualAppendPoint({1, 7});
        ptr_model->manualAppendPoint({2, 7});
        ptr_model->manualAppendPoint({3, 7});
        ptr_model->manualAppendPoint({4, 7});
        ptr_model->manualAppendPoint({5, 7});
        ptr_model->manualAppendPoint({0, 8});
        ptr_model->manualAppendPoint({1, 8});
        ptr_model->manualAppendPoint({2, 8});
        ptr_model->manualAppendPoint({3, 8});
        ptr_model->manualAppendPoint({4, 8});
        ptr_model->manualAppendPoint({5, 8});
    }
}

void MainWindow::onPlayClicked()
{
    // динамически создаем объекты игры
    ptr_model = new GameModel(this);
    ptr_view = new GameView(this);

    // применить скорость
    ptr_model->setSpeed(ui->spinBox->value());

    // если разрешено редактирование - добавлять новые клетки
    if (ui->checkBoxEdit->isChecked())
        connect(ptr_view, &GameView::riseCell,
                ptr_model, &GameModel::manualAppendPoint);

    // обработка игровых сигналов
    connect(ptr_model, &GameModel::cellWasRisen,
            ptr_view, &GameView::onCellWasRisen);

    connect(ptr_model, &GameModel::cellWasKilled,
            ptr_view, &GameView::onCellWasKilled);

    connect(ptr_model, &GameModel::newEpoch,
            this, [this](int epoch) {ui->lcdNumber->display(epoch);} );

    connect(ui->pushButtonPlay, &QPushButton::clicked,
            ptr_model, &GameModel::start);

    connect(ui->pushButtonPause, &QPushButton::clicked,
            ptr_model, &GameModel::pause);

    // работа с сенсорным экраном
    ptr_view->setTouchScreenEnabled(ui->checkBoxTouchScreen->isChecked());

    // загрузка карты
    if (ui->groupBoxMap->isChecked())
        loadMap();

    // отображение сцены
    ui->pageScene->layout()->addWidget(ptr_view);
    ui->stackedWidget->setCurrentWidget(ui->pageScene);
}
