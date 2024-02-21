/**
 * @file gfx.h
 * @brief Header for graphics libs.
 *
 * @author Marko Srpak
 * @copyright See LICENSE.
 */

#ifndef GFX_GFX_H
#define GFX_GFX_H

/*--------------------------- INCLUDES ---------------------------------------*/
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
/*--------------------------- MACROS AND DEFINES -----------------------------*/
/*--------------------------- TYPEDEFS AND STRUCTS ---------------------------*/
/*--------------------------- EXTERN -----------------------------------------*/
/*--------------------------- GLOBAL FUNCTION PROTOTYPES ---------------------*/

/**
 * @brief Initialize graphics.
 *
 */
void gfx_init();

#endif /*GFX_GFX_H*/
