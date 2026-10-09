#include "widget.h"
#include <QGridLayout>
#include <QString>
#include <iostream>
#include <QThread>
#include <QtConcurrent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //set properties
    this->setWindowTitle(title);
    this->resize(600,600);
    //set buttons
    // 
    QGridLayout *l = new QGridLayout(this);
    //set layouts settings
    l->setSpacing(1);
    l->setHorizontalSpacing(1);
    l->setVerticalSpacing(1);
    //set button self
    for (size_t i = 0; i < numberOfXos ; i++)
    {
    static int NOWIN ;
        QPushButton* btn = new QPushButton("",this);
        //
        btn->setStyleSheet(
            //set button on normal
            "QPushButton"
            "{"
            //remove button self
            "border :2pt red fixed;"
            //set black background
            "background : black;"
            //set font
            "font: 700 20pt 'Noto Sans';"
            //set text color
            "color: white;"
        "}"
        //set hover effect change background
        "QPushButton:hover{background:green;}"
        //set press background
        "QPushButton:pressed{background:yellow;}"
        );
        //set buttons Square
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    
        btn->setMinimumSize(80, 80); 
        btn->resize(120,120);
        //set player function
        auto plrDo  =[btn,this]() 
        {
            //set text
            this->onButtonClick(btn,player);
           //set bot rule
           const int win = this->winner();
           //set win effect
           if ((win !=  0)||(this->is_draw()))
           { 
            this->setWindowTitle((win==0)? "Draw":QString("the winner is:")+this->rols.at(win-1));
            //fress window 
                this->reset();
           }
           
        };
        //set button effect
        connect(btn, &QPushButton::clicked,this,plrDo);
        buttons.push_back(btn); 
        //
        //add button on row ,coloumn
        l->addWidget(btn,row(i),coloumn(i));
        //
    }
    
} 