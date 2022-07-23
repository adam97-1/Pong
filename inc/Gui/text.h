#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>

/*!
 * \brief The Text class inherit from <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Text.php">sf::Text</a>.
 * This class sets text on default settings, such as style of font, size of character, color etc.
 */
class Text : public sf::Text
{
public:
    Text();

private:
    sf::Font m_font;
};

#endif // TEXT_H
