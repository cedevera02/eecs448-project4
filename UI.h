#ifndef UI_H
#define UI_H
#include "Restaurant.h"
#include <vector>
#include <iostream>
#include <string>

class UI
{
    public:
    UI(std::vector<Restaurant>* vec); // UI object constructor, store _resVector member variable, fills in cuisine vector.
    int printMenu();
    void printAll();
    void printByPrice(int lower, int higher);
    void printByCuisine(std::string choice);
    void printByRating(int type, int rating);
    void printRandom();
    void giveRating(std::string name, int rating);
    void removeRestaurant(std::string name);

    private:
    std::vector<Restaurant>* _resVector; // vector storing Restaurant objects

};

#endif
