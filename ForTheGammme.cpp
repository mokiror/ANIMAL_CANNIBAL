#include "ForTheGammme.hpp"


void ForTheGame()
{

    //����� ��������� ��������� ����������
    //������ �������� ���� ������
    for (int i = tailY; i > 0; i--)
    {
        s[i].snakeX = s[i - 1].snakeX;
        s[i].snakeY = s[i - 1].snakeY; 

    }

    //�������� ����
    if (tailX == 0)
    {
        s[0].snakeY += 1; //����
    }
    if (tailX == 1)
    {
        s[0].snakeX -= 1; //�����
    }
    if (tailX == 2)
    {
        s[0].snakeX += 1; //�����
    }
    if (tailX == 3)
    {
        s[0].snakeY -= 1; //�����
    }

    //����� ���� �� �������� �� ������
    if (s[0].snakeX > hight)
    {
        s[0].snakeX = 0;
    }
    if (s[0].snakeX < 0)
    {
        s[0].snakeX = hight;
    }
    if (s[0].snakeY > width)
    {
        s[0].snakeY = 0;
    }
    if (s[0].snakeY < 0)
    {
        s[0].snakeY = width;
    }

    //����������� � ������� 
    if ((s[0].snakeX == f.fruitX) && (s[0].snakeY == f.fruitY))
    {
        tailY++;

        //�������� ����������� �����
        f.fruitX = rand() % hight;
        f.fruitY = rand() % width;

    }

    //������� ���������
    for (int i = 1; i < tailY; i++)
    {
        if ((s[0].snakeX == s[i].snakeX) && (s[0].snakeY == s[i].snakeY))
        {
            endOfGame = false;
        }
    }

}

void ForTheGame2()
{
    //����� ��������� ��������� ����������
    //������ �������� ���� ������
    for (int i = tailY; i > 0; i--)
    {
        s[i].snakeX = s[i - 1].snakeX;
        s[i].snakeY = s[i - 1].snakeY;

    }

    //�������� ����
    if (tailX == 0)
    {
        s[0].snakeY += 1; //����
    }
    if (tailX == 1)
    {
        s[0].snakeX -= 1; //�����
    }
    if (tailX == 2)
    {
        s[0].snakeX += 1; //�����
    }
    if (tailX == 3)
    {
        s[0].snakeY -= 1; //�����
    }

    //����� �� ������ �� ��������
    if (s[0].snakeX > hight2)
    {
        s[0].snakeX = 0;
    }
    if (s[0].snakeX < 0)
    {
        s[0].snakeX = hight2;
    }
    if (s[0].snakeY > width2)
    {
        s[0].snakeY = 0;
    }
    if (s[0].snakeY < 0)
    {
        s[0].snakeY = width2;
    }


    //����������� �� ����� ������ 
    if ((s[0].snakeX == v.villianX) && (s[0].snakeY == v.villianY))
    {
        counterOfLives -= 1;

        //�������� ����������� �����
        v.villianX = rand() % hight2;
        v.villianY = rand() % width2;


        //�������� ����������� �����
        v2.villianX2 = rand() % hight2;
        v2.villianY2 = rand() % width2;

        //�������� ����������� �����
        f.fruitX = rand() % hight2;
        f.fruitY = rand() % width2;

    }

    //����������� �� ����� ������ 
    if ((s[0].snakeX == v2.villianX2) && (s[0].snakeY == v2.villianY2))
    {
        counterOfLives -= 1;

        //�������� ����������� �����
        v.villianX = rand() % hight2;
        v.villianY = rand() % width2;


        //�������� ����������� �����
        v2.villianX2 = rand() % hight2;
        v2.villianY2 = rand() % width2;

        //�������� ����������� �����
        f.fruitX = rand() % hight2;
        f.fruitY = rand() % width2;

    }


    //����������� � ������� 
    if ((s[0].snakeX == f.fruitX) && (s[0].snakeY == f.fruitY))
    {
        tailY++;

        //�������� ����������� �����
        f.fruitX = rand() % hight2;
        f.fruitY = rand() % width2;

        //�������� ����������� �����
        v.villianX = rand() % hight2;
        v.villianY = rand() % width2;

        //�������� ����������� �����
        v2.villianX2 = rand() % hight2;
        v2.villianY2 = rand() % width2;

    }

    if (counterOfLives == 0)
    {
        endOfGame = false;
    }

    //������� ���������
    for (int i = 1; i < tailY; i++)
    {
        if ((s[0].snakeX == s[i].snakeX) && (s[0].snakeY == s[i].snakeY) || (counterOfLives == 0))
        {
            endOfGame = false;
        }
    }

}


