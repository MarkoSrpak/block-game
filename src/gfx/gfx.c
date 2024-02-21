/**
 * @file gfx.c
 * @brief Graphics manager.
 *
 * @author Marko Srpak
 * @copyright See LICENSE.
 */

/*--------------------------- INCLUDES ---------------------------------------*/
#include "gfx.h"
#include <stdio.h>
/*--------------------------- MACROS AND DEFINES -----------------------------*/
/*--------------------------- TYPEDEFS AND STRUCTS ---------------------------*/
/*--------------------------- STATIC FUNCTION PROTOTYPES ---------------------*/

/**
 * @brief
 *
 * @param error
 * @param description
 */
static void error_callback(int error, const char *description);
/*--------------------------- VARIABLES --------------------------------------*/
/*--------------------------- STATIC FUNCTIONS -------------------------------*/

static void error_callback(int error, const char *description)
{
    fprintf(stderr, "Error: %s\n", description);
}
/*--------------------------- GLOBAL FUNCTIONS -------------------------------*/

void gfx_init()
{
    // Register error callbacks
    glfwSetErrorCallback(error_callback);

    // Initialize glfw
    if (!glfwInit()) {
        fprintf(stderr, "Error: Initialization failed\n");
        return;
    }
}
