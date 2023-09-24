#include "TableFor3.h"

void TableFor3::initVariables()
{

}

void TableFor3::initButtons()
{
	//but = new TableButton(sf::Vector2f(300, 300));

	std::string str[12];

	str[0] = "Player 1 hill"; str[1] = "Player 1-2 vists"; str[2] = "Player 1-3 vists";
	str[3] = "Player 2 hill"; str[4] = "Player 2-3 vists"; str[5] = "Player 2-1 vists";
	str[6] = "Player 3 hill"; str[7] = "Player 3-1 vists"; str[8] = "Player 3-2 vists";

	buts.push_back(new TableButton(sf::Vector2f(300, 300), str[6]));
	buts.push_back(new TableButton(sf::Vector2f(35, 200), str[7]));
	buts.push_back(new TableButton(sf::Vector2f(35, 650), str[8]));
	buts.push_back(new TableButton(sf::Vector2f(150, 400), "Player 3 bullet"));

	//------------------------------------------------------------------------------

	buts.push_back(new TableButton(sf::Vector2f(540, 300), str[0]));
	buts.push_back(new TableButton(sf::Vector2f(805, 200), str[2]));
	buts.push_back(new TableButton(sf::Vector2f(805, 650), str[1]));
	buts.push_back(new TableButton(sf::Vector2f(695, 400), "Player 3 bullet"));

	//-----------------------------------------------------------------------------

	buts.push_back(new TableButton(sf::Vector2f(420, 610), str[3]));
	buts.push_back(new TableButton(sf::Vector2f(230, 850),str[4]));
	buts.push_back(new TableButton(sf::Vector2f(610, 850), str[5]));
	buts.push_back(new TableButton(sf::Vector2f(420, 740), "Player 2 bullet"));

	////////////////////////////////////////////////////////////////////////////////////

	vistSetBut = new VistSetButton(sf::Vector2f(425, 50));

	////////////////////////////////////////////////////////////////////////////////////

	but1 = new LetterButton(sf::Vector2f(465, 420));
	but2 = new LetterButton(sf::Vector2f(405, 420));
	but3 = new LetterButton(sf::Vector2f(435, 500));
}

void TableFor3::initBackground()
{
	if (!backgroundTexture.loadFromFile("Textures/3-way_bullet.png"))
	{
		std::cerr << "ERROR!!! TABLEFOR3::INITBACKGROUND() -- could not load from file at 'Textures/3-way_bullet.png'\n";
	}

	background.setTexture(backgroundTexture);
}

//Constructor and destructor
TableFor3::TableFor3()
{
	initVariables();
	initButtons();
	initBackground();
}

TableFor3::~TableFor3()
{
	for (int i = 0; i < buts.size(); i++)
		delete buts[i];

	buts.clear();

	delete vistSetBut;

	delete but1;
	delete but2;
	delete but3;
}

std::vector<TableButton*>& TableFor3::getButtons()
{
	return buts;
}

VistSetButton* TableFor3::getVistButtons()
{
	return vistSetBut;
}

LetterButton& TableFor3::getLetterButton(std::string butName)
{
	if (butName == "b1") return *but1;
	else if (butName == "b2") return *but2;
	else if (butName == "b3") return *but3;
	else std::cerr << "ERROR!!! TABLEFOR3::GETLETTERBUTTON(STD::STRING) -- uknown butName parameter!\n";
}


//Main functions
void TableFor3::update(sf::RenderWindow* window, ApplicationState* as, sf::Clock& escapeCooldown, STATES& lastExitedState)
{
	for (int i = 0; i < buts.size(); i++)
		buts[i]->update(window);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && escapeCooldown.getElapsedTime().asSeconds() >= 0.2f)
	{
		escapeCooldown.restart();
		lastExitedState = STATES::PEOPLE_3;
		as->setState(STATES::PAUSE_MENU);
	}

	centBut.update(window, as);
	lastExitedState = STATES::PEOPLE_3;

	vistSetBut->update(window);

	but1->update(window);
	but2->update(window);
	but3->update(window);
}

void TableFor3::render(sf::RenderWindow* window)
{
	window->draw(background);


	for (int i = 0; i < buts.size(); i++)
		buts[i]->render(window);

	vistSetBut->render(window);

	but1->render(window);
	but2->render(window);
	but3->render(window);

	centBut.render(window);
}