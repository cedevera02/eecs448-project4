#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class loginWindow;
}

class loginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);///constructor
    ~loginWindow();
    QString getUsername() const;///helper to return the username
    bool isValidName();///helper to see if the name is valid

private slots:
    void on_pushButton_Login_clicked();///event that triggers when the button is clicked to get the username input

private:
    Ui::loginWindow *ui;///pointer to the ui object that is the window
    QString username;///User entered name
    bool misValidName;
    void validateName(QString* name);///helper that validates the name
    void cleanName(QString* name);///helper that cleans spaces from the name
    void closeEvent(QCloseEvent *event);///this makes sure the user has logged in before they close the window
};

#endif // LOGINWINDOW_H
