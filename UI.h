#ifndef UI_H
#define UI_H
#include "Restaurant.h"
#include <vector>
#include <iostream>
#include <string>

class UI
{
    public:
    UI(std::vector<Restaurant> vec); // UI object constructor, store _ResPtr member variable
    void printMenu();
    void printAll();
    void printByPrice(int lower, int higher);
    void printByCuisine(int choice);
    void printByRating(int type);
    void printRandom();
    void giveRating();
    void removeRestaurant();
    int intInputCheck();

    private:
    std::vector<Restaurant> _ResVector; // vector storing Restaurant objects

};

#endif