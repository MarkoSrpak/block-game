/**
 * @file window.c
 * @brief Window manager.
 *
 * @author Marko Srpak
 * @copyright See LICENSE.
 */

/*--------------------------- INCLUDES ---------------------------------------*/
#include "window.h"
#include <stdio.h>
/*--------------------------- MACROS AND DEFINES -----------------------------*/
/*--------------------------- TYPEDEFS AND STRUCTS ---------------------------*/
/*--------------------------- STATIC FUNCTION PROTOTYPES ---------------------*/

/**
 * @brief Callback for closing the window.
 *
 * @param window
 */
static void window_close_callback(GLFWwindow *window);

/**
 * @brief Callback for pressing a key, window specific.
 *
 * @param window
 * @param key
 * @param scancode
 * @param action
 * @param mods
 */
static void key_callback(GLFWwindow *window, int key, int scancode, int action,
                         int mods);

/**
 * @brief Callback for when window size gets changed.
 *
 * @param window
 * @param width
 * @param height
 */
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
/*--------------------------- VARIABLES --------------------------------------*/
GLFWwindow *window;
/*--------------------------- STATIC FUNCTIONS -------------------------------*/
static void window_close_callback(GLFWwindow *window)
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action,
                         int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}
/*--------------------------- GLOBAL FUNCTIONS -------------------------------*/

void window_init()
{
    // Create glfw window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(640, 480, "Block game", NULL, NULL);
    if (!window) {
        printf("Window or OpenGL context creation failed\n");
        return;
    }

    // Make window current context
    glfwMakeContextCurrent(window);

    // Initialize glad
    gladLoadGL(glfwGetProcAddress);

    // Set callback for window closing
    glfwSetWindowCloseCallback(window, window_close_callback);

    // Set callback for key presses for specific window
    glfwSetKeyCallback(window, key_callback);

    // Set callback for window size changes
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}
