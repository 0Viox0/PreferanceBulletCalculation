#pragma once

#include "ApplicationState.h"

#include "MainMenu.h"
#include "Settings.h"
#include "TableFor3.h"
#include "tableFor4.h"
#include "PauseMenu.h"
#include "FinalizingScreen.h"


class Application
{
private:
	//application window
	sf::RenderWindow* window;
	sf::VideoMode resolution;

	sf::Event ev;

	//application state
	ApplicationState* applicationState;

	sf::Clock beInState;


	//different states
	MainMenu* mainMenu;
	Settings settings;
	TableFor3 tableFor3;
	TableFor4 tableFor4;
	PauseMenu* pauseMenu;
	FinalizingScreen* finalizingScreen;

	//escape cooldown
	sf::Clock escapeCooldown;

	//variables
	STATES lastExitedState;

	//Init funcions
	void initVariables();
	void initWindow();

public:
	//Constructor and destructor
	Application();
	~Application();

	//Accessors
	bool isRunning();


	//Functions




	//Main functions
	void run();

	void eventLoop();
	void update();
	
	void render();
};