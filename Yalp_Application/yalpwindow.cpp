#include "yalpwindow.h"
#include "ui_yalpwindow.h"
#include "loginwindow.h"
#include "testsuite.h"
#include <QCloseEvent>
//#include "UI.h"

YalpWindow::YalpWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::YalpWindow)
{
    ui->setupUi(this);
    design();
    m_inFileName = "restaurants.txt";
    m_minRB = 0;
    m_maxRB = 0;
    m_cuisineType = "";
    m_ratingType = 0; //1 is personal, 2 is public
    m_rating[0] = 0; m_rating[1] = 5; // m_rating[0] is min, m_rating[1] = max
    m_valid = true;
    m_restVector = new std::vector<Restaurant>;
    //m_printVector = new std::vector<Restaurant>;
    bool read = readIn();
    if(!read){
        QMessageBox::about(this, "File Read", "File failed to read...");
    }
    m_username = "GUEST";
    m_isGuest = true;
    m_restToRate = "";
    m_restRate = 0;
    printAllRest(m_restVector);
    //ui->RestaurantTextEdit->setText(m_restVector->at(99).getName());

}

YalpWindow::~YalpWindow()
{
    delete ui;
    m_restVector->clear();
    delete m_restVector;
    m_printVector->clear();
    delete m_printVector;
}

///Creates a test vector to test out code on
void YalpWindow::TestVectorCreator()
{
    Restaurant temp("Tortas_Jalisco");
    temp.setCuisine("Mexican");
    temp.setPrice(1);
    temp.setRating(4.9);
    temp.setPRating(0);
    m_restVector->push_back(temp);
    Restaurant temp1("Terrebonne_Po'_Boys");
    temp1.setCuisine("Cajun");
    temp1.setPrice(1);
    temp1.setRating(4.9);
    temp1.setPRating(0);
    m_restVector->push_back(temp1);
    Restaurant temp2("Encore_Cafe");
    temp2.setCuisine("Asian_Fusion");
    temp2.setPrice(2);
    temp2.setRating(4.6);
    temp2.setPRating(0);
    m_restVector->push_back(temp2);
    Restaurant temp3("War_Restaurant");
    temp3.setCuisine("Sushi");
    temp3.setPrice(2);
    temp3.setRating(4.3);
    temp3.setPRating(0);
    m_restVector->push_back(temp3);
}

///runs the test suite
void YalpWindow::on_testButton_clicked()
{
    ///create testSuite object and run main testSuite function
    testSuite test;
    test.setModal(true);
    test.exec();
}

///Stores which minimum price value is chosen in m_minRB
void YalpWindow::on_Min1RB_clicked()
{
    m_minRB = 1;
    printVariables();
}

///Stores which minimum price value is chosen in m_minRB
void YalpWindow::on_Min2RB_clicked()
{
    m_minRB = 2;
    printVariables();
}

///Stores which minimum price value is chosen in m_minRB
void YalpWindow::on_Min3RB_clicked()
{
    m_minRB = 3;
    printVariables();
}

///Stores which maximum price value is chosen in m_maxRB
void YalpWindow::on_Max1RB_clicked()
{
    m_maxRB = 1;
    printVariables();
}

///Stores which maximum price value is chosen in m_maxRB
void YalpWindow::on_Max2RB_clicked()
{
    m_maxRB = 2;
    printVariables();
}

///Stores which maximum price value is chosen in m_maxRB
void YalpWindow::on_Max3RB_clicked()
{
    m_maxRB = 3;
    printVariables();
}

///Calls Choices class create vector with filter values passed in to return a vector containing restaurants
/// it will print in the RestaurantTextEdit
void YalpWindow::on_searchFilterButton_clicked()
{
    if (checkFilters()){
        ui->RestaurantTextEdit->clear();
        m_choices.setRestVector(m_restVector);
        m_printVector = new std::vector<Restaurant>;
        m_printVector = m_choices.createVector(m_minRB, m_maxRB, m_ratingType, m_rating, m_cuisineType);
        if ((int)m_printVector->size() == 0){
            QMessageBox::warning(this, "Filtered Restaurants", "It seems there are no restaurants matching your choices.");
        }else{
            printAllRest(m_printVector);
        }
    }
}

///Stores which type of rating value is chosen in m_ratingType
void YalpWindow::on_publicRRadioButtn_clicked()
{
    m_ratingType = 2;
    printVariables();
}

///Stores which type of rating value is chosen in m_ratingType
void YalpWindow::on_personalRRadioButton_clicked()
{
    m_ratingType = 1;
    printVariables();
}

///Stores which type of cuisine is typed adn changes it into form used, storing it into m_cuisineType
void YalpWindow::on_cusineTypeLineEdit_textEdited(const QString &arg1)
{
    m_cuisineType = makeFormat(arg1);
    printVariables();
}

