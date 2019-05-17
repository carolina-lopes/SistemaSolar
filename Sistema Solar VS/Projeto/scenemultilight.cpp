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

bool paused = false;


SceneMultiLight::SceneMultiLight() :
	plane(10.0f, 10.0f, 10, 0)
{

	sun = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Sun\\Sun.obj", true);
	mercury = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Mercury\\Mercury.obj", true);
	venus = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Venus\\Venus.obj", true);
	earth = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Earth\\Earth.obj", true);
	mars = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Mars\\Mars.obj", true);
	jupiter = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Jupiter\\Jupiter.obj", true);
	saturn = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Saturn\\Saturn.obj", true);
	uranus = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Uranus\\Uranus.obj", true);
	neptune = ObjMesh::load("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\objects\\Neptune\\NEptune.obj", true);
	
	
}

void SceneMultiLight::initScene()
{
    compileAndLinkShader();

    glEnable(GL_DEPTH_TEST);

    view = glm::lookAt(vec3(150.f,50.f,-40.f), vec3(0.0f,0.0f,10.0f), vec3(0.0f,1.0f,0.0f));
    projection = mat4(1.0f);
	prog.setUniform("Light.Intensity", vec3(1.0f, 1.0f, 1.0f));
	
}

void SceneMultiLight::update( float t )
{
	
}

void SceneMultiLight::render()
{

	
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
	Texture::loadTexture("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_sun.jpg");
	setMatrices();
	sun->render();

	model = mat4(1.0f);
	model = glm::translate(model, vec3(0.f, 0.f, 57.f));//mudar o valor 15.f para um valor á escala (fazer com todos os outros translate )
	model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
	Texture::loadTexture("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_mercury.jpg");
	setMatrices();
	mercury->render();

	model = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 108.f));
	model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 18.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
	Texture::loadTexture("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_venus.jpg");
	setMatrices();
	venus->render();

	model = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 149.f));
	model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.003f, 0.003f, 0.003f));
	Texture::loadTexture("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_earth_daymap.jpg");
	setMatrices();
	earth->render();

	model = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 228.f));
	model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 25.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
	Texture::loadTexture("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_mars.jpg");
	setMatrices();
	mars->render();

	model = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 780.f));
	model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 17.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));
	Texture::loadTexture("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_jupiter.jpg");
	setMatrices();
	jupiter->render();


	model = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 1437.f));
	model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.03f, 0.03f, 0.03f));
	Texture::loadTexture("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_saturn.jpg");
	setMatrices();
	saturn->render();

	model = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 2871.f));
	model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 15.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.03f, 0.03f, 0.03f));
	Texture::loadTexture("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_uranus.jpg");
	setMatrices();
	uranus->render();

	model = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 4530.f));
	model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 15.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // REVER
	model = glm::scale(model, glm::vec3(0.03f, 0.03f, 0.03f));											   /// REVER
	Texture::loadTexture("C:\\Users\\carol\\Desktop\\Projeto\\Projeto\\Texturas\\2k_neptune.jpg");
	setMatrices();
	neptune->render();

	
}

void SceneMultiLight::setMatrices()
{
    mat4 mv = view * model;
    prog.setUniform("ModelViewMatrix", mv);
    prog.setUniform("NormalMatrix",
                    glm::mat3( vec3(mv[0]), vec3(mv[1]), vec3(mv[2]) ));
    prog.setUniform("MVP", projection * mv);
}

void SceneMultiLight::resize(int w, int h)
{
    glViewport(0,0,w,h);
    width = w;
    height = h;
    projection = glm::perspective(glm::radians(45.0f), (float)w/h, 0.1f, 10000.0f);
}

void SceneMultiLight::compileAndLinkShader()
{
	try {
		prog.compileShader("shader/multilight.vert");
		prog.compileShader("shader/multilight.frag");
    	prog.link();
    	prog.use();
    } catch(GLSLProgramException & e) {
 		cerr << e.what() << endl;
 		exit( EXIT_FAILURE );
    }
}
