#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_surface.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "actions.h"
#include "param.h"
#include "splash.h"
#include "world.h"

uint32_t colors[MAX_PLAYERS + 1] = {0};

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void init_colors(SDL_PixelFormatDetails* format)
{
    // colors[0] = SDL_MapRGB(format, 0x00, 0x00, 0x00);
    // colors[1] = SDL_MapRGB(format, 0xFF, 0, 0);
    // colors[2] = SDL_MapRGB(format, 0, 0xFF, 0);
    // colors[3] = SDL_MapRGB(format, 0, 0x0, 0xFF);
    // colors[4] = SDL_MapRGB(format, 0xFF, 0, 0xFF);
    

    SDL_Palette *palette = SDL_GetSurfacePalette(screenSurface);

    colors[0] = SDL_MapRGB(format, palette, 0x00, 0x00, 0x00);
    colors[1] = SDL_MapRGB(format, palette, 0xFF, 0, 0);
    colors[2] = SDL_MapRGB(format, palette, 0, 0xFF, 0);
    colors[3] = SDL_MapRGB(format, palette, 0, 0x0, 0xFF);
    colors[4] = SDL_MapRGB(format, palette, 0xFF, 0, 0xFF);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void inits(int argc, char* argv[])
{
    // Get window surface
    screenSurface           = SDL_GetWindowSurface(window);
    SDL_PixelFormatDetails* format = SDL_GetPixelFormatDetails(screenSurface->format);
    init_colors(format);
    actions_init();
    world_create_players();
    printf("inits done\n");
}
