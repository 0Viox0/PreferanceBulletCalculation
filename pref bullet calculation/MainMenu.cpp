#include "MainMenu.h"

void MainMenu::initVariables()
{
	
}

void MainMenu::initBackground()
{
	if (!backgroundTexture.loadFromFile("Textures/Main_menu_background.png"))
		std::cerr << "ERROR!!! MAINMENU::INITBACKGROUND --could not open the file at 'Texutres/Main_menu_background.png'\n";

	background.setTexture(backgroundTexture);
}

void MainMenu::initButtons(sf::RenderWindow* window)
{
	start = new MainMenuButton(BUTTON_TYPES::START,
								sf::Vector2f(
									100,
									470
								)
							);

	settings = new MainMenuButton(BUTTON_TYPES::SETTINGS, 
									sf::Vector2f(
										100, 
										630
									)
								);

	exit = new MainMenuButton(BUTTON_TYPES::EXIT,
		sf::Vector2f(
			100,
			750
		)
	);

	
}

void MainMenu::initCirc()
{
	circ = new CircleAroundNumber();
}

//Constructor and destructor
MainMenu::MainMenu(sf::RenderWindow* window)
{
	initVariables();
	initBackground();
	initButtons(window);
	initCirc();
}

MainMenu::~MainMenu()
{
	delete settings;
	delete start;
	
	delete circ;
}

//settters

//Main functions
void MainMenu::update(sf::RenderWindow* window, ApplicationState* as)
{
	if (start->update(window) == BUTTON_TYPES::START)
	{
		if (circ->getCircleAround() == CIRCLES_AROUND::A) as->setState(STATES::PEOPLE_3);
		else if (circ->getCircleAround() == CIRCLES_AROUND::B) as->setState(STATES::PEOPLE_4);
	}
	else if (settings->update(window) == BUTTON_TYPES::SETTINGS)
	{
		as->setState(STATES::SETTING);
	}
	else if (exit->update(window) == BUTTON_TYPES::EXIT)
	{
		as->setGameOver(true);
	}

	circ->update(window);
}

void MainMenu::render(sf::RenderWindow* window)
{
	window->draw(background);

	start->render(window);
	settings->render(window);
	exit->render(window);

	circ->render(window);
}