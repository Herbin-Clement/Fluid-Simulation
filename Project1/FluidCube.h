#include <SFML/Graphics.hpp>
class FluidCube
{
	public:
		int size;
		float dt;
		float diff;
		float visc;

		float* s;
		float* density;
		
		float* Vx;
		float* Vy;

		float* Vx0;
		float* Vy0;
		
		sf::RectangleShape* r;
		void intitialise();
		FluidCube(int size, float diffusion, float viscosity, float dt);
		void step();
		void addDensity(int x, int y, float amount);
		void addVelocity(int x, int y, float amountX, float amountY);
		void render(sf::RenderWindow* window);
};

