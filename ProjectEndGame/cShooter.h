#pragma once
#include <glm/vec3.hpp>
#include <iostream>

class cShooter
{
public:
	void Shoot();
	glm::vec3 getPosition();
	void setPosition(glm::vec3 newPosition);
protected:
	glm::vec3 position;
};