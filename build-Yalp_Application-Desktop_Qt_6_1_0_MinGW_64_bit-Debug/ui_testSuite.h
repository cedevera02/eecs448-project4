/********************************************************************************
** Form generated from reading UI file 'testsuite.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSUITE_H
#define UI_TESTSUITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_testSuite
{
public:
    QTextEdit *textEdit;

    void setupUi(QDialog *testSuite)
    {
        if (testSuite->objectName().isEmpty())
            testSuite->setObjectName(QString::fromUtf8("testSuite"));
        testSuite->resize(532, 511);
        textEdit = new QTextEdit(testSuite);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 20, 491, 471));
        textEdit->setReadOnly(true);

        retranslateUi(testSuite);

        QMetaObject::connectSlotsByName(testSuite);
    } // setupUi

    void retranslateUi(QDialog *testSuite)
    {
        testSuite->setWindowTitle(QCoreApplication::translate("testSuite", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testSuite: public Ui_testSuite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSUITE_H
