#include "LetterButton.h"


void LetterButton::initVariables()
{
	letterName = ' ';
    text.setString(" ");

    //but.setSize(sf::Vector2f(36.f, 40.f));

    but.setScale(sf::Vector2f(0.06f, 0.1f));
}

//Constructor and destructor
LetterButton::LetterButton(sf::Vector2f pos) : TableButton(pos, "Name letter")
{
	initVariables();
}

LetterButton::~LetterButton()
{

}

//getters
const std::string LetterButton::getLetterName() const
{
    return text.getString().toAnsiString();
}

//Fucntions
void LetterButton::updateInput(sf::RenderWindow*)
{
    getInputLetter();
}

void LetterButton::getInputLetter()
{
   // if (text.getString().getSize() == 0)
    if (cursor.getCursorHidden() == false)
        for (int key = sf::Keyboard::A; key <= sf::Keyboard::Z; key++)
        {
            if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key)))
            {
                //char letter = static_cast<char>(key + 65); // Converting key to ASCII letter

                //std::cout << "here";

                text.setString(char(int('A') + key));

                //std::cout << text.getString().toAnsiString() << '\n';

                //std::cout << "Inputted letter: " << letter << std::endl;
                break;
            }
        }

    if (cursor.getCursorHidden() == false)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
        {
            text.setString(" ");
        }
}

//Main functions
void LetterButton::update(sf::RenderWindow* window)
{
    TableButton::update(window);

    cursor.setPosition(sf::Vector2f(
        but.getPosition().x + horizontalOffset * (text.getString() == " " ? 0 : 2), but.getPosition().y
    ));
}

void LetterButton::render(sf::RenderWindow* window)
{
    //std::cout << text.getString().toAnsiString() << '\n';

	TableButton::render(window);
    window->draw(text);
}