#include "yalpwindow.h"
#include "ui_yalpwindow.h"
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
    srand(time(NULL));
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
    bool read = readIn();
   if (read){
        m_choices.setRestVector(m_restVector);
        m_printVector = m_choices.createVector(m_minRB, m_maxRB, m_ratingType, m_rating, m_cuisineType);
        //int i = 0;
        for(int i = 0; i < (int)m_printVector->size(); i++){
            ui->RestaurantTextEdit->append(m_printVector->at(i).getName() + "  " + m_printVector->at(i).getCusine() + "  " +QString::number(m_printVector->at(i).getPrice()) + "  Rating: " + QString::number(m_printVector->at(i).getRating()) + "  Personal Rating: " + QString::number(m_printVector->at(i).getPRating()) + "\n");
        }
   }
   else{
       ui->RestaurantTextEdit->setText("Read Failed\n"); //probably use a QMessageBox for this instead
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

///reads in Restaurants from restaurant.txt
bool YalpWindow::readIn()
{
    QFile m_file("C:/Users/cedev/OneDrive/Documents/~eecs448/Project4/eecs448-project4/Yalp_Application/restaurants.txt");
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
    bool read = readIn();
    if (read){
    TestVectorCreator();
        m_choices.setRestVector(m_restVector);
    //int i = rand() % (m_restVector->size()) + 0;
   //Restaurant temp = (m_restVector->at(i));
        Restaurant temp = m_choices.printRandom();
        ui->RestaurantTextEdit->setText(temp.getName() + "  " + temp.getCusine() + "  " +QString::number(temp.getPrice()) + "  Rating: " + QString::number(temp.getRating()) + "  Personal Rating: " + QString::number(temp.getPRating()) + "\n");
    }
    else{
      ui->RestaurantTextEdit->setText("Failed Read");
    }
    //ui->RestaurantTextEdit->setText("Hello!");
}
