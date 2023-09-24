#include "MainMenuButton.h"

void MainMenuButton::initVariables()
{
	isButtonClicked = false;
}

//Constructors and destructors
MainMenuButton::MainMenuButton(BUTTON_TYPES button_type, sf::Vector2f position)
{
	initVariables();

	switch (button_type)
	{
	case BUTTON_TYPES::SETTINGS:
		buttonType = BUTTON_TYPES::SETTINGS;
		if (!texture.loadFromFile("Textures/settings_button.png"))
			std::cerr << "ERROR!!! MAINMENUBUTTON::MAINMENUBUTTON()::SWITCH()::CASE BUTTON_TYPES::SETTINGS -- could not open the file at 'Textures/settings_button.png'\n";
		if (!textureOnHit.loadFromFile("Textures/setting_button_on_click.png"))
			std::cerr << "ERROR!!! MAINMENUBUTTON::MAINMENUBUTTON()::SWITCH()::CASE BUTTON_TYPES::SETTINGS -- could not open the file at 'Textures/setting_button_on_click.png'\n";
		break;
	case BUTTON_TYPES::START:
		buttonType = BUTTON_TYPES::START;
		if (!texture.loadFromFile("Textures/start_button.png"))
			std::cerr << "ERROR!!! MAINMENUBUTTON::MAINMENUBUTTON()::SWITCH()::CASE BUTTON_TYPES::START -- could not open the file at 'Textures/start_button.png'\n";
		if (!textureOnHit.loadFromFile("Textures/start_button_on_click.png"))
			std::cerr << "ERROR!!! MAINMENUBUTTON::MAINMENUBUTTON()::SWITCH()::CASE BUTTON_TYPES::START -- could not open the file at 'Textures/start_button_on_click.png'\n";
		break;
	case BUTTON_TYPES::EXIT:
		buttonType = BUTTON_TYPES::EXIT;
		if (!texture.loadFromFile("Textures/exit_button.png"))
			std::cerr << "ERROR!!! MAINMENUBUTTON::MAINMENUBUTTON()::SWITCH()::CASE BUTTON_TYPES::EXIT -- could not open the file at 'Textures/exit_button.png'\n";
		if (!textureOnHit.loadFromFile("Textures/exit_button_on_click.png"))
			std::cerr << "ERROR!!! MAINMENUBUTTON::MAINMENUBUTTON()::SWITCH()::CASE BUTTON_TYPES::EXIT -- could not open the file at 'Textures/exit_button_on_click.png'\n";
		break;
	case BUTTON_TYPES::CONTINUE:
		buttonType = BUTTON_TYPES::CONTINUE;
		if (!texture.loadFromFile("Textures/continue_button.png"))
			std::cerr << "ERROR!!! MAINMENUBUTTON::MAINMENUBUTTON()::SWITCH()::CASE BUTTON_TYPES::CONTINUE -- could not open the file at 'Textures/continue_button.png'\n";
		if (!textureOnHit.loadFromFile("Textures/continue_button_on_click.png"))
			std::cerr << "ERROR!!! MAINMENUBUTTON::MAINMENUBUTTON()::SWITCH()::CASE BUTTON_TYPES::CONTINUE -- could not open the file at 'Textures/continue_button_on_click.png'\n";
		break;
	}

	sprite.setTexture(texture);
	spriteOnHit.setTexture(textureOnHit);

	sprite.setPosition(position);
	spriteOnHit.setPosition(position.x, position.y - 10);
}

MainMenuButton::~MainMenuButton()
{

}

//Getters
const sf::FloatRect MainMenuButton::getBounds() const
{
	return (isButtonClicked ? sprite.getGlobalBounds() : spriteOnHit.getGlobalBounds());
}

//Setters
void MainMenuButton::setButtonClicked(const bool& value)
{
	isButtonClicked = value;
}

//Main functions
BUTTON_TYPES MainMenuButton::update(sf::RenderWindow* window)
{
	if (sprite.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y)
		|| spriteOnHit.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
	{
		isButtonClicked = true;
	}
	else
	{
		isButtonClicked = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) 
		&& sprite.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
	{
		if (buttonType == BUTTON_TYPES::START)
		{
			return START;
		}
		else if (buttonType == BUTTON_TYPES::SETTINGS)
		{
			return SETTINGS;
		}
		else if (buttonType == BUTTON_TYPES::EXIT)
		{
			return EXIT;
		}
		else if (buttonType == BUTTON_TYPES::CONTINUE)
		{
			return CONTINUE;
		}
	}

	return NOT_CLICKED;
}

void MainMenuButton::render(sf::RenderWindow* window)
{
	switch (isButtonClicked)
	{
	case true:
		window->draw(spriteOnHit);
		break;
	case false:
		window->draw(sprite);
		break;
	}
}