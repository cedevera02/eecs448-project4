#ifndef CHOICES_H
#define CHOICES_H
#include "Restaurant.h"
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

class Choices
{
    public:
    Choices();
    Choices(std::vector<Restaurant>* vec); /// Choices object constructor, store _resVector member variable, fills in cuisine vector.
    //int printMenu(); /// prints full user menu.
    //void printAll();/// prints all restaurants.
    void printByPrice();/// prints restaurants fitting the users given price range.
    void printByCuisine();/// prints all restaurants that fits the users choosen cusine.
    void printByRating();/// prints all restaurants fitting in the users given rating range(eitehr personal or public ratings).
    Restaurant printRandom();/// prints a random restaurant.
    //void giveRating(QString name, double rating);/// allows a logged in user to assign a restaurant a personal rating.
    //void removeRestaurant(QString name);/// allows a logged in user to remove a restaurant from their list.
    std::vector<Restaurant>* createVector(int minRB,int maxRB,int ratingType,int rating[2], QString cuisineType); ///creates a vector of restaurants that match the given parameters
    void setRestVector(std::vector<Restaurant>* vec);

    private:
    std::vector<Restaurant>* _resVector; ///< vector storing Restaurant objects.
    std::vector<Restaurant>* m_printVector;
    int m_minRB; ///shows which radio button is chosen for min price
    int m_maxRB; ///shows which radio button is chosen for max price
    int m_ratingType; ///shows what the public rating chosen
    int m_rating[2]; ///show what the personal rating chose
    QString m_cuisineType;

};

#endif // CHOICES_H
