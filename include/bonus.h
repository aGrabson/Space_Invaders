#ifndef BONUS_H_
#define BONUS_H_
#include <allegro.h>
#include <stdbool.h>
#include "errors.h"
int bonus_width;                                /**< \brief Szerokoœæ bonusów*/
int bonus_height;                               /**< \brief Wysokoœæ bonusów*/
int bonus_pos_x;                                /**< \brief Pozycja bonusów wzglêdem osi X*/
int bonus_pos_y;                                /**< \brief Pozycja bonusów wzglêdem osi Y*/
int bonus_gun_timer;                            /**< \brief Czas trwania bonusu ulepszonego dzia³ka*/
int bonus_speed;                                /**< \brief Prêdkoœæ poruszania siê bonusów na planszy*/
int bonus_selection;                            /**< \brief Informacja o tym, który bonus zosta³ wylosowany*/
int chance_of_bonus;                            /**< \brief Szansa na wypadniêcie bonusu*/

bool bonus_available;                           /**< \brief Mo¿liwoœæ wypadniêcia bonusu*/

BITMAP *bonus_live_texture;                     /**< \brief WskaŸnik na obszar pamiêci przeznaczony na teksture bonusu dodatkowego ¿ycia*/
BITMAP *bonus_gun_texture;                      /**< \brief WskaŸnik na obszar pamiêci przeznaczony na teksture bonusu ulepszonego dzia³ka*/
BITMAP *bonus_barrier_texture;                  /**< \brief WskaŸnik na obszar pamiêci przeznaczony na teksture bonusu bariery*/

extern void init_bonus(int,int);
extern void move_bonus(int);
extern void spawn_bonus(int,int);
extern void bonus_collision(int,int,int*,int*,int*,int*,int,int,int,bool*);
extern void draw_bonus(BITMAP*);
#endif // BONUS_H_
