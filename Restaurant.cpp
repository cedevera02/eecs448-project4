#include "Restaurant.h"

Restaurant::Restaurant(std::string name)
{
    m_name = name;
}

void Restaurant::setName(std::string name)
{
    m_name = name;
}

void Restaurant::setCuisine(std::string cuisine)
{
    m_cuisine = cuisine;
}

void Restaurant::setPrice(int price)
{
    m_price = price;
}

void Restaurant::setRating(int rating)
{
    m_rating = rating;
}

void Restaurant::setPRating(int pRating)
{
    m_pRating = pRating;
}

std::string Restaurant::getName()
{
    return m_name;
}

std::string Restaurant::getCusine()
{
    return m_cuisine;
}

int Restaurant::getPrice()
{
    return m_price;
}

int Restaurant::getRating()
{
    return m_rating;
}

int Restaurant::getPRating()
{
    return m_pRating;
}