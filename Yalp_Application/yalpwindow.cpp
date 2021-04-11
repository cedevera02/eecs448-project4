#include "yalpwindow.h"
#include "ui_yalpwindow.h"

YalpWindow::YalpWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::YalpWindow)
{
    ui->setupUi(this);
}

YalpWindow::~YalpWindow()
{
    delete ui;
}

