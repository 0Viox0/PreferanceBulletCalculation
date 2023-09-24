#pragma once

#include "includes.h"

enum CIRCLES_AROUND {A, B};

class CircleAroundNumber
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f A_position;
	sf::Vector2f B_position;

	sf::RectangleShape hitbox_A;
	sf::RectangleShape hitbox_B;

	CIRCLES_AROUND circledAround;

	int offsetX;
	int offsetY;

	void initVariables();
	void initTexturAndSprite();
	void initHitBoxes();

public:
	//Constructor and destructor
	CircleAroundNumber();
	~CircleAroundNumber();

	//getters
	CIRCLES_AROUND getCircleAround();

	//Main functions
	void update(sf::RenderWindow*);
	void render(sf::RenderWindow*);
};