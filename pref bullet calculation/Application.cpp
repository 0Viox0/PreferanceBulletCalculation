#include "Application.h"

void Application::initVariables()
{
	escapeCooldown.restart();
	resolution = sf::VideoMode(900, 950);
	lastExitedState = STATES::PEOPLE_3;
}

void Application::initWindow()
{
	window = new sf::RenderWindow(resolution, "pref", sf::Style::Close);
}

//Constructor and destructor
Application::Application()
{
	applicationState = new ApplicationState();

	initVariables();
	initWindow();

	mainMenu = new MainMenu(window);
	pauseMenu = new PauseMenu(window);

	finalizingScreen = new FinalizingScreen(tableFor3.getButtons(), tableFor3.getVistButtons());
}

Application::~Application()
{
	delete window;

	delete mainMenu;
	delete pauseMenu;

	delete applicationState;
}

//Accessors
bool Application::isRunning()
{
	return window->isOpen() && !applicationState->getGameOver();
}


//Main functions
void Application::run()
{
	update();
	render();
}

void Application::eventLoop()
{
	while (window->pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed) window->close();
	}
}

void Application::update()
{
	eventLoop();

	switch (applicationState->getState())
	{
	case STATES::MAIN_MENU:
		mainMenu->update(window, applicationState);
		break;
	case STATES::SETTING:
		settings.update();
		break;
	case STATES::PEOPLE_3:
		tableFor3.update(window, applicationState, escapeCooldown, lastExitedState);
		break;
	case STATES::PEOPLE_4:
		tableFor4.update(window, applicationState, escapeCooldown, lastExitedState);
		break;
	case STATES::PAUSE_MENU:
		pauseMenu->update(window, applicationState, escapeCooldown, lastExitedState);
		break;
	case STATES::FINALIZING_SCREEN:
		if (lastExitedState == STATES::PEOPLE_3)
			finalizingScreen->update(escapeCooldown, applicationState, tableFor3.getButtons(), tableFor3.getVistButtons(),
										tableFor3.getLetterButton("b1"),
										tableFor3.getLetterButton("b2"),
										tableFor3.getLetterButton("b3"));
		else if (lastExitedState == STATES::PEOPLE_4)
			finalizingScreen->update2(escapeCooldown, applicationState, tableFor4.getButtons(), tableFor4.getVistButtons(),
										tableFor4.getLetterButton("b1"),
										tableFor4.getLetterButton("b2"),
										tableFor4.getLetterButton("b3"),
										tableFor4.getLetterButton("b4")
				);
	}	
}

void Application::render()
{
	window->clear();

	switch (applicationState->getState())
	{
	case STATES::MAIN_MENU:
		mainMenu->render(window);
		break;
	case STATES::SETTING:
		settings.render();
		break;
	case STATES::PEOPLE_3:
		tableFor3.render(window);
		break;
	case STATES::PEOPLE_4:
		tableFor4.render(window);
		break;
	case STATES::PAUSE_MENU:
		if (lastExitedState == STATES::PEOPLE_3)
			tableFor3.render(window);
		else if (lastExitedState == STATES::PEOPLE_4)
			tableFor4.render(window);

		pauseMenu->render(window);
		break;
	case  STATES::FINALIZING_SCREEN:
		if (lastExitedState == STATES::PEOPLE_3)
			tableFor3.render(window);
		else if (lastExitedState == STATES::PEOPLE_4)
			tableFor4.render(window);

		finalizingScreen->render(window);
		break;
	}

	window->display();
}