///Writes out to a file on window close if the user is not a guess
void YalpWindow::closeEvent(QCloseEvent *event)
{
    //adapted from https://stackoverflow.com/questions/17480984/qt-how-do-i-handle-the-event-of-the-user-pressing-the-x-close-button
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Exit",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);//this brings up a popup box that asks you if you want to exit or not when you try to close the window
    if (resBtn != QMessageBox::Yes) { //if they click yes
        event->ignore(); //ignores close out
    } else {
        if(!m_isGuest) { //not a guest
            writeOut(); //this writes out to the file
        }
        event->accept();//accept the event
    }
}

///This writes the current restaurant vector to a text file
void YalpWindow::writeOut()
{
    QFile m_file(m_username + ".txt");//new QFile object
    if(m_file.open(QFile::WriteOnly | QFile::Text)) { //opens the file, this function returns a bool
        QTextStream stream (&m_file);//opens stream output to the file object
        for(int i = 0; i < (int)m_restVector->size(); i++) {
            stream << m_restVector->at(i).getName() << " " << m_restVector->at(i).getCusine()
                   << " " << m_restVector->at(i).getPrice() << " " << m_restVector->at(i).getRating() << " " << m_restVector->at(i).getPRating() << Qt::endl;//writes all of the vector object items out
        }
        m_file.close();
    }
}

///reads in Restaurants from restaurant.txt
/// @return true if file could be read in, false otherwise
bool YalpWindow::readIn()
{

    QFile m_file(m_inFileName);
        if(m_file.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream stream (&m_file);
            while(!stream.atEnd())
            {
                stream >> m_tempRestName >> m_tempRestType >> m_tempPricing >> m_tempRating >> m_tempUserRating;


                Restaurant temp = Restaurant(m_tempRestName);
                temp.setCuisine(m_tempRestType);
                temp.setPrice(m_tempPricing);
                temp.setRating(m_tempRating);
                temp.setPRating(m_tempUserRating);
                m_restVector->push_back(temp);
            }

            m_file.close();
            bool haveRes= true;
            m_choices.setRestVector(m_restVector);
            while(haveRes){
                m_choices.removeRestaurant("",haveRes);
            }
            return true;
        }
        else
        {
            return false;
        }
}

///Stores min rating chosen in m_rating[0]
void YalpWindow::on_MinRSpinBox_valueChanged(int arg1)
{
    m_rating[0] = arg1;
    printVariables();

}

///Stores max rating chosen in m_rating[1]
void YalpWindow::on_MaxRSpinBox_valueChanged(int arg1)
{
    m_rating[1] = arg1;
    printVariables();
}

///prinst out random restaurant
void YalpWindow::on_FeelingHungryButton_clicked()
{
    m_choices.setRestVector(m_restVector);
    Restaurant temp = m_choices.printRandom();
    ui->RestaurantTextEdit->setText(makeNice("<html><b>"+temp.getName())+"</b></html>"  + "  " + "<html><i>"+makeNice(temp.getCusine())+"</i></html>"  + "  " + dollarPrice(temp.getPrice()) + "  Rating: " + QString::number(temp.getRating()) + "  Personal Rating: " + QString::number(temp.getPRating()) + "\n\n");
}

///stores restaurant name to be removed
/// @param arg1 name of restaurant
void YalpWindow::on_removeRestLineEdit_textEdited(const QString &arg1)
{
    m_removeRest = makeFormat(arg1);
    //ui->RestaurantTextEdit->setText("<html><b>"+m_removeRest+"</b><html>");
}

///removes restaurant stored in m_removeRest
void YalpWindow::on_removeRestButton_clicked()
{
    m_choices.setRestVector(m_restVector); //set restvector that restaurant will be removed from
    bool haveRes = true;
    m_choices.removeRestaurant(m_removeRest, haveRes); //remove restaurant
    if (haveRes){
        QMessageBox::about(this,"Removing Restaurant", "The restaurant " + m_removeRest + " has been removed.");
    }else{
         QMessageBox::about(this,"Removing Restaurant", "No restaurant with matching names.");
    }
    printAllRest(m_restVector);
}

///username helper
void YalpWindow::setUsername(QString aUsername)
{
    m_username = aUsername;
}

///This opens the login window when the button if clicked
void YalpWindow::on_loginButton_clicked()
{
    if(m_username == "GUEST") { //makes sure the user is a guest, they can't login again if they aren't a guest
        loginWindow loginWind;//create the window object
        loginWind.setModal(true);//modal state means the new window prevents use of the other windows
        loginWind.exec();//splats the window

        if(loginWind.isValidName()) { //if we get a valid name we set the local username, set to not a guest, say you are signed in, set the file name, change the label, then if we have a file we read in
            m_username = loginWind.getUsername();
            m_isGuest = false;
            QMessageBox::about(this, "Login", "Signed in as " + m_username);
            m_inFileName = m_username + ".txt";
            ui->GuestNameLabel->setText(m_username);
            QFile testFile(m_inFileName);
            if(testFile.exists()) {
                m_restVector->clear();
                readIn();
                printAllRest(m_restVector);
             }
        } else {
            QMessageBox::about(this, "Login", "No login detected. You are still a guest.");
        }
    } else {
        QMessageBox::warning(this, "Login", "Already signed in as " + m_username);
    }

}

