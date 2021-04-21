#include "testsuite.h"
#include "ui_testsuite.h"

testSuite::testSuite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testSuite)
{
    ui->setupUi(this);
}

testSuite::~testSuite()
{
    delete ui;
}
