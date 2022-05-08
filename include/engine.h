#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#include <allegro.h>
#include <stdbool.h>
#include "timer.h"
#include "player.h"
#include "bullet.h"
#include "errors.h"
#include "enemy.h"
#include "main_menu.h"
#include "settings.h"
#include "game_gui.h"
#include "bonus.h"
#include "highscore.h"

int width;                              /**< \brief Szerokosc okna gry*/
int height;                             /**< \brief Wysokosc okna gry*/
int width_starting_window;              /**< \brief Szerokosc okna gry*/
int height_starting_window;             /**< \brief Wysokosc okna gry*/

int game_mode;                          /**< \brief Tryb gry*/
int start_window_counter;               /**< \brief Licznik czasu wyświetlania ekranu startowego*/

BITMAP *buffer;                         /**< \brief Wskaźnik na obszar pamięci przeznaczony na bufor graficzny ekranu*/
BITMAP *ready_texture;                  /**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture ekranu startowego*/
BITMAP *steady_texture;                 /**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture ekranu startowego*/
BITMAP *go_texture;                     /**< \brief Wskaźnik na obszar pamięci przeznaczony na teksture ekranu startowego*/

FILE* high_score_file;                  /**< \brief Wskaźnik na plik wykorzystywany przy otwieraniu pliku*/


bool close_button;                      /**< \brief Stan przycisku odpowiedzialnego za zamknięcie gry*/
bool do_save;                           /**< \brief Zmienna informujaca o zapisie do pliku*/
bool win;                               /**< \brief Zmienna informujaca o wygranej*/
bool lose;                              /**< \brief Zmienna informujaca o przegranej*/

SAMPLE *battle_sound;                   /**< \brief Wskaznik na obszar pamieci przeznaczony na plik audio*/

extern void start_allegro(int);
extern void stop_allegro();
extern void init_engine_var();
extern void end_of_game();
extern void game_reset();
extern void save_score();

extern void update();
extern void render();
#endif // ENGINE_H_INCLUDED
