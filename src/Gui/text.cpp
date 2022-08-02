#include "Gui/text.h"
#include <iostream>
Text::Text()
{
    // Load font from file and sets font of the text.
    if(!m_font.loadFromFile("./Fonts/ayar.ttf"))
        std::cout << "loadFontsFromFile: false";
    this->setFont(m_font);
}
