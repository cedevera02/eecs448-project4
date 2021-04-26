#include "Choices.h"


///Choices CONSTRUCTOR
///
///@param vec Takes in restaurant vector pointer
Choices::Choices(std::vector<Restaurant>* vec)
{
    _resVector = vec;
    m_minRB = 0;
    m_maxRB = 0;
    m_ratingType = 0;
    m_rating[0] = 0;m_rating[1] = 5;
    m_cuisineType = "";
    srand(time(NULL));

}

///Choices CONSTRUCTOR
/// Contains no param
Choices::Choices()
{
    m_minRB = 0;
    m_maxRB = 0;
    m_ratingType = 0;
    m_rating[0] = 0;m_rating[1] = 5;
    m_cuisineType = "";
    srand(time(NULL));
}

///METHODS
///
///Prints out all of the menu options that user can choose from
///@return Returns the int value that the user chooses
//int Choices::printMenu()
//{
//    int input;


//    std::cout << "\n1. Show all Restaurants\n2. Search by Prices\n3. Search by Cuisine\n4. Search by Rating\n5. Give a Rating\n6. Remove a Restaurant\n7. Random\n8. Exit Program\n";
//    std::cin >> input;

//    while(std::cin.fail() || input < 1 || input > 8)
//    {
//        std::cin.clear();
//        std::cin.ignore();
//        std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
//        std::cin >> input;
//    }

//    return input;
//}

///sets the print and rest vectors
///@param vec Takes in restaurant vector pointer
void Choices::setRestVector(std::vector<Restaurant>* vec)
{
    _resVector = vec;
    m_printVector = new std::vector<Restaurant>;
    for (int i = 0; i < (int)vec->size(); i++){
        m_printVector->push_back(vec->at(i));
    }
}

///This method prints all of the retaurants and their data
///
///Acesses local restaurant vector and formats the output into lines
//void Choices::printAll()
//{
//    for(int i=0; i < _resVector->size(); i++)
//    {
//        std::cout << _resVector->at(i).getName() << "  " << _resVector->at(i).getCusine() << "  " <<_resVector->at(i).getPrice() << "  Rating: " << _resVector->at(i).getRating() << "  Personal Rating: " << _resVector->at(i).getPRating() << "\n";
//    }
//}

///This method prints all of the restaurants in a certain price range
///
///@param lower The lower bound for the price range
///@param higher The higher boudn for the price range
void Choices::printByPrice()
{
    std::vector<Restaurant>* temp = new std::vector<Restaurant>;

    for(int i=0; i < (int)m_printVector->size(); i++)
    {
        if(m_printVector->at(i).getPrice() >= m_minRB && m_printVector->at(i).getPrice() <= m_maxRB)
        {
            temp->push_back(m_printVector->at(i));
        }

    }
    m_printVector->clear();
    delete m_printVector;
    m_printVector = temp;
}

///This method prints all of the restaurants in a given cuisine type
///
///@param choice The cuisine choice entered by the user
void Choices::printByCuisine()
{
    std::vector<Restaurant>* temp = new std::vector<Restaurant>;
    for(int i=0; i < (int)m_printVector->size(); i++)
    {
        if(m_printVector->at(i).getCusine() == m_cuisineType)
        {
            temp->push_back(m_printVector->at(i));
        }

    }
    m_printVector->clear();
    delete m_printVector;
    m_printVector = temp;
}


///This methods prints all of the restaurants in a given rating range
///
///@param type This determines if it personal or global rating
///@param ratingLower The lower bound for the rating
///@param ratingHigher The higher bound for the rating
void Choices::printByRating()
{
    std::vector<Restaurant>* temp = new std::vector<Restaurant>;
    for(int i = 0; i < (int)m_printVector->size(); i++)
    {
        if(m_ratingType == 1)//Personal
        {
            if(m_printVector->at(i).getPRating() >= m_rating[0] && m_printVector->at(i).getPRating() <= m_rating[1])
            {
                temp->push_back(m_printVector->at(i));
            }
        }
        else if(m_ratingType == 2)//Public
        {
            if(m_printVector->at(i).getRating() >= m_rating[0] && m_printVector->at(i).getRating() <= m_rating[1])
            {
                temp->push_back(m_printVector->at(i));
            }
        }
    }

    m_printVector->clear();
    delete m_printVector;
    m_printVector = temp;
}

///This method selects and prints a random restaurant and its data
/// @return returns random restaurant
Restaurant Choices::printRandom()
{
    int i = rand() % (_resVector->size()-1) + 0;
    return (_resVector->at(i));
    //std::cout << _resVector->at(i).getName() << "  " << _resVector->at(i).getCusine() << "  " <<_resVector->at(i).getPrice() << "  Rating: " << _resVector->at(i).getRating() << "  Personal Rating: " << _resVector->at(i).getPRating() << "\n";
    //m_ui->RestaurantTextEdit->insertPlainText(_resVector->at(i).getName() + "  " + _resVector->at(i).getCusine() + "  " +QString::number(_resVector->at(i).getPrice()) + "  Rating: " + QString::number(_resVector->at(i).getRating()) + "  Personal Rating: " + QString::number(_resVector->at(i).getPRating()) + "\n");
}

///This methods allows a user to give a retaurant a personal rating
///
///@param name The name of the restaurant to rate
///@param rating The rating double that the user gives
bool Choices::giveRating(QString name, int rating)
{
    bool haveRes = false;
    for(int i = 0; i < (int)_resVector->size(); i++)
    {
        if(_resVector->at(i).getName() == name)
        {
            _resVector->at(i).setPRating(rating);
            haveRes = true;
        }
    }
 return haveRes;
}

///This methods allows a user to remove a restaurant from the vector
///
///@param name The restaurant object to removes
/// @param haveRes whether or not the restaurant name is present
void Choices::removeRestaurant(QString name, bool& haveRes)
{
    haveRes = false;
    for(int i = 0; i < (int)_resVector->size(); i++)
    {
        if (name.toLower() == _resVector->at(i).getName().toLower()){
            haveRes = true;
            _resVector->erase(_resVector->begin() + i);
            break;
        }
    }
}

///This method creates a vector from the _resVector by filtering out restaurants based on parameters
/// @param minRB[3] boolean array that determines which of 3 minimum price points was chosen
/// @param maxRB[3] boolean array that determines which of 3 minimum prices points was chosen
/// @param ratingType 1 if personal 2 is public/global
/// @param rating integer array, rating[0] is minimum rating, rating[1] is maximum rating
/// @param cuisneType type of cuisine to be searched
std::vector<Restaurant>* Choices::createVector(int minRB, int maxRB,int ratingType,int rating[], QString cuisineType)
{
    m_minRB = minRB;
    m_maxRB = maxRB;
    m_ratingType = ratingType;
    m_rating[0] = rating[0];
    m_rating[1] = rating[1];
    m_cuisineType = cuisineType;

    if (!(m_minRB == 0 && m_maxRB == 0))
    {
        printByPrice();
    }
    if(m_ratingType != 0){
      printByRating();
    }
    if (m_cuisineType != "")
    {
        printByCuisine();
    }
    return m_printVector;
}
