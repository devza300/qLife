#include <QtTest>
#include <QCoreApplication>

#include "GameModel.h"

class math : public QObject
{
    Q_OBJECT

public:
    math();
    ~math();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

private:
    GameModel *ptr_model;

};

math::math()
{
    ptr_model = new GameModel(nullptr);
}

math::~math()
{
    delete ptr_model;
}

void math::initTestCase()
{
    ptr_model->setSpeed(1000);

    // Галактика Кока
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

    ptr_model->start();
}

void math::cleanupTestCase()
{
    ptr_model->clearModel();
}

void math::test_case1()
{
    ptr_model->pause();
}

QTEST_MAIN(math)

#include "tst_math.moc"
