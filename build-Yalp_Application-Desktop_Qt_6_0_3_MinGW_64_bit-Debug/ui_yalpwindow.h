/********************************************************************************
** Form generated from reading UI file 'yalpwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YALPWINDOW_H
#define UI_YALPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QKeySequenceEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YalpWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_8;
    QSplitter *splitter_2;
    QFrame *frame;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *FiltersLabel;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *PriceLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *MinPriceLabel;
    QRadioButton *Min1RB;
    QRadioButton *Min2RB;
    QRadioButton *Min3RB;
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
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *RatingsLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *PublicRLabel;
    QSpinBox *PublicRSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *MineRLabel;
    QSpinBox *MineRSpinBox;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QKeySequenceEdit *CusineTypeKeySeq;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *UsingAsLabel;
    QLabel *GuessNameLabel;
    QPushButton *pushButton;
    QSplitter *splitter;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QLabel *LawrenceRestaurantsLabel;
    QPushButton *FeelingHungryButton;
    QTextEdit *RestaurantTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *YalpWindow)
    {
        if (YalpWindow->objectName().isEmpty())
            YalpWindow->setObjectName(QString::fromUtf8("YalpWindow"));
        YalpWindow->resize(800, 607);
        centralwidget = new QWidget(YalpWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_8 = new QHBoxLayout(centralwidget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(3);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        FiltersLabel = new QLabel(frame);
        FiltersLabel->setObjectName(QString::fromUtf8("FiltersLabel"));
        QFont font;
        font.setPointSize(12);
        FiltersLabel->setFont(font);

        verticalLayout_5->addWidget(FiltersLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        PriceLabel = new QLabel(frame);
        PriceLabel->setObjectName(QString::fromUtf8("PriceLabel"));
        QFont font1;
        font1.setPointSize(10);
        PriceLabel->setFont(font1);

        verticalLayout->addWidget(PriceLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        MinPriceLabel = new QLabel(frame);
        MinPriceLabel->setObjectName(QString::fromUtf8("MinPriceLabel"));

        horizontalLayout->addWidget(MinPriceLabel);

        Min1RB = new QRadioButton(frame);
        Min1RB->setObjectName(QString::fromUtf8("Min1RB"));

        horizontalLayout->addWidget(Min1RB);

        Min2RB = new QRadioButton(frame);
        Min2RB->setObjectName(QString::fromUtf8("Min2RB"));

        horizontalLayout->addWidget(Min2RB);

        Min3RB = new QRadioButton(frame);
        Min3RB->setObjectName(QString::fromUtf8("Min3RB"));

        horizontalLayout->addWidget(Min3RB);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        MaxPriceLabel = new QLabel(frame);
        MaxPriceLabel->setObjectName(QString::fromUtf8("MaxPriceLabel"));

        horizontalLayout_2->addWidget(MaxPriceLabel);

        Max1RB = new QRadioButton(frame);
        Max1RB->setObjectName(QString::fromUtf8("Max1RB"));

        horizontalLayout_2->addWidget(Max1RB);

        Max2RB = new QRadioButton(frame);
        Max2RB->setObjectName(QString::fromUtf8("Max2RB"));

        horizontalLayout_2->addWidget(Max2RB);

        Max3RB = new QRadioButton(frame);
        Max3RB->setObjectName(QString::fromUtf8("Max3RB"));

        horizontalLayout_2->addWidget(Max3RB);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        PPPLabel = new QLabel(frame);
        PPPLabel->setObjectName(QString::fromUtf8("PPPLabel"));

        verticalLayout_4->addWidget(PPPLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        PPPSpacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

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


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        RatingsLabel = new QLabel(frame);
        RatingsLabel->setObjectName(QString::fromUtf8("RatingsLabel"));
        RatingsLabel->setFont(font1);

        verticalLayout_2->addWidget(RatingsLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        PublicRLabel = new QLabel(frame);
        PublicRLabel->setObjectName(QString::fromUtf8("PublicRLabel"));

        horizontalLayout_5->addWidget(PublicRLabel);

        PublicRSpinBox = new QSpinBox(frame);
        PublicRSpinBox->setObjectName(QString::fromUtf8("PublicRSpinBox"));

        horizontalLayout_5->addWidget(PublicRSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        MineRLabel = new QLabel(frame);
        MineRLabel->setObjectName(QString::fromUtf8("MineRLabel"));

        horizontalLayout_4->addWidget(MineRLabel);

        MineRSpinBox = new QSpinBox(frame);
        MineRSpinBox->setObjectName(QString::fromUtf8("MineRSpinBox"));

        horizontalLayout_4->addWidget(MineRSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        verticalLayout_3->addWidget(label);

        CusineTypeKeySeq = new QKeySequenceEdit(frame);
        CusineTypeKeySeq->setObjectName(QString::fromUtf8("CusineTypeKeySeq"));

        verticalLayout_3->addWidget(CusineTypeKeySeq);


        verticalLayout_5->addLayout(verticalLayout_3);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_5);

        splitter_2->addWidget(frame);
        layoutWidget = new QWidget(splitter_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_8 = new QVBoxLayout(layoutWidget);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(378, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        UsingAsLabel = new QLabel(layoutWidget);
        UsingAsLabel->setObjectName(QString::fromUtf8("UsingAsLabel"));

        horizontalLayout_6->addWidget(UsingAsLabel);

        GuessNameLabel = new QLabel(layoutWidget);
        GuessNameLabel->setObjectName(QString::fromUtf8("GuessNameLabel"));

        horizontalLayout_6->addWidget(GuessNameLabel);


        verticalLayout_7->addLayout(horizontalLayout_6);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_7->addWidget(pushButton);


        horizontalLayout_7->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_7);

        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        LawrenceRestaurantsLabel = new QLabel(layoutWidget1);
        LawrenceRestaurantsLabel->setObjectName(QString::fromUtf8("LawrenceRestaurantsLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Lucida Fax"));
        font2.setPointSize(15);
        LawrenceRestaurantsLabel->setFont(font2);

        verticalLayout_6->addWidget(LawrenceRestaurantsLabel);

        FeelingHungryButton = new QPushButton(layoutWidget1);
        FeelingHungryButton->setObjectName(QString::fromUtf8("FeelingHungryButton"));

        verticalLayout_6->addWidget(FeelingHungryButton);

        RestaurantTextEdit = new QTextEdit(layoutWidget1);
        RestaurantTextEdit->setObjectName(QString::fromUtf8("RestaurantTextEdit"));

        verticalLayout_6->addWidget(RestaurantTextEdit);

        splitter->addWidget(layoutWidget1);

        verticalLayout_8->addWidget(splitter);

        splitter_2->addWidget(layoutWidget);

        horizontalLayout_8->addWidget(splitter_2);

        YalpWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(YalpWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
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
        PriceLabel->setText(QCoreApplication::translate("YalpWindow", "Price", nullptr));
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
        PublicRLabel->setText(QCoreApplication::translate("YalpWindow", "Public:", nullptr));
        MineRLabel->setText(QCoreApplication::translate("YalpWindow", "Mine:", nullptr));
        label->setText(QCoreApplication::translate("YalpWindow", "Cusine Type:", nullptr));
        UsingAsLabel->setText(QCoreApplication::translate("YalpWindow", "Using as:", nullptr));
        GuessNameLabel->setText(QCoreApplication::translate("YalpWindow", "Guess", nullptr));
        pushButton->setText(QCoreApplication::translate("YalpWindow", "Login", nullptr));
        LawrenceRestaurantsLabel->setText(QCoreApplication::translate("YalpWindow", "Lawrence Restaurants", nullptr));
        FeelingHungryButton->setText(QCoreApplication::translate("YalpWindow", "Feeling Hungry!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YalpWindow: public Ui_YalpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YALPWINDOW_H
