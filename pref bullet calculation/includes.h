#pragma once
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

enum STATES { MAIN_MENU, SETTING, PEOPLE_3, PEOPLE_4, PAUSE_MENU, FINALIZING_SCREEN };

enum TABLE_TYPEFROM { TABLE_FOR_3, TABLE_FOR_4 };