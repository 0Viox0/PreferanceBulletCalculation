#pragma once

#include "includes.h"

#include "ApplicationState.h"

class CenterButton
{
private:
	sf::CircleShape pressBut;

	sf::RectangleShape calculateWindow;

	sf::Font font;

	sf::Text calculate_text;

	bool renderCalculateWindow;

	void initVariables();
	void initTextAndFont();
	void initPressBut();
	void initCalculateWindow();

public:
	//Constructor and destructor
	CenterButton();
	~CenterButton();


	//Main functions
	void update(sf::RenderWindow*, ApplicationState*);
	void render(sf::RenderWindow*);

};