#include "Restaurant.h"

///RESTAURANT CONSTRUCTOR
///
///@param name Takes in the name of the rataurant
Restaurant::Restaurant(std::string name)
{
    m_name = name;
    m_cuisine = "";
    m_price = 0;
    m_rating = 0.0;
    m_pRating = 0;
}

///Default written out
Restaurant::~Restaurant()
{

}

///METHODS
///
///This sets the restaurant name
///@param name Name of the restaurant
void Restaurant::setName(std::string name)
{
    m_name = name;
}

///This sets the restaurant cuisine type
///
///@param cuisine Cuisine type of restaurant
void Restaurant::setCuisine(std::string cuisine)
{
    m_cuisine = cuisine;
}


///This sets the restaurant price
///
///@param price Price of restaurant
void Restaurant::setPrice(int price)
{
    m_price = price;
}

///This sets the global restaurant rating
///
///@param rating Global rating of restaurant
void Restaurant::setRating(double rating)
{
    m_rating = rating;
}

///This set the personal restaurant rating
///
///@param pRating Personal rating of restaurant
void Restaurant::setPRating(double pRating)
{
    m_pRating = pRating;
}

//This get the restaurant name
///
///@return Returns the restaurant name string
std::string Restaurant::getName()
{
    return m_name;
}

///This gets the cuisine type
///
///@return Returns the restaurant cuisine string
std::string Restaurant::getCusine()
{
    return m_cuisine;
}

///This gets the restaurant price
///
///@return Returns the restaurant price int
int Restaurant::getPrice()
{
    return m_price;
}

///This gets the global restaurant rating
///
///@return Returns the restaurant global rating double
double Restaurant::getRating()
{
    return m_rating;
}

///This gets the personal restaurant rating
///
///@return Returns the restaurant personal rating double
double Restaurant::getPRating()
{
    return m_pRating;
}