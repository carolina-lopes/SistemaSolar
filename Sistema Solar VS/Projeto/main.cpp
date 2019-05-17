#include "scene.h"
#include "scenerunner.h"
#include "scenemultilight.h"
#define GLEW_STATIC


int main(int argc, char *argv[])
{

	SceneRunner runner("SolarSystem");
	std::unique_ptr<Scene> scene;
	scene = std::unique_ptr<Scene>(new SceneMultiLight());

	return runner.run(*scene);
}
