#include "yalpwindow.h"
#include "ui_yalpwindow.h"
#include "UI.h"

YalpWindow::YalpWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::YalpWindow)
{
    ui->setupUi(this);
    ui->RestaurantTextEdit->setReadOnly(true);
    m_UI.setUI(ui);
}

YalpWindow::~YalpWindow()
{
    delete ui;
}


void YalpWindow::on_FeelingHungryButton_clicked()
{
    m_UI.printRandom();
}
