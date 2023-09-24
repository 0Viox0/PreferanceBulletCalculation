#pragma once

#include "includes.h"

#include "TableButton.h"
#include "CenterButton.h"
#include "VistSetButton.h"
#include "LetterButton.h"

#include "ApplicationState.h"


class TableFor3
{
private:
	sf::Texture backgroundTexture;
	sf::Sprite background;

	//Buttons
	std::vector<TableButton*> buts;

	//Center button
	CenterButton centBut;

	//vist button
	VistSetButton* vistSetBut;

	//Letter name button
	LetterButton* but1;
	LetterButton* but2;
	LetterButton* but3;

	//Variables


	void initVariables();
	void initButtons();
	void initBackground();

public:
	//Constructor and destructor
	TableFor3();
	~TableFor3();

	//Functions

	//getters
	std::vector<TableButton*>& getButtons();
	VistSetButton* getVistButtons();
	//"b1" - for 1st button, "b2" - for 2dn button, "b3" - for 3rd button
	LetterButton& getLetterButton(std::string);


	//Main functions
	void update(sf::RenderWindow*, ApplicationState*, sf::Clock&, STATES&);
	void render(sf::RenderWindow*);
};