#pragma once

#include "includes.h"

#include "ApplicationState.h"

enum BUTTON_TYPES {SETTINGS, START, EXIT, CONTINUE, NOT_CLICKED};

class MainMenuButton
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	BUTTON_TYPES buttonType;

	sf::Texture textureOnHit;
	sf::Sprite spriteOnHit;

	bool isButtonClicked;

	void initVariables();

public:
	//Constructors and destructors
	MainMenuButton(BUTTON_TYPES button_type, sf::Vector2f position);
	~MainMenuButton();

	//Getters
	const sf::FloatRect getBounds() const;

	//Setters
	void setButtonClicked(const bool&);

	//Main functions
	BUTTON_TYPES update(sf::RenderWindow*);
	void render(sf::RenderWindow*);
};