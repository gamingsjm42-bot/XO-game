//includes
#include "mt/propabillity.h"
/// @brief that return id of returning
int bot(std::vector<size_t> buttonProba)
{
    //
    //s
    size_t card_lambda = 0;
    //set card_lamda = sum(buttonProba)
    for(auto i = buttonProba.begin();i!=buttonProba.end();i++) card_lambda+=*i;
    //fix card_lamda
    //set on proba
    size_t idOfproba = 0 ;
    //
    size_t returning =0;
    //
    size_t randomNumber = rand()%card_lambda;
    //
    //fix 0
   if(buttonProba[0] == 0) returning++;
    for (size_t i = 0; i < randomNumber; i++)
    {
        //add id of proba
        idOfproba++;
        //set conditiom 
        if(idOfproba== buttonProba[returning])
        {
            //add a returning
            idOfproba=0;
            returning++;
        }
    }
    //returning
    return returning;
}
///