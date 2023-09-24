#include "CircleAroundNumber.h"


void CircleAroundNumber::initVariables()
{
	A_position = sf::Vector2f(580,245);
	B_position = sf::Vector2f(680, 245);

	offsetX = 20;
	offsetY = 20;

	circledAround = CIRCLES_AROUND::A;
}

void CircleAroundNumber::initTexturAndSprite()
{
	if (!texture.loadFromFile("Textures/Highlighting_amount_of_players.png"))
		std::cerr << "ERROR!!! CIRCLEAROUNDNUMBER::INITTEXTURANDSPRITE() -- could not load the file 'Textures/Highlighting_amount_of_players.png'\n";

	sprite.setTexture(texture);
	sprite.setPosition(A_position);
}

void CircleAroundNumber::initHitBoxes()
{
	hitbox_A.setPosition(sprite.getPosition().x + offsetX, sprite.getPosition().y + offsetY);
	hitbox_A.setSize(
			sf::Vector2f(
				sprite.getGlobalBounds().getSize().x - offsetX * 2, sprite.getGlobalBounds().getSize().x - offsetY * 2
			)
		);

	hitbox_A.setFillColor(sf::Color(0, 0, 0, 0));



	hitbox_B.setPosition(sprite.getPosition().x + 100 + offsetX, sprite.getPosition().y + offsetY);
	hitbox_B.setSize(
			sf::Vector2f(
				sprite.getGlobalBounds().getSize().x - offsetX * 2, sprite.getGlobalBounds().getSize().x - offsetY * 2
			)
	);

	hitbox_B.setFillColor(sf::Color(0, 0, 0, 0));
}

//Constructor and destructor
CircleAroundNumber::CircleAroundNumber()
{
	initVariables();
	initTexturAndSprite();
	initHitBoxes();
}

CircleAroundNumber::~CircleAroundNumber()
{

}

//getters
CIRCLES_AROUND CircleAroundNumber::getCircleAround()
{
	return circledAround;
}


//Main functions
void CircleAroundNumber::update(sf::RenderWindow* window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (hitbox_A.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			sprite.setPosition(A_position);
			circledAround = A;
		}
		else if (hitbox_B.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			sprite.setPosition(B_position);
			circledAround = B;
		}
	}
}

void CircleAroundNumber::render(sf::RenderWindow* window)
{
	window->draw(sprite);

	//DEBUG
	window->draw(hitbox_A);
	window->draw(hitbox_B);
}