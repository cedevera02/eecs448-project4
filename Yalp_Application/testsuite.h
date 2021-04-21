#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QDialog>

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
};

#endif // TESTSUITE_H
