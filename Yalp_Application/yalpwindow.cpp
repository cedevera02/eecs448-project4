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
    printAllRest();

}

YalpWindow::~YalpWindow()
{
    delete ui;
    m_restVector->clear();
    delete m_restVector;
    m_printVector->clear();
    delete m_printVector;
}

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
    temp.setCuisine("Asian_Fusion");
    temp.setPrice(2);
    temp.setRating(4.6);
    temp.setPRating(0);
    m_restVector->push_back(temp2);
    Restaurant temp3("War_Restaurant");
    temp.setCuisine("Sushi");
    temp.setPrice(2);
    temp.setRating(4.3);
    temp.setPRating(0);
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
    ui->RestaurantTextEdit->setText(QString::number(m_minRB));
}

///Stores which minimum price value is chosen in m_minRB
void YalpWindow::on_Min2RB_clicked()
{
    m_minRB = 2;
    ui->RestaurantTextEdit->setText(QString::number(m_minRB));
}

///Stores which minimum price value is chosen in m_minRB
void YalpWindow::on_Min3RB_clicked()
{
    m_minRB = 3;
    ui->RestaurantTextEdit->setText(QString::number(m_minRB));
}

///Stores which maximum price value is chosen in m_maxRB
void YalpWindow::on_Max1RB_clicked()
{
    m_maxRB = 1;
    ui->RestaurantTextEdit->setText(QString::number(m_maxRB));
}

///Stores which maximum price value is chosen in m_maxRB
void YalpWindow::on_Max2RB_clicked()
{
    m_maxRB = 2;
    ui->RestaurantTextEdit->setText(QString::number(m_maxRB));
}

///Stores which maximum price value is chosen in m_maxRB
void YalpWindow::on_Max3RB_clicked()
{
    m_maxRB = 3;
    ui->RestaurantTextEdit->setText(QString::number(m_maxRB));
}

///Calls Choices class create vector with filter values passed in to return a vector containing restaurants
/// it will print in the RestaurantTextEdit
void YalpWindow::on_searchFilterButton_clicked()
{
    ui->RestaurantTextEdit->clear();
    m_choices.setRestVector(m_restVector);
    m_printVector = m_choices.createVector(m_minRB, m_maxRB, m_ratingType, m_rating, m_cuisineType);
    //int i = 0;
    for(int i = 0; i < (int)m_printVector->size(); i++){
        ui->RestaurantTextEdit->append("<html><b>"+makeNice(m_printVector->at(i).getName())+"</b></html>" + "  " + "<html><i>"+makeNice(m_printVector->at(i).getCusine())+"</i></html>" + "  " +dollarPrice(m_printVector->at(i).getPrice()) + "  Rating: " + QString::number(m_printVector->at(i).getRating()) + "  Personal Rating: " + QString::number(m_printVector->at(i).getPRating()) + "\n\n");
    }
}

///Stores which type of rating value is chosen in m_ratingType
void YalpWindow::on_publicRRadioButtn_clicked()
{
    m_ratingType = 2;
    ui->RestaurantTextEdit->setText(QString::number(m_ratingType));
}

///Stores which type of rating value is chosen in m_ratingType
void YalpWindow::on_personalRRadioButton_clicked()
{
    m_ratingType = 1;
    ui->RestaurantTextEdit->setText(QString::number(m_ratingType));
}

///Stores which type of cuisine is typed adn changes it into form used, storing it into m_cuisineType
void YalpWindow::on_cusineTypeLineEdit_textEdited(const QString &arg1)
{
    m_cuisineType = arg1;
    if (m_cuisineType.size() > 0){
        for (int i = 0; i < m_cuisineType.size();i++){
            if (i == 0){
                m_cuisineType[i] = m_cuisineType[i].toUpper();
            } else if (m_cuisineType[i] == ' '){
                m_cuisineType[i] = '_';
            } else if (i < m_cuisineType.size() && m_cuisineType[i-1] == '_'){
                m_cuisineType[i] = m_cuisineType[i].toUpper();
            }else{
                m_cuisineType[i] = m_cuisineType[i].toLower();
            }
        }
    }
    ui->RestaurantTextEdit->setText(m_cuisineType);
}

void YalpWindow::closeEvent(QCloseEvent *event)
{
    //adapted from https://stackoverflow.com/questions/17480984/qt-how-do-i-handle-the-event-of-the-user-pressing-the-x-close-button
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Exit",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        if(!m_isGuest) {
            writeOut();
        }
        event->accept();
    }
}

