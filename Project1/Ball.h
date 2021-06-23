#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>


class Ball
{
	private:
		sf::Vector2f acc;
		sf::Vector2f vel;
		sf::Vector2f pos;

	public:
		Ball(float x, float y, float Vx, float Vy, float Ax, float Ay);
		Ball(sf::Vector2f p, sf::Vector2f v, sf::Vector2f a);
		sf::Vector2f getPos();
		sf::Vector2f getVel();
		sf::Vector2f getAcc();
		void setPos(float x, float y);
		void setPos(sf::Vector2f p);
		void setVel(float x, float y);
		void setVel(sf::Vector2f v);
		void setAcc(float x, float y);
		void setAcc(sf::Vector2f a);
		void move();
		void display();
};


#endif // !BALL_H