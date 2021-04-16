#ifndef YALPWINDOW_H
#define YALPWINDOW_H

#include <QMainWindow>
#include <vector>
#include "Choices.h"
#include "Restaurant.h"
#include <QFile>
#include <QTextStream>


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

    void on_Min1RB_clicked();

    void on_Min2RB_clicked();

    void on_Min3RB_clicked();

    void on_Max1RB_clicked();

    void on_Max2RB_clicked();

    void on_Max3RB_clicked();

    void on_searchFilterButton_clicked();

    void on_publicRRadioButtn_clicked();

    void on_radioButton_2_clicked();

    void on_cusineTypeLineEdit_textEdited(const QString &arg1);

private:
    Ui::YalpWindow *ui;
    std::vector<Restaurant>* m_restVector; ///vector containing all restaurants in file
    std::vector<Restaurant>* m_printVector; ///vector to be printed when search is finished
    int m_minRB;
    int m_maxRB;
    int m_pubRate;
    int m_mineRate;
    int m_ratingType;
    int m_rating[2];
    QString m_tempRestName;
    QString m_tempRestType;
    int m_tempPricing;
    double m_tempRating;
    int m_tempUserRating;
    QString m_cuisineType;
    Choices m_choices;
    void TestVectorCreator();
    bool readIn();

};
#endif // YALPWINDOW_H
