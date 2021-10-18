#include <iostream> 
#include <SFML/Graphics.hpp>
#include <cmath>
#include "lib.h"
#include "FluidCube.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(W, H), "Title");

	sf::Event event;

	float theta;
	float coefficient;
	int frame;
	float vx;
	float vy;


	FluidCube fluid = FluidCube(S, 2.0f, 0.1f, 0.000001f);
	theta = 0.0f;
	coefficient = 10000.0f;
	frame = 1;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				fluid.addDensity((event.mouseButton.x * S/ W), (event.mouseButton.y * S / H), 100.0f);
			}
			else
			{
				fluid.addVelocity((event.mouseButton.x * S / W), (event.mouseButton.y * S / H), 0.0f, 100.0f);
			}
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Left)
			{
				theta -= degToRad(10.0f);
			}
			if (event.key.code == sf::Keyboard::Right)
			{
				theta += degToRad(10.0f);
			}
		}


		vx = cos(theta) * coefficient;
		vy = sin(theta) * coefficient;
		fluid.addDensity((int)S / 2, (int)S / 2, 150.0f);
		fluid.addVelocity((int) S / 2, (int) S / 2, vx, vy);
		fluid.step();
		fluid.render(&window);

		window.display();
		std::cout << "step " << frame++ << " -------------------------------------------------------------" << std::endl;
	}

	return 0;
}