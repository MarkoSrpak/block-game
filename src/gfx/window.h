/**
 * @file window.h
 * @brief Window manager header.
 *
 * @author Marko Srpak
 * @copyright See LICENSE.
 */

#ifndef GFX_WINDOW_H
#define GFX_WINDOW_H

/*--------------------------- INCLUDES ---------------------------------------*/
#include "gfx.h"
/*--------------------------- MACROS AND DEFINES -----------------------------*/
/*--------------------------- TYPEDEFS AND STRUCTS ---------------------------*/
/*--------------------------- EXTERN -----------------------------------------*/
extern GLFWwindow *window;
/*--------------------------- GLOBAL FUNCTION PROTOTYPES ---------------------*/

/**
 * @brief Initialize window manager.
 *
 */
void window_init();

#endif /*GFX_WINDOW_H*/
