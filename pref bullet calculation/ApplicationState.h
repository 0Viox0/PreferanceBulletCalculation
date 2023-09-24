#pragma once

#include "includes.h"

class ApplicationState
{
private:
	STATES applicatoinState;

	bool gameOver;

	void initVariables();
	void initApplicationState();

public:
	//Constructor and destructor
	ApplicationState();
	~ApplicationState();

	//setters
	void setGameOver(bool);

	//getters
	bool getGameOver();
	
	//getters
	STATES getState();

	//setters
	void setState(STATES);
};