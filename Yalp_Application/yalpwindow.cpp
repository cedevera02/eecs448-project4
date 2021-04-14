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
    TestVectorCreator(); // create temp restVector for testing
    Choices choice(m_restVector);
    m_choices = choice;
    for (int i = 0; i < (int)m_restVector->size(); i++){
        ui->RestaurantTextEdit->setText(m_restVector->at(i).getName() + "  " + m_restVector->at(i).getCusine() + "  " +QString::number(m_restVector->at(i).getPrice()) + "  Rating: " + QString::number(m_restVector->at(i).getRating()) + "  Personal Rating: " + QString::number(m_restVector->at(i).getPRating()) + "\n");
    }
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
    temp.setCuisine("Cajun");
    temp.setPrice(1);
    temp.setRating(4.9);
    temp.setPRating(0);
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


void YalpWindow::on_Min1RB_clicked()
{
    m_minRB = 1;
}

void YalpWindow::on_Min2RB_clicked()
{
    m_minRB = 2;
}

void YalpWindow::on_Min3RB_clicked()
{
    m_minRB = 3;
}

void YalpWindow::on_Max1RB_clicked()
{
    m_maxRB = 1;
}

void YalpWindow::on_Max2RB_clicked()
{
    m_maxRB = 2;
}

void YalpWindow::on_Max3RB_clicked()
{
    m_maxRB = 3;
}

void YalpWindow::on_searchFilterButton_clicked()
{
    m_printVector = m_choices.createVector(m_minRB, m_maxRB, m_ratingType, m_rating, m_cuisineType);
    for (int i = 0; i < (int)m_printVector->size(); i++)
    {
        ui->RestaurantTextEdit->setText(m_restVector->at(i).getName() + "  " + m_restVector->at(i).getCusine() + "  " +QString::number(m_restVector->at(i).getPrice()) + "  Rating: " + QString::number(m_restVector->at(i).getRating()) + "  Personal Rating: " + QString::number(m_restVector->at(i).getPRating()) + "\n");
    }
}

void YalpWindow::on_publicRRadioButtn_clicked()
{
    m_ratingType = 2;
}

void YalpWindow::on_radioButton_2_clicked()
{
    m_ratingType = 1;
}


void YalpWindow::on_cusineTypeLineEdit_textEdited(const QString &arg1)
{
    m_cuisineType = arg1;
    if (m_cuisineType.size() > 0){
        for (int i = 0; i < m_cuisineType.size();i++){
            if (i == 0){
                m_cuisineType[i] = m_cuisineType[i].toUpper();
            }
            if (m_cuisineType[i] == ' '){
                m_cuisineType[i] = '_';
                if (i+1 < m_cuisineType.size()){
                    m_cuisineType[i+1] = m_cuisineType[i+1].toUpper();
                }
            }
        }
    }
}
