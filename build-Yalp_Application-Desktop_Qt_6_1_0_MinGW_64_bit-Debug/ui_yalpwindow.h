/********************************************************************************
** Form generated from reading UI file 'yalpwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YALPWINDOW_H
#define UI_YALPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YalpWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_12;
    QFrame *frame;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout;
    QLabel *FiltersLabel;
    QSpacerItem *verticalSpacer;
    QLabel *PriceLabel;
    QGroupBox *MinPriceGroupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *MinPriceLabel;
    QRadioButton *Min1RB;
    QRadioButton *Min2RB;
    QRadioButton *Min3RB;
    QVBoxLayout *verticalLayout_13;
    QGroupBox *MaxPriceGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *MaxPriceLabel;
    QRadioButton *Max1RB;
    QRadioButton *Max2RB;
    QRadioButton *Max3RB;
    QVBoxLayout *verticalLayout_4;
    QLabel *PPPLabel;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *PPPSpacer;
    QVBoxLayout *DollarSignLayout;
    QLabel *DS1Label;
    QLabel *DS2Label;
    QLabel *DS3Label;
    QVBoxLayout *PricePerPersonLayout;
    QLabel *PPP1Label;
    QLabel *PPP2Label;
    QLabel *PPP3Label;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QLabel *RatingsLabel;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *publicRRadioButtn;
    QRadioButton *personalRRadioButton;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *MinRateLabel;
    QSpinBox *MinRSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *MaxRateLabel;
    QSpinBox *MaxRSpinBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *cuisineTypeLabel;
    QLineEdit *cusineTypeLineEdit;
    QPushButton *searchFilterButton;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_17;
    QVBoxLayout *verticalLayout_16;
    QLabel *AddPRLabel;
    QHBoxLayout *horizontalLayout_13;
    QLabel *RestToRateLabel;
    QLineEdit *RestToBeRatiedLineEdit;
    QSpinBox *RestToRateSpinBox;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *AddRatinButton;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *testButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *UsingAsLabel;
    QLabel *GuessNameLabel;
    QPushButton *loginButton;
    QVBoxLayout *verticalLayout_8;
    QLabel *LawrenceRestaurantsLabel;
    QVBoxLayout *verticalLayout_6;
    QPushButton *FeelingHungryButton;
    QTextEdit *RestaurantTextEdit;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit;
    QPushButton *removeRestButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *YalpWindow)
    {
        if (YalpWindow->objectName().isEmpty())
            YalpWindow->setObjectName(QString::fromUtf8("YalpWindow"));
        YalpWindow->resize(959, 752);
        centralwidget = new QWidget(YalpWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_12 = new QHBoxLayout(centralwidget);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(3);
        verticalLayout_14 = new QVBoxLayout(frame);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        FiltersLabel = new QLabel(frame);
        FiltersLabel->setObjectName(QString::fromUtf8("FiltersLabel"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        FiltersLabel->setFont(font);

        verticalLayout->addWidget(FiltersLabel);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_11->addLayout(verticalLayout);

        PriceLabel = new QLabel(frame);
        PriceLabel->setObjectName(QString::fromUtf8("PriceLabel"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        PriceLabel->setFont(font1);

        verticalLayout_11->addWidget(PriceLabel);


        verticalLayout_12->addLayout(verticalLayout_11);

        MinPriceGroupBox = new QGroupBox(frame);
        MinPriceGroupBox->setObjectName(QString::fromUtf8("MinPriceGroupBox"));
        horizontalLayout = new QHBoxLayout(MinPriceGroupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        MinPriceLabel = new QLabel(MinPriceGroupBox);
        MinPriceLabel->setObjectName(QString::fromUtf8("MinPriceLabel"));

        horizontalLayout->addWidget(MinPriceLabel);

        Min1RB = new QRadioButton(MinPriceGroupBox);
        Min1RB->setObjectName(QString::fromUtf8("Min1RB"));

        horizontalLayout->addWidget(Min1RB);

        Min2RB = new QRadioButton(MinPriceGroupBox);
        Min2RB->setObjectName(QString::fromUtf8("Min2RB"));

        horizontalLayout->addWidget(Min2RB);

        Min3RB = new QRadioButton(MinPriceGroupBox);
        Min3RB->setObjectName(QString::fromUtf8("Min3RB"));

        horizontalLayout->addWidget(Min3RB);


        verticalLayout_12->addWidget(MinPriceGroupBox);


        verticalLayout_14->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        MaxPriceGroupBox = new QGroupBox(frame);
        MaxPriceGroupBox->setObjectName(QString::fromUtf8("MaxPriceGroupBox"));
        horizontalLayout_2 = new QHBoxLayout(MaxPriceGroupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        MaxPriceLabel = new QLabel(MaxPriceGroupBox);
        MaxPriceLabel->setObjectName(QString::fromUtf8("MaxPriceLabel"));

        horizontalLayout_2->addWidget(MaxPriceLabel);

        Max1RB = new QRadioButton(MaxPriceGroupBox);
        Max1RB->setObjectName(QString::fromUtf8("Max1RB"));

        horizontalLayout_2->addWidget(Max1RB);

        Max2RB = new QRadioButton(MaxPriceGroupBox);
        Max2RB->setObjectName(QString::fromUtf8("Max2RB"));

        horizontalLayout_2->addWidget(Max2RB);

        Max3RB = new QRadioButton(MaxPriceGroupBox);
        Max3RB->setObjectName(QString::fromUtf8("Max3RB"));

        horizontalLayout_2->addWidget(Max3RB);


        verticalLayout_13->addWidget(MaxPriceGroupBox);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        PPPLabel = new QLabel(frame);
        PPPLabel->setObjectName(QString::fromUtf8("PPPLabel"));
        PPPLabel->setFont(font1);

        verticalLayout_4->addWidget(PPPLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        PPPSpacer = new QSpacerItem(30, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(PPPSpacer);

        DollarSignLayout = new QVBoxLayout();
        DollarSignLayout->setObjectName(QString::fromUtf8("DollarSignLayout"));
        DS1Label = new QLabel(frame);
        DS1Label->setObjectName(QString::fromUtf8("DS1Label"));

        DollarSignLayout->addWidget(DS1Label);

        DS2Label = new QLabel(frame);
        DS2Label->setObjectName(QString::fromUtf8("DS2Label"));

        DollarSignLayout->addWidget(DS2Label);

        DS3Label = new QLabel(frame);
        DS3Label->setObjectName(QString::fromUtf8("DS3Label"));

        DollarSignLayout->addWidget(DS3Label);


        horizontalLayout_3->addLayout(DollarSignLayout);

        PricePerPersonLayout = new QVBoxLayout();
        PricePerPersonLayout->setObjectName(QString::fromUtf8("PricePerPersonLayout"));
        PPP1Label = new QLabel(frame);
        PPP1Label->setObjectName(QString::fromUtf8("PPP1Label"));

        PricePerPersonLayout->addWidget(PPP1Label);

        PPP2Label = new QLabel(frame);
        PPP2Label->setObjectName(QString::fromUtf8("PPP2Label"));

        PricePerPersonLayout->addWidget(PPP2Label);

        PPP3Label = new QLabel(frame);
        PPP3Label->setObjectName(QString::fromUtf8("PPP3Label"));

        PricePerPersonLayout->addWidget(PPP3Label);


        horizontalLayout_3->addLayout(PricePerPersonLayout);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_13->addLayout(verticalLayout_4);


        verticalLayout_14->addLayout(verticalLayout_13);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        RatingsLabel = new QLabel(frame);
        RatingsLabel->setObjectName(QString::fromUtf8("RatingsLabel"));
        RatingsLabel->setFont(font1);

        verticalLayout_5->addWidget(RatingsLabel);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        publicRRadioButtn = new QRadioButton(frame);
        buttonGroup = new QButtonGroup(YalpWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(publicRRadioButtn);
        publicRRadioButtn->setObjectName(QString::fromUtf8("publicRRadioButtn"));

        horizontalLayout_9->addWidget(publicRRadioButtn);

        personalRRadioButton = new QRadioButton(frame);
        buttonGroup->addButton(personalRRadioButton);
        personalRRadioButton->setObjectName(QString::fromUtf8("personalRRadioButton"));

        horizontalLayout_9->addWidget(personalRRadioButton);


        horizontalLayout_10->addLayout(horizontalLayout_9);


        verticalLayout_5->addLayout(horizontalLayout_10);


        verticalLayout_9->addLayout(verticalLayout_5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        MinRateLabel = new QLabel(frame);
        MinRateLabel->setObjectName(QString::fromUtf8("MinRateLabel"));

        horizontalLayout_4->addWidget(MinRateLabel);

        MinRSpinBox = new QSpinBox(frame);
        MinRSpinBox->setObjectName(QString::fromUtf8("MinRSpinBox"));
        MinRSpinBox->setMaximum(5);

        horizontalLayout_4->addWidget(MinRSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        MaxRateLabel = new QLabel(frame);
        MaxRateLabel->setObjectName(QString::fromUtf8("MaxRateLabel"));

        horizontalLayout_5->addWidget(MaxRateLabel);

        MaxRSpinBox = new QSpinBox(frame);
        MaxRSpinBox->setObjectName(QString::fromUtf8("MaxRSpinBox"));
        MaxRSpinBox->setMaximum(5);

        horizontalLayout_5->addWidget(MaxRSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_11->addLayout(verticalLayout_2);


        verticalLayout_9->addLayout(horizontalLayout_11);


        verticalLayout_10->addLayout(verticalLayout_9);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        cuisineTypeLabel = new QLabel(frame);
        cuisineTypeLabel->setObjectName(QString::fromUtf8("cuisineTypeLabel"));
        cuisineTypeLabel->setFont(font1);

        verticalLayout_3->addWidget(cuisineTypeLabel);

        cusineTypeLineEdit = new QLineEdit(frame);
        cusineTypeLineEdit->setObjectName(QString::fromUtf8("cusineTypeLineEdit"));
        cusineTypeLineEdit->setMaxLength(30);

        verticalLayout_3->addWidget(cusineTypeLineEdit);

        searchFilterButton = new QPushButton(frame);
        searchFilterButton->setObjectName(QString::fromUtf8("searchFilterButton"));

        verticalLayout_3->addWidget(searchFilterButton);


        verticalLayout_10->addLayout(verticalLayout_3);


        verticalLayout_14->addLayout(verticalLayout_10);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_17 = new QVBoxLayout(frame_2);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        AddPRLabel = new QLabel(frame_2);
        AddPRLabel->setObjectName(QString::fromUtf8("AddPRLabel"));
        AddPRLabel->setFont(font1);

        verticalLayout_16->addWidget(AddPRLabel);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        RestToRateLabel = new QLabel(frame_2);
        RestToRateLabel->setObjectName(QString::fromUtf8("RestToRateLabel"));

        horizontalLayout_13->addWidget(RestToRateLabel);

        RestToBeRatiedLineEdit = new QLineEdit(frame_2);
        RestToBeRatiedLineEdit->setObjectName(QString::fromUtf8("RestToBeRatiedLineEdit"));

        horizontalLayout_13->addWidget(RestToBeRatiedLineEdit);

        RestToRateSpinBox = new QSpinBox(frame_2);
        RestToRateSpinBox->setObjectName(QString::fromUtf8("RestToRateSpinBox"));
        RestToRateSpinBox->setMaximum(5);

        horizontalLayout_13->addWidget(RestToRateSpinBox);


        verticalLayout_16->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        AddRatinButton = new QPushButton(frame_2);
        AddRatinButton->setObjectName(QString::fromUtf8("AddRatinButton"));

        horizontalLayout_14->addWidget(AddRatinButton);

        horizontalSpacer_3 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_3);


        verticalLayout_16->addLayout(horizontalLayout_14);


        verticalLayout_17->addLayout(verticalLayout_16);


        verticalLayout_14->addWidget(frame_2);


        horizontalLayout_12->addWidget(frame);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        testButton = new QPushButton(centralwidget);
        testButton->setObjectName(QString::fromUtf8("testButton"));

        horizontalLayout_7->addWidget(testButton);

        horizontalSpacer = new QSpacerItem(378, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        UsingAsLabel = new QLabel(centralwidget);
        UsingAsLabel->setObjectName(QString::fromUtf8("UsingAsLabel"));

        horizontalLayout_6->addWidget(UsingAsLabel);

        GuessNameLabel = new QLabel(centralwidget);
        GuessNameLabel->setObjectName(QString::fromUtf8("GuessNameLabel"));

        horizontalLayout_6->addWidget(GuessNameLabel);


        verticalLayout_7->addLayout(horizontalLayout_6);

        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        verticalLayout_7->addWidget(loginButton);


        horizontalLayout_7->addLayout(verticalLayout_7);


        verticalLayout_15->addLayout(horizontalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        LawrenceRestaurantsLabel = new QLabel(centralwidget);
        LawrenceRestaurantsLabel->setObjectName(QString::fromUtf8("LawrenceRestaurantsLabel"));
        QFont font2;
        font2.setFamilies(QStringList{QString::fromUtf8("Lucida Fax")});
        font2.setPointSize(15);
        LawrenceRestaurantsLabel->setFont(font2);

        verticalLayout_8->addWidget(LawrenceRestaurantsLabel);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        FeelingHungryButton = new QPushButton(centralwidget);
        FeelingHungryButton->setObjectName(QString::fromUtf8("FeelingHungryButton"));

        verticalLayout_6->addWidget(FeelingHungryButton);

        RestaurantTextEdit = new QTextEdit(centralwidget);
        RestaurantTextEdit->setObjectName(QString::fromUtf8("RestaurantTextEdit"));
        QFont font3;
        font3.setPointSize(12);
        RestaurantTextEdit->setFont(font3);
        RestaurantTextEdit->setReadOnly(true);

        verticalLayout_6->addWidget(RestaurantTextEdit);


        verticalLayout_8->addLayout(verticalLayout_6);


        verticalLayout_15->addLayout(verticalLayout_8);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_8->addWidget(lineEdit);

        removeRestButton = new QPushButton(centralwidget);
        removeRestButton->setObjectName(QString::fromUtf8("removeRestButton"));

        horizontalLayout_8->addWidget(removeRestButton);


        verticalLayout_15->addLayout(horizontalLayout_8);


        horizontalLayout_12->addLayout(verticalLayout_15);

        YalpWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(YalpWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 959, 21));
        YalpWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(YalpWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        YalpWindow->setStatusBar(statusbar);

        retranslateUi(YalpWindow);

        QMetaObject::connectSlotsByName(YalpWindow);
    } // setupUi

    void retranslateUi(QMainWindow *YalpWindow)
    {
        YalpWindow->setWindowTitle(QCoreApplication::translate("YalpWindow", "YalpWindow", nullptr));
        FiltersLabel->setText(QCoreApplication::translate("YalpWindow", "Filters", nullptr));
        PriceLabel->setText(QCoreApplication::translate("YalpWindow", "Price:", nullptr));
        MinPriceLabel->setText(QCoreApplication::translate("YalpWindow", "Min:", nullptr));
        Min1RB->setText(QCoreApplication::translate("YalpWindow", "$", nullptr));
        Min2RB->setText(QCoreApplication::translate("YalpWindow", "$$", nullptr));
        Min3RB->setText(QCoreApplication::translate("YalpWindow", "$$$", nullptr));
        MaxPriceLabel->setText(QCoreApplication::translate("YalpWindow", "Max:", nullptr));
        Max1RB->setText(QCoreApplication::translate("YalpWindow", "$", nullptr));
        Max2RB->setText(QCoreApplication::translate("YalpWindow", "$$", nullptr));
        Max3RB->setText(QCoreApplication::translate("YalpWindow", "$$$", nullptr));
        PPPLabel->setText(QCoreApplication::translate("YalpWindow", "Price Per Person:", nullptr));
        DS1Label->setText(QCoreApplication::translate("YalpWindow", "$", nullptr));
        DS2Label->setText(QCoreApplication::translate("YalpWindow", "$$", nullptr));
        DS3Label->setText(QCoreApplication::translate("YalpWindow", "$$$", nullptr));
        PPP1Label->setText(QCoreApplication::translate("YalpWindow", "- under $10", nullptr));
        PPP2Label->setText(QCoreApplication::translate("YalpWindow", "- $11-$30", nullptr));
        PPP3Label->setText(QCoreApplication::translate("YalpWindow", "- $31-$60", nullptr));
        RatingsLabel->setText(QCoreApplication::translate("YalpWindow", "Rating (1-5):", nullptr));
        publicRRadioButtn->setText(QCoreApplication::translate("YalpWindow", "Public", nullptr));
        personalRRadioButton->setText(QCoreApplication::translate("YalpWindow", "Personal", nullptr));
        MinRateLabel->setText(QCoreApplication::translate("YalpWindow", "Min:", nullptr));
        MaxRateLabel->setText(QCoreApplication::translate("YalpWindow", "Max:", nullptr));
        cuisineTypeLabel->setText(QCoreApplication::translate("YalpWindow", "Cusine Type:", nullptr));
        searchFilterButton->setText(QCoreApplication::translate("YalpWindow", "Search", nullptr));
        AddPRLabel->setText(QCoreApplication::translate("YalpWindow", "Add a Personal Rating to a Restaurant:", nullptr));
        RestToRateLabel->setText(QCoreApplication::translate("YalpWindow", "Restaurant Name:", nullptr));
        AddRatinButton->setText(QCoreApplication::translate("YalpWindow", "Add Rating", nullptr));
        testButton->setText(QCoreApplication::translate("YalpWindow", "Run Test Suite", nullptr));
        UsingAsLabel->setText(QCoreApplication::translate("YalpWindow", "Using as:", nullptr));
        GuessNameLabel->setText(QCoreApplication::translate("YalpWindow", "Guess", nullptr));
        loginButton->setText(QCoreApplication::translate("YalpWindow", "Login", nullptr));
        LawrenceRestaurantsLabel->setText(QCoreApplication::translate("YalpWindow", "Lawrence Restaurants", nullptr));
        FeelingHungryButton->setText(QCoreApplication::translate("YalpWindow", "Feeling Hungry!", nullptr));
        removeRestButton->setText(QCoreApplication::translate("YalpWindow", "Remove Restaurant", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YalpWindow: public Ui_YalpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YALPWINDOW_H
