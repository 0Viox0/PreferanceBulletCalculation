#include "TableFor4.h"

void TableFor4::initVariables()
{

}

void TableFor4::initButton()
{
	std::string str[16];

	str[0] = "Player 1 hill"; str[1] = "Player 1-2 vists"; str[2] = "Player 1-3 vists"; str[3] = "Player 1-4 vists";
	str[4] = "Player 2 hill"; str[5] = "Player 2-1 vists"; str[6] = "Player 2-3 vists"; str[7] = "Player 2-4 vists";
	str[8] = "Player 3 hill"; str[9] = "Player 3-1 vists"; str[10] = "Player 3-2 vists"; str[11] = "Player 3-4 vists";
	str[12] = "Player 4 hill"; str[13] = "Player 4-1 vists"; str[14] = "Player 4-2 vists"; str[15] = "Player 4-3 vists";

	buts.push_back(new TableButton(sf::Vector2f(425, 300), str[0]));
	buts.push_back(new TableButton(sf::Vector2f(425, 165), "dummy bullet"));
	buts.push_back(new TableButton(sf::Vector2f(425, 50), str[2]));
	buts.push_back(new TableButton(sf::Vector2f(150, 50), str[3]));
	buts.push_back(new TableButton(sf::Vector2f(700, 50), str[1]));
	
	//------------------------------------------------------------------------------
	
	buts.push_back(new TableButton(sf::Vector2f(575, 450), str[4]));
	buts.push_back(new TableButton(sf::Vector2f(693, 450), "dummy bullet"));
	buts.push_back(new TableButton(sf::Vector2f(800, 450), str[7]));
	buts.push_back(new TableButton(sf::Vector2f(800, 190), str[5]));
	buts.push_back(new TableButton(sf::Vector2f(800, 720), str[6]));

	//-----------------------------------------------------------------------------

	buts.push_back(new TableButton(sf::Vector2f(425, 610), str[8]));
	buts.push_back(new TableButton(sf::Vector2f(425, 740), "dummy bullet"));
	buts.push_back(new TableButton(sf::Vector2f(425, 855), str[9]));
	buts.push_back(new TableButton(sf::Vector2f(150, 855), str[11]));
	buts.push_back(new TableButton(sf::Vector2f(700, 855), str[10]));

	//-----------------------------------------------------------------------------

	buts.push_back(new TableButton(sf::Vector2f(265, 450), str[12]));
	buts.push_back(new TableButton(sf::Vector2f(149, 450), "dummy bullet"));
	buts.push_back(new TableButton(sf::Vector2f(40, 450), str[14]));
	buts.push_back(new TableButton(sf::Vector2f(40, 720), str[15]));
	buts.push_back(new TableButton(sf::Vector2f(40, 190), str[13]));

	////////////////////////////////////////////////////////////////////////////////////

	vistSetBut = new VistSetButton(sf::Vector2f(565, 300));

	////////////////////////////////////////////////////////////////////////////////////

	but1 = new LetterButton(sf::Vector2f(433, 410));
	but2 = new LetterButton(sf::Vector2f(480, 455));
	but3 = new LetterButton(sf::Vector2f(433, 500));
	but4 = new LetterButton(sf::Vector2f(388, 455));
}


void TableFor4::initBackground()
{
	if (!backgroundTexture.loadFromFile("Textures/4-way_bullet.png"))
		std::cerr << "ERROR!!! TABLEFOR4::INITBACKGROUND -- could not load the file at 'Textures/4-way_bullet.png'\n";

	background.setTexture(backgroundTexture);
}

//Constructor and destructor
TableFor4::TableFor4()
{
	initVariables();
	initButton();
	initBackground();
}

TableFor4::~TableFor4()
{
	for (int i = 0; i < buts.size(); i++)
		delete buts[i];
	
	buts.clear();
	
	delete vistSetBut;
	
	delete but1;
	delete but2;
	delete but3;
}

//getters
std::vector<TableButton*>& TableFor4::getButtons()
{
	return buts;
}

VistSetButton* TableFor4::getVistButtons()
{
	return vistSetBut;
}

LetterButton& TableFor4::getLetterButton(std::string butName)
{

	if (butName == "b1") return *but1;
	else if (butName == "b2") return *but2;
	else if (butName == "b3") return *but3;
	else if (butName == "b4") return *but4;
	else std::cerr << "ERROR!!! TABLEFOR3::GETLETTERBUTTON(STD::STRING) -- uknown butName parameter!\n";
}

//Main functions
void TableFor4::update(sf::RenderWindow* window, ApplicationState* as, sf::Clock& escapeCooldown, STATES& lastExitedState)
{
	for (int i = 0; i < buts.size(); i++)
		buts[i]->update(window);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && escapeCooldown.getElapsedTime().asSeconds() >= 0.2f)
	{
		escapeCooldown.restart();
		lastExitedState = STATES::PEOPLE_4;
		as->setState(STATES::PAUSE_MENU);
	}
	
	centBut.update(window, as);
	lastExitedState = STATES::PEOPLE_4;
	
	vistSetBut->update(window);
	
	but1->update(window);
	but2->update(window);
	but3->update(window);
	but4->update(window);
}

void TableFor4::render(sf::RenderWindow* window)
{
	window->draw(background);

	for (int i = 0; i < buts.size(); i++)
		buts[i]->render(window);

	vistSetBut->render(window);
	
	but1->render(window);
	but2->render(window);
	but3->render(window);
	but4->render(window);

	centBut.render(window);
}