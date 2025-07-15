/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QPushButton *btnOneShot;
    QLabel *label;
    QSpinBox *spinBoxIntv;
    QRadioButton *radioContiue;
    QRadioButton *radioOneShot;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioPrecise;
    QRadioButton *radioCoarse;
    QRadioButton *radioVeryCoarse;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *LCDHour;
    QLCDNumber *LCDMin;
    QLCDNumber *LCDSec;
    QLabel *labElapsedTime;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(429, 307);
        QFont font;
        font.setPointSize(10);
        Widget->setFont(font);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 5, -1, 5);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(9);
        btnStart = new QPushButton(groupBox);
        btnStart->setObjectName("btnStart");

        gridLayout->addWidget(btnStart, 0, 0, 1, 1);

        btnStop = new QPushButton(groupBox);
        btnStop->setObjectName("btnStop");
        btnStop->setEnabled(false);

        gridLayout->addWidget(btnStop, 0, 1, 1, 1);

        btnOneShot = new QPushButton(groupBox);
        btnOneShot->setObjectName("btnOneShot");

        gridLayout->addWidget(btnOneShot, 0, 2, 1, 2);

        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        spinBoxIntv = new QSpinBox(groupBox);
        spinBoxIntv->setObjectName("spinBoxIntv");
        spinBoxIntv->setMaximum(999999);
        spinBoxIntv->setValue(1000);

        gridLayout->addWidget(spinBoxIntv, 1, 1, 1, 1);

        radioContiue = new QRadioButton(groupBox);
        radioContiue->setObjectName("radioContiue");
        radioContiue->setChecked(true);

        gridLayout->addWidget(radioContiue, 1, 2, 1, 1);

        radioOneShot = new QRadioButton(groupBox);
        radioOneShot->setObjectName("radioOneShot");
        radioOneShot->setChecked(false);

        gridLayout->addWidget(radioOneShot, 1, 3, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName("groupBox_3");
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 5, -1, -1);
        radioPrecise = new QRadioButton(groupBox_3);
        radioPrecise->setObjectName("radioPrecise");
        radioPrecise->setChecked(false);

        horizontalLayout_2->addWidget(radioPrecise);

        radioCoarse = new QRadioButton(groupBox_3);
        radioCoarse->setObjectName("radioCoarse");
        radioCoarse->setChecked(true);

        horizontalLayout_2->addWidget(radioCoarse);

        radioVeryCoarse = new QRadioButton(groupBox_3);
        radioVeryCoarse->setObjectName("radioVeryCoarse");

        horizontalLayout_2->addWidget(radioVeryCoarse);


        verticalLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 5, -1, 5);
        LCDHour = new QLCDNumber(groupBox_2);
        LCDHour->setObjectName("LCDHour");
        LCDHour->setSmallDecimalPoint(false);
        LCDHour->setDigitCount(2);
        LCDHour->setSegmentStyle(QLCDNumber::SegmentStyle::Filled);
        LCDHour->setProperty("value", QVariant(87.000000000000000));
        LCDHour->setProperty("intValue", QVariant(87));

        horizontalLayout->addWidget(LCDHour);

        LCDMin = new QLCDNumber(groupBox_2);
        LCDMin->setObjectName("LCDMin");
        LCDMin->setSmallDecimalPoint(false);
        LCDMin->setDigitCount(2);
        LCDMin->setSegmentStyle(QLCDNumber::SegmentStyle::Filled);
        LCDMin->setProperty("value", QVariant(26.000000000000000));
        LCDMin->setProperty("intValue", QVariant(26));

        horizontalLayout->addWidget(LCDMin);

        LCDSec = new QLCDNumber(groupBox_2);
        LCDSec->setObjectName("LCDSec");
        LCDSec->setDigitCount(2);
        LCDSec->setProperty("intValue", QVariant(35));

        horizontalLayout->addWidget(LCDSec);


        verticalLayout->addWidget(groupBox_2);

        labElapsedTime = new QLabel(Widget);
        labElapsedTime->setObjectName("labElapsedTime");
        labElapsedTime->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(labElapsedTime);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\345\231\250", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\345\231\250", nullptr));
        btnStart->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        btnStop->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242", nullptr));
        btnOneShot->setText(QCoreApplication::translate("Widget", "\345\212\250\346\200\201\345\210\233\345\273\272\345\215\225\346\254\241\345\256\232\346\227\266\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\345\221\250\346\234\237", nullptr));
        spinBoxIntv->setSuffix(QCoreApplication::translate("Widget", " ms", nullptr));
        radioContiue->setText(QCoreApplication::translate("Widget", "\350\277\236\347\273\255\345\256\232\346\227\266", nullptr));
        radioOneShot->setText(QCoreApplication::translate("Widget", "\345\215\225\346\254\241\345\256\232\346\227\266", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\345\231\250\347\262\276\345\272\246", nullptr));
        radioPrecise->setText(QCoreApplication::translate("Widget", "PreciseTimer", nullptr));
        radioCoarse->setText(QCoreApplication::translate("Widget", "CoarseTimer", nullptr));
        radioVeryCoarse->setText(QCoreApplication::translate("Widget", "VeryCoarseTimer", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\210\345\260\217\346\227\266\357\274\232\345\210\206\357\274\232\347\247\222\357\274\211", nullptr));
        labElapsedTime->setText(QCoreApplication::translate("Widget", "\346\265\201\351\200\235\347\232\204\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
