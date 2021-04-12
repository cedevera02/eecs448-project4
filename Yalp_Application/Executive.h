#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Restaurant.h"
#include <vector>
#include <fstream>
#include <string>
#include "UI.h" //include this so we can create and use UI
#include "Account.h"
#include <QFile>
#include <QTextStream>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class YalpWindow; }
QT_END_NAMESPACE

/// This class handles the main program loop and is called as the single entry point from main


#define STD_FILE_NAME       "restaurants" ///< Starting text file name that all others are based off of
#define SHOW_ALL_CODE       (1) ///< Macro code for option to show all restaurants
#define SEARCH_PRICE_CODE   (2) ///< Macro code for option to search by price
#define SEARCH_TYPE_CODE    (3) ///< Macro code for option to search by cuisine
#define SEARCH_RATING_CODE  (4) ///< Macro code for option to search by rating (either global or personal)
#define GIVE_RATING_CODE    (5) ///< Macro code for option to give a rating
#define REMOVE_REST_CODE    (6) ///< Macro code for option to remove a restaurant
#define RANDOM_CODE         (7) ///< Macro code for option to get a random restaurant
#define EXIT_CODE           (8) ///< Macro code for option to exit the program


class Executive
{

    private:
    std::vector<Restaurant>* m_restVector;///< Pointer to vector holding all restaurant objects
    UI m_UI;///< Local instance of UI to call UI methods
    Account m_Account;///< Local instance of Account to call Account methods
    //std::string m_userFile;//
    int m_menuChoice;///< Variable to hold users menu selection
    std::vector<QString> m_cuisineVector;///< A vector to hold all of the cuisine types for searching by cuisine
    bool m_isReturning;///< Used to see if a file needs to be written out to or not, only ultimately false if GUEST

    QString m_tempRestName;///< Temp holder for restaurant name
    QString m_tempRestType;///< Temp holder for restaurant type
    int m_tempPricing;///< Temp holder for restaurant price
    double m_tempRating;///< Temp holder for restaurant rating
    int m_tempUserRating;///< Temp holder for personal restaurant rating

    //QFile m_file;///< File stream that is opened and closed for reads and writes
    //std::ofstream m_outFile;
    Ui::YalpWindow *m_ui;



    public:
    Executive(Ui::YalpWindow *ui);/// Executive constructor, initializes local objects and vars, requires ui parameter
    ~Executive();/// Executive desctructor, clears out the heap allocation
    void run();/// Main program loop that handles menu choices
    bool readIn(QString fileToParse);/// Reads in from the specified text file
    void writeOut(QString fileToWrite);/// Writes out to a secified text file
    void fillCuisineVector();/// Fills out the cuisine vector
    void correctInvalid();/// Helper function to reduce code repition on input checking

};


#endif // EXECUTIVE_H
