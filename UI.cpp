#include "UI.h"



UI::UI(std::vector<Restaurant>* vec)
{
    _resVector = vec;
 
}

void UI::printMenu()
{
    int input;

    
    std::cout << "Project Name Place Holder\n--------------------------\n1. Show all Restaurants\n2. Search by Prices\n3. Search by Cuisine\n4. Search by Rating\n5. Give a Rating\n6. Remove a Restaurant\n7. Random\n8. Exit Program\n";
    std::cin >> input;

    while(std::cin.fail() || input < 1 || input > 8)
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Sorry, your input did not seem to be a valid input. Try again: ";
        std::cin >> input;
    }
}

void UI::printAll()
{
    for(int i=0; i < _resVector->size(); i++)
    {
        std::cout << _resVector->at(i).getName() << "  " << _resVector->at(i).getCusine() << "  " <<_resVector->at(i).getPrice() << "  Rating: " << _resVector->at(i).getRating() << "  Personal Rating: " << _resVector->at(i).getPRating() << "\n";
    }
}

void UI::printByPrice(int lower, int higher)
{
    bool haveRes = false; // to have a different cout when there are no Restaurtants that fit the category.
    for(int i=0; i < _resVector->size(); i++)
    {
        if(_resVector->at(i).getPrice() > lower && _resVector->at(i).getPrice() < higher)
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

void UI::printByRating(int type, int rating)
{
    bool haveRes = false; 
	for(int i = 0; i < _resVector->size(); i++)
    {
        if(type == 0)//Personal
        {
	        if(_resVector->at(i).getRating() == rating)
            {
	            haveRes = true;
    	        std::cout << _resVector->at(i).getName() << "  " << _resVector->at(i).getCusine() << "  " <<_resVector->at(i).getPrice() << "  Rating: " << _resVector->at(i).getRating() << "  Personal Rating: " << _resVector->at(i).getPRating() << "\n";
            }
        }
        else if(type == 1)//Public
        {
            if(_resVector->at(i).getPRating() == rating)
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

void UI::printRandom()
{
    int random= 0;
    bool haveRes = false;
    for(int i = 0; i < _resVector->size(); i++)
    {
	    random = rand() %2;
	    if(random == 1)
        {
	        haveRes = true;
	        std::cout << _resVector->at(i).getName() << "  " << _resVector->at(i).getCusine() << "  " <<_resVector->at(i).getPrice() << "  Rating: " << _resVector->at(i).getRating() << "  Personal Rating: " << _resVector->at(i).getPRating() << "\n";
	    }
	}
}

void UI::giveRating(std::string name, int rating)
{
    bool haveRes = false;
    for(int i = 0; i < _resVector->size(); i++)
    {
	    haveRes = true;
	    if(_resVector->at(i).getName().compare(name) == 0)
        {
	        _resVector->at(i).setRating(rating);
	        std::cout << "\nRating " << rating << " set successfully for restaurant " << _resVector->at(i).getName() << "\n";
	    }
    }
    
    if(!haveRes)
    {
        std::cout << "\nNo restaurant found with the matching name!" << "\n";
    }
}

void UI::removeRestaurant(std::string name)
{
    bool haveRes = false;
    for(int i = 0; i < _resVector->size(); i++)
    {
	    haveRes = true;
	    _resVector->erase(_resVector->begin() + i);
	    std::cout << "\nThe restaurant " << name << " was removed successfully from the list of restaurants" << "\n";
    }
    
    if(!haveRes)
    {
        std::cout << "\nNo restaurant found with the matching name!" << "\n";
    }
}
