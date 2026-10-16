#include "widget.h"
#include <QGridLayout>
#include <QString>
#include <iostream>
#include <QThread>
#include <QtConcurrent>
#include "bot.cpp"
//
//
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
        //set statements
        //define bot
        std::vector <size_t> bot_properties;
           //set bot

           //set three  bot
           for (size_t self_id = 0; self_id < numberOfXos; self_id++)
           {
                for (size_t auther1_id = 0; auther1_id < numberOfXos; auther1_id++)
                {
                    for (size_t auther2_id = 0; auther2_id < numberOfXos; auther2_id++)
                    {
                        // set self!=auther1!=auther2
                        if(self_id != auther1_id && auther1_id != auther2_id && auther1_id != self_id)
                        {
                             //set proba var add
                             int proba1 = 0;
                            if(mt::Aligne<size_t>(
                                //set  P(x,y) self
                            mt::Point<size_t>(row(self_id),coloumn(self_id))
                            //set P(x,y) auther1
                            ,mt::Point<size_t>(row(auther1_id),coloumn(auther1_id))
                            //sett P3 (x,y) auther 2
                            ,mt::Point<size_t>(row(auther2_id),coloumn(auther2_id)))) 
                            { 
                             //   bot_properties[self_id]  ;
                             const auto some_all = rols(buttons[self_id]->text())+ rols(buttons[auther1_id]->text())+ \
                             rols(buttons[auther2_id]->text());
                             //
                             if(some_all ==3 || some_all ==6) proba1 +=20;
                             else if(some_all ==2 || some_all == 4) proba1 +=10;
                             else {proba1 +=1;}
                            }
                            else{proba1+=1;}
                            //add  proba1
                            bot_properties[self_id]+= proba1;
                        }
                    }
                }
           }
           //set random
           mt::LiniarExperiment<QPushButton> btnPush(std::vector<QPushButton*>(btn));
           btnPush.setRandomFun([](){return bot(bot_properties);});
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
           //bot rule
           else
           {

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