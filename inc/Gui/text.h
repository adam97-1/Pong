#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>

/*!
 * \brief The Text class inherit from <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Text.php">sf::Text</a>.
 * This class sets text style to default.
 */
class Text : public sf::Text
{
public:
    /*!
     * \brief Text is a default constructor.
     * It loads default text font.
     */
    Text();
    bool setFont(const std::string &filename);

private:
    sf::Font m_font;        //! Font of the text
};

#endif // TEXT_H
