/*********************************************************************
** Program name: Final Project
** Author: Katie Stutts
** Date:June 2nd, 2019
** Description:
*********************************************************************/
#include "ItemSpace.hpp"
#include "Item.hpp"
#include "Berries.hpp"
#include "CoconutPhone.hpp"
#include "Knife.hpp"
#include "Wood.hpp"
#include "Game.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/******************************************************
*
******************************************************/
ItemSpace::ItemSpace()
{
    name = "Item Space";
}

/******************************************************
*
******************************************************/
ItemSpace::~ItemSpace() {}

/******************************************************
*
******************************************************/
string ItemSpace::getName()
{
    return name;
}

/******************************************************
*
******************************************************/
int ItemSpace::runEvent()
{
    cout << " -~*~--~*~--~*~--~*~--~*~--~*~-" << endl;
    cout << "\t \t  ITEM   SPACE" << endl;
    cout << " -~*~--~*~--~*~--~*~--~*~--~*~-" << endl;

    int whichItem;
    whichItem = generateCoconutPhone();
    cout << "which item is: " << whichItem << endl;
//    createNewItem(1);

    switch (whichItem)
    {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
    }

//    cout << "Inside itemspace class" << endl;

}
