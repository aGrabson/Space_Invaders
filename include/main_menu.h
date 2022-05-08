#ifndef MAIN_MENU_H_INCLUDED
#define MAIN_MENU_H_INCLUDED
#include <allegro.h>
#include <stdbool.h>
#include "errors.h"
int logo_pos_x;							/**< \brief Pozycja loga gry na ekranie względem osi X*/
int logo_pos_y;							/**< \brief Pozycja loga gry na ekranie względem osi Y*/
int logo_width;							/**< \brief Szerokość loga gry*/
int logo_height;						/**< \brief Wysokość loga gry*/

int start_width;						/**< \brief Szerokość przycisku start*/
int start_height;       				/**< \brief Wysokość przycisku start*/
int start_pos_x;        				/**< \brief Pozycja przycisku start na ekranie względem osi X*/
int start_pos_y;        				/**< \brief Pozycja przycisku start na ekranie względem osi Y*/
bool start_button;						/**< \brief Stan pocisku start*/

int high_score_width;					/**< \brief Szerokość przycisku tablicy wyników*/
int high_score_height;  				/**< \brief Wysokość przycisku tablicy wyników*/
int high_score_pos_x;   				/**< \brief Pozycja przycisku tablicy wyników na ekranie względem osi X*/
int high_score_pos_y;   				/**< \brief Pozycja przycisku tablicy wyników na ekranie względem osi Y*/
bool high_score_button; 				/**< \brief Stan pocisku tablicy wyników*/

int settings_width;						/**< \brief Szerokość przycisku opcje*/
int settings_height;    				/**< \brief Wysokość przycisku opcje*/
int settings_pos_x;     				/**< \brief Pozycja przycisku opcje na ekranie względem osi X*/
int settings_pos_y;     				/**< \brief Pozycja przycisku opcje na ekranie względem osi Y*/
bool settings_button;   				/**< \brief Stan pocisku opcje*/

int quit_width;							/**< \brief Szerokość przycisku wyjścia*/
int quit_height;        				/**< \brief Wysokość przycisku wyjścia*/
int quit_pos_x;         				/**< \brief Pozycja przycisku wyjścia na ekranie względem osi X*/
int quit_pos_y;         				/**< \brief Pozycja przycisku wyjścia na ekranie względem osi Y*/
bool quit_button;       				/**< \brief Stan pocisku wyjścia*/

BITMAP *logo;							/**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture loga gry*/

BITMAP *start_not_active;				/**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture nieaktywnego przycisku start*/
BITMAP *start_active;					/**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture aktywnego przycisku start*/

BITMAP *high_score_not_active;			/**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture nieaktywnego przycisku tablicy wyników*/
BITMAP *high_score_active;              /**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture aktywnego przycisku tablicy wyników*/

BITMAP *settings_not_active;			/**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture nieaktywnego przycisku opcje*/
BITMAP *settings_active;                /**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture aktywnego przycisku opcje*/

BITMAP *quit_not_active;				/**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture nieaktywnego przycisku wyjścia*/
BITMAP *quit_active;                    /**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture aktywnego przycisku wyjścia*/

extern void init_main_menu(int,int);
extern void render_main_menu(BITMAP*);
extern void update_main_menu(int*,bool*,int*);
#endif // MAIN_MENU_H_INCLUDED
