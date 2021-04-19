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
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();
    QString getUsername() const;

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::loginWindow *ui;
    QString username;
    bool isValidName;
    void validateName(QString name);
    void cleanName(QString name);
};

#endif // LOGINWINDOW_H
