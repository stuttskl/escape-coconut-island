#include "MysterySpace.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;


MysterySpace::MysterySpace()
{
    name = "Mystery Space";
}

MysterySpace::~MysterySpace() {}

string MysterySpace::getName()
{
    return name;
}

int MysterySpace::runEvent()
{
    cout << " -~*~--~*~--~*~--~*~--~*~--~*~-" << endl;
    cout << "\t \t  MYSTERY SPACE" << endl;
    cout << " -~*~--~*~--~*~--~*~--~*~--~*~-" << endl;
    cout << "There is a 50% chance a good event will happen, and a 50% chance a bad event will happen." << endl;
    cout << "Only fate truly knows what's in store..." << endl;
    cout << "----------------------------------------" << endl;
    int goodOrBad = getRand(1, 6);
    switch (goodOrBad)
    {
        case 1:
            cout << "Suddenly a heavy downpour and brutal winds wash over you, and you hardly have any time to find "
                    "cover. As a result, you get a little sick. Health decreases by 2." << endl;
            return -2;
        case 2:
            cout << "Out of nowhere, you are attacked by an angry, rabid squirrel. You have no time to think, and "
                    "are unfortunately injured. Health decreases by 4." << endl;
            return -4;
        case 3:
            cout << "You suddenly realize your knapsack feels a lot lighter… three items lighter, to be specific."
                    "You realize you left your knapsack alone earlier, and another island dweller has stolen 3 "
                    "of your items. You lose 3 items from your knapsack." << endl;
            return -3;
        case 4:
            cout << "You’ve just stumbled upon a small dead animal. You feel sad that the animal did not survive, "
                    "but grateful for the nutrition it provides. Health increases by 4." << endl;
            return 4;
        case 5:
            cout << "Despite the overbearing struggle for survival, you realize that you are on a beautiful island, "
                    "and the weather is remarkably beautiful today. You take just a moment, to close your eyes,"
                    "breathe deeply and feel gratitude that you are alive. Morale increases by 2." << endl;
            return 2;
        case 6:
            cout << "You have been walking for what seems like hours, and you stumble upon a beautiful meadow with the "
                    "most gorgeous and fragrant flowers you've seen. This puts you in a good mood, and to make things "
                    "even better, you discover delicious fruits. Health increases by 2, Morale increases by 3." << endl;
            return 2;
    }
}