#ifndef GAME_GUI_H
#define GAME_GUI_H
#include <allegro.h>
#include <stdio.h>
#include <stdbool.h>
#include "errors.h"
char score_num[20];                                                     /**< \brief Tablica przechowuj�ca wynik w formie napisu po przekonwertowaniu go z liczby*/

int score_width;                                                        /**< \brief Szeroko�� napisu reprezentuj�cego wynik gry na ekranie*/
int score_height;                                                       /**< \brief Wysoko�� napisu reprezentuj�cego wynik gry na ekranie*/
int score_pos_x;                                                        /**< \brief Pozycja napisu reprezentuj�cego wynik gry na ekranie wzgl�dem osi X*/
int score_pos_y;                                                        /**< \brief Pozycja napisu reprezentuj�cego wynik gry na ekranie wzgl�dem osi Y*/
int end_screen_width;                                                   /**< \brief Szeroko�� okna ko�cowego*/
int end_screen_height;                                                  /**< \brief Wysoko�� okna ko�cowego*/
int end_screen_pos_x;                                                   /**< \brief Pozycja okna ko�cowego wzgl�dem osi X*/
int end_screen_pos_y;                                                   /**< \brief Pozycja okna ko�cowego wzgl�dem osi Y*/

BITMAP* score_texture;                                                  /**< \brief Wskaznik na obszar pamieci przeznaczony na tekstur� napis SCORE*/
BITMAP* score_bitmap;                                                   /**< \brief Pomocniczy wskaznik wykorzystywany podczas konwertowania wyniku z liczby na napis i wy�wietlaniu na ekranie.*/
BITMAP* lose_screen;                                                    /**< \brief Wskaznik na obszar pamieci przeznaczony na tekstur� okna, gdy si� przegra*/
BITMAP* win_screen;                                                     /**< \brief Wskaznik na obszar pamieci przeznaczony na tekstur� okna, gdy si� wygra*/

extern void init_gui(int,int);
extern void draw_gui(BITMAP*,int,int,bool,bool);
extern void draw_score(BITMAP*,int,int,int,double,bool);
#endif // GAME_GUI_H
