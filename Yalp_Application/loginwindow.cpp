#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_pushButton_Login_clicked()
{
    if(!ui->lineEdit_username->text().isEmpty()) {
        username = ui->lineEdit_username->text();

        validateName(username);

        if(isValidName) {
            QMessageBox::information(this, "Login", "Username is valid " + username);
        } else {
            QMessageBox::warning(this, "Login", "Username is invalid");
        }

    }
}

QString loginWindow::getUsername() const
{
    return username;
}

void loginWindow::cleanName(QString name)
{
    QString tempName = "";

    for(int i = 0; i < name.length(); i++) {
        if(name[i] != ' ') {
            tempName += name[i];
        }
    }
    name = tempName;
}

void loginWindow::validateName(QString name)
{
    cleanName(name);

    if(name != "") {
        isValidName = true;
    } else {
        isValidName = false;
    }
    return;
}
