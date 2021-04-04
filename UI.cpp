#include "UI.h"


///UI CONSTRUCTOR
///
///@param vec Takes in restaurant vector pointer
UI::UI(std::vector<Restaurant>* vec)
{
    _resVector = vec;
 
}

///METHODS
///
///Prints out all of the menu options that user can choose from
///@return Returns the int value that the user chooses
int UI::printMenu()
{
    int input;

    
    std::cout << "\n1. Show all Restaurants\n2. Search by Prices\n3. Search by Cuisine\n4. Search by Rating\n5. Give a Rating\n6. Remove a Restaurant\n7. Random\n8. Exit Program\n";
    std::cin >> input;

    while(std::cin.fail() || input < 1 || input > 8)
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
        std::cin >> input;
    }

    return input;
}

///This method prints all of the retaurants and their data
///
///Acesses local restaurant vector and formats the output into lines
void UI::printAll()
{
    for(int i=0; i < _resVector->size(); i++)
    {
        std::cout << _resVector->at(i).getName() << "  " << _resVector->at(i).getCusine() << "  " <<_resVector->at(i).getPrice() << "  Rating: " << _resVector->at(i).getRating() << "  Personal Rating: " << _resVector->at(i).getPRating() << "\n";
    }
}

///This method prints all of the restaurants in a certain price range
///
///@param lower The lower bound for the price range
///@param higher The higher boudn for the price range
void UI::printByPrice(int lower, int higher)
{
    bool haveRes = false; // to have a different cout when there are no Restaurtants that fit the category.
    for(int i=0; i < _resVector->size(); i++)
    {
        if(_resVector->at(i).getPrice() >= lower && _resVector->at(i).getPrice() <= higher)
        {
            haveRes = true;
            std::cout << _resVector->at(i).getName() << "  " << _resVector->at(i).getCusine() << "  " <<_resVector->at(i).getPrice() << "  Rating: " << _resVector->at(i).getRating() << "  Personal Rating: " << _resVector->at(i).getPRating() << "\n";
        }

    }

    if(haveRes == false)
    {
        std::cout << "No restaurants fit that criteria." << "\n";
    }
}

///This method prints all of the restaurants in a given cuisine type
///
///@param choice The cuisine choice entered by the user
void UI::printByCuisine(std::string choice)
{
    bool haveRes = false; // to have a different cout when there are no Restaurtants that fit the category.
    for(int i=0; i < _resVector->size(); i++)
    {
        if(_resVector->at(i).getCusine() == choice)
        {
            haveRes = true;
            std::cout << _resVector->at(i).getName() << "  " << _resVector->at(i).getCusine() << "  " <<_resVector->at(i).getPrice() << "  Rating: " << _resVector->at(i).getRating() << "  Personal Rating: " << _resVector->at(i).getPRating() << "\n";
        }

    }

    if(haveRes == false)
    {
        std::cout << "No restaurants fit that criteria." << "\n";
    }
}


///This methods prints all of the restaurants in a given rating range
///
///@param type This determines if it personal or global rating
///@param ratingLower The lower bound for the rating
///@param ratingHigher The higher bound for the rating
void UI::printByRating(int type, double ratingLower, double ratingHigher)
{
    bool haveRes = false; 
	for(int i = 0; i < _resVector->size(); i++)
    {
        if(type == 1)//Personal
        {
	        if(_resVector->at(i).getPRating() >= ratingLower && _resVector->at(i).getPRating() <= ratingHigher)
            {
	            haveRes = true;
    	        std::cout << _resVector->at(i).getName() << "  " << _resVector->at(i).getCusine() << "  " <<_resVector->at(i).getPrice() << "  Rating: " << _resVector->at(i).getRating() << "  Personal Rating: " << _resVector->at(i).getPRating() << "\n";
            }
        }
        else if(type == 2)//Public
        {
            if(_resVector->at(i).getRating() >= ratingLower && _resVector->at(i).getRating() <= ratingHigher)
            {
	            haveRes = true;
    	        std::cout << _resVector->at(i).getName() << "  " << _resVector->at(i).getCusine() << "  " <<_resVector->at(i).getPrice() << "  Rating: " << _resVector->at(i).getRating() << "  Personal Rating: " << _resVector->at(i).getPRating() << "\n";
            }
        }
    }
	
    if(haveRes == false)
    {
        std::cout << "\nNo restaurants fit that criteria." << "\n";
    }
}

///This method selects and prints a random restaurant and its data
void UI::printRandom()
{
    int i = rand() % (_resVector->size()-1) + 0;
    std::cout << _resVector->at(i).getName() << "  " << _resVector->at(i).getCusine() << "  " <<_resVector->at(i).getPrice() << "  Rating: " << _resVector->at(i).getRating() << "  Personal Rating: " << _resVector->at(i).getPRating() << "\n";

}

///This methods allows a user to give a retaurant a personal rating
///
///@param name The name of the restaurant to rate
///@param rating The rating double that the user gives
void UI::giveRating(std::string name, double rating)
{
    bool haveRes = false;
    for(int i = 0; i < _resVector->size(); i++)
    {
	    haveRes = true;
	    if(_resVector->at(i).getName().compare(name) == 0)
        {
	        _resVector->at(i).setPRating(rating);
	        std::cout << "\nRating " << rating << " set successfully for restaurant " << _resVector->at(i).getName() << "\n";
	    }
    }
    
    if(!haveRes)
    {
        std::cout << "\nNo restaurant found with the matching name!" << "\n";
    }
}

///This methods allows a user to remove a restaurant from the vector
///
///@param name The restaurant object to removes
void UI::removeRestaurant(std::string name)
{
    bool haveRes = false;
    for(int i = 0; i < _resVector->size(); i++)
    {
        if (_resVector->at(i).getName()== name){
            haveRes = true;
            _resVector->erase(_resVector->begin() + i);
            break;
        }
    }
	std::cout << "\nThe restaurant " << name << " was removed successfully from the list of restaurants" << "\n";
    
    if(!haveRes)
    {
        std::cout << "\nNo restaurant found with the matching name! Did you make sure to include the underlines(_)?" << "\n";
    }
}
