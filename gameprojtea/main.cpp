#include "menugame.h"
#include "menugame.h"
using namespace sf;

int main() {
    int gamestate = 1;
    RenderWindow window(VideoMode(1082, 739), "NaHee");
    Menugame menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up || event.key.code == Keyboard::W) {
                    menu.moveup();
                }
                else if (event.key.code == Keyboard::Down || event.key.code == Keyboard::S) {
                    menu.movedown();
                }
                else if (event.key.code == Keyboard::Return) {
                    int pressed = menu.getPressed();
                    if (pressed == 0) {
                        std::cout << "play";
                    }
                    else if (pressed == 1) {
                        std::cout << "setting";
                    }
                    else if (pressed == 2) {
                        std::cout << "exit";
                        window.close();
                    }
                }
            }
        }

        window.clear();
        menu.render(window);
        window.display();
    }
    return 0;
}
