#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include "yalpwindow.h"

///constructor
loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    misValidName = false;
}

///destructor
loginWindow::~loginWindow()
{
    delete ui;
}

///close event that makes sure the user logs in before they exit the window
void loginWindow::closeEvent(QCloseEvent *event)
{
    if(isValidName()) {
        event->accept();//accepts the exit event if the name is valid
    } else {
        QMessageBox::warning(this, "Login", "Must enter valid username before exiting");
        event->ignore();//denys the exit event
    }
}

///button click event for getting input from the text box
void loginWindow::on_pushButton_Login_clicked()
{
    if(!ui->lineEdit_username->text().isEmpty()) { //makes sure the box isn't empty
        username = ui->lineEdit_username->text(); //gets the input from the box

        validateName(&username);//calls validation function

        if(misValidName) {
            QMessageBox::information(this, "Login", "Username is valid. Exit login window to continue as user.");
        } else {
            QMessageBox::warning(this, "Login", "Username is invalid. Please try again.");
        }

    }
}

///helper function to return the username
QString loginWindow::getUsername() const
{
    return username;
}

///helper function to see if the name is valid
bool loginWindow::isValidName()
{
    return misValidName;
}

///helper function to clean any spaces out of the username
void loginWindow::cleanName(QString* name)
{
    QString tempName = ""; //empty string
    QString holder = *name;//the holder has the current name in it

    for(int i = 0; i < holder.length(); i++) {
        if(holder[i] != ' ') {
            tempName += holder[i];//if the char isn't a space at that index, we add it to the temp name
        }
    }
    *name = tempName;//set the value of the current name to the cleaned temp name
}

///helper function to validate the username
void loginWindow::validateName(QString* name)
{
    cleanName(&username);//calls the clean name function

    if(*name != "") {//if the name is not empty it is valid
        misValidName = true;
    } else {
        misValidName = false;
    }
    return;
}
