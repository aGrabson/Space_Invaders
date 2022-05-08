#ifndef BONUS_H_
#define BONUS_H_
#include <allegro.h>
#include <stdbool.h>
#include "errors.h"
int bonus_width;                                /**< \brief Szeroko�� bonus�w*/
int bonus_height;                               /**< \brief Wysoko�� bonus�w*/
int bonus_pos_x;                                /**< \brief Pozycja bonus�w wzgl�dem osi X*/
int bonus_pos_y;                                /**< \brief Pozycja bonus�w wzgl�dem osi Y*/
int bonus_gun_timer;                            /**< \brief Czas trwania bonusu ulepszonego dzia�ka*/
int bonus_speed;                                /**< \brief Pr�dko�� poruszania si� bonus�w na planszy*/
int bonus_selection;                            /**< \brief Informacja o tym, kt�ry bonus zosta� wylosowany*/
int chance_of_bonus;                            /**< \brief Szansa na wypadni�cie bonusu*/

bool bonus_available;                           /**< \brief Mo�liwo�� wypadni�cia bonusu*/

BITMAP *bonus_live_texture;                     /**< \brief Wska�nik na obszar pami�ci przeznaczony na teksture bonusu dodatkowego �ycia*/
BITMAP *bonus_gun_texture;                      /**< \brief Wska�nik na obszar pami�ci przeznaczony na teksture bonusu ulepszonego dzia�ka*/
BITMAP *bonus_barrier_texture;                  /**< \brief Wska�nik na obszar pami�ci przeznaczony na teksture bonusu bariery*/

extern void init_bonus(int,int);
extern void move_bonus(int);
extern void spawn_bonus(int,int);
extern void bonus_collision(int,int,int*,int*,int*,int*,int,int,int,bool*);
extern void draw_bonus(BITMAP*);
#endif // BONUS_H_
