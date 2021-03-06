#ifndef GAME_GUI_H
#define GAME_GUI_H
#include <allegro.h>
#include <stdio.h>
#include <stdbool.h>
#include "errors.h"
char score_num[20];                                                     /**< \brief Tablica przechowująca wynik w formie napisu po przekonwertowaniu go z liczby*/

int score_width;                                                        /**< \brief Szerokość napisu reprezentującego wynik gry na ekranie*/
int score_height;                                                       /**< \brief Wysokość napisu reprezentującego wynik gry na ekranie*/
int score_pos_x;                                                        /**< \brief Pozycja napisu reprezentującego wynik gry na ekranie względem osi X*/
int score_pos_y;                                                        /**< \brief Pozycja napisu reprezentującego wynik gry na ekranie względem osi Y*/
int end_screen_width;                                                   /**< \brief Szerokość okna końcowego*/
int end_screen_height;                                                  /**< \brief Wysokość okna końcowego*/
int end_screen_pos_x;                                                   /**< \brief Pozycja okna końcowego względem osi X*/
int end_screen_pos_y;                                                   /**< \brief Pozycja okna końcowego względem osi Y*/

BITMAP* score_texture;                                                  /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę napis SCORE*/
BITMAP* score_bitmap;                                                   /**< \brief Pomocniczy wskaznik wykorzystywany podczas konwertowania wyniku z liczby na napis i wyświetlaniu na ekranie.*/
BITMAP* lose_screen;                                                    /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę okna, gdy się przegra*/
BITMAP* win_screen;                                                     /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę okna, gdy się wygra*/

extern void init_gui(int,int);
extern void draw_gui(BITMAP*,int,int,bool,bool);
extern void draw_score(BITMAP*,int,int,int,double,bool);
#endif // GAME_GUI_H
