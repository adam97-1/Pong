#include "Gui/text.h"
#include <iostream>
Text::Text()
{
    // Load font from file and sets font of the text.
    if(!m_font.loadFromFile("./Fonts/ayar.ttf"))
        std::cout << "loadFontsFromFile: false";
    sf::Text::setFont(m_font);
}

bool Text::setFont(const std::string &filename)
{

    if(m_font.loadFromFile(filename))
    {
        sf::Text::setFont(m_font);
        return true;
    }
    else
        return false;
}
