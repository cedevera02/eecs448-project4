#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>

class Restaurant
{
    private:
    std::string m_name;
    std::string m_cuisine;
    int m_price;
    double m_rating;
    double m_pRating;

    public:

    Restaurant(std::string name);
    ~Restaurant();
    void setName(std::string name);
    void setCuisine(std::string cuisine);
    void setPrice(int price);
    void setRating(double rating);
    void setPRating(double pRating);
    std::string getName();
    std::string getCusine();
    int getPrice();
    double getRating();
    double getPRating();

};

#endif