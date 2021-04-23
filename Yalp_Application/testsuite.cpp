#include "testsuite.h"
#include "ui_testsuite.h"

testSuite::testSuite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testSuite)
{
    ui->setupUi(this);
    run();
}

testSuite::~testSuite()
{
    delete ui;
    m_restVector->clear();
    delete m_restVector;
}

void testSuite::run()
{
    ///all test will be called here
    ///ui->textEdit->insertPlainText("testing\n");
    ///ui->textEdit->insertPlainText("test complete");
    ///
    /// make new objects to use for testing

    loginTest();
    restVecTest();
    priceRangeTest();
    personalRatingTest();
    publicRatingTest();
    cuisineVecTest();
}

///Creates a test vector to test out code on
void testSuite::TestVectorCreator()
{
    Restaurant temp("Tortas_Jalisco");
    temp.setCuisine("Mexican");
    temp.setPrice(1);
    temp.setRating(4.9);
    temp.setPRating(4.5);
    m_restVector->push_back(temp);
    Restaurant temp1("Terrebonne_Po'_Boys");
    temp1.setCuisine("Cajun");
    temp1.setPrice(1);
    temp1.setRating(4.9);
    temp1.setPRating(4.8);
    m_restVector->push_back(temp1);
    Restaurant temp2("Encore_Cafe");
    temp2.setCuisine("Asian_Fusion");
    temp2.setPrice(2);
    temp2.setRating(4.6);
    temp2.setPRating(4.2);
    m_restVector->push_back(temp2);
    Restaurant temp3("War_Restaurant");
    temp3.setCuisine("Sushi");
    temp3.setPrice(2);
    temp3.setRating(4.3);
    temp3.setPRating(4.0);
    m_restVector->push_back(temp3);
}


void testSuite::loginTest()
{
    /// test code
    bool pass = false;

    ///actually not sure what to put here yet

    /// results print out
    ui->textEdit->insertPlainText("Test #: user can log in and use program with account     ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }

}

void testSuite::restVecTest()
{
    /// test code
    bool pass = false;
    m_restVector = new std::vector<Restaurant>;
    if(m_restVector == nullptr)
    {
        pass = false;
    }
    else
    {
        pass = true;
    }

    /// results print out
    ui->textEdit->insertPlainText("Test #: a restaurant vector is created       ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }


    /// test code
    pass = false;

    TestVectorCreator(); //fills vector with restaurants
    QString name[4] = {"Tortas_Jalisco","Terrebonne_Po'_Boys","Encore_Cafe","War_Restaurant"};
    QString cuisine[4] = {"Mexican","Cajun","Asian_Fusion","Sushi"};
    int price[4] = {1,1,2,2};
    double rating[4] = {4.9,4.9,4.6,4.3};
    double prating[4] = {4.5,4.8,4.2,4.0};

    for(int i=0; i < 4; i++)
    {
        if(m_restVector->at(i).getName() == name[i])
        {
            pass = true;
        }
        else
        {
            pass = false;
            break;
        }

        if(m_restVector->at(i).getCusine() == cuisine[i])
        {
            pass = true;
        }
        else
        {
            pass = false;
            break;
        }

        if(m_restVector->at(i).getPrice() == price[i])
        {
            pass = true;
        }
        else
        {
            pass = false;
            break;
        }

        if(m_restVector->at(i).getRating() == rating[i])
        {
            pass = true;
        }
        else
        {
            pass = false;
            break;
        }

        if(m_restVector->at(i).getPRating() == prating[i])
        {
            pass = true;
        }
        else
        {
            pass = false;
            break;
        }
    }

    /// results print out
    ui->textEdit->insertPlainText("Test #: the resturant vector is filled correctly       ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}

void testSuite::priceRangeTest()
{
    /// test code
    bool pass = false;
    int randomVal = 1 + rand() % 3;

    Restaurant test("Test");
    test.setPrice(randomVal);

    if(test.getPrice() >= 1 || test.getPrice() <= 3)
    {
        pass = true;
    }
    else
    {
        pass = false;
    }

    /// results print out
    ui->textEdit->insertPlainText("Test #: Price range any value between 1-3       ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}

void testSuite::personalRatingTest()
{
    /// test code
    bool pass = false;
    double randomVal = (5 - 1) * ((double)rand() / (double)RAND_MAX) + 1;

    Restaurant test("Test");
    test.setPRating(randomVal);

    if(test.getPRating() >= 1 || test.getPRating() <= 5)
    {
        pass = true;
    }
    else
    {
        pass = false;
    }

    /// results print out
    ui->textEdit->insertPlainText("Test #: User choose personal rating value between 1-5       ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}

void testSuite::publicRatingTest()
{
    /// test code
    bool pass;

    /// results print out
    ui->textEdit->insertPlainText("Test     ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}

void testSuite::cuisineVecTest()
{
    /// test code
    bool pass;

    /// results print out
    ui->textEdit->insertPlainText("Test     ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}



