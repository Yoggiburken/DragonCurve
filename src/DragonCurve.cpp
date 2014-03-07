#include"../include/DragonCurve.hpp"
#include<cmath>

const float PI = 3.141592;
const unsigned short LINE_LENGTH = 10;

DragonCurve::DragonCurve()
{
	lines_.setPrimitiveType(sf::LinesStrip);
	lines_.append(sf::Vertex(sf::Vector2f(260, 270-LINE_LENGTH/2), sf::Color::Green));
	lines_.append(sf::Vertex(sf::Vector2f(260, 270+LINE_LENGTH/2), sf::Color::Green));
}

void DragonCurve::update()
{
	size_t vertex_count = lines_.getVertexCount();
	
	for(int i=0; i<vertex_count-1; i++) {
		sf::Vertex line;
		line.color = sf::Color::Green;

		sf::Vector2f delta = lines_[vertex_count - i-1].position - lines_[vertex_count - i-2].position;
		float angle = -PI/2 + atan2(delta.y, delta.x);

		line.position = sf::Vector2f(LINE_LENGTH*cos(angle), LINE_LENGTH*sin(angle)) + lines_[lines_.getVertexCount()-1].position;

		lines_.append(line);
	}
}

void DragonCurve::render(sf::RenderWindow& window)
{
	window.draw(lines_);
}
