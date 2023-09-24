#include "PauseMenu.h"

void PauseMenu::initVariables()
{

}

void PauseMenu::initBackgroundBlackingOut(sf::RenderWindow* window)
{
	backgroundBlackingOut.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	backgroundBlackingOut.setFillColor(sf::Color(0, 0, 0, 150));
}

void PauseMenu::initPauseMenuBackground(sf::RenderWindow* window)
{
	if (!pauseMenuTexture.loadFromFile("Textures/Pause_menu_background.png"))
		std::cerr << "ERROR!!! PAUSEMENU::INITPAUSEMENUBACKGROUND() -- could not load the file at 'Texture/Pause_menu_background.png'\n";

	pauseMenuSprite.setTexture(pauseMenuTexture);
	pauseMenuSprite.setPosition(sf::Vector2f(
									window->getSize().x / 2 - pauseMenuSprite.getGlobalBounds().width / 2, 
									window->getSize().y / 2 - pauseMenuSprite.getGlobalBounds().height / 2));
}

void PauseMenu::initButtons()
{
	cont = new MainMenuButton(BUTTON_TYPES::CONTINUE,
								sf::Vector2f(
									pauseMenuSprite.getPosition().x + 90,
									pauseMenuSprite.getPosition().y + 230
								)
							);

	exit = new MainMenuButton(BUTTON_TYPES::EXIT,
								sf::Vector2f(
									pauseMenuSprite.getPosition().x + 140,
									pauseMenuSprite.getPosition().y + 400
								)
							);
}



PauseMenu::PauseMenu(sf::RenderWindow* window)
{
	initVariables();
	initBackgroundBlackingOut(window);
	initPauseMenuBackground(window);
	initButtons();
}

PauseMenu::~PauseMenu()
{
	delete cont;
	delete exit;
}

//Main functions
void PauseMenu::update(sf::RenderWindow* window, ApplicationState* as, sf::Clock& escapeCooldown, STATES lastExitedState)
{
	if (cont->update(window) == BUTTON_TYPES::CONTINUE)
	{
		as->setState(lastExitedState);
	}
	else if (exit->update(window) == BUTTON_TYPES::EXIT)
	{
		as->setState(STATES::MAIN_MENU);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && escapeCooldown.getElapsedTime().asSeconds() >= 0.2)
	{
		escapeCooldown.restart();
		as->setState(lastExitedState);
	}
}

void PauseMenu::render(sf::RenderWindow* window)
{
	window->draw(backgroundBlackingOut);
	window->draw(pauseMenuSprite);

	cont->render(window);
	exit->render(window);
}