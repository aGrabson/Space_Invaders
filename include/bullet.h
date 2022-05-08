#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#include <allegro.h>
#include <stdbool.h>
#include "errors.h"
int bullet_pos_x;       			            /**< \brief Pozycja pocisku na ekranie względem osi X*/
int bullet_pos_x_doubled;       			    /**< \brief Pozycja pocisku na ekranie względem osi X*/
int bullet_pos_y;       			            /**< \brief Pozycja pocisku na ekranie względem osi Y*/
int bullet_pos_y_doubled;       			    /**< \brief Pozycja pocisku na ekranie względem osi Y*/
int bullet_width;       			            /**< \brief Szerokość modelu pocisku*/
int bullet_height;      			            /**< \brief Wysokość modelu pocisku*/
int bullet_speed;       			            /**< \brief Prędkość przemieszczania się pocisku po osi Y*/

bool spawn_bullet;      			            /**< \brief Informacja o istnieniu pocisku*/
bool spawn_bullet_doubled;                      /**< \brief Informacja o istnieniu dwóch pocisków*/
bool activated_doubled_gun;                     /**< \brief Informacja o aktywacji bonusu podwójnego działka*/

BITMAP *bullet_texture;				            /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę pocisku*/

SAMPLE * bullet_sound;                          /**< \brief Wskaznik na obszar pamieci przeznaczony na plik audio*/

extern void init_bullet_var(int,int);
extern void draw_bullet(BITMAP*,int,int,int,int,bool*);
extern void set_bullet_pos(int,int,int,int);
extern void move_bullet();
extern void delete_bullet(int);
#endif // BULLET_H_INCLUDED
