#include "ApplicationState.h"

void ApplicationState::initVariables()
{
	gameOver = false;
}

void ApplicationState::initApplicationState()
{
	applicatoinState = MAIN_MENU;
}


//Constructor and destructor
ApplicationState::ApplicationState()
{
	initVariables();
	initApplicationState();
}

ApplicationState::~ApplicationState()
{

}

//setters
void ApplicationState::setGameOver(bool value)
{
	gameOver = value;
}

bool ApplicationState::getGameOver()
{
	return gameOver;
}

STATES ApplicationState::getState()
{
	return applicatoinState;
}

void ApplicationState::setState(STATES value)
{
	applicatoinState = value;
}