#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_
#include <allegro.h>
#include <stdbool.h>
#include "errors.h"
#include <stdio.h>
#include "game_gui.h"
int back_width;					/**< \brief Szerokość przycisku cofania*/
int back_height;				/**< \brief Wysokość przycisku cofania*/
int back_pos_x;					/**< \brief Pozycja przycisku cofania względem pozycji X*/
int back_pos_y;					/**< \brief Pozycja przycisku cofania względem pozycji Y*/

int high_score_text_width;      /**< \brief Szerokość przycisku high score*/
int high_score_text_height;     /**< \brief Wysokość przycisku high score*/
int high_score_text_pos_x;		/**< \brief Pozycja przycisku high score względem pozycji X*/
int high_score_text_pos_y;		/**< \brief Pozycja przycisku high score względem pozycji Y*/

bool back_button;				/**< \brief Stan pocisku cofania*/
bool do_save;                   /**< \brief Informacja o zapisaniu wyniku do pliku*/

FILE *high_score_file;          /**< \brief Wskaźnik na plik wykorzystywany przy otwieraniu pliku*/

BITMAP *hs_back_not_active;		/**< \brief Wskaznik na obszar pamieci przeznaczony na teksture przycisku nieaktywnego*/
BITMAP *hs_back_active;			/**< \brief Wskaznik na obszar pamieci przeznaczony na teksture przycisku aktywnego*/
BITMAP *top5;                   /**< \brief Wskaznik na obszar pamieci przeznaczony na teksture napisu top5*/

extern void init_highscore(int,int);
extern void update_highscore(int*,int*,int*,BITMAP**);
extern void render_highscore(BITMAP*,int,int);
extern void sort_score();
extern void save_score(int);

#endif // HIGHSCORE_H_
