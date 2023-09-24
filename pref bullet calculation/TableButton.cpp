#include "TableButton.h"

void TableButton::initVariables()
{
	textString = "";
	value = 0;
	inputCooldown.restart();
	horizontalOffset = 15;
}

void TableButton::initShape(sf::Vector2f pos)
{
	butTexture.loadFromFile("Textures/tableButtonDesign.png");
	but.setTexture(butTexture);
	but.setScale(sf::Vector2f(0.1f, 0.1f));
	but.setPosition(pos);
	//but.setFillColor(sf::Color::White);
	//but.setSize(sf::Vector2f(60.f, 40.f));

	cursor.setPosition(but.getPosition());
}

void TableButton::initFontAndText()
{
	if (!font.loadFromFile("Fonts/Times New Romance.ttf"))
		std::cerr << "ERROR!!! TABLEBUTTON::INITFONTANDTEXT() -- could not open the file at 'Fonts/Times New Romance.ttf'\n";

	text.setFont(font);
	text.setString(textString);
	text.setFillColor(sf::Color::Black);
	text.setPosition(but.getPosition().x, but.getPosition().y + 5);
}

TableButton::TableButton(sf::Vector2f pos, std::string tag)
{
	initVariables();
	initShape(pos);
	initFontAndText();

	this->tag = tag;
}

TableButton::~TableButton()
{

}

//getters
std::string TableButton::getTag()
{
	return tag;
}

int TableButton::getValue()
{
	return value;
}


//Setters
void TableButton::setValueInt(int value)
{
	this->value = value;
}

void TableButton::updateCursor(sf::RenderWindow* window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (but.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			cursor.setCursor(false);
		}
		else
			cursor.setCursor(true);
	}
}

//Functions
void TableButton::updateInput(sf::RenderWindow* window)
{
	if (cursor.getCursorHidden() == false && inputCooldown.getElapsedTime().asSeconds() >= 0.15)
	{
		inputCooldown.restart();

		if (value * 10 < 1000)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
			{
				text.setString(text.getString() + "0");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				text.setString(text.getString() + "1");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				text.setString(text.getString() + "2");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			{
				text.setString(text.getString() + "3");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				text.setString(text.getString() + "4");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
			{
				text.setString(text.getString() + "5");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
			{
				text.setString(text.getString() + "6");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
			{
				text.setString(text.getString() + "7");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
			{
				text.setString(text.getString() + "8");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
			{
				text.setString(text.getString() + "9");
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
		{
			text.setString(text.getString().substring(0, text.getString().getSize() - 1));
		}

		if (!text.getString().isEmpty())
		{
			char* charStr = new char[text.getString().getSize()];

			for (int i = 0; i < text.getString().getSize(); i++)
				charStr[i] = text.getString().toAnsiString()[i];

			value = atoi(charStr);

			delete charStr;
		}
		else 
			value = 0;
		
		//std::cout << value << '\n';
	}
}


//Main functions
void TableButton::update(sf::RenderWindow* window)
{
	updateCursor(window);
	updateInput(window);
	cursor.update(window);

	cursor.setPosition(sf::Vector2f(
						but.getPosition().x + horizontalOffset * text.getString().getSize(), but.getPosition().y
						)
					);
}

void TableButton::render(sf::RenderWindow* window)
{
	window->draw(but);

	if (value != 0)
		window->draw(text);

	cursor.render(window);
}