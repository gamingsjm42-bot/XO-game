#pragma once

#include <QWidget>
#include <QPushButton>
#include <math.h>
#include <vector>
#include <thread>
#include <chrono>
#include "mt/geomtry.h"
#include <QKeyEvent>
#include <iostream>
//

//
//
//
//set widget
class Widget : public QWidget
{

public:
   //constractors
    explicit Widget(QWidget *parent = nullptr);
private:
    //set title
    const char* title = "XO";
    //set Xos
    const size_t numberOfXos = 9;
    //set press effect
    size_t row(size_t id){ return (id/sqrt(numberOfXos));}
    size_t coloumn(size_t id){ return id%int(sqrt(numberOfXos));}
    /// @brief that function returning  a button
    std::vector<QPushButton*> buttons;
    //set all
    //set rols 
    const std::vector<const char*> rols = {"O","X"};
    //set role id
    const size_t numberOfRols = 2;
    using Rol = enum{NONE = 0,X=1,O=2};
    int rols(QString input)
    {
        //set returning
        for (int i = 0; i < numberOfRols; i++) if(input.toStdString() == rols[i]) return i+1;
        //returning
        return 0;
    }
    //set player var
    size_t player  = 0;
    /// @brief that fumctiom retiurn number
    bool is_avoid(){for(int i = 0;i<numberOfXos;i++) if(!buttons[i]->text().isEmpty()) return false; return true;}
    ///@that function begin a new math
    void begin(){this->setWindowTitle(title);}
    /// @brief that function return a player var
    /// @param btn that button what press
    /// @param id that id of player do
    void onButtonClick(QPushButton* btn,size_t id)
    {
        begin();
        //set text player condition if player sleep
      if(btn->text().isEmpty())
      {
        //set text plt
        btn->setText(rols[id]);
        //edit player properties
        player++;
        player%=numberOfRols;
      }
        //
    }
    /// @brief that function return id of winner 0 is Not Winner
    /// @return 
    int winner()
    {
        //set O(n^3) forloop
        for (size_t i = 0; i <numberOfXos; i++)
        { 
            for (size_t j = 0; j< numberOfXos; j++)
            {
                for (size_t k = 0; k < numberOfXos; k++)
                { 
                    //Aligne condition
                    if (mt::Aligne(mt::Point{row(i),coloumn(i)},mt::Point{row(j),coloumn(j)},mt::Point{row(k),coloumn(k)})\
                    //!= text condition
                 &&( (buttons[i]->text()==buttons[j]->text())&& (buttons[j]->text()==buttons[k]->text())) 
                 //set != number
                 &&(i!=j && j!=k && k!=i)
                 //!= '' condition
                 &&!(buttons[i]->text().isEmpty() || buttons[j]->text().isEmpty() || buttons[k]->text().isEmpty())
                ) 
                    {
                        //set find function
                        int id= 0;
                        //
                        for (auto rol = rols.begin(); rol != rols.end(); rol++) 
                        {
                            //set id add
                            id++;
                            //fix button
                            if(buttons[i]->text()==*rol) { return id;}
                        }
                    }
                    
                }
                
            }
            
        }
        return 0;
    }
    /// @brief that function reset XO
    void reset()
    { 
        //sleeo
        
        //reset buttons
        for (size_t i = 0; i < numberOfXos; i++) buttons[i]->setText("");
    }
    //set
    //
    //
    bool is_draw(){for (size_t i = 0; i < numberOfXos; i++) if(buttons[i]->text().isEmpty()) return false; return true;}
    //isEmpty
};