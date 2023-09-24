#include "CenterButton.h"

//Private functions

void CenterButton::initVariables()
{
	renderCalculateWindow = false;
}

void CenterButton::initPressBut()
{
	pressBut.setFillColor(sf::Color(0, 162, 232, 100));
	pressBut.setRadius(20);
	pressBut.setPosition(sf::Vector2f(450.f - pressBut.getGlobalBounds().width / 2.f + 3,
										475.f - pressBut.getGlobalBounds().height / 2.f));
}

void CenterButton::initCalculateWindow()
{
	calculateWindow.setSize(sf::Vector2f(250, 150));
	calculateWindow.setFillColor(sf::Color(0, 0, 255, 100));
	calculateWindow.setPosition(sf::Vector2f(
									pressBut.getPosition().x - calculateWindow.getGlobalBounds().width / 2 + 16,
									pressBut.getPosition().y - calculateWindow.getGlobalBounds().height
								));
}

void CenterButton::initTextAndFont()
{
	if (!font.loadFromFile("Fonts/Times New Romance.ttf"))
		std::cerr << "ERROR!!! CENTERBUTTON::INITTEXTANDFONT() -- could not load the file at 'Fonts/Times New Romance.ttf'\n";

	calculate_text.setFont(font);
	calculate_text.setString("To calculate\npress enter");
	calculate_text.setStyle(calculate_text.Bold);
	calculate_text.setCharacterSize(30);
	calculate_text.setPosition(calculateWindow.getPosition().x + calculate_text.getGlobalBounds().width / 2 - 25, 
								calculateWindow.getPosition().y + 40);
}

//Constructor and destructor
CenterButton::CenterButton()
{
	initVariables();
	initPressBut();
	initCalculateWindow();
	initTextAndFont();
}

CenterButton::~CenterButton()
{

}

//Main functions
void CenterButton::update(sf::RenderWindow* window, ApplicationState* as)
{
	if (pressBut.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
	{
		pressBut.setFillColor(sf::Color(255, 127, 39));
		renderCalculateWindow = true;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			as->setState(STATES::FINALIZING_SCREEN);
		}
	}
	else
	{
		pressBut.setFillColor(sf::Color(sf::Color::Cyan));
		renderCalculateWindow = false;
	}
}

void CenterButton::render(sf::RenderWindow* window)
{
	window->draw(pressBut);

	if (renderCalculateWindow)
	{
		window->draw(calculateWindow);
		window->draw(calculate_text);
	}
}