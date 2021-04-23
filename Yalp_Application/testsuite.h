#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QDialog>
#include "Restaurant.h"

namespace Ui {
class testSuite;
}

class testSuite : public QDialog
{
    Q_OBJECT

public:
    explicit testSuite(QWidget *parent = nullptr);
    ~testSuite();

private:
    Ui::testSuite *ui;
    std::vector<Restaurant>* m_restVector;
    void run();
    void TestVectorCreator();

    void loginTest();
    void restVecTest();
    void priceRangeTest();
    void personalRatingTest();
    void publicRatingTest();
    void cuisineVecTest();

};

#endif // TESTSUITE_H
