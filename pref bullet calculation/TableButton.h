#pragma once

#include "includes.h"

#include "TableCursor.h"

class TableButton
{
private:
	std::string tag;


	sf::Clock inputCooldown;


	int value;

	sf::Font font;

	std::string textString;

	void initVariables();
	void initShape(sf::Vector2f);
	void initFontAndText();

public:
	//dumb putting these variables in the public
	//but it happened because i didnt make base class to inherit from
	//and i now i need acces to these variables for different letter button... sad (
	//...i later realised i could've just made members protected but now it's too late
	//because i added a lot of things and if i wanted to change something i would just
	//mess up the code.... bruuuuuuuuuuuh
	int horizontalOffset;
	//sf::RectangleShape but;
	sf::Texture butTexture;
	sf::Sprite but;
	TableCursor cursor;
	sf::Text text;


	//Constructor and desctructor
	TableButton(sf::Vector2f, std::string);
	~TableButton();

	//getters
	std::string getTag();
	int getValue();

	//setters
	void setValueInt(int);

	//functions
	virtual void updateInput(sf::RenderWindow*);
	void updateCursor(sf::RenderWindow*);

	//Main functions
	void update(sf::RenderWindow*);
	void render(sf::RenderWindow*);
};