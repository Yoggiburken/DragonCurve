#ifndef DRAGON_CURVE_HPP
#define DRAGON_CURVE_HPP

#include<SFML/Graphics.hpp>

class DragonCurve {
public:
							DragonCurve();

	void					update();
	void					render(sf::RenderWindow& window);
private:
	sf::VertexArray			lines_;
};

#endif
