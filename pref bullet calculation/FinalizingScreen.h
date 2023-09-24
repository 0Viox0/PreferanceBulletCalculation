#pragma once

#include "includes.h"

#include "TableFor3.h"

#include "ApplicationState.h"

#include "CalculatorFor3.h"
#include "CalculatorFor4.h"

#include "LetterButton.h"

#include "includes.h"

class FinalizingScreen
{
private:
	sf::RectangleShape rect;

	sf::Font font;
	sf::Text results;


	//Calculators to calculate everything
	CalculatorFor3* calc;
	CalculatorFor4* calc2;

	void initVariables();
	void initText();
	void initRect();

public:
	//Constructor and destructor
	FinalizingScreen(std::vector<TableButton*>&, VistSetButton*);
	~FinalizingScreen();

	int findValueByTag(std::vector<TableButton*>&, std::string);

	//Main functions
	void update(sf::Clock& escapeButtonCooldown, ApplicationState* as, std::vector<TableButton*>&, 
					VistSetButton*, LetterButton&, LetterButton&, LetterButton&);
	void update2(sf::Clock& escapeButtonCooldown, ApplicationState* as, std::vector<TableButton*>&,
		VistSetButton*, LetterButton&, LetterButton&, LetterButton&, LetterButton&);

	void render(sf::RenderWindow*);
};