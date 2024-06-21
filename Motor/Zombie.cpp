#include "Zombie.h"
#include <random>
#include <ctime>
#include<glm/gtx/rotate_vector.hpp>

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void Zombie::init(float speed, glm::vec2 position)
{
	this->speed = speed;
	this->position = position;
	color.set(24, 74, 2, 0.8);


}

void Zombie::update(vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies)
{
	std::mt19937 randomEngine(time(nullptr));
	std::uniform_real_distribution<float>randRotate(-40.0f, 40.0f);
	if (collideWithLevel(levelData)) {
		direction = glm::rotate(direction, randRotate(randomEngine));
	}
}
