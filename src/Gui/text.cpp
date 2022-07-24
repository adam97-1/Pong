#include "Gui/text.h"
#include <iostream>
Text::Text()
{
    if(!m_font.loadFromFile("./Fonts/bit5x5.ttf"))
        std::cout << "loadFontsFromFile: false";
    this->setFont(m_font);
}
