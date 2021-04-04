#ifndef UI_H
#define UI_H
#include "Restaurant.h"
#include <vector>
#include <iostream>
#include <string>

class UI
{
    public:
    UI(){}
    UI(std::vector<Restaurant>* vec); // UI object constructor, store _resVector member variable, fills in cuisine vector.
    int printMenu(); // prints full user menu.
    void printAll();// prints all restaurants.
    void printByPrice(int lower, int higher);// prints restaurants fitting the users given price range.
    void printByCuisine(std::string choice);// prints all restaurants that fits the users choosen cusine.
    void printByRating(int type, double ratingLower, double ratingHigher);// prints all restaurants fitting in the users given rating range(eitehr personal or public ratings).
    void printRandom();// prints a random restaurant.
    void giveRating(std::string name, double rating);// allows a logged in user to assign a restaurant a personal rating.
    void removeRestaurant(std::string name);// allows a logged in user to remove a restaurant from their list.

    private:
    std::vector<Restaurant>* _resVector; // vector storing Restaurant objects.

};

#endif
