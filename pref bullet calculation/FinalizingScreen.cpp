#include "FinalizingScreen.h"

void FinalizingScreen::initVariables()
{

}

void FinalizingScreen::initRect()
{
	rect.setSize(sf::Vector2f(600, 600));
	rect.setPosition(sf::Vector2f(450 - rect.getGlobalBounds().width / 2, 
								475 - rect.getGlobalBounds().height / 2));
	rect.setFillColor(sf::Color(0, 0, 0, 100));
}

void FinalizingScreen::initText()
{
	if (!font.loadFromFile("Fonts/Times New Romance.ttf"))
		std::cerr << "ERROR!!! FINALIZINGSCREEN::INITTEXT() -- could not open the file at 'Fonts/Times New Romance.ttf'\n";

	results.setFont(font);
	results.setPosition(rect.getPosition().x + rect.getSize().x / 2 - 100, 
						rect.getPosition().y + rect.getSize().y / 2 - 50);
	results.setCharacterSize(50);
	results.setFillColor(sf::Color::Black);
}

//Constructor and destructor
FinalizingScreen::FinalizingScreen(std::vector<TableButton*>& buts, VistSetButton* vistSetBut)
{
	initVariables();
	initRect();

	initText();

	calc = new CalculatorFor3(
		"bruh1", findValueByTag(buts, "Player 1 hill"), findValueByTag(buts, "Player 1-2 vists"), findValueByTag(buts, "Player 1-3 vists"),
		"bruh2", findValueByTag(buts, "Player 2 hill"), findValueByTag(buts, "Player 2-3 vists"), findValueByTag(buts, "Player 2-1 vists"),
		"bruh3", findValueByTag(buts, "Player 3 hill"), findValueByTag(buts, "Player 3-1 vists"), findValueByTag(buts, "Player 3-2 vists"));


	calc2 = new CalculatorFor4(
		"bruh1", findValueByTag(buts, "Player 1 hill"), findValueByTag(buts, "Player 1-4 vists"), findValueByTag(buts, "Player 1-3 vists"), findValueByTag(buts, "Player 1-2 vists"),
		"bruh2", findValueByTag(buts, "Player 2 hill"), findValueByTag(buts, "Player 2-3 vists"), findValueByTag(buts, "Player 2-4 vists"), findValueByTag(buts, "Player 2-1 vists"),
		"bruh3", findValueByTag(buts, "Player 3 hill"), findValueByTag(buts, "Player 3-4 vists"), findValueByTag(buts, "Player 3-1 vists"), findValueByTag(buts, "Player 3-2 vists"),
		"bruh4", findValueByTag(buts, "Player 4 hill"), findValueByTag(buts, "Player 4-1 vists"), findValueByTag(buts, "Player 4-2 vists"), findValueByTag(buts, "Player 4-3 vists")
	);

}

FinalizingScreen::~FinalizingScreen()
{
	delete calc;
	delete calc2;
}

int FinalizingScreen::findValueByTag(std::vector<TableButton*>& buts, std::string tagToFind)
{
	for (int i = 0; i < buts.size(); i++)
	{
		//std::cout << buts[i]->getTag() << " and " << tagToFind << '\n';
		if (buts[i]->getTag() == tagToFind) { return buts[i]->getValue(); }
	}

	//std::cout << "\n-------------------\n";
}


