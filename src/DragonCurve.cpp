#include"../include/DragonCurve.hpp"
#include<cmath>

const float PI = 3.141592;
const unsigned short LINE_LENGTH = 10;

DragonCurve::DragonCurve()
{
	lines_.setPrimitiveType(sf::Lines);
	lines_.append(sf::Vertex(sf::Vector2f(260, 270-LINE_LENGTH/2), sf::Color::Green));
	lines_.append(sf::Vertex(sf::Vector2f(260, 270+LINE_LENGTH/2), sf::Color::Green));
}

void DragonCurve::update()
{
	sf::Vertex temp[lines_.getVertexCount()];
	for(size_t i=0; i<lines_.getVertexCount(); i++) {
		temp[i] = lines_[i];
	}

	size_t vertex_count = lines_.getVertexCount();
	
	for(int i=0; i<vertex_count; i+=2) {
		sf::Vertex line[2];
		line[0].color = sf::Color::Green;
		line[1].color = sf::Color::Green;

		line[0].position = lines_[lines_.getVertexCount()-1].position;

		sf::Vector2f delta = lines_[vertex_count - i-1].position - lines_[vertex_count - i-2].position;
		float angle = -PI/2 + atan2(delta.y, delta.x);

		line[1].position = sf::Vector2f(LINE_LENGTH*cos(angle), LINE_LENGTH*sin(angle)) + line[0].position;

		lines_.append(line[0]);
		lines_.append(line[1]);
	}
}

void DragonCurve::render(sf::RenderWindow& window)
{
	window.draw(lines_);
}
