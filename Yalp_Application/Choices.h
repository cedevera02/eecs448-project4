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
    void printByPrice();/// prints restaurants fitting the users given price range.
    void printByCuisine();/// prints all restaurants that fits the users choosen cusine.
    void printByRating();/// prints all restaurants fitting in the users given rating range(eitehr personal or public ratings).
    Restaurant printRandom();/// prints a random restaurant.
    bool giveRating(QString name, int rating);/// allows a logged in user to assign a restaurant a personal rating.
    void removeRestaurant(QString name, bool& haveRes);/// allows a logged in user to remove a restaurant from their list.
    std::vector<Restaurant>* createVector(int minRB,int maxRB,int ratingType,int rating[], QString cuisineType); ///creates a vector of restaurants that match the given parameters
    void setRestVector(std::vector<Restaurant>* vec);///sets the _resVector equal to for fiddling with

    private:
    std::vector<Restaurant>* _resVector; ///< vector storing Restaurant objects.
    std::vector<Restaurant>* m_printVector; ///vector that stores restaurant based on filters
    int m_minRB; ///shows which radio button is chosen for min price
    int m_maxRB; ///shows which radio button is chosen for max price
    int m_ratingType; ///shows what the public rating chosen
    int m_rating[2]; ///show what the personal rating chose
    bool isGuest; ///indicates whether the user has logged in or not
    QString m_cuisineType; ///type of restaurant the user is asking for

};

#endif // CHOICES_H
