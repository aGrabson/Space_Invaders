#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <allegro.h>
#include "bullet.h"
#include "enemy.h"
#include "errors.h"
int player_lives;                           /**< \brief Ilość żyć gracza*/
int player_pos_x;                           /**< \brief Pozycja gracza na ekranie względem osi X*/
int player_pos_y;                           /**< \brief Pozycja gracza na ekranie względem osi Y*/
int player_width;                           /**< \brief Szerokość modelu gracza*/
int player_height;                          /**< \brief Wysokość modelu gracza*/
int player_speed;                           /**< \brief Prędkość poruszania się gracza po osi X*/
int player_padding;                         /**< \brief Odległość gracza od dolnej krawędzi aplikacji*/
int points;
int lives_width;                            /**< \brief Szerokość napisu "LIVES"*/
int lives_height;                           /**< \brief Wysokość napisu "LIVES"*/
int animation_counter_1;                    /**< \brief Licznik animacji wybuchu nr1*/
int animation_counter_2;                    /**< \brief Licznik animacji wybuchu nr2*/
bool player_visable;                        /**< \brief Stan widoczności tekstury gracza*/
bool player_able_to_shoot;                  /**< \brief Stan możliwości do strzelania*/
bool player_movable;                        /**< \brief Stan możliwości poruszania się gracza*/
int player_immortal;                        /**< \brief Licznik nieśmiertelności bytu*/
int barrier_animation_1;                    /**< \brief Licznik animacji bariery początkowej*/
int barrier_animation_2;                    /**< \brief Licznik animacji bariery zanikającej*/

BITMAP *player_texture;                     /**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture gracza*/
BITMAP *player_barrier_texture;             /**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture bariery początkowej*/
BITMAP *player_barrier_2_texture;           /**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture bariery końcowej*/
BITMAP *lives;                              /**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture napisu "LIVES"*/
BITMAP *player_exp_first;                   /**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture eksplozji nr1*/
BITMAP *player_exp_last;                    /**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture eksplozji nr2*/
BITMAP *current_player_texture;             /**< \brief Wskaźnik na teksture gracza, która ma być obecnie wyświetlana*/

SAMPLE *sound_exp;                          /**< \brief Wskaznik na obszar pamieci przeznaczony na plik audio*/

extern void init_player(int,int);
extern void move_player(int,int);
extern void player_bullet_collision(BITMAP*);
extern void draw_player(BITMAP*);
extern void show_lives(BITMAP*,int);
extern void update_player(int,int,BITMAP*);
extern void player_exp_animation(BITMAP*,int);
extern void player_barrier_animation(BITMAP*,int);
#endif // PLAYER_H_INCLUDED
