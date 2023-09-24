#pragma once

#include "includes.h"

#include "MainMenuButton.h"

#include "ApplicationState.h"

class PauseMenu
{
private:
	sf::RectangleShape backgroundBlackingOut;

	sf::Texture pauseMenuTexture;
	sf::Sprite pauseMenuSprite;

	//buttons
	MainMenuButton* cont;
	MainMenuButton* exit;

	void initVariables();
	void initBackgroundBlackingOut(sf::RenderWindow*);
	void initPauseMenuBackground(sf::RenderWindow*);
	void initButtons();

public:
	//Constructor and destructor
	PauseMenu(sf::RenderWindow*);
	~PauseMenu();

	//Main functions
	void update(sf::RenderWindow*, ApplicationState*, sf::Clock&, STATES);
	void render(sf::RenderWindow*);
};