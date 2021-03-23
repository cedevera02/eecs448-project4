#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>

class Restaurant
{
    private:
    std::string m_name;
    std::string m_cuisine;
    int m_price;
    int m_rating;
    int m_pRating;

    public:

    Restaurant(std::string name);
    void setName(std::string name);
    void setCuisine(std::string cuisine);
    void setPrice(int price);
    void setRating(int rating);
    void setPRating(int pRating);
    std::string getName();
    std::string getCusine();
    int getPrice();
    int getRating();
    int getPRating();

};

#endif