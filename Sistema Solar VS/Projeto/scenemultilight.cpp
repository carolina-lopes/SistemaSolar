#include "scenemultilight.h"
#include "texture.h"
#include "sphere.h"
#include "stb/stb_image.h"
#include <GLFW\glfw3.h>
#define GLEW_STATIC

#include <sstream>
#include <iostream>

using std::endl;
using std::cerr;

#include <C:\OpenGL\glm\glm\gtc\matrix_transform.hpp>
#include<GLFW/glfw3.h>
using glm::vec3;
using glm::mat4;

bool SceneMultiLight::paused = false;


SceneMultiLight::SceneMultiLight()
{

	sun = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Sun\\Sun.obj", true);
	texSun = Texture::loadPixels("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_sun.jpg", sSun, tSun);
	

	mercury = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Mercury\\Mercury.obj", true);
	texMerc = Texture::loadPixels("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_mercury.jpg", sMerc, tMerc);


	venus = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Venus\\Venus.obj", true);
	texVenu = Texture::loadPixels("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_venus.jpg", sVenu, tVenu);
	

	earth = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Earth\\Earth.obj", true);
	texEart = Texture::loadPixels("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_earth_daymap.jpg", sEart, tEart);


	mars = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Mars\\Mars.obj", true);
	texMars = Texture::loadPixels("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_mars.jpg", sMars, tMars);
	

	jupiter = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Jupiter\\Jupiter.obj", true);
	texJupi = Texture::loadPixels("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_jupiter.jpg", sJupi, tJupi);


	saturn = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Saturn\\Saturn.obj", true);
	texSatu = Texture::loadPixels("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_saturn.jpg", sSatu, tSatu);
	

	uranus = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Uranus\\Uranus.obj", true);
	texUran = Texture::loadPixels("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_uranus.jpg", sUran, tUran);


	neptune = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Neptune\\NEptune.obj", true);
	texNept = Texture::loadPixels("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_neptune.jpg", sNept, tNept);
}

void SceneMultiLight::initScene()
{
	compileAndLinkShader();
	glEnable(GL_DEPTH_TEST);

	view = glm::lookAt(vec3(150.f, 50.f, -150.f), vec3(0.0f, 0.0f, 10.0f), vec3(0.0f, 1.0f, 0.0f));
	projection = mat4(1.0f);
	prog.setUniform("Light.Intensity", vec3(1.0f, 1.0f, 1.0f));
	glGenTextures(1, &textL);

}

void SceneMultiLight::update(float t)
{

}

