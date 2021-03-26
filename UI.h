#ifndef UI_H
#define UI_H
#include "Restaurant.h"
#include <iostream>

class UI
{
    public:
    UI(Restaurant** ptr); // UI object constructor, store _ResVecPtr member variable
    void printMenu();
    void printAll();
    void printByCuisine(int choice);
    void printByRating();
    void printRandom();
    void giveRating();
    void removeRestaurant();

    private:
    Restaurant** _ResVecPtr;

};

#endif