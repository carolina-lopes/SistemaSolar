#include "cookbookogl.h"
#include "scene.h"
#include <GLFW/glfw3.h>
#include "glutils.h"
#include "scenemultilight.h"
#include <iostream>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#include <map>
#include <string>

class SceneRunner {
private:
    GLFWwindow * window;
    int fbw, fbh;

public:
    SceneRunner(const std::string & windowTitle, int width = WIN_WIDTH, int height = WIN_HEIGHT, int samples = 0) {
        // Initialize GLFW
        if( !glfwInit() ) exit( EXIT_FAILURE );

#ifdef __APPLE__
        // Select OpenGL 4.1
        glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
        glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
#else
        // Select OpenGL 4.3
        glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
        glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
#endif
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
        if(samples > 0) {
            glfwWindowHint(GLFW_SAMPLES, samples);
        }

        // Open the window
        window = glfwCreateWindow( WIN_WIDTH, WIN_HEIGHT, windowTitle.c_str(), NULL, NULL );
        if( ! window ) {
            glfwTerminate();
            exit( EXIT_FAILURE );
        }
        glfwMakeContextCurrent(window);

        // Get framebuffer size
        glfwGetFramebufferSize(window, &fbw, &fbh);

        // Load the OpenGL functions.
        if(!gladLoadGL()) { exit(-1); }

        GLUtils::dumpGLInfo();

        // Initialization
        glClearColor(0.5f,0.5f,0.5f,1.0f);
#ifndef __APPLE__
        glDebugMessageCallback(GLUtils::debugCallback, NULL);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
        glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION, GL_DEBUG_TYPE_MARKER, 0,
		    GL_DEBUG_SEVERITY_NOTIFICATION, -1 , "Start debugging");
#endif
    }

    int run(Scene & scene) {
        scene.setDimensions(fbw, fbh);
        scene.initScene();
        scene.resize(fbw, fbh);
	
		glfwSetKeyCallback(window, SceneMultiLight::keyfunc);

        // Enter the main loop
        mainLoop(window, scene);

        // Close window and terminate GLFW
        glfwTerminate();

        // Exit program
        return EXIT_SUCCESS;
    }

    static std::string parseCLArgs(int argc, char ** argv, std::map<std::string, std::string> & sceneData) {
        if( argc < 2 ) {
            printHelpInfo(argv[0], sceneData);
            exit(EXIT_FAILURE);
        }

        std::string recipeName = argv[1];
        auto it = sceneData.find(recipeName);
        if( it == sceneData.end() ) {
            printf("Unknown recipe: %s\n\n", recipeName.c_str());
            printHelpInfo(argv[0], sceneData);
            exit(EXIT_FAILURE);
        }

        return recipeName;
    }

private:
    static void printHelpInfo(const char * exeFile,  std::map<std::string, std::string> & sceneData) {
        printf("Usage: %s recipe-name\n\n", exeFile);
        printf("Recipe names: \n");
        for( auto it : sceneData ) {
            printf("  %11s : %s\n", it.first.c_str(), it.second.c_str());
        }
    }

    void mainLoop(GLFWwindow * window, Scene & scene) {
        while( ! glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE) ) {
            GLUtils::checkForOpenGLError(__FILE__,__LINE__);
            scene.update(float(glfwGetTime()));
            scene.render();
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
};



void  SceneMultiLight::keyfunc(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		SceneMultiLight::paused = !SceneMultiLight::paused;

	}

	else if (key == GLFW_KEY_DOWN) {
		if(eyex<=1500.0f)
			eyex += 20.f;
	}
		
	else if (key == GLFW_KEY_UP) {
		if(eyex>=0.0f)
			eyex -= 20.f;
	}
		
	else if (key == GLFW_KEY_LEFT) {
		if(eyez<=150.0f)
			eyez += 20.f;
	}
		
	else if (key == GLFW_KEY_RIGHT)
	{
		if(eyez<=-150.0f)
			eyez -= 20.f;
	}
		

	else if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
		SceneMultiLight::checksun = !SceneMultiLight::checksun;

	else if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
		SceneMultiLight::checkmerc = !SceneMultiLight::checkmerc;

	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
		SceneMultiLight::checkvenus = !SceneMultiLight::checkvenus;

	else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
		SceneMultiLight::checkearth = !SceneMultiLight::checkearth;

	else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
		SceneMultiLight::checkmars = !SceneMultiLight::checkmars;

	else if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
		SceneMultiLight::checkjup = !SceneMultiLight::checkjup;

	else if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
		SceneMultiLight::checksat = !SceneMultiLight::checksat;

	else if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
		SceneMultiLight::checkurn = !SceneMultiLight::checkurn;

	else if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
		SceneMultiLight::checknep = !SceneMultiLight::checknep;


}