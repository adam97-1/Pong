#ifndef MAINMENU_H
#define MAINMENU_H

#include <vector>
#include <Gui/view.h>
#include <Gui/text.h>

/*!
 * \brief The MainMenu class inherit from View.
 * This class contains all elements for display on main menu.
 */
class MainMenu : public View
{
public:
    MainMenu();

private:
    Text m_title;                       //! Object display title of view.
    std::vector<Text> m_menuOptions;    //! Object display all options in menu.
};

#endif // MAINMENU_H
