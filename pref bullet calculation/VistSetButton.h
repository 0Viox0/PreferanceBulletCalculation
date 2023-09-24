#pragma once

#include "includes.h"

#include "TableButton.h"

class VistSetButton : public TableButton
{
private:
	sf::Font font;
	sf::Text text;

	void initVariables();
	void initFontAndText();

public:
	//Constructor and destructor
	VistSetButton(sf::Vector2f pos);
	~VistSetButton();

	//Main functions
	void update(sf::RenderWindow*);
	void render(sf::RenderWindow*);
};