///prints out all restaurants in vector input
/// @param vect is the vector to be printed out
void YalpWindow::printAllRest(std::vector<Restaurant>* vect)
{
    ui->RestaurantTextEdit->clear();
    for (int i = 0; i < (int)vect->size(); i++){
        ui->RestaurantTextEdit->append("<html><b>"+makeNice(vect->at(i).getName())+"</b></html>" + "  " + "<html><i>"+makeNice(vect->at(i).getCusine())+"</i></html>"  + "  " + dollarPrice(vect->at(i).getPrice()) + "  Rating: " + QString::number(vect->at(i).getRating()) + "  Personal Rating: " + QString::number(vect->at(i).getPRating()) + "\n\n");
    }
}

///Removes underlines from string and returns it
/// @param word is the word being edited
/// @return edited string
QString YalpWindow::makeNice(QString word)
{
    for (int i = 0; i < word.size(); i++){
        if (word[i] == '_'){
            word[i] = ' ';
        }
    }
    return word;
}

///adds underlines to name instead of spaces, and capitalizes first letter of every word
/// @param is the word being edited
/// @return edited string
QString YalpWindow::makeFormat(QString word)
{
    if (word.size() > 0){
        for (int i = 0; i < word.size();i++){
            if (i == 0){
                word[i] = word[i].toUpper();
            } else if (word[i] == ' '){
                word[i] = '_';
            } else if (i < word.size() && word[i-1] == '_'){
                word[i] = word[i].toUpper();
            }else{
                word[i] = word[i].toLower();
            }
        }
    }

    return word;
}

///represents price range with dollar sign
/// @param price range
/// @return string with "price" number of $
QString YalpWindow::dollarPrice(int price)
{
    QString dollars = "";
    for (int i =0; i< price; i++){
        dollars += "$";
    }
    return dollars;
}

///stores restaurant to be rated
void YalpWindow::on_RestToBeRatiedLineEdit_textEdited(const QString &arg1)
{
    m_restToRate = makeFormat(arg1);
}

///stores rating of restaurant
void YalpWindow::on_RestToRateSpinBox_valueChanged(int arg1)
{
    m_restRate = arg1;
}

///adds rating in m_restRate to restuarant specified in m_restToRate
void YalpWindow::on_AddRatinButton_clicked()
{
    m_choices.setRestVector(m_restVector);
    if (m_restToRate == ""){
        QMessageBox::warning(this,"Rating a Restaurant", "A Blank Restaurant Name Cannot Be Given a Rating.");
    }else{
        bool present = m_choices.giveRating(m_restToRate, m_restRate);
        if (present){
            QMessageBox::about(this, "Rating a Restaurant", "Rating " + QString::number(m_restRate) + " set successfully for restaurant " + m_restToRate);
        }else{
            QMessageBox::about(this, "Rating a Restaurant", "No restaurant found with matching name!");
        }
    }
    printAllRest(m_restVector);
}

///prints out all stored variables for filter
void YalpWindow::printVariables()
{
    ui->RestaurantTextEdit->setText("Min Price: " + QString::number(m_minRB) + '\n');
    ui->RestaurantTextEdit->append("Max Price: " + QString::number(m_maxRB) + '\n');
    ui->RestaurantTextEdit->append("Cuisine Type: " + m_cuisineType + '\n');
    ui->RestaurantTextEdit->append("Rating Type: " + QString::number(m_ratingType) + '\n');
    ui->RestaurantTextEdit->append("Min Rating: " + QString::number(m_rating[0]) + '\n');
    ui->RestaurantTextEdit->append("Max Rating: " + QString::number(m_rating[1]) + '\n');
}

///Adds colors to window
void YalpWindow::design()
{
    this->setStyleSheet("background-color: #fbc466;");
    ui->RestaurantTextEdit->setStyleSheet("background-color: white;");
    ui->frame->setStyleSheet("background-color: #f6e1bd;");
    ui->centralwidget->setStyleSheet("QPushButton {background-color: #fa8223}");
    //ui->FeelingHungryButton->setStyleSheet("background-color: beige;");
    //ui->loginButton->setStyleSheet("background-color: white;");
    //ui->testButton->setStyleSheet("background-color: white;");
    //ui->removeRestButton->setStyleSheet("background-color: white;");
    ui->removeRestLineEdit->setStyleSheet("background-color: white;");

}

bool YalpWindow::checkFilters()
{
    bool okay = true;
    if (m_minRB > m_maxRB){
        okay = false;
        QMessageBox::warning(this, "Filter Warning", "Minimum price range cannot be larger than maximum price range.");
    }
    if (m_rating[0] > m_rating[1]){
        okay = false;
        QMessageBox::warning(this, "Filter Warning", "Minimum rating range cannot be larger than maximum rating range.");
    }
    return okay;
}
