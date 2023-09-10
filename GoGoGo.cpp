#include "GoGoGo.hpp"


void GoGoGo()
{
    RenderWindow window(VideoMode(hight * cube, width * cube), "ANIMAL_CANNIBAL");

    Texture menu;
    menu.loadFromFile("C:/Users/����/Desktop/menu.png"); //��������� ����
    Sprite menuuu(menu);
    menuuu.setPosition(-20, 0);

    Texture second;
    second.loadFromFile("C:/Users/����/Desktop/second.png"); //��������� ����
    Sprite secondMenu(second);
    secondMenu.setPosition(-20, 0);

    Texture gg;
    gg.loadFromFile("C:/Users/����/Desktop/gg.png"); //��������� ����
    Sprite gameOver(gg);
    gameOver.setPosition(-20, 0);

    Texture set;
    set.loadFromFile("C:/Users/����/Desktop/settt.png"); //��������� ����
    Sprite settings(set);
    settings.setPosition(-20, 0);


    Clock clock; //�������� �� ������� �����
    float timer = 0, delay = 0.2;

    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window.close();
        }
    }

    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    while (window.isOpen())
    {


        window.draw(menuuu);

        if (Keyboard::isKeyPressed(Keyboard::Tab))
        {
            window.draw(secondMenu);
            if (Keyboard::isKeyPressed(Keyboard::Q))
            {
                StartGame01();
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::W))
            {
                StartGame02();
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::E))
            {
                window.draw(settings);
            }
            if (Keyboard::isKeyPressed(Keyboard::R))
            {
                window.close();
            }
        }

        window.display();
    }

}