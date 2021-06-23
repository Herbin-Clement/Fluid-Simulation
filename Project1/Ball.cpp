#include "Ball.h"

Ball::Ball(float x, float y, float Vx, float Vy, float Ax, float Ay)
{
	pos.x = x;
	pos.y = y;
	vel.x = Vx;
	vel.y = Vy;
	acc.x = Ax;
	acc.y = Ay;
}

Ball::Ball(sf::Vector2f p, sf::Vector2f v, sf::Vector2f a)
{
	pos = p;
	vel = v;
	acc = a;
}

sf::Vector2f Ball::getPos()
{
	return pos;
}

sf::Vector2f Ball::getVel()
{
	return vel;
}

sf::Vector2f Ball::getAcc()
{
	return acc;
}

void Ball::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Ball::setPos(sf::Vector2f p)
{
	pos = p;
}

void Ball::setVel(float x, float y)
{
	vel.x = x;
	vel.y = y;
}

void Ball::setVel(sf::Vector2f v)
{
	vel = v;
}

void Ball::setAcc(float x, float y)
{
	acc.x = x;
	acc.y = y;
}

void Ball::setAcc(sf::Vector2f a)
{
	acc = a;
}

void Ball::move()
{
	pos.x += vel.x;
	pos.y += vel.y;
	vel.x += acc.x;
	vel.y += acc.y;
}