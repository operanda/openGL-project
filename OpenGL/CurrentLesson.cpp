#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <shaders.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <camera1.h>

using namespace std;

int superkey = 0;
int width = 1200;
int height = 1000;

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = width / 2.0f;
float lastY = height / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;


//Shader ourShader("vertex.vs", "fragment.fs");



void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        superkey = 1;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

class doggo
{
public:
    int count = 1, count2 = 0, count3 = 1;
    float a = 0.01, b = 0, c = 0, d = 0, z = 0.1, g = 0;
   // Shader ourShader;
    unsigned int VAOfrontLegs, VAObackLegs, VAOhips, VAObody, VAOchest, VAOhead[2], VAOears;
    unsigned int VBOfrontLegs, VBObackLegs, VBOhips, VBObody, VBOchest, VBOhead[2], VBOears;
    float currentFrame;
 
   
 

    doggo() 
    {
        float hips[] = {
-0.77f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
-0.70f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
-0.70f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
-0.70f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,

-0.77f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
-0.70f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
-0.70f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
-0.70f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,

-0.73f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
-0.73f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
-0.73f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
-0.73f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
-0.73f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,
-0.73f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,

-0.77f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
-0.77f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
-0.77f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
-0.77f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,

-0.77f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
-0.73f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
-0.73f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
-0.73f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,

-0.77f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
-0.73f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
-0.73f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
-0.77f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
-0.73f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
-0.77f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,

     -0.77f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
-0.70f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
-0.70f, -0.2f, 0.23f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
-0.70f, -0.2f, 0.23f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.2f, 0.23f, 0.36f, 0.25f, 0.2f,

-0.77f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
-0.70f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
-0.70f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
-0.70f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,

-0.73f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
-0.73f, -0.5f, 0.25f, 0.0f, 0.0f, 0.0f,
-0.73f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
-0.73f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
-0.73f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,
-0.73f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,

-0.77f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.5f, 0.25f, 0.0f, 0.0f, 0.0f,
-0.77f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
-0.77f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
-0.77f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,

-0.77f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
-0.73f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
-0.73f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
-0.73f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,
-0.77f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,

-0.77f, -0.5f, 0.25f, 0.0f, 0.0f, 0.0f,
-0.73f, -0.5f, 0.25f, 0.0f, 0.0f, 0.0f,
-0.73f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
-0.77f, -0.5f, 0.25f, 0.0f, 0.0f, 0.0f,
-0.73f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
-0.77f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
        };
        //backlegs 
        float backlegs[] = {
            -0.80f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,

            -0.80f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,

            -0.80f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,

            -0.80f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,

            -0.65f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,

            -0.80f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,

                    -0.80f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,

            -0.80f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,

            -0.80f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,

            -0.80f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,

            -0.65f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.65f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.65f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,

            -0.80f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,
        };
        //body
        float body[] = {
            -0.80f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
            -0.35f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
            -0.80f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
            -0.35f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
            -0.27f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,

            -0.80f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
            -0.35f, -0.15f, 0.35f, 0.0f, 0.0f, 0.0f,
            -0.80f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,
            -0.35f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
            -0.27f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,

            -0.80f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
            -0.27f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
            -0.27f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
            -0.27f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,
            -0.80f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,

            -0.80f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
            -0.35f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
            -0.35f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
            -0.80f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
            -0.35f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
            -0.80f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,

            -0.27f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
            -0.35f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
            -0.35f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
            -0.27f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
            -0.35f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
            -0.27f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,

            -0.80f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
            -0.80f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
            -0.80f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
            -0.80f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
            -0.80f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,
        };
        //chest
        float chest[] = {
            -0.25f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
            -0.38f, -0.21f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.1f,  -0.18f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.25f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
            -0.1f,  -0.18f, 0.68f, 0.0f, 0.0f, 0.0f,
             0.03f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,

            -0.25f,  0.17f, 0.23f, 0.36f, 0.25f, 0.2f,
            -0.38f, -0.21f, 0.23f, 0.0f,  0.0f, 0.0f,
            -0.1f,  -0.18f, 0.23f, 0.0f,  0.0f, 0.0f,
            -0.25f,  0.17f, 0.23f, 0.36f, 0.25f, 0.2f,
            -0.1f,  -0.18f, 0.23f, 0.0f,  0.0f, 0.0f,
             0.03f,  0.17f, 0.23f, 0.36f, 0.25f, 0.2f,

            -0.25f, 0.17f, 0.23f, 0.36f, 0.25f, 0.2f,
            -0.25f, 0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
            -0.25f, 0.17f, 0.23f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.23f, 0.36f, 0.25f, 0.2f,

            -0.38f, -0.21f, 0.23f, 0.0f, 0.0f, 0.0f,
            -0.38f, -0.21f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.1f,  -0.18f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.38f, -0.21f, 0.23f, 0.0f, 0.0f, 0.0f,
            -0.1f,  -0.18f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.1f,  -0.18f, 0.23f, 0.0f, 0.0f, 0.0f,

             0.03f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
            -0.1f,  -0.18f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.1f,  -0.18f, 0.23f, 0.0f, 0.0f, 0.0f,
             0.03f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
            -0.1f,  -0.18f, 0.23f, 0.0f, 0.0f, 0.0f,
             0.03f,  0.17f, 0.23f, 0.36f, 0.25f, 0.2f,

            -0.25f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
            -0.38f, -0.21f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.38f, -0.21f, 0.23f, 0.0f, 0.0f, 0.0f,
            -0.25f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
            -0.38f, -0.21f, 0.23f, 0.0f, 0.0f, 0.0f,
            -0.25f,  0.17f, 0.23f, 0.36f, 0.25f, 0.2f,
        };  
        //frontlegs
        float frontlegs[] = {
            -0.21f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
            -0.21f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f, 
            -0.12f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
            -0.21f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
            -0.12f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
            -0.12f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,

            -0.21f,  0.1f, 0.68f, 0.1f, 0.0f, 0.0f,
            -0.21f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.12f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.21f,  0.1f, 0.68f, 0.1f, 0.0f, 0.0f,
            -0.12f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.12f,  0.1f, 0.68f, 0.1f, 0.0f, 0.0f,

            -0.21f,  0.1f, 0.68f, 0.36f, 0.25f, 0.2f,
            -0.21f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
            -0.12f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
            -0.21f,  0.1f, 0.68f, 0.36f, 0.25f, 0.2f,
            -0.12f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
            -0.12f,  0.1f, 0.68f, 0.36f, 0.25f, 0.2f,

            -0.21f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.21f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
            -0.12f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
            -0.21f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.12f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
            -0.12f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,

            -0.12f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
            -0.12f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
            -0.12f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.12f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
            -0.12f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.12f,  0.1f, 0.68f, 0.36f, 0.25f, 0.2f,

            -0.21f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
            -0.21f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
            -0.21f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.21f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
            -0.21f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
            -0.21f,  0.1f, 0.68f, 0.36f, 0.25f, 0.2f,

                    -0.21f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
            -0.21f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
            -0.12f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
            -0.21f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
            -0.12f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
            -0.12f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,

            -0.21f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,
            -0.21f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
            -0.12f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
            -0.21f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,
            -0.12f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
            -0.12f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,

            -0.21f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,
            -0.21f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
            -0.12f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
            -0.21f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,  
            -0.12f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
            -0.12f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,

            -0.21f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
            -0.21f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
            -0.12f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
            -0.21f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
            -0.12f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
            -0.12f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,

            -0.12f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
            -0.12f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
            -0.12f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
            -0.12f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
            -0.12f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
            -0.12f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,

            -0.21f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
            -0.21f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
            -0.21f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
            -0.21f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
            -0.21f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
            -0.21f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,

        };
        //head
        float head[] = {
            -0.13f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,

            -0.13f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,

            -0.13f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,

            -0.13f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,

             0.03f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
             0.03f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,

            -0.13f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
            -0.13f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,


        };
        //morda
        float morda[] = {
             0.03f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,

             0.03f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,

             0.03f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.1f,  0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,

             0.03f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,

             0.15f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.15f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,

             0.03f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
             0.03f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,

        }; //
        //ears
        float ears[] = {
           -0.13f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,

           -0.13f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,

           -0.13f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,

           -0.13f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,

           -0.06f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,


           -0.13f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,


                   -0.13f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,

           -0.13f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,

           -0.13f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,

           -0.13f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,

           -0.06f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.06f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,


           -0.13f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
           -0.13f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,





        };
        glGenVertexArrays(1, &VAOfrontLegs);
        glGenVertexArrays(1, &VAObackLegs);
        glGenVertexArrays(1, &VAObody);
        glGenVertexArrays(2, VAOhead);
        glGenVertexArrays(1, &VAOears);
        glGenVertexArrays(1, &VAOchest);
        glGenVertexArrays(1, &VAOhips);
        glGenBuffers(1, &VBOfrontLegs);
        glGenBuffers(1, &VBObackLegs);
        glGenBuffers(1, &VBObody);
        glGenBuffers(1, &VBOchest);
        glGenBuffers(1, &VBOhips);
        glGenBuffers(2, VBOhead);
        glGenBuffers(1, &VBOears);



        glBindVertexArray(VAOfrontLegs);

        glBindBuffer(GL_ARRAY_BUFFER, VBOfrontLegs);
        glBufferData(GL_ARRAY_BUFFER, sizeof(frontlegs), frontlegs, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(VAOhips);

        glBindBuffer(GL_ARRAY_BUFFER, VBOhips);
        glBufferData(GL_ARRAY_BUFFER, sizeof(hips), hips, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(VAObackLegs);

        glBindBuffer(GL_ARRAY_BUFFER, VBObackLegs);
        glBufferData(GL_ARRAY_BUFFER, sizeof(backlegs), backlegs, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(VAObody);

        glBindBuffer(GL_ARRAY_BUFFER, VBObody);
        glBufferData(GL_ARRAY_BUFFER, sizeof(body), body, GL_STATIC_DRAW);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glBindVertexArray(VAOchest);

        glBindBuffer(GL_ARRAY_BUFFER, VBOchest);
        glBufferData(GL_ARRAY_BUFFER, sizeof(chest), chest, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(VAOhead[0]);

        glBindBuffer(GL_ARRAY_BUFFER, VBOhead[0]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(head), head, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(VAOhead[1]);

        glBindBuffer(GL_ARRAY_BUFFER, VBOhead[1]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(morda), morda, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(VAOears);

        glBindBuffer(GL_ARRAY_BUFFER, VBOears);
        glBufferData(GL_ARRAY_BUFFER, sizeof(ears), ears, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
    void draw()
    {

        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        //int a = 4;
        Shader ourShader("vertex.vs", "fragment.fs");
        ourShader.use();
        glm::mat4 model = glm::mat4(1.0f); 
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);
    
        model = glm::translate(model,  glm::vec3(a, b, c));
        if (superkey == 1)
            if (superkey == 1)
            {
                model = glm::mat4(1.0f);
                model = glm::rotate(model, (55.0f), glm::vec3(0.0f, 0.5f, 0.0f));
                model = glm::translate(model, glm::vec3(a, b, c));
                model = glm::rotate(model, 7 * (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 0.5f));
            }

        
        view = camera.GetViewMatrix();
        projection = glm::perspective(glm::radians(camera.Zoom), (float)width / (float)height, 0.1f, 100.0f);
  
        ourShader.setMat4("view", view);
        ourShader.setMat4("model", model);
        ourShader.setMat4("projection", projection);

 
        glBindVertexArray(VAOchest);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(VAObody);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(VAOhead[0]);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(VAOhead[1]);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(VAOears);
        glDrawArrays(GL_TRIANGLES, 0, 72);
     //   model = glm::mat4(1.0f);

        model = glm::rotate(model,  g, glm::vec3(0.0f, 0.0f, -z));
        model = glm::translate(model, glm::vec3(0.0f, b, c));
        if (superkey == 1)
        {
            model = glm::mat4(1.0f);
            model = glm::rotate(model, (55.0f), glm::vec3(0.0f, 0.5f, 0.0f));
            model = glm::translate(model, glm::vec3(a, b, c));
            model = glm::rotate(model, 7 * (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, -0.5f));
        }
        ourShader.setMat4("model", model);

        glBindVertexArray(VAObackLegs);

        glDrawArrays(GL_TRIANGLES, 0, 72);
        glBindVertexArray(VAOhips);
        glDrawArrays(GL_TRIANGLES, 0, 72);

        glBindVertexArray(VAOfrontLegs);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(a, b, c));
        model = glm::rotate(model, g, glm::vec3(0.0f, 0.0f, z));
        if (superkey == 1)
        {
            model = glm::mat4(1.0f);
            model = glm::rotate(model, (55.0f), glm::vec3(0.0f, 0.5f, 0.0f));
            model = glm::translate(model, glm::vec3(a, b, c));
            model = glm::rotate(model, 7 * (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 0.5f));
        }

        ourShader.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 72);
      //  cout << "22";
        a += 0.01;
        if ((d <= 0.27) && count == 1)
        {
            d += 0.002;
          //  z -= 0.015;
        }
        if (d >= 0.27)
            count = 0;
        if ((d >= 0) && count == 0)
        {
            d -= 0.002;
         //   z += 0.015;
        }
        if (d <= 0)
            count = 1;

        if ((g <= 0.11) && count3 == 1)
        {
            g += 0.002;
            //  z -= 0.015;
        }
        if (g >= 0.11)
            count3 = 0;
        if ((g >= 0) && count3 == 0)
        {
            g -= 0.002;
            //   z += 0.015;
        }
        if (g <= 0)
            count3 = 1;
        d += 0.001;
        cout << d << endl;
    }



}; 

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  

 
    //  window creation
    GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    //hips
    float vertices[] = {
     -0.77f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
     -0.70f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
     -0.70f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
     -0.70f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,

     -0.77f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
     -0.70f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
     -0.70f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
     -0.70f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,

     -0.73f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
     -0.73f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
     -0.73f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
     -0.73f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
     -0.73f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,
     -0.73f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,

     -0.77f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
     -0.77f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
     -0.77f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
     -0.77f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,

     -0.77f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
     -0.73f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
     -0.73f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.2f, 0.7f, 0.36f, 0.25f, 0.2f,
     -0.73f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.2f, 0.67f, 0.36f, 0.25f, 0.2f,

     -0.77f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
     -0.73f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
     -0.73f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
     -0.77f, -0.5f, 0.7f, 0.0f, 0.0f, 0.0f,
     -0.73f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,
     -0.77f, -0.5f, 0.67f, 0.0f, 0.0f, 0.0f,

          -0.77f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
     -0.70f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
     -0.70f, -0.2f, 0.23f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
     -0.70f, -0.2f, 0.23f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.2f, 0.23f, 0.36f, 0.25f, 0.2f,

     -0.77f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
     -0.70f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
     -0.70f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
     -0.70f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,

     -0.73f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
     -0.73f, -0.5f, 0.25f, 0.0f, 0.0f, 0.0f,
     -0.73f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
     -0.73f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
     -0.73f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,
     -0.73f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,

     -0.77f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.5f, 0.25f, 0.0f, 0.0f, 0.0f,
     -0.77f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
     -0.77f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
     -0.77f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,

     -0.77f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
     -0.73f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
     -0.73f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
     -0.73f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,
     -0.77f, -0.2f, 0.2f, 0.36f, 0.25f, 0.2f,

     -0.77f, -0.5f, 0.25f, 0.0f, 0.0f, 0.0f,
     -0.73f, -0.5f, 0.25f, 0.0f, 0.0f, 0.0f,
     -0.73f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
     -0.77f, -0.5f, 0.25f, 0.0f, 0.0f, 0.0f,
     -0.73f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
     -0.77f, -0.5f, 0.2f, 0.0f, 0.0f, 0.0f,
    };
    //backlegs 
    float vertices2[] = {
        -0.80f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,

        -0.80f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,

        -0.80f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,

        -0.80f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,

        -0.65f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,

        -0.80f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f, 0.72f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.65f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f, 0.65f, 0.36f, 0.25f, 0.2f,

                -0.80f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,

        -0.80f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,

        -0.80f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,

        -0.80f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,

        -0.65f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.65f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.65f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,

        -0.80f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f, 0.18f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.2f, 0.25f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f, 0.25f, 0.36f, 0.25f, 0.2f,
    };
    //body
    float vertices3[] = {
        -0.80f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
        -0.35f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
        -0.80f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
        -0.35f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
        -0.27f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,

        -0.80f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
        -0.35f, -0.15f, 0.35f, 0.0f, 0.0f, 0.0f,
        -0.80f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,
        -0.35f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
        -0.27f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,

        -0.80f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
        -0.27f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
        -0.27f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
        -0.27f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,
        -0.80f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,

        -0.80f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
        -0.35f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
        -0.35f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
        -0.80f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
        -0.35f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
        -0.80f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,

        -0.27f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
        -0.35f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
        -0.35f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
        -0.27f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
        -0.35f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
        -0.27f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,

        -0.80f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.15f, 0.65f, 0.0f, 0.0f, 0.0f,
        -0.80f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
        -0.80f,  0.1f,  0.65f, 0.36f, 0.25f, 0.2f,
        -0.80f, -0.15f, 0.25f, 0.0f, 0.0f, 0.0f,
        -0.80f,  0.1f,  0.25f, 0.36f, 0.25f, 0.2f,
    };
    //chest
    float vertices4[] = {
        -0.25f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
        -0.38f, -0.21f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.1f,  -0.18f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.25f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
        -0.1f,  -0.18f, 0.68f, 0.0f, 0.0f, 0.0f,
         0.03f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,

        -0.25f,  0.17f, 0.23f, 0.36f, 0.25f, 0.2f,
        -0.38f, -0.21f, 0.23f, 0.0f,  0.0f, 0.0f,
        -0.1f,  -0.18f, 0.23f, 0.0f,  0.0f, 0.0f,
        -0.25f,  0.17f, 0.23f, 0.36f, 0.25f, 0.2f,
        -0.1f,  -0.18f, 0.23f, 0.0f,  0.0f, 0.0f,
         0.03f,  0.17f, 0.23f, 0.36f, 0.25f, 0.2f,

        -0.25f, 0.17f, 0.23f, 0.36f, 0.25f, 0.2f,
        -0.25f, 0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
        -0.25f, 0.17f, 0.23f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.23f, 0.36f, 0.25f, 0.2f,

        -0.38f, -0.21f, 0.23f, 0.0f, 0.0f, 0.0f,
        -0.38f, -0.21f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.1f,  -0.18f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.38f, -0.21f, 0.23f, 0.0f, 0.0f, 0.0f,
        -0.1f,  -0.18f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.1f,  -0.18f, 0.23f, 0.0f, 0.0f, 0.0f,

         0.03f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
        -0.1f,  -0.18f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.1f,  -0.18f, 0.23f, 0.0f, 0.0f, 0.0f,
         0.03f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
        -0.1f,  -0.18f, 0.23f, 0.0f, 0.0f, 0.0f,
         0.03f,  0.17f, 0.23f, 0.36f, 0.25f, 0.2f,

        -0.25f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
        -0.38f, -0.21f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.38f, -0.21f, 0.23f, 0.0f, 0.0f, 0.0f,
        -0.25f,  0.17f, 0.68f, 0.36f, 0.25f, 0.2f,
        -0.38f, -0.21f, 0.23f, 0.0f, 0.0f, 0.0f,
        -0.25f,  0.17f, 0.23f, 0.36f, 0.25f, 0.2f,
    };  // - 17 - 24    1 -5
    //frontlegs
    float vertices5[] = {
        -0.21f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
        -0.21f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f, // 0.4f, 0.4f, 0.4f,
        -0.12f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
        -0.21f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
        -0.12f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
        -0.12f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,

        -0.21f,  0.1f, 0.68f, 0.1f, 0.0f, 0.0f,
        -0.21f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.12f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.21f,  0.1f, 0.68f, 0.1f, 0.0f, 0.0f,
        -0.12f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.12f,  0.1f, 0.68f, 0.1f, 0.0f, 0.0f,

        -0.21f,  0.1f, 0.68f, 0.36f, 0.25f, 0.2f,
        -0.21f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
        -0.12f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
        -0.21f,  0.1f, 0.68f, 0.36f, 0.25f, 0.2f,
        -0.12f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
        -0.12f,  0.1f, 0.68f, 0.36f, 0.25f, 0.2f,

        -0.21f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.21f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
        -0.12f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
        -0.21f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.12f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
        -0.12f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,

        -0.12f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
        -0.12f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
        -0.12f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.12f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
        -0.12f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.12f,  0.1f, 0.68f, 0.36f, 0.25f, 0.2f,

        -0.21f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
        -0.21f, -0.5f, 0.75f, 0.0f, 0.0f, 0.0f,
        -0.21f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.21f,  0.1f, 0.75f, 0.36f, 0.25f, 0.2f,
        -0.21f, -0.5f, 0.68f, 0.0f, 0.0f, 0.0f,
        -0.21f,  0.1f, 0.68f, 0.36f, 0.25f, 0.2f,

                -0.21f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
        -0.21f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
        -0.12f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
        -0.21f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
        -0.12f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
        -0.12f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,

        -0.21f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,
        -0.21f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
        -0.12f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
        -0.21f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,
        -0.12f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
        -0.12f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,

        -0.21f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,
        -0.21f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,// was 33
        -0.12f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
        -0.21f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,  // was 26
        -0.12f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
        -0.12f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,

        -0.21f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
        -0.21f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
        -0.12f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
        -0.21f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
        -0.12f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
        -0.12f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,

        -0.12f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
        -0.12f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
        -0.12f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
        -0.12f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
        -0.12f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
        -0.12f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,

        -0.21f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
        -0.21f, -0.5f, 0.23f, 0.0f, 0.0f, 0.0f,
        -0.21f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
        -0.21f,  0.1f, 0.23f, 0.36f, 0.25f, 0.2f,
        -0.21f, -0.5f, 0.16f, 0.0f, 0.0f, 0.0f,
        -0.21f,  0.1f, 0.16f, 0.36f, 0.25f, 0.2f,

    };
    //head
    float vertices6[] = {
        -0.13f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,

        -0.13f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,

        -0.13f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,

        -0.13f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,

         0.03f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
         0.03f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,

        -0.13f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.17f, 0.56f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.42f, 0.56f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.17f, 0.35f, 0.36f, 0.25f, 0.2f,
        -0.13f, 0.42f, 0.35f, 0.36f, 0.25f, 0.2f,


    };
    //morda
    float vertices7[] = {
         0.03f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,

         0.03f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,

         0.03f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.1f,  0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,

         0.03f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,

         0.15f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.15f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,

         0.03f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.22f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.35f, 0.53f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.22f, 0.38f, 0.0f, 0.0f, 0.0f,
         0.03f, 0.35f, 0.38f, 0.0f, 0.0f, 0.0f,

    }; //
    //ears
    float vertices8[] = {
       -0.13f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,

       -0.13f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,

       -0.13f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,

       -0.13f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,

       -0.06f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,


       -0.13f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.42f, 0.61f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.56f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.42f, 0.56f, 0.0f, 0.0f, 0.0f,


               -0.13f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,

       -0.13f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,

       -0.13f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,

       -0.13f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,

       -0.06f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.06f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,


       -0.13f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.42f, 0.3f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.26f, 0.35f, 0.0f, 0.0f, 0.0f,
       -0.13f, 0.42f, 0.35f, 0.0f, 0.0f, 0.0f,





    }; 

    glEnable(GL_DEPTH_TEST);
    

    Shader ourShader("vertex.vs", "fragment.fs");


    float verticesJUJU[] = {
     -0.5f, -0.5f, -0.5f,
      0.5f, -0.5f, -0.5f,
      0.5f,  0.5f, -0.5f,
      0.5f,  0.5f, -0.5f,
     -0.5f,  0.5f, -0.5f,
     -0.5f, -0.5f, -0.5f,

     -0.5f, -0.5f,  0.5f,
      0.5f, -0.5f,  0.5f,
      0.5f,  0.5f,  0.5f,
      0.5f,  0.5f,  0.5f,
     -0.5f,  0.5f,  0.5f,
     -0.5f, -0.5f,  0.5f,

     -0.5f,  0.5f,  0.5f,
     -0.5f,  0.5f, -0.5f,
     -0.5f, -0.5f, -0.5f,
     -0.5f, -0.5f, -0.5f,
     -0.5f, -0.5f,  0.5f,
     -0.5f,  0.5f,  0.5f,

      0.5f,  0.5f,  0.5f,
      0.5f,  0.5f, -0.5f,
      0.5f, -0.5f, -0.5f,
      0.5f, -0.5f, -0.5f,
      0.5f, -0.5f,  0.5f,
      0.5f,  0.5f,  0.5f,

     -0.5f, -0.5f, -0.5f,
      0.5f, -0.5f, -0.5f,
      0.5f, -0.5f,  0.5f,
      0.5f, -0.5f,  0.5f,
     -0.5f, -0.5f,  0.5f,
     -0.5f, -0.5f, -0.5f,

     -0.5f,  0.5f, -0.5f,
      0.5f,  0.5f, -0.5f,
      0.5f,  0.5f,  0.5f,
      0.5f,  0.5f,  0.5f,
     -0.5f,  0.5f,  0.5f,
     -0.5f,  0.5f, -0.5f,
    };

   
    



 
    float b = 0.01f;
    float a = 0.001f;
    doggo bb;
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

        bb.draw();
     
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

 
    glfwTerminate();
    return 0;
}







