#include <stdlib.h>
#include "FluidCube.h"
#include "lib.h"

FluidCube::FluidCube(int size, float diffusion, float viscosity, float dt)
{
	int N = size;
	this->size = size;
	this->dt = dt;
	this->diff = diffusion;
	this->visc = viscosity;

	this->s = (float *) calloc(N * N, sizeof(float));
	this->density = (float *) calloc(N * N, sizeof(float));

	this->Vx = (float*) calloc(N * N, sizeof(float));
	this->Vy = (float*) calloc(N * N, sizeof(float));

	this->Vx0 = (float*) calloc(N * N, sizeof(float));
	this->Vy0 = (float*) calloc(N * N, sizeof(float));

	r = (sf::RectangleShape*) calloc(N * N, sizeof(sf::RectangleShape));
	intitialise();
}

void FluidCube::intitialise()
{
	int i, j, N;
	N = this->size;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			r[IX(i, j)] = sf::RectangleShape(sf::Vector2f(W / N, H / N));
			r[IX(i, j)].setPosition(sf::Vector2f( i * W / N, j * H / N));
		}
	}
}

void FluidCube::step()
{
	int i, j, index;
	int N = this->size;
	float visc = this->visc;
	float diff = this->diff;
	float dt = this->dt;
	float* Vx = this->Vx;
	float* Vy = this->Vy;
	float* Vx0 = this->Vx0;
	float* Vy0 = this->Vy0;
	float* s = this->s;
	float* density = this->density;	
	diffuse(1, Vx0, Vx, visc, dt, 4, N);
	diffuse(2, Vy0, Vy, visc, dt, 4, N);
	project(Vx0, Vy0, Vx, Vy, 4, N);
	advect(1, Vx, Vx0, Vx0, Vy0, dt, N); 
	advect(2, Vy, Vy0, Vx0, Vy0, dt, N);

	project(Vx, Vy, Vx0, Vy0, 4, N);

	diffuse(0, s, density, diff, dt, 4, N);
	advect(0, density, s, Vx, Vy, dt, N);
}

void FluidCube::addDensity(int x, int y, float amount)
{
	density[IX(x, y)] += amount;
}

void FluidCube::addVelocity(int x, int y, float amountX, float amountY)
{
	int index = IX(x, y);

	Vx[index] += amountX;
	Vy[index] += amountY;
}

void FluidCube::render(sf::RenderWindow* window)
{
	int i, j, index, c;
	float d;
	float moy = 0;
	float max = 0;
	sf::RectangleShape rect;
	for (i = 0; i < this->size; i++)
	{
		for (j = 0; j < this->size; j++)
		{
			d = density[IX(i, j)];
			moy += d;
			if (d > max) max = d;
			c = (constraint(d, 0, 255) / 255) * 255;
			r[IX(i, j)].setFillColor(sf::Color(c, c, c));
			rect = r[IX(i, j)];
			(*window).draw(rect);
		}
	}
	moy = moy / (this->size * this->size);
	std::cout << "moy : " << moy << " , max = " << max << std::endl;
}