void StartGame01()
{
    RenderWindow window(VideoMode(hight * cube, width * cube), "ANIMAL_CANNIBAL");

    Texture ground;
    ground.loadFromFile("C:/Users/����/Desktop/tiles.png"); //��������� ����
    Sprite tiles(ground);

    Texture snake;
    snake.loadFromFile("C:/Users/����/Desktop/snake.png"); //��������� ����
    Sprite snakesss(snake);

    Texture apple;
    apple.loadFromFile("C:/Users/����/Desktop/Eggs.png"); //��������� ����
    Sprite applesss(apple);

    Texture gg;
    gg.loadFromFile("C:/Users/����/Desktop/gg.png"); //��������� ����
    Sprite gameOver(gg);
    gameOver.setPosition(-20, 0);

    Clock clock; //�������� �� ������� �����
    float timer = 0, delay = 0.2;


    while (window.isOpen())
    {
        for (int i = 0; i < hight; i++)
        {
            for (int j = 0; j < width; j++)
            {
                tiles.setPosition(i * cube, j * cube); //������� ������������ ������
                window.draw(tiles); //������ 
            }
        }

        //������� �����
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;


        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }


        //���������� ������� ����� ����������
        if (Keyboard::isKeyPressed(Keyboard::A)) //���� ������� ����� ������
        {
            tailX = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) //���� ������� ������ ������
        {
            tailX = 2;
        }
        if (Keyboard::isKeyPressed(Keyboard::W)) //���� ������� ����� ������
        {
            tailX = 3;
        }
        if (Keyboard::isKeyPressed(Keyboard::S))  //���� ������� ���� ������
        {
            tailX = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::X))  //���� ������� ���� ������
        {
            endOfGame = false;
            window.draw(gameOver);
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                window.close();
            }
        }


        if (timer > delay && endOfGame)
        {
            timer = 0;
            ForTheGame();
        }


        window.clear();


        //��������� ������ 
        for (int i = 0; i < hight; i++)
        {
            for (int j = 0; j < width; j++)
            {
                tiles.setPosition(i * cube, j * cube); //������� ������������ ������
                window.draw(tiles); //������ 
            }
        }


        //������ ����
        for (int i = 0; i < tailY; i++)
        {

            if (i != 0)
            {
                snakesss.setTextureRect(IntRect(0, 0, cube, cube));
            }
            else
            {
                snakesss.setTextureRect(IntRect(tailX * cube, cube, cube, cube));
            }

            snakesss.setPosition(s[i].snakeX * cube, s[i].snakeY * cube);
            window.draw(snakesss);


        }

        //������ ������
        applesss.setPosition(f.fruitX * cube, f.fruitY * cube);
        window.draw(applesss);

        //gg
        if (!endOfGame)
        {
            window.draw(gameOver);
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                window.close();
            }
        }

        window.display();
    }

}