//Main functions
void FinalizingScreen::update(sf::Clock& escapeButtonCooldown, ApplicationState* as, 
							std::vector<TableButton*>& buts, VistSetButton* vistSetBut,
							LetterButton& lb1, LetterButton& lb2, LetterButton& lb3)
{
	//calculate and update text here
	result res;

	std::string str[12];

	str[0] = "Player 1 hill"; str[1] = "Player 1-2 vists"; str[2] = "Player 1-3 vists";
	str[3] = "Player 2 hill"; str[4] = "Player 2-3 vists"; str[5] = "Player 2-1 vists";
	str[6] = "Player 3 hill"; str[7] = "Player 3-1 vists"; str[8] = "Player 3-2 vists";

	res = calc->calculate(
		lb1.getLetterName(), findValueByTag(buts, str[0]), findValueByTag(buts, str[1]), findValueByTag(buts, str[2]),
		lb2.getLetterName() , findValueByTag(buts, str[3]), findValueByTag(buts, str[4]), findValueByTag(buts, str[5]),
		lb3.getLetterName(), findValueByTag(buts, str[6]), findValueByTag(buts, str[7]), findValueByTag(buts, str[8]));


	results.setString(
		res.player[0].nameOfThePlayer + ":	" + std::to_string(res.player[0].res * vistSetBut->getValue()) + '\n' +
		res.player[1].nameOfThePlayer + ":	" + std::to_string(res.player[1].res * vistSetBut->getValue()) + '\n' +
		res.player[2].nameOfThePlayer + ":	" + std::to_string(res.player[2].res * vistSetBut->getValue()) + '\n');

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && escapeButtonCooldown.getElapsedTime().asSeconds() >= 0.2)
	{
		escapeButtonCooldown.restart();
		as->setState(STATES::MAIN_MENU);
	}
}

void FinalizingScreen::update2(sf::Clock& escapeButtonCooldown, ApplicationState* as,
							std::vector<TableButton*>& buts, VistSetButton* vistSetBut,
							LetterButton& lb1, LetterButton& lb2, LetterButton& lb3, LetterButton& lb4)
{
	//calculate and update text here
	result2 res;

	std::string str[16];

	str[0] = "Player 1 hill"; str[1] = "Player 1-2 vists"; str[2] = "Player 1-3 vists"; str[3] = "Player 1-4 vists";
	str[4] = "Player 2 hill"; str[5] = "Player 2-1 vists"; str[6] = "Player 2-3 vists"; str[7] = "Player 2-4 vists";
	str[8] = "Player 3 hill"; str[9] = "Player 3-1 vists"; str[10] = "Player 3-2 vists"; str[11] = "Player 3-4 vists";
	str[12] = "Player 4 hill"; str[13] = "Player 4-1 vists"; str[14] = "Player 4-2 vists"; str[15] = "Player 4-3 vists";

	res = calc2->calculate(
		lb1.getLetterName(), findValueByTag(buts, str[0]), findValueByTag(buts, str[3]), findValueByTag(buts, str[2]), findValueByTag(buts, str[1]),
		lb2.getLetterName(), findValueByTag(buts, str[4]), findValueByTag(buts, str[6]), findValueByTag(buts, str[7]), findValueByTag(buts, str[5]),
		lb3.getLetterName(), findValueByTag(buts, str[8]), findValueByTag(buts, str[11]), findValueByTag(buts, str[9]), findValueByTag(buts, str[10]),
		lb4.getLetterName(), findValueByTag(buts, str[12]), findValueByTag(buts, str[13]), findValueByTag(buts, str[14]), findValueByTag(buts, str[15])
	);

	results.setString(
		res.player[0].nameOfThePlayer + ":	" + std::to_string(res.player[0].res * vistSetBut->getValue()) + '\n' +
		res.player[1].nameOfThePlayer + ":	" + std::to_string(res.player[1].res * vistSetBut->getValue()) + '\n' +
		res.player[2].nameOfThePlayer + ":	" + std::to_string(res.player[2].res * vistSetBut->getValue()) + '\n' +
		res.player[3].nameOfThePlayer + ":	" + std::to_string(res.player[3].res * vistSetBut->getValue()) + '\n');


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && escapeButtonCooldown.getElapsedTime().asSeconds() >= 0.2)
	{
		escapeButtonCooldown.restart();
		as->setState(STATES::MAIN_MENU);
	}
}

void FinalizingScreen::render(sf::RenderWindow* window)
{
	window->draw(rect);
	window->draw(results);

	//std::cout << results.getString().toAnsiString() << '\n';
}