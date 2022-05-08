#ifndef GAME_GUI_H
#define GAME_GUI_H
#include <allegro.h>
#include <stdio.h>
#include <stdbool.h>
#include "errors.h"
char score_num[20];                                                     /**< \brief Tablica przechowuj¹ca wynik w formie napisu po przekonwertowaniu go z liczby*/

int score_width;                                                        /**< \brief Szerokoœæ napisu reprezentuj¹cego wynik gry na ekranie*/
int score_height;                                                       /**< \brief Wysokoœæ napisu reprezentuj¹cego wynik gry na ekranie*/
int score_pos_x;                                                        /**< \brief Pozycja napisu reprezentuj¹cego wynik gry na ekranie wzglêdem osi X*/
int score_pos_y;                                                        /**< \brief Pozycja napisu reprezentuj¹cego wynik gry na ekranie wzglêdem osi Y*/
int end_screen_width;                                                   /**< \brief Szerokoœæ okna koñcowego*/
int end_screen_height;                                                  /**< \brief Wysokoœæ okna koñcowego*/
int end_screen_pos_x;                                                   /**< \brief Pozycja okna koñcowego wzglêdem osi X*/
int end_screen_pos_y;                                                   /**< \brief Pozycja okna koñcowego wzglêdem osi Y*/

BITMAP* score_texture;                                                  /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturê napis SCORE*/
BITMAP* score_bitmap;                                                   /**< \brief Pomocniczy wskaznik wykorzystywany podczas konwertowania wyniku z liczby na napis i wyœwietlaniu na ekranie.*/
BITMAP* lose_screen;                                                    /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturê okna, gdy siê przegra*/
BITMAP* win_screen;                                                     /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturê okna, gdy siê wygra*/

extern void init_gui(int,int);
extern void draw_gui(BITMAP*,int,int,bool,bool);
extern void draw_score(BITMAP*,int,int,int,double,bool);
#endif // GAME_GUI_H