void YalpWindow::writeOut()
{
    QFile m_file(m_username + ".txt");
    if(m_file.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream stream (&m_file);
        for(int i = 0; i < (int)m_restVector->size() - 1; i++) {
            stream << m_restVector->at(i).getName() << " " << m_restVector->at(i).getCusine()
                   << " " << m_restVector->at(i).getPrice() << " " << m_restVector->at(i).getRating() << " " << m_restVector->at(i).getPRating() << Qt::endl;
        }
        m_file.close();
    }
}

///reads in Restaurants from restaurant.txt
bool YalpWindow::readIn()
{
    QFile m_file("restaurants.txt");
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
    ui->RestaurantTextEdit->setText(QString::number(m_rating[0]));

}

///Stores max rating chosen in m_rating[1]
void YalpWindow::on_MaxRSpinBox_valueChanged(int arg1)
{
    m_rating[0] = arg1;
    ui->RestaurantTextEdit->setText(QString::number(m_rating[0]));
}

void YalpWindow::on_FeelingHungryButton_clicked()
{
    m_choices.setRestVector(m_restVector);
    Restaurant temp = m_choices.printRandom();
    ui->RestaurantTextEdit->setText(makeNice("<html><b>"+temp.getName())+"</b></html>"  + "  " + "<html><i>"+makeNice(temp.getCusine())+"</i></html>"  + "  " + dollarPrice(temp.getPrice()) + "  Rating: " + QString::number(temp.getRating()) + "  Personal Rating: " + QString::number(temp.getPRating()) + "\n\n");
}

void YalpWindow::on_lineEdit_textEdited(const QString &arg1)
{
    m_removeRest = arg1;
    if (m_removeRest.size() > 0){
        for (int i = 0; i < m_removeRest.size();i++){
            if (i == 0){
                m_removeRest[i] = m_removeRest[i].toUpper();
            } else if (m_removeRest[i] == ' '){
                m_removeRest[i] = '_';
            } else if (i < m_removeRest.size() && m_removeRest[i-1] == '_'){
                m_removeRest[i] = m_removeRest[i].toUpper();
            }else{
                m_removeRest[i] = m_removeRest[i].toLower();
            }
        }
    }
    ui->RestaurantTextEdit->setText("<html><b>"+m_removeRest+"</b><html>");
}



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
}

void YalpWindow::setUsername(QString aUsername)
{
    m_username = aUsername;
}
void YalpWindow::on_loginButton_clicked()
{
    if(m_username == "GUEST") {
        loginWindow loginWind;
        loginWind.setModal(true);
        loginWind.exec();

        if(loginWind.isValidName()) {
            m_username = loginWind.getUsername();
            m_isGuest = false;
            QMessageBox::about(this, "Login", "Signed in as " + m_username);
            ui->GuessNameLabel->setText(m_username);
        } else {
            QMessageBox::about(this, "Login", "No login detected. You are still a guest.");
        }
    } else {
        QMessageBox::warning(this, "Login", "Already signed in as " + m_username);
    }
}

void YalpWindow::printAllRest()
{
    ui->RestaurantTextEdit->clear();
    for (int i = 0; i < (int)m_restVector->size()-1; i++){
        ui->RestaurantTextEdit->append("<html><b>"+makeNice(m_restVector->at(i).getName())+"</b></html>" + "  " + "<html><i>"+makeNice(m_restVector->at(i).getCusine())+"</i></html>"  + "  " + dollarPrice(m_restVector->at(i).getPrice()) + "  Rating: " + QString::number(m_restVector->at(i).getRating()) + "  Personal Rating: " + QString::number(m_restVector->at(i).getPRating()) + "\n\n");
    }
}

///Removes underlines from string and returns it
QString YalpWindow::makeNice(QString word)
{
    for (int i = 0; i < word.size(); i++){
        if (word[i] == '_'){
            word[i] = ' ';
        }
    }
    return word;
}

QString YalpWindow::dollarPrice(int price)
{
    QString dollars = "";
    for (int i =0; i< price; i++){
        dollars += "$";
    }
    return dollars;
}

void YalpWindow::on_RestToBeRatiedLineEdit_textEdited(const QString &arg1)
{
    m_restToRate = arg1;
    if (m_restToRate.size() > 0){
        for (int i = 0; i < m_restToRate.size();i++){
            if (i == 0){
                m_restToRate[i] = m_restToRate[i].toUpper();
            } else if (m_restToRate[i] == ' '){
                m_restToRate[i] = '_';
            } else if (i < m_restToRate.size() && m_restToRate[i-1] == '_'){
                m_restToRate[i] = m_restToRate[i].toUpper();
            }else{
                m_restToRate[i] = m_restToRate[i].toLower();
            }
        }
    }
}

void YalpWindow::on_RestToRateSpinBox_valueChanged(int arg1)
{
    m_restRate = arg1;
}

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
}
