/********************************************************************************
** Form generated from reading UI file 'imageSimilarity.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESIMILARITY_H
#define UI_IMAGESIMILARITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imageSimilarityClass
{
public:
    QAction *actionOpen;
    QAction *action2;
    QAction *actionSimilar;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QGraphicsView *SrcImgView;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *imageSimilarityClass)
    {
        if (imageSimilarityClass->objectName().isEmpty())
            imageSimilarityClass->setObjectName(QStringLiteral("imageSimilarityClass"));
        imageSimilarityClass->resize(934, 642);
        actionOpen = new QAction(imageSimilarityClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        action2 = new QAction(imageSimilarityClass);
        action2->setObjectName(QStringLiteral("action2"));
        actionSimilar = new QAction(imageSimilarityClass);
        actionSimilar->setObjectName(QStringLiteral("actionSimilar"));
        centralWidget = new QWidget(imageSimilarityClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        SrcImgView = new QGraphicsView(centralWidget);
        SrcImgView->setObjectName(QStringLiteral("SrcImgView"));
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        SrcImgView->setForegroundBrush(brush);

        horizontalLayout_3->addWidget(SrcImgView);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(frame);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        horizontalLayout->addWidget(label_5);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 4);
        verticalLayout->setStretch(1, 4);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);

        imageSimilarityClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(imageSimilarityClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 934, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        imageSimilarityClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(imageSimilarityClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        imageSimilarityClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(imageSimilarityClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        imageSimilarityClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(action2);
        menu_2->addAction(actionSimilar);

        retranslateUi(imageSimilarityClass);

        QMetaObject::connectSlotsByName(imageSimilarityClass);
    } // setupUi

    void retranslateUi(QMainWindow *imageSimilarityClass)
    {
        imageSimilarityClass->setWindowTitle(QApplication::translate("imageSimilarityClass", "imageSimilarity", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("imageSimilarityClass", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        action2->setText(QApplication::translate("imageSimilarityClass", "2", Q_NULLPTR));
        actionSimilar->setText(QApplication::translate("imageSimilarityClass", "\347\233\270\344\274\274\345\233\276\347\211\207", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        pushButton_2->setText(QApplication::translate("imageSimilarityClass", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        pushButton->setText(QApplication::translate("imageSimilarityClass", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        menu->setTitle(QApplication::translate("imageSimilarityClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("imageSimilarityClass", "\345\212\237\350\203\275", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class imageSimilarityClass: public Ui_imageSimilarityClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESIMILARITY_H
