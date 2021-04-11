#ifndef YALPWINDOW_H
#define YALPWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class YalpWindow; }
QT_END_NAMESPACE

class YalpWindow : public QMainWindow
{
    Q_OBJECT

public:
    YalpWindow(QWidget *parent = nullptr);
    ~YalpWindow();

private:
    Ui::YalpWindow *ui;
};
#endif // YALPWINDOW_H
