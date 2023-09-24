#pragma once

#include "includes.h"

class TableCursor
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	bool hideCursor;

	bool visible;

	int indexStopped;

	sf::Clock animationTimer;

	void initVariables();
	void initTextureAndSprite();

public:
	//Constructor and destructor
	TableCursor();
	~TableCursor();

	//getters
	bool getCursorHidden();

	//setters
	void setCursor(bool);
	void setPosition(sf::Vector2f pos);

	//Fucntions
	void updateInput(sf::RenderWindow*);
	void updateAnimation();



	//getters
	const sf::Vector2f getPosition() const;


	//Main functions
	void update(sf::RenderWindow*);
	void render(sf::RenderWindow*);

};