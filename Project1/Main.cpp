#include <iostream> 
#include <SFML/Graphics.hpp>

#include "lib.h"
#include "FluidCube.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(W, H), "Title");

	sf::Event event;

	int s = 1;
	FluidCube fluid = FluidCube(S, 10.0f, 0.1f, 0.000001f);

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
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				fluid.addDensity((event.mouseButton.x * S/ W), (event.mouseButton.y * S / H), 10000.0f);
			}
			else
			{
				fluid.addVelocity((event.mouseButton.x * S / W), (event.mouseButton.y * S / H), 0.0f, 100000.0f);
			}
		}

		fluid.addDensity((int)S / 2, (int)S / 2, 10000.0f);
		fluid.addVelocity((int) S / 2 + 1,(int) S / 2, 100000.0f, 0.0f);
		fluid.step();
		fluid.render(&window);
		//std::cout << "step " << s++ << " -------------------------------------------------------------" << std::endl;
		window.display();
	}

	return 0;
}