#include "Planet.hpp"

Planet::Planet(float distance, float radius, float angle, float velocity, glm::vec3 location) {
	this->distance = distance;
	this->radius = radius;
	this->angle = angle;
	this->velocity = velocity;
	this->location = location;

}

float Planet::getdistance() {
	return this->distance;
}

float Planet::getradius() {
	return this->radius;
}

float Planet::getangle() {
	return this->angle;
}

float Planet::getvelocity() {
	return this->velocity;
}

glm::vec3 Planet::getlocation() {
	return (this->location);
};

/*float Planet::getlocationY() {
	return (this->location.y);
};

float Planet::getlocationZ() {
	return this->location.z;
};*/
