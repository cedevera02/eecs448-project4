#ifndef YALPWINDOW_H
#define YALPWINDOW_H

#include <QMainWindow>
#include <vector>
#include "Choices.h"
#include "Restaurant.h"
#include "testsuite.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class YalpWindow; }
QT_END_NAMESPACE

class YalpWindow : public QMainWindow
{
    Q_OBJECT

public:
    YalpWindow(QWidget *parent = nullptr);
    ~YalpWindow();
    void setUsername(QString aUsername);

private slots:

    void on_Min1RB_clicked(); ///stores min price range

    void on_testButton_clicked();///creates tests suite objects and opens the window

    void on_Min2RB_clicked();///stores min price range

    void on_Min3RB_clicked();///stores min price range

    void on_Max1RB_clicked();///stores max price range

    void on_Max2RB_clicked();///stores max price range

    void on_Max3RB_clicked();///stores max price range

    void on_searchFilterButton_clicked();///calls Choices function to print out restaurants fitting the filter specifications

    void on_publicRRadioButtn_clicked();///stores public rating specified

    void on_personalRRadioButton_clicked();///stores personal rating specified

    void on_cusineTypeLineEdit_textEdited(const QString &arg1);///stores cuisine type speficied

    void on_MinRSpinBox_valueChanged(int arg1);///stores minimum rating speficied

    void on_MaxRSpinBox_valueChanged(int arg1);///stores maximum rating speficied

    void on_FeelingHungryButton_clicked();///prints out one random restaurant

    void on_removeRestLineEdit_textEdited(const QString &arg1);///stores restaurant to be removed

    void on_removeRestButton_clicked();///calls Choices class methods to remove restaurant

    void on_loginButton_clicked();

    void on_RestToBeRatiedLineEdit_textEdited(const QString &arg1);///stores restaurant to be rated's name

    void on_RestToRateSpinBox_valueChanged(int arg1);///stores rating to be added

    void on_AddRatinButton_clicked();///calls Choices class methods to add rating

private:
    Ui::YalpWindow *ui;
    std::vector<Restaurant>* m_restVector; ///vector containing all restaurants in file
    std::vector<Restaurant>* m_printVector; ///vector to be printed when search is finished
    int m_minRB; ///min price range
    int m_maxRB; ///max price range
    int m_ratingType;///2 is public rating, 1 is personal rating
    int m_rating[2];///[0] is for min, [1] is for max
    QString m_tempRestName;///temporary name used for readIn
    QString m_tempRestType;///temporary cuisine used for readIn
    int m_tempPricing;///temporary price used for readIn
    double m_tempRating;///temporary rating used for readIn
    int m_tempUserRating;///temporary rating used for readIn
    QString m_cuisineType;///used to stores cuisine type for search option
    Choices m_choices;///choices class object that handles all the filtering stuff
    QString m_removeRest; ///restaurant to be removed
    QFile m_file;///file to read in/write out
    QString m_username;///username of user
    QString m_restToRate; ///restaurant to rate for personal
    int m_restRate; ///rating to give for personal rating
    bool m_isGuest;///indicates whether user has logged in
    void TestVectorCreator();///creates dummy restvector to work with
    bool readIn(); ///function that reads in from restaurant text file
    void writeOut();///writes out to username.txt to keep a record of their preferences
    bool m_valid; /// tells whether input for filter is valid
    void printAllRest(std::vector<Restaurant>* vect);///prints all the restaurants in m_restVector
    QString makeNice(QString word);///removes the underlines in QString and then returns it
    QString makeFormat(QString word);///puts input into format used for restaurants
    QString dollarPrice(int price); ///turns number price into dollar sign
    void closeEvent(QCloseEvent *event);
    void printVariables();///prints out all stored variables
    QString m_inFileName;
};
#endif // YALPWINDOW_H