void StartGame02()
{

    RenderWindow window(VideoMode(hight2 * cube, width2 * cube), "ANIMAL_CANNIBAL");

    Texture ground;
    ground.loadFromFile("C:/Users/����/Desktop/tiles.png"); //��������� ����
    Sprite tiles(ground);

    Texture snake;
    snake.loadFromFile("C:/Users/����/Desktop/snake.png"); //��������� ����
    Sprite snakesss(snake);

    Texture apple;
    apple.loadFromFile("C:/Users/����/Desktop/Eggs.png"); //��������� ����
    Sprite applesss(apple);

    Texture vil;
    vil.loadFromFile("C:/Users/����/Desktop/villian.png"); //��������� ����
    Sprite villian(vil);
    villian.setPosition(-20, 0);

    Texture gg;
    gg.loadFromFile("C:/Users/����/Desktop/gg.png"); //��������� ����
    Sprite gameOver(gg);
    gameOver.setPosition(-20, 0);

    Clock clock; //�������� �� ������� �����
    float timer = 0, delay = 0.2;

    //�������� ����������� ����
    v.villianX = rand() % hight2;
    v.villianY = rand() % width2;

    v2.villianX2 = rand() % hight2;
    v2.villianY2 = rand() % width2;


    while (window.isOpen())
    {
        for (int i = 0; i < hight2; i++)
        {
            for (int j = 0; j < width2; j++)
            {
                tiles.setPosition(i * cube, j * cube); //������� ������������ ������
                window.draw(tiles); //������ 
            }
        }

        //������� �����
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;


        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }


        //���������� ������� ����� ����������
        if (Keyboard::isKeyPressed(Keyboard::A)) //���� ������� ����� ������
        {
            tailX = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) //���� ������� ������ ������
        {
            tailX = 2;
        }
        if (Keyboard::isKeyPressed(Keyboard::W)) //���� ������� ����� ������
        {
            tailX = 3;
        }
        if (Keyboard::isKeyPressed(Keyboard::S))  //���� ������� ���� ������
        {
            tailX = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::X))  //���� ������� ���� ������
        {
            window.close();

            RenderWindow window(VideoMode(hight * cube, width * cube), "ANIMAL_CANNIBAL");

            Texture gg;
            gg.loadFromFile("C:/Users/����/Desktop/gg.png"); //��������� ����
            Sprite gameOver(gg);
            gameOver.setPosition(-20, 0);

            while (window.isOpen())
            {
                endOfGame = false;
                window.draw(gameOver);
                if (Keyboard::isKeyPressed(Keyboard::A))
                {
                    window.close();
                }

                window.display();
            }
        }

        if (timer > delay && endOfGame)
        {
            timer = 0;
            ForTheGame2();
        }

        window.clear();


        //��������� ������ 
        for (int i = 0; i < hight2; i++)
        {
            for (int j = 0; j < width2; j++)
            {
                tiles.setPosition(i * cube, j * cube); //������� ������������ ������
                window.draw(tiles); //������ 
            }
        }

        //������ ����
        for (int i = 0; i < tailY; i++)
        {
            if (i != 0)
            {
                snakesss.setTextureRect(IntRect(0, 0, cube, cube));
            }
            else
            {
                snakesss.setTextureRect(IntRect(tailX * cube, cube, cube, cube));
            }

            snakesss.setPosition(s[i].snakeX * cube, s[i].snakeY * cube);
            window.draw(snakesss);
        }

        //������ ������
        applesss.setPosition(f.fruitX * cube, f.fruitY * cube);
        window.draw(applesss);

        //������ ����
        villian.setPosition(v.villianX * cube, v.villianY * cube);
        window.draw(villian);

        //������ ����
        villian.setPosition(v2.villianX2 * cube, v2.villianY2 * cube);
        window.draw(villian);

        //gg
        if (!endOfGame)
        {
            window.close();

            RenderWindow window(VideoMode(hight * cube, width * cube), "ANIMAL_CANNIBAL");

            Texture gg;
            gg.loadFromFile("C:/Users/����/Desktop/gg.png"); //��������� ����
            Sprite gameOver(gg);
            gameOver.setPosition(-20, 0);

            while (window.isOpen())
            {
                window.draw(gameOver);
                if (Keyboard::isKeyPressed(Keyboard::A))
                {
                    window.close();
                }
                window.display();
            }

        }

        window.display();
    }
}
