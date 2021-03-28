#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Restaurant.h"
#include <vector>
#include <fstream>
#include <string>
#include "UI.h" //include this so we can create and use UI

#define STD_FILE_NAME       "restaurants.txt"
#define SHOW_ALL_CODE       (1)
#define SEARCH_PRICE_CODE   (2)
#define SEARCH_TYPE_CODE    (3)
#define SEARCH_RATING_CODE  (4)
#define GIVE_RATING_CODE    (5)
#define REMOVE_REST_CODE    (6)
#define RANDOM_CODE         (7)
#define EXIT_CODE           (8)


class Executive
{

    private:
    std::vector<Restaurant>* m_restVector;
    std::string m_userFile;
    int m_menuChoice;

    std::string m_tempRestName;
    std::string m_tempRestType;
    int m_tempPricing;
    int m_tempRating;
    int m_tempUserRating;

    std::fstream m_file;
    //std::ofstream m_outFile;

    bool m_isNewUser; //use to tell if it's a new user and what you need to for write out sequence

    public:
    Executive();
    ~Executive();
    void run();
    bool readIn(std::string fileToParse);
    void writeOut(const char* fileToWrite);

};


#endif