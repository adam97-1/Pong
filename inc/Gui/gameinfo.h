#ifndef GAMEINFO_H
#define GAMEINFO_H

#include <SFML/Graphics.hpp>
#include "Gui/view.h"


/*!
 * \brief The GameInfo class inherits from View.
 * This class contains all elements for display on main menu.
 */
class GameInfo : public View
{
public:
    GameInfo(sf::RenderWindow & window);
    GraphicView updateView();
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void handleInputKeyboard();
    void onSettingsChangeResolution(sf::VideoMode videoMode);
private:
    enum GameInfoOptions
    {
        InfoPlayer1,
        InfoPlayer2,
        InfoBack
    };

    void setTextString();
    void setMenuTextPosition();
};

#endif // GAMEINFO_H
