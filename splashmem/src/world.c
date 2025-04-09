#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "actions.h"
#include "param.h"
#include "player.h"
#include "world.h"

#define CHAR_WIDTH 16
#define CHAR_HEIGHT 16

/* !!!!!!!!!!!!!!!! MAP !!!!!!!!!!!!!!!!!!!!! */
uint8_t mapmem[MAP_SIZE * MAP_SIZE] = {0};

/*  PLAYERS */
t_player* players[MAX_PLAYERS] = {0};

void afficherTexte(SDL_Renderer* renderer, SDL_Texture* fontTexture, const char* texte, int x, int y,
                   int charWidth, int charHeight)
{
    SDL_Rect srcRect, destRect;

    for (size_t i = 0; i < strlen(texte); i++)
    {
        char c = texte[i];

        // Calculer la position du caractère dans la sprite sheet (ASCII)
        int index = c - ' ';                  // ' ' (espace) commence à l'index 0
        srcRect.x = (index % 16) * charWidth; // Grille de 16 caractères par ligne
        srcRect.y = (index / 16) * charHeight;
        srcRect.w = charWidth;
        srcRect.h = charHeight;

        // Position où afficher le caractère
        destRect.x = x + i * charWidth; // Décalage horizontal par caractère
        destRect.y = y;
        destRect.w = charWidth;
        destRect.h = charHeight;

        // Copier le caractère depuis la texture vers le renderer
        SDL_RenderTexture(renderer, fontTexture, &srcRect, &destRect);
    }
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_create_players()
{
    int i = 0;

    for (i = 0; i < MAX_PLAYERS; i++)
    {
        players[i] = (t_player*)malloc(sizeof(t_player));
        player_init(players[i], i);
        world_paint_spot(players[i]->x, players[i]->y, players[i]->id);
    }
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_do_player_action(t_player* p_player)
{
    // ici du code a qui fonctionne
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_paint_spot(uint32_t x, uint32_t y, uint32_t num)
{
    uint32_t pos = y * MAP_SIZE + x;
    mapmem[pos]  = num;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
int world_get_winner(t_player* players[])
{
    // Compter les pixels de chaque joueur
    int MaxPixelEC   = 0;
    int PlayerWinner = -1;
    int NbrPixelEC   = 0;

    for (int i = 0; i < MAX_PLAYERS; ++i)
    {
        NbrPixelEC = 0;

        for (int j = 0; j < MAP_SIZE * MAP_SIZE; ++j)
        {
            if (mapmem[j] == players[i]->id)
            {
                NbrPixelEC++;
            }
        }

        printf("Joueur %d : %d pixels\n", players[i]->id, NbrPixelEC);

        if (NbrPixelEC > MaxPixelEC) // EC = En cours
        {
            MaxPixelEC   = NbrPixelEC;
            PlayerWinner = players[i]->id;
        }
    }

    return PlayerWinner;
}

void result()
{
    SDL_Window*   window   = NULL;
    SDL_Renderer* renderer = NULL;

    // Créer une fenêtre SDL2
    window = SDL_CreateWindow("SplashMem", 640, 480, SDL_WINDOW_OPENGL);
    if (window == NULL)
    {
        printf("Erreur de création de fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    // Créer un renderer pour la fenêtre
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL)
    {
        printf("Erreur de création de renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    // Charger la sprite sheet pour la police (par exemple "font.bmp")
    SDL_Surface* fontSurface = SDL_LoadBMP("./src/Pixel-Game.bmp");
    if (!fontSurface)
    {
        printf("Erreur SDL_LoadBMP : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer, fontSurface);
    SDL_DestroySurface(fontSurface);
    if (!fontTexture)
    {
        printf("Erreur SDL_CreateTextureFromSurface : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    // Boucle pour garder la fenêtre ouverte
    int quitting = 0;
    while (!quitting)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                quitting = 1;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Afficher du texte à la position (100, 100)
        afficherTexte(renderer, fontTexture, "Bonjour SDL3 !", 100, 100, CHAR_WIDTH, CHAR_HEIGHT);

        SDL_RenderPresent(renderer);
    }

    // Nettoyage et fermeture
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
