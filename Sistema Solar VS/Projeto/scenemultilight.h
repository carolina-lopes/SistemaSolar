#ifndef SCENEMULTILIGHT_H
#define SCENEMULTILIGHT_H

#include "scene.h"
#include "glslprogram.h"
#include "plane.h"
#include "objmesh.h"
#include <GLFW\glfw3.h>

#include "cookbookogl.h"

#include <C:\OpenGL\glm\glm\glm.hpp>

class SceneMultiLight : public Scene
{
private:
	GLSLProgram prog;
	std::unique_ptr<ObjMesh> sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune;

	GLubyte* texSun, * texMerc, * texVenu, * texEart, * texMars, * texJupi, * texSatu, * texUran, * texNept;

	GLint sSun, tSun, sMerc, tMerc, sVenu, tVenu, sEart, tEart, sMars, tMars, sJupi, tJupi, sSatu, tSatu, sUran, tUran, sNept, tNept;

	void setMatrices();
	void compileAndLinkShader();

	GLfloat MercuryAngle = 6.34f;
	GLfloat MercurySpeed = 4.74f;

	GLfloat VenusAngle = 2.19f;
	GLfloat VenusSpeed = 3.5f;

	GLfloat EarthAngle = 1.57f;
	GLfloat EarthSpeed = 2.98f;

	GLfloat MarsAngle = 1.67f;
	GLfloat MarsSpeed = 2.41f;

	GLfloat JupiterAngle = 0.32f;
	GLfloat JupiterSpeed = 1.31f;

	GLfloat SaturnAngle = 0.93f;
	GLfloat SaturnSpeed = 0.97f;

	GLfloat UranosAngle = 1.02f;
	GLfloat UranosSpeed = 0.68f;

	GLfloat NeptuneAngle = 0.72f;
	GLfloat NeptuneSpeed = 0.54f;



public:

	GLuint textL;

	SceneMultiLight();

	static void keyfunc(GLFWwindow*, int, int, int, int);
	void textureLoad(GLubyte*, int, int);

	void initScene();
	void update(float t);
	void render();
	void resize(int, int);
};

#endif // SCENEMULTILIGHT_H