void SceneMultiLight::render()
{

	if (SceneMultiLight::paused == false) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glClearColor(0.f, 0.f, 0.f, 0.f);


		prog.setUniform("Light.Position", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
		prog.setUniform("Material.Kd", 1.f, 1.f, 1.f);
		prog.setUniform("Material.Ks", 1.f, 1.f, 1.f);
		prog.setUniform("Material.Ka", 0.1f, 0.1f, 0.1f);
		prog.setUniform("Material.Shininess", 100.0f);

		model = mat4(1.0f);
		model = glm::translate(model, vec3(.0f, .0f, 0.0f));
		model = glm::scale(glm::mat4(1.f), glm::vec3(0.1f, 0.1f, 0.1f));
		textureLoad(texSun, sSun, tSun);
		setMatrices();
		sun->render();

		MercuryAngle += MercurySpeed;
		while (MercuryAngle > 360.0)
			MercuryAngle -= 360.0;
		float temp1Angle = (MercuryAngle / 180.0) * 3.14159;
		model = glm::translate(glm::mat4(1.f), glm::vec3(sin(temp1Angle) * 57.9f, 0.f, cos(temp1Angle) * 57.9f));
		model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
		textureLoad(texMerc, sMerc, tMerc);
		setMatrices();
		mercury->render();


		VenusAngle += VenusSpeed;
		while (VenusAngle > 360.0)
			VenusAngle -= 360.0;
		float temp2Angle = (VenusAngle / 180.0) * 3.14159;
		model = glm::translate(glm::mat4(1.f), glm::vec3(sin(temp2Angle) * 108.2f, 0.f, cos(temp2Angle) * 108.2f));
		model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 18.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
		textureLoad(texVenu, sVenu, tVenu);
		setMatrices();
		venus->render();


		EarthAngle += EarthSpeed;
		while (EarthAngle > 360.0)
			EarthAngle -= 360.0;
		float temp3Angle = (EarthAngle / 180.0) * 3.14159;
		model = glm::translate(glm::mat4(1.f), glm::vec3(sin(temp3Angle) * 149.6f, 0.f, cos(temp3Angle) * 149.6f));
		model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.003f, 0.003f, 0.003f));
		textureLoad(texEart, sEart, tEart);
		setMatrices();
		earth->render();

		MarsAngle += MarsSpeed;
		while (MarsAngle > 360.0)
			MarsAngle -= 360.0;
		float temp4Angle = (MarsAngle / 180.0) * 3.14159;
		model = glm::translate(glm::mat4(1.f), glm::vec3(sin(temp4Angle) * 227.9f, 0.f, cos(temp4Angle) * 227.9f));
		model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 25.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
		textureLoad(texMars, sMars, tMars);
		setMatrices();
		mars->render();

		JupiterAngle += JupiterSpeed;
		while (JupiterAngle > 360.0)
			JupiterAngle -= 360.0;
		float temp5Angle = (JupiterAngle / 180.0) * 3.14159;
		model = glm::translate(glm::mat4(1.f), glm::vec3(sin(temp5Angle) * 778.3f, 0.f, cos(temp5Angle) * 778.3f));
		model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 17.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));
		Texture::loadTexture(texJupi, sJupi, tJupi);
		setMatrices();
		jupiter->render();


		SaturnAngle += SaturnSpeed;
		while (SaturnAngle > 360.0)
			SaturnAngle -= 360.0;
		float temp6Angle = (SaturnAngle / 180.0) * 3.14159;
		model = glm::translate(glm::mat4(1.f), glm::vec3(sin(temp6Angle) * 1427.f, 0.f, cos(temp6Angle) * 1427.f));
		model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.03f, 0.03f, 0.03f));
		textureLoad(texSatu, sSatu, tSatu);
		setMatrices();
		saturn->render();

		UranosAngle += UranosSpeed;
		while (UranosAngle > 360.0)
			UranosAngle -= 360.0;
		float temp7Angle = (UranosAngle / 180.0) * 3.14159;
		model = glm::translate(glm::mat4(1.f), glm::vec3(sin(temp7Angle) * 2871.f, 0.f, cos(temp7Angle) * 2871.f));
		model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 15.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.03f, 0.03f, 0.03f));
		textureLoad(texUran, sUran, tUran);
		setMatrices();
		uranus->render();


		NeptuneAngle += NeptuneSpeed;
		while (NeptuneAngle > 360.0)
			NeptuneAngle -= 360.0;
		float temp8Angle = (NeptuneAngle / 180.0) * 3.14159;
		model = glm::translate(glm::mat4(1.f), glm::vec3(sin(temp8Angle) * 4497.f, 0.f, cos(temp8Angle) * 4497.f));
		model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 15.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.03f, 0.03f, 0.03f));
		textureLoad(texNept, sNept, tNept);
		setMatrices();
		neptune->render();
	}

}

void SceneMultiLight::setMatrices()
{
	mat4 mv = view * model;
	prog.setUniform("ModelViewMatrix", mv);
	prog.setUniform("NormalMatrix",
		glm::mat3(vec3(mv[0]), vec3(mv[1]), vec3(mv[2])));
	prog.setUniform("MVP", projection * mv);
}

void SceneMultiLight::resize(int w, int h)
{
	glViewport(0, 0, w, h);
	width = w;
	height = h;
	projection = glm::perspective(glm::radians(70.0f), (float)w / h, 0.1f, 10000.0f);
}

void SceneMultiLight::compileAndLinkShader()
{
	try {
		prog.compileShader("shader/multilight.vert");
		prog.compileShader("shader/multilight.frag");
		prog.link();
		prog.use();
	}
	catch (GLSLProgramException & e) {
		cerr << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

void SceneMultiLight::textureLoad(GLubyte* data, int width, int height) {

	glBindTexture(GL_TEXTURE_2D, textL);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

}


