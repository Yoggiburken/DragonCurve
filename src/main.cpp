#include"../include/DragonCurve.hpp"
#include<iostream>

int main()
{
	sf::RenderWindow 	window(sf::VideoMode(800, 600), sf::String("ZIGGYZAG"), sf::Style::Default, sf::ContextSettings(0, 0, 8, 2, 0));;
	window.setVerticalSyncEnabled(true);
	sf::Event			event;
	sf::Clock			clock;
	sf::Time			elapsed_time;
	sf::Time			curve_update;

	DragonCurve 				zz;
	float				zoomlevel = 1;

	unsigned short		update_limit = 18;
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
			}
		}

		elapsed_time += clock.restart();
		while(elapsed_time >= sf::milliseconds(16))
		{
			curve_update += elapsed_time;
			if(updates < update_limit && curve_update >= sf::milliseconds(500)) {
				zz.update();
				updates++;
				curve_update -= sf::milliseconds(500);
			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					sf::View view = window.getView();
					view.zoom(0.9);
					zoomlevel *=0.9;
					window.setView(view);
			} 
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					sf::View view = window.getView();
					view.zoom(1.1);
					zoomlevel *=1.1;
					window.setView(view);
			} 
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					sf::View view = window.getView();
					view.move(sf::Vector2f(0, -5*zoomlevel));
					window.setView(view);
			} 
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					sf::View view = window.getView();
					view.move(sf::Vector2f(0, 5*zoomlevel));
					window.setView(view);
			} 
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					sf::View view = window.getView();
					view.move(sf::Vector2f(-5*zoomlevel, 0));
					window.setView(view);
			} 
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					sf::View view = window.getView();
					view.move(sf::Vector2f(5*zoomlevel, 0));
					window.setView(view);
			}
			elapsed_time -= sf::milliseconds(16);
		}

		window.clear();
		zz.render(window);
		window.display();
	}
}
