#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <QMainWindow>

///This class holds the data about each restaurant

class Restaurant
{
    private:
    QString m_name;///< Stores the restaurant name
    QString m_cuisine;///< Stores the restaurant cuisine type
    int m_price;///< Stores the restaurant price range
    double m_rating;///< Stores the restaurant global rating
    double m_pRating;///< Stores the restaurant personal rating

    public:
    Restaurant(QString name);/// Simple constrictor to inizialize member variables
    ~Restaurant();
    void setName(QString name);/// Helper function to set restaurant name
    void setCuisine(QString cuisine);/// Helper function to set restaurant cuisine
    void setPrice(int price);/// Helper function to set restaurant price
    void setRating(double rating);/// Helper function to set restaurant global rating
    void setPRating(double pRating);/// Helper cuntion to set restaurant personal rating
    QString getName();/// Helper function to get restaurant name
    QString getCusine();/// Helper function to get restaurant cuisine type
    int getPrice();/// Helper function to get restaurant price
    double getRating();/// Helper function to get restaurant global rating
    double getPRating();/// Helper function to get restaurant personal rating

};

#endif// RESTAURANT_H
