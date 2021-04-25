#include "testsuite.h"


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
    m_restVector = new std::vector<Restaurant>;
    Choices m_choice(m_restVector);

    restVecTest();
    priceRangeTest();
    personalRatingTest();
    publicRatingTest();
    cuisineTest();
    //randRestTest();
    removeRestTest();
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

void testSuite::restVecTest()
{
    /// test code
    bool pass = false;

    if(m_restVector == nullptr)
    {
        pass = false;
    }
    else
    {
        pass = true;
    }

    /// results print out
    ui->textEdit->insertPlainText("Test #: A restaurant vector is created       ");
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
    ui->textEdit->insertPlainText("Test #: The resturant vector is filled correctly       ");
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
    bool pass = false;
    double test_rate = (rand() % 6) + 1; // random number between 1 and 5 inclusive. Maybe need to change to ^^ rand method


    Restaurant ratingTest("rating test");
    ratingTest.setRating(test_rate);

    if(ratingTest.getRating() >=1 || ratingTest.getRating() <=5)
    {
        pass = true;
    }
    else
    {
        pass = false;
    }

    /// results print out
    ui->textEdit->insertPlainText("Test #: User choose public rating value between 1-5          ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}

void testSuite::cuisineTest()
{
    /// test code
    bool pass = false;

    // the cuisines that should be there
    QString cuisine[4] = {"Mexican","Cajun","Asian_Fusion","Sushi"};


    for(int i=0; i < 4; i++) // fill cuisine vector
    {
        for(int j=0;  j < 4; j++)
        {
            m_cuisineVector.push_back(m_restVector->at(i).getCusine());
        }

        if(m_restVector->at(i).getCusine() == m_cuisineVector.at(i))
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
    ui->textEdit->insertPlainText("Test #: The cuisine vector is filled correctly    ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}

void testSuite::randRestTest()
{
    bool pass = false;
    /// testing the random restaurant functionality
    Restaurant randRes = m_choice.printRandom();
    // ui->textEdit->setText("<html><b>"+randRes.getName()+"</b></html>"  + "  " + "<html><i>"+randRes.getCusine()+"</i></html>"  + "  " + QString::number(randRes.getPrice()) + "  Rating: " + QString::number(randRes.getRating()) + "  Personal Rating: " + QString::number(randRes.getPRating()) + "\n\n");

    QString name[4] = {"Tortas_Jalisco","Terrebonne_Po'_Boys","Encore_Cafe","War_Restaurant"};
    QString cuisine[4] = {"Mexican","Cajun","Asian_Fusion","Sushi"};
    int price[4] = {1,1,2,2};
    double rating[4] = {4.9,4.9,4.6,4.3};
    double prating[4] = {4.5,4.8,4.2,4.0};

    for(int i=0; i < 4; i++)
    {

        if(randRes.getName() == name[i])
        {
            pass = true;
        }
        else
        {
            pass = false;
        }

        if(randRes.getCusine() == cuisine[i])
        {
            pass = true;
        }
        else
        {
            pass = false;
        }

        if(randRes.getPrice() == price[i])
        {
            pass = true;
        }
        else
        {
            pass = false;
        }

        if(randRes.getRating() == rating[i])
        {
            pass = true;
        }
        else
        {
            pass = false;
        }

        if(randRes.getPRating() == prating[i])
        {
            pass = true;
        }
        else
        {
            pass = false;
        }

    }

    /// results print out
    ui->textEdit->insertPlainText("Test #: The random restaurant function returns a random restaurant within the list       ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }
}

void testSuite::removeRestTest()
{
    /// testing the remove restaurant functionality
    bool pass = false;
    bool haveRes = true;
    m_choice.setRestVector(m_restVector);

    // removing the restaurant war restaurant
    m_choice.removeRestaurant("Encore_Cafe", haveRes);
    /// checking if the restaurant vector is now size 3
    if(haveRes)
    {
        pass = true; //the restaurant exists and has been removed
    }
    else
    {
        pass = false;
    }

    ui->textEdit->insertPlainText("Test #: After removing a restaurant the restaurant, a restaurant has been removed       ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }

/////////////////////////////////////////////////////////////////

    /// checking if the correct restaurant is removed

    for(int i=0; i<3; i++)
    {
        if(m_restVector->at(i).getName() == "Encore_Cafe")
        {
            pass = false;
        }
        else
        {
            pass = true;
            if(m_restVector->at(i).getCusine() == "Asian_Fusion")
            {
                pass = false;
            }
            else
            {
                pass = true;
                if(m_restVector->at(i).getPrice() == 2)
                {
                    pass = false;
                }
                else
                {
                    pass = true;
                    if(m_restVector->at(i).getRating() == 4.6)
                    {
                        pass = false;
                    }
                    else
                    {
                        pass = true;
                        if(m_restVector->at(i).getPRating() == 4.2)
                        {
                            pass = false;
                        }
                        else
                        {
                            pass = true;
                            break;
                        }
                    }

                }

            }

        }
    }





    ui->textEdit->insertPlainText("Test #: When removing a restaurtant, the correct one is removed and no others are       ");
    if(pass)
    {
        ui->textEdit->insertPlainText("PASS\n");
    }
    else
    {
        ui->textEdit->insertPlainText("FAIL\n");
    }



}



