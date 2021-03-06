#include <iostream>

using namespace std;

#include "../../common/randomizer.h"

int grass;
int tree;
int cow;
int chicken;
int pig;
int sheep;
bool nearCave;

void generateWorld()
{
    grass = randomInt(5, 25);
    tree = randomInt(10, 20);
    cow = randomInt(0, 10);
    chicken = randomInt(0, 10);
    pig = randomInt(0, 10);
    sheep = randomInt(0, 10);
    nearCave = randomBool();
}

void modifyWorld(string type, int amount)
{
    if(type == "grass") { grass += amount; }
    else if(type == "tree") { tree += amount; }
    else if(type == "cow") { cow += amount; }
    else if (type == "chicken") { chicken += amount; }
    else if (type == "pig") { pig += amount; }
    else if (type == "sheep") { sheep += amount; }
}

int returnWorldInfo(string type)
{
    if(type == "grass") { return grass; }
    else if(type == "tree") { return tree; }
    else if(type == "cow") { return cow; }
    else if (type == "chicken") { return chicken; }
    else if (type == "pig") { return pig; }
    else if (type == "sheep") { return sheep; }
    else { return -1;}
}
