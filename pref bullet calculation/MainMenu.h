#pragma once

#include "includes.h"

#include "MainMenuButton.h"
#include "CircleAroundNumber.h"

#include "ApplicationState.h"

class MainMenu
{
private:
	sf::Sprite background;
	sf::Texture backgroundTexture;

	MainMenuButton* settings;
	MainMenuButton* start;
	MainMenuButton* exit;

	CircleAroundNumber* circ;

	void initVariables();
	void initBackground();
	void initButtons(sf::RenderWindow*);
	void initCirc();

public:
	//Constructor and destructor
	MainMenu(sf::RenderWindow*);
	~MainMenu();

	
	//settters


	//Functions



	//Main functoins
	void update(sf::RenderWindow*, ApplicationState*);
	void render(sf::RenderWindow*);
};