#ifndef YALPWINDOW_H
#define YALPWINDOW_H

#include <QMainWindow>
#include "UI.h"

QT_BEGIN_NAMESPACE
namespace Ui { class YalpWindow; }
QT_END_NAMESPACE

class YalpWindow : public QMainWindow
{
    Q_OBJECT

public:
    YalpWindow(QWidget *parent = nullptr);
    ~YalpWindow();

private slots:
    void on_FeelingHungryButton_clicked();

private:
    Ui::YalpWindow *ui;
    UI m_UI;

};
#endif // YALPWINDOW_H
