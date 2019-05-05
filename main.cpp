#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "SnakeView.h"
#include "SnakeController.h"

int main() {
    srand(time(NULL));
    sf::Event event;
    int recSize = 40;
    int row=20,column=20;
    //--------------------------------------------------------------------------//
    sf::RenderWindow window(sf::VideoMode(recSize*row,recSize*column), "Snake");
    Snake snake(row,column,0,0);
    SnakeView snakeView(window, snake, recSize);
    SnakeController snakeController(snake, snakeView,window);
    snake.draw();
    while (window.isOpen()){
        while (window.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        snakeView.draw();
        snakeController.controllEvent(event);

        window.display();
    }

    return 0;

}