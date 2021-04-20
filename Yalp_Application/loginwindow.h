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
    bool isValidName();

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::loginWindow *ui;
    QString username;
    bool misValidName;
    void validateName(QString* name);
    void cleanName(QString* name);
    void closeEvent(QCloseEvent *event);
};

#endif // LOGINWINDOW_H
