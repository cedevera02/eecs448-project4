#ifndef UI_H
#define UI_H
#include "Restaurant.h"
#include <vector>
#include <iostream>
#include <string>

class UI
{
    public:
    UI(Restaurant** ptr); // UI object constructor, store _ResPtr member variable
    void printMenu();
    void printAll();
    void printByPrice(int lower, int higher);
    void printByCuisine(int choice);
    void printByRating();
    void printRandom();
    void giveRating();
    void removeRestaurant();
    int intInputCheck();

    private:
    Restaurant** _ResPtr; // vector, ptr to vector storing Restaurant objects

};

#endif