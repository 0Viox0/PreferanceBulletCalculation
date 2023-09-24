#include "TableCursor.h"

void TableCursor::initVariables()
{
	visible = true;	//for animation
	hideCursor = true;

	indexStopped = -1;
}

void TableCursor::initTextureAndSprite()
{
	if (!texture.loadFromFile("Textures/cursor.png"))
		std::cerr << "ERROR!!! TABLECURSOR::INITTEXTUREANDSPRITE() -- could not load the file at 'Textures/cursor.png'\n";

	sprite.setTexture(texture);

	sprite.setScale(0.f, 0.f);
}

//Constructor and destructor
TableCursor::TableCursor()
{
	animationTimer.restart();
	initTextureAndSprite();
}

TableCursor::~TableCursor()
{

}

//getters
bool TableCursor::getCursorHidden()
{
	return hideCursor;
}

//setters
void TableCursor::setCursor(bool value)
{
	hideCursor = value;
}

void TableCursor::setPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}


//Fucntions
void TableCursor::updateInput(sf::RenderWindow* window)
{

}

void TableCursor::updateAnimation()
{
	if (animationTimer.getElapsedTime().asSeconds() >= 0.5)
	{
		animationTimer.restart();

		if (visible) visible = false;
		else if (!visible) visible = true;

		if (visible)
			sprite.setScale(0.2f, 0.4f);
		else if (!visible)
			sprite.setScale(0, 0);
	}
}

//getters
const sf::Vector2f TableCursor::getPosition() const
{
	return sprite.getPosition();
}

//Main functions
void TableCursor::update(sf::RenderWindow* window)
{
	updateInput(window);
	updateAnimation();
}

void TableCursor::render(sf::RenderWindow* window)
{
	if (!hideCursor)
		window->draw(sprite);
}