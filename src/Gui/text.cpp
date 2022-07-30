#include "Gui/text.h"
#include <iostream>
Text::Text()
{
    // Try load font form file and sets font for text.
    if(!m_font.loadFromFile("./Fonts/bit5x5.ttf"))
        std::cout << "loadFontsFromFile: false";
    this->setFont(m_font);
}
