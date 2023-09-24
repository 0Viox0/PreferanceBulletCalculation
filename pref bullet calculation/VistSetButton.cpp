#include "VistSetButton.h"

void VistSetButton::initVariables()
{

}

void VistSetButton::initFontAndText()
{
	if (!font.loadFromFile("Fonts/Times New Romance.ttf"))
		std::cerr << "ERROR!!! VISITSETBUTTON::iNITFONTANDTEXT() -- could not open the file at 'Fonts/Times New Romance.ttf'\n";

	text.setString("Vist value");
	text.setFont(font);
	text.setCharacterSize(30);
	text.setPosition(
		but.getPosition().x + but.getGlobalBounds().getSize().x / 2 - text.getGlobalBounds().width / 2,
		but.getPosition().y - 45);
	text.setFillColor(sf::Color(0, 0, 0, 230));
	text.setStyle(text.Bold);
}

//Constructor and destructor
VistSetButton::VistSetButton(sf::Vector2f pos) : TableButton(pos, "vist set button")
{
	initVariables();
	initFontAndText();
}

VistSetButton::~VistSetButton()
{

}

//Main functions
void VistSetButton::update(sf::RenderWindow* window)
{
	TableButton::update(window);
}

void VistSetButton::render(sf::RenderWindow* window)
{
	TableButton::render(window);
	window->draw(text);
}