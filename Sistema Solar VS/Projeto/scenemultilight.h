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

    Plane plane;
    std::unique_ptr<ObjMesh> sun, mercury, venus, earth , mars, jupiter, saturn, uranus, neptune;

    void setMatrices();
    void compileAndLinkShader();

public:


    SceneMultiLight();

	static void keyfunc(GLFWwindow*, int, int, int, int);

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};

#endif // SCENEMULTILIGHT_H
