#include "Gui/graphicInterface.h"
#include <iostream>

int main()
{

    GraphicInteface graphicInterface;

    // run the program as long as the window is open
    while (graphicInterface.accessWindow().isOpen())
    {
        graphicInterface.updateGraphic();
        graphicInterface.accessWindow().display();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (graphicInterface.accessWindow().pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                graphicInterface.accessWindow().close();
        }
    }

    return 0;
}
