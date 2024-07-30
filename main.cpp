#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <sstream>
#include "Menu.h"
using namespace std;
using namespace sf;

int main()
{
	srand(time(0));
	Menu m;
	m.display();
	return 0;
}