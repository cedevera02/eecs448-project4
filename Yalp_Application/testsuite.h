#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include "Restaurant.h"
#include "Choices.h"
#include "ui_testsuite.h"


/// This class is the test suite
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
    Choices m_choice; ///Local instance of Choices to call Choices methods
    std::vector<Restaurant>* m_restVector;/// vector storing Restaurant objects
    std::vector<QString> m_cuisineVector;///vector storing cuisine objects
    void run(); ///runs all the tests
    void TestVectorCreator(); ///test restaruant objects in test vector to use for methods

    void restVecTest(); ///tests if restaurant vector was filled correctly
    void priceRangeTest(); ///Tests the bounds of the price range
    void personalRatingTest(); ///tests the bounds of adding a personal rating
    void publicRatingTest(); ///tests if a rating is with the correct restaurant
    void cuisineTest(); ///tests if cuisine vector is filled and is accurate
    void randRestTest(); ///tests calling a random restuarant
    void removeRestTest(); ///tests removing a restaurant from restaruant vector

};

#endif // TESTSUITE_H
