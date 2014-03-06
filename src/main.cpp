#include"../include/DragonCurve.hpp"
#include<iostream>

int main()
{
	sf::RenderWindow 	window(sf::VideoMode(800, 600), sf::String("ZIGGYZAG"));;
	sf::Event			event;
	sf::Clock			clock;
	sf::Time			elapsed_time;

	DragonCurve 				zz;

	unsigned short		update_limit = 14;
	unsigned short		updates =0;

	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed) {
				window.close();
			} else if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			} else if(event.type == sf::Event::MouseWheelMoved) {
				sf::View view = window.getView();
				view.zoom(1-event.mouseWheel.delta/10);
				window.setView(view);
			}
		}

		elapsed_time += clock.restart();
		while(elapsed_time >= sf::milliseconds(400) && updates < update_limit)
		{
			zz.update();
			elapsed_time -= sf::milliseconds(400);
			updates++;
		}

		window.clear();
		zz.render(window);
		window.display();
	}
}
