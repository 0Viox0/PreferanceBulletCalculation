#pragma once

#include "includes.h"

#include "TableButton.h"
#include "CenterButton.h"
#include "VistSetButton.h"
#include "LetterButton.h"

class TableFor4
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
	LetterButton* but4;

	//Variables


	void initVariables();
	void initButton();
	void initBackground();
public:
	//Constructor and destructor
	TableFor4();
	~TableFor4();

	//getters
	std::vector<TableButton*>& getButtons();
	VistSetButton* getVistButtons();
	LetterButton& getLetterButton(std::string);

	//Fucntions



	//Main functions
	void update(sf::RenderWindow* window, ApplicationState* as, sf::Clock& escapeCooldown, STATES&);
	void render(sf::RenderWindow*);
};