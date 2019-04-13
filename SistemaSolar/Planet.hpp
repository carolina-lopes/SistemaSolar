#pragma once
#include <iostream>
#include <string>
#include <C:\OpenGL\glm\glm\glm.hpp>
#define GLM_SWIZZLE

class Planet {
	float distance;// distance from sun
	float radius;// radius of planet
	float angle; // angle of inclination
	float velocity;// velocity of rotation
	glm::vec3 location;// location in view
	//Acrescentar textura


public:

	Planet(float distance, float radius, float angle, float velocity, glm::vec3 location);
	float getdistance();
	float getradius();
	float getangle();
	float getvelocity();
	glm::vec3 getlocation();
	
};