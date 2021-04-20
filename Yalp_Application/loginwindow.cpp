#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include "yalpwindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    misValidName = false;
}

loginWindow::~loginWindow()
{
    delete ui;
}
//make it give the name to the main, give successful login to the main so we know if they are still a guest or not

void loginWindow::closeEvent(QCloseEvent *event)
{
    if(isValidName()) {
        event->accept();
    } else {
        QMessageBox::warning(this, "Login", "Must enter valid username before exiting");
        event->ignore();
    }
}

void loginWindow::on_pushButton_Login_clicked()
{
    if(!ui->lineEdit_username->text().isEmpty()) {
        username = ui->lineEdit_username->text();

        validateName(&username);

        if(misValidName) {
            QMessageBox::information(this, "Login", "Username is valid. Exit login window to continue as user.");
        } else {
            QMessageBox::warning(this, "Login", "Username is invalid. Please try again.");
        }

    }
}

QString loginWindow::getUsername() const
{
    return username;
}

bool loginWindow::isValidName()
{
    return misValidName;
}

void loginWindow::cleanName(QString* name)
{
    QString tempName = "";
    QString holder = *name;

    for(int i = 0; i < holder.length(); i++) {
        if(holder[i] != ' ') {
            tempName += holder[i];
        }
    }
    *name = tempName;
}

void loginWindow::validateName(QString* name)
{
    cleanName(&username);

    if(*name != "") {
        misValidName = true;
    } else {
        misValidName = false;
    }
    return;
}
