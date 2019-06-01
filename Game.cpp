#include <iostream>
#include <string>
#include <random>
#include "Space.hpp"
#include "Game.hpp"
#include "MysterySpace.hpp"
#include "DangerSpace.hpp"
#include "ItemSpace.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Game::Game()
{
    Space *startingSpace = new Space;
    currentSpace = startingSpace;
    Space *space1 = createNewSpaceType();
    Space *space2 = createNewSpaceType();
    Space *space3 = createNewSpaceType();
    Space *space4 = createNewSpaceType();
    Space *space5 = createNewSpaceType();
    Space *space6 = createNewSpaceType();
    Space *space7 = createNewSpaceType();
    Space *space8 = createNewSpaceType();
    Space *space9 = createNewSpaceType();
    Space *space10 = createNewSpaceType();
    Space *space11 = createNewSpaceType();

    // remember to not do links both ways

    spaceLinker(currentSpace, space1, right);
    spaceLinker(currentSpace, space4, down);

    spaceLinker(space1, currentSpace, left);
    spaceLinker(space1, space2, right);
    spaceLinker(space1, space5, down);

    spaceLinker(space2, space1, left);
    spaceLinker(space2, space3, right);
    spaceLinker(space2, space6, down);

    spaceLinker(space3, space2, left);
    spaceLinker(space3, space7, down);

    spaceLinker(space4, currentSpace, up);
    spaceLinker(space4, space5, right);
    spaceLinker(space4, space8, down);

    spaceLinker(space5, space1, up);
    spaceLinker(space5, space4, left);
    spaceLinker(space5, space9, down);
    spaceLinker(space5, space6, right);

    spaceLinker(space6, space2, up);
    spaceLinker(space6, space5, left);
    spaceLinker(space6, space10, down);
    spaceLinker(space6, space7, right);

    spaceLinker(space7, space3, up);
    spaceLinker(space7, space6, left);
    spaceLinker(space7, space11, down);

    spaceLinker(space8, space4, up);
    spaceLinker(space8, space9, right);

    spaceLinker(space9, space5, up);
    spaceLinker(space9, space8, left);
    spaceLinker(space9, space10, right);

    spaceLinker(space10, space6, up);
    spaceLinker(space10, space9, left);
    spaceLinker(space10, space11, right);

    spaceLinker(space11, space7, up);
    spaceLinker(space11, space10, left);

    steps = 0;
}

void Game::spaceLinker(Space *s1, Space *s2, Direction d)
{
    switch (d)
    {
        case up:
            s1->setUp(s2);
            s2->setDown(s1);
            break;
        case down:
            s1->setDown(s2);
            s2->setUp(s1);
            break;
        case left:
            s1->setLeft(s2);
            s2->setRight(s1);
            break;
        case right:
            s1->setRight(s2);
            s2->setLeft(s1);
            break;
    }
}

Space* Game::createNewSpaceType()
{
    int newSpaceType = getRandomNum(1, 10);

    if (newSpaceType == 1 || newSpaceType == 2 || newSpaceType == 3)
    {
        new ItemSpace;
        numSpaces++;
//        cout << "New Item space created" << endl;
        return new ItemSpace;
    } else if (newSpaceType == 4 || newSpaceType == 5 || newSpaceType == 6)
    {
        new DangerSpace;
        numSpaces++;
//        cout << "New Danger space created" << endl;
        return new DangerSpace;
    } else if (newSpaceType == 7 || newSpaceType == 8 || newSpaceType == 9)
    {
        new MysterySpace;
        numSpaces++;
//        cout << "New Mystery space created" << endl;
        return new MysterySpace;
    } else {
        new Space;
        numSpaces++;
//        cout << "New space created" << endl;
        return new Space;
    }
}

void Game::startGame()
{

    cout << "Number of current spaces is: " << numSpaces << endl;
    cout << "Starting space type is: " << currentSpace->getName() << endl;
    nextMove();
    cout << "Next space is: " << currentSpace->getName() << endl;

}

void Game::nextMove()
{
    int nextMove = 0;
    cout << "Where would you like to move next?" << endl;
    cout << " 1. Up \n 2. Down \n 3. Left \n 4. Right" << endl;
    cin >> nextMove;

    switch (nextMove)
    {
        case 1:
            if (currentSpace->getUp() == nullptr)
            {
                cout << "Sorry! Cannot move up!" << endl;
                break;
            }
            move(up);
            break;
        case 2:
            if (currentSpace->getDown() == nullptr)
            {
                cout << "Sorry! Cannot move down!" << endl;
                break;
            }
            move(down);
            break;
        case 3:
            if (currentSpace->getLeft() == nullptr)
            {
                cout << "Sorry! Cannot move left!" << endl;
                break;
            }
            move(left);
            break;
        case 4:
            if (currentSpace->getRight() == nullptr)
            {
                cout << "Sorry! Cannot move right!" << endl;
                break;
            }
            move(right);
            break;
    }
}

void Game::move(Direction d)
{
    switch(d)
    {
        case up:
            currentSpace = currentSpace->getUp();
            cout << "Moving up!" << endl;
            break;
        case down:
            currentSpace = currentSpace->getDown();
            cout << "Moving down!" << endl;
            break;
        case left:
            currentSpace = currentSpace->getLeft();
            cout << "Moving left!" << endl;
            break;
        case right:
            currentSpace = currentSpace->getRight();
            cout << "Moving right!" << endl;
            break;
    }

    steps++;
}

int Game::getRandomNum(int min, int max)
{
    // copied from https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> roll(min, max);

    return roll(gen);
}