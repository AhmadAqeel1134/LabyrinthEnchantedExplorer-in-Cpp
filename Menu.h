#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Game.h"
#include <fstream>
#include <string>
#include <sstream>


using namespace sf;
using namespace std;

class Menu {
public:
    Sprite mBack, iBack, aBack;
    Texture mBack_text, iBack_text, aBack_text;


    Menu() {
        mBack_text.loadFromFile("IMG/backgroung.png");
        iBack_text.loadFromFile("IMG/back.png");
        aBack_text.loadFromFile("IMG/back.png");

        mBack.setTexture(mBack_text);
        iBack.setTexture(iBack_text);
        aBack.setTexture(aBack_text);

    }

    void display()
    {
        Game g;
        RenderWindow window(VideoMode(550, 550), "Game Menu");
        Font font1, font2;
        font1.loadFromFile("font/KnightWarrior.otf");
        font2.loadFromFile("font/Raleway.ttf");

        SoundBuffer audio1, audio2;
        audio1.loadFromFile("audio/button_sound_01.wav");
        audio2.loadFromFile("audio/button_sound_02.wav");

        Sound sound1, sound2;
        sound1.setBuffer(audio1);
        sound2.setBuffer(audio2);

        Music m1;
        m1.openFromFile("audio/MainMenu.ogg");
        bool isMouseOverPlay = false;
        bool isMouseOverHighScore = false;
        bool isMouseOverInstructions = false;
        bool isMouseOverAbout = false;
        bool isMouseOverQuit = false;

        Color lightGrey(220, 220, 220, 250);
        Color paleGreen(152, 251, 152, 250);
        Color paleRed(240, 128, 128, 250);

        Text playText("Play", font1, 48);
        playText.setFillColor(paleGreen);
        playText.setPosition(window.getSize().x / 2 - playText.getGlobalBounds().width / 2, 200);


        Text highScoreText("High Score", font1, 48);
        highScoreText.setFillColor(lightGrey);
        highScoreText.setPosition(window.getSize().x / 2 - highScoreText.getGlobalBounds().width / 2, 250);

        Text instructText("Instructions", font1, 48);
        instructText.setFillColor(lightGrey);
        instructText.setPosition(window.getSize().x / 2 - instructText.getGlobalBounds().width / 2, 300);

        Text aboutText("About", font1, 48);
        aboutText.setFillColor(lightGrey);
        aboutText.setPosition(window.getSize().x / 2 - aboutText.getGlobalBounds().width / 2, 350);

        Text quitText("Quit", font1, 48);
        quitText.setFillColor(paleRed);
        quitText.setPosition(window.getSize().x / 2 - quitText.getGlobalBounds().width / 2, 400);
     
        m1.play();
        while (window.isOpen())
        {
            if (playText.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
            {
                if (!isMouseOverPlay)
                {
                    sound1.play();
                    isMouseOverPlay = true;
                }
                playText.setFillColor(Color::Green);
            }
            else
            {
                isMouseOverPlay = false;
                playText.setFillColor(paleGreen);
            }

            if (highScoreText.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
            {
                if (!isMouseOverHighScore)
                {
                    sound1.play();
                    isMouseOverHighScore = true;
                }
                highScoreText.setFillColor(Color::White);
            }
            else
            {
                isMouseOverHighScore = false;
                highScoreText.setFillColor(lightGrey);
            }

            if (instructText.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
            {
                if (!isMouseOverInstructions)
                {
                    sound1.play();
                    isMouseOverInstructions = true;
                }
                instructText.setFillColor(Color::White);
            }
            else
            {
                isMouseOverInstructions = false;
                instructText.setFillColor(lightGrey);
            }

            if (aboutText.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
            {
                if (!isMouseOverAbout)
                {
                    sound1.play();
                    isMouseOverAbout = true;
                }
                aboutText.setFillColor(Color::White);
            }
            else
            {
                isMouseOverAbout = false;
                aboutText.setFillColor(lightGrey);
            }

            if (quitText.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
            {
                if (!isMouseOverQuit)
                {
                    sound1.play();
                    isMouseOverQuit = true;
                }
                quitText.setFillColor(Color::Red);
            }
            else
            {
                isMouseOverQuit = false;
                quitText.setFillColor(paleRed);
            }


            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) {
                    window.close();
                }
            }
            if (e.type == Event::MouseButtonPressed)
            {
                if (e.mouseButton.button == Mouse::Left)
                {
                    if (playText.getGlobalBounds().contains(Vector2f(e.mouseButton.x, e.mouseButton.y)))
                    {
                        cout << "Play Button Clicked" << endl;
                        sound2.play();
                        m1.stop();
                        //starting game
                        g.startGame();
                    }
                    else if (highScoreText.getGlobalBounds().contains(Vector2f(e.mouseButton.x, e.mouseButton.y)))
                    {
                        cout << "High Score Button Clicked" << endl;
                        sound2.play();
                        ifstream file("high_score.txt");
                        if (!file.is_open())
                        {
                            cout << "Error opening file" << endl;
                        }
                        RenderWindow window(VideoMode(550, 550), "Highest Score ", Style::Close);
                        Text  hst;
                        hst.setFont(font1);
                        hst.setCharacterSize(24);
                        hst.setFillColor(Color::White);
                        hst.setPosition(100, 250);

                        string line;
                        string  hs;
                        hs = "The highest score ever made is: ";
                        while (getline(file, line)) {
                            hs += line + "\n";
                        }
                        hst.setString(hs);


                        while (window.isOpen()) {
                            Event e;
                            while (window.pollEvent(e)) {
                                if (e.type == Event::Closed)
                                    window.close();
                            }

                            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                                return;
                            }

                            window.clear(Color::Black);
                            window.draw(hst);
                            window.display();
                        }
                        //show high scores
                    }
                    else if (instructText.getGlobalBounds().contains(Vector2f(e.mouseButton.x, e.mouseButton.y)))
                    {
                        cout << "Instructions Button Clicked" << endl;
                        sound2.play();
                        //show instructions
                        RenderWindow window_ins(VideoMode(550, 550), "Instructions");

                        Text headText("INSTRUCTIONS", font1, 60);
                        headText.setFillColor(Color::White);
                        headText.setPosition(window_ins.getSize().x / 2 - headText.getGlobalBounds().width / 2, 50);

                        Text insText(
                            "Labyrinth Enchanted Explorer\nMove through the maze and reach end\nTake the items to ease your path \n"
                            "Here's how to play:\n"
                            "- Use the arrow keys control your player \n"
                            "- Avoid the enemy. If you hit enemy\n you lose a life!\n"
                            "- Collect power-ups along the way to help you in your journey.\n Power-ups can give you abilities \nlike speed boost and life etc.\n"
                            "Remember, stay safe and have fun!", font2, 24);
                        insText.setFillColor(Color::White);
                        insText.setOutlineThickness(2);
                        insText.setPosition(50, 150);

                        while (window_ins.isOpen())
                        {
                            Event i;
                            while (window_ins.pollEvent(i))
                            {
                                if (i.type == Event::Closed)
                                    window_ins.close();
                            }
                            if (Keyboard::isKeyPressed(Keyboard::BackSpace))
                                window_ins.close();
                            window_ins.clear(Color::Black);
                            window_ins.draw(iBack);
                            window_ins.draw(headText);
                            window_ins.draw(insText);
                            window_ins.display();
                        }
                    }
                    else if (aboutText.getGlobalBounds().contains(Vector2f(e.mouseButton.x, e.mouseButton.y)))
                    {
                        cout << "About Button Clicked" << endl;
                        sound2.play();
                        RenderWindow window_abt(VideoMode(550, 550), "About");

                        Text headtext("ABOUT", font1, 60);
                        headtext.setFillColor(Color::White);
                        headtext.setPosition(window_abt.getSize().x / 2 - headtext.getGlobalBounds().width / 2, 50);

                        Text abtText(
                            "Labyrinth Enchanted Explorer is an immersive\n adventure and game set in a magical maze\n filled with mysteries.\n"
                            "Embark on a journey through winding paths \nhidden passages to uncover enchanted treasures.\n"
                            "Explore this captivating labyrinth created\n by our talented team.\n"
                            "Remember, embrace the magic\nEnjoy your exploration!", font2, 20);

                        abtText.setFillColor(Color::White);
                        abtText.setOutlineThickness(2);
                        abtText.setPosition(50, 150);


                        while (window_abt.isOpen())
                        {
                            Event i;
                            while (window_abt.pollEvent(i))
                            {
                                if (i.type == Event::Closed)
                                    window_abt.close();

                            }
                            if (Keyboard::isKeyPressed(Keyboard::BackSpace))
                                window_abt.close();
                            window_abt.clear(Color::Black);
                            window_abt.draw(iBack);
                            window_abt.draw(abtText);
                            window_abt.draw(headtext);
                            window_abt.display();
                        }
                    }
                    else if (quitText.getGlobalBounds().contains(Vector2f(e.mouseButton.x, e.mouseButton.y)))
                    {
                        cout << "Quit Button Clicked" << endl;
                        sound2.play();
                        m1.stop();
                        //exit game;
                        window.close();
                    }
                }
            }
            window.clear(Color::Black);
            window.draw(mBack);
            window.draw(playText);
            window.draw(highScoreText);
            window.draw(instructText);
            window.draw(aboutText);
            window.draw(quitText);
            window.display();
        }
    }
};
