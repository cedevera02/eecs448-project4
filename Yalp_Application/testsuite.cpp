#include "testsuite.h"
#include "ui_testsuite.h"

testSuite::testSuite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testSuite)
{
    ui->setupUi(this);
    run();
}

testSuite::~testSuite()
{
    delete ui;
}

void testSuite::run()
{
    ///all test will be called here
    ///ui->textEdit->insertPlainText("testing\n");
    ///ui->textEdit->insertPlainText("test complete");
    loginTest();
    restVecTest();
    priceRangeTest();
    personalRatingTest();
    publicRatingTest();
    cuisineVecTest();
}


void testSuite::loginTest()
{
    /// test code
    bool pass = true;

    /// results print out
    ui->textEdit->insertPlainText("Test 1: user can log in and use program with account     ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }

}

void testSuite::restVecTest()
{
    /// test code
    bool pass = false;

    /// results print out
    ui->textEdit->insertPlainText("Test     ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}

void testSuite::priceRangeTest()
{
    /// test code
    bool pass;

    /// results print out
    ui->textEdit->insertPlainText("Test     ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}

void testSuite::personalRatingTest()
{
    /// test code
    bool pass;

    /// results print out
    ui->textEdit->insertPlainText("Test     ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}

void testSuite::publicRatingTest()
{
    /// test code
    bool pass;

    /// results print out
    ui->textEdit->insertPlainText("Test     ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}

void testSuite::cuisineVecTest()
{
    /// test code
    bool pass;

    /// results print out
    ui->textEdit->insertPlainText("Test     ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}



