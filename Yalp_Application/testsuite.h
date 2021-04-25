#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include "Restaurant.h"
#include "Choices.h"
#include "ui_testsuite.h"

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
    Choices m_choice;
    std::vector<Restaurant>* m_restVector;
    std::vector<QString> m_cuisineVector;
    void run();
    void TestVectorCreator();

    void restVecTest();
    void priceRangeTest();
    void personalRatingTest();
    void publicRatingTest();
    void cuisineTest();
    void randRestTest();
    void removeRestTest();

};

#endif // TESTSUITE_H
