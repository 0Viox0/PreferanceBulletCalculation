#pragma once

#include "includes.h"

#include "TableButton.h"

class LetterButton : TableButton
{
private:
	char letterName;
	
	void initVariables();
public:
	//Constructor and destructor
	LetterButton(sf::Vector2f);
	~LetterButton();

	//getters
	const std::string getLetterName() const;

	
	//Fucntions
	void updateInput(sf::RenderWindow*) override;

	void getInputLetter();
	

	//Main functions
	void update(sf::RenderWindow*);
	void render(sf::RenderWindow*);
};