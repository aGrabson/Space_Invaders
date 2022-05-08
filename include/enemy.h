#ifndef ENEMY_H
#define ENEMY_H
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "bullet.h"
#include <stdlib.h>
#include <time.h>
#include "bonus.h"
#include "errors.h"

/** \brief Struktura przeciwników
* @param id Informacja o typie przeciwnika
* @param x Pozycja wroga względem osi X
* @param y Pozycja wroga względem osi y
* @param *next Wskaźnik na następny element listy
*/
struct enemy
{
    int id;
    int x;
    int y;
    struct enemy *next;
};

/** \brief Struktura pocisków wroga
* @param x Pozycja pocisku względem osi X
* @param y Pozycja pocisku względem osi Y
* @param *next Wskaźnik na następny element listy
*/
struct enemy_bullet
{
    int x;
    int y;
    struct enemy_bullet *next;
};

int enemy_frame;                                                /**< \brief Informacja, którą klatkę animacji nieprzyjaciół wyświetlić*/
int animation_counter;                                          /**< \brief Czas trwania jednej klatki animacji*/
int enemy_width;                                                /**< \brief Szerokość wroga*/
int enemy_height;                                               /**< \brief Wysokość wroga*/
int x_start_pos;                                                /**< \brief Pozycja startowa wroga względem osi X*/
int y_start_pos;                                                /**< \brief Pozycja startowa wroga względem osi Y*/
int enemy_counter;                                              /**< \brief Licznik ilości wrogów*/
int enemy_time_counter;                                         /**< \brief Odlicza od 0 do when_spawn_enemy_bullet*/
int when_spawn_enemy_bullet;                                    /**< \brief Częstotliwość tworzenia pocisku przeciwnika*/
int enemy_down_move_value;                                      /**< \brief Wartość o jaką ilość pikseli wrogowie poruszą się w dół po odbiciu od ściany*/
int enemy_padding;                                              /**< \brief Odstęp między przeciwnikami*/
int level_number;                                               /**< \brief Numer obecnego poziomu*/
int enemy_bullet_speed;                                         /**< \brief Prędkość poruszania się pocisku wroga*/
int enemy_bullet_width;                                         /**< \brief Szerokość pocisku wroga*/
int enemy_bullet_height;                                        /**< \brief Wysokość pocisku wroga*/

double enemy_speed;                                             /**< \brief Prędkość wroga*/

bool do_file_addres;                                            /**< \brief Informacja czy trzeba wyznaczyć scieżkę do pliku przechowującego ustawienie następnego poziomu*/

FILE *level;                                                    /**< \brief Wskaźnik na plik wykorzystywany przy otwieraniu pliku*/

BITMAP* enemy_texture;                                          /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę wroga*/
BITMAP* enemy_2_texture;                                        /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę wroga*/
BITMAP* enemy_UFO_texture;                                      /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę wroga*/
BITMAP* enemy_UFO_2_texture;                                    /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę wroga*/
BITMAP* enemy_octopus_texture;                                  /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę wroga*/
BITMAP* enemy_octopus_2_texture;                                /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę wroga*/
BITMAP* enemy_shielded_texture;                                 /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę wroga*/
BITMAP* enemy_shielded_2_texture;                               /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę wroga*/
BITMAP *enemy_bullet_texture;                                   /**< \brief Wskaznik na obszar pamieci przeznaczony na teksturę pocisku*/

SAMPLE *sound_exp_enemy;                                        /**< \brief Wskaznik na obszar pamieci przeznaczony na plik audio*/

struct enemy *aliens;                                           /**< \brief Wskaźnik na pierwszy element listy zawierającej przeciwników*/
struct enemy_bullet *bullet;                                    /**< \brief Wskaźnik na pierwszy element listy zawierającej pociski przeciwników*/

extern int find_max_enemy_right();
extern int find_max_enemy_left();
extern int find_max_x_enemy_left();
extern int find_max_x_enemy_right();
extern int find_max_y_enemy_down();

extern void init_enemy(int,int);
extern void draw_enemy(BITMAP*);
extern void update_enemy(int,int,int,int,int*,bool*);
extern void create_enemies(char *,bool*);
extern void insert_enemy_front(int);
extern void delete_enemy(struct enemy*,struct enemy**);
extern void enemy_bullet_collision(int,int,int*);
extern void move_enemy(struct enemy**,int);
extern void enemy_atack(int);
extern void insert_bullet_front(int,int);
extern void draw_enemy_bullet(BITMAP*);
extern void move_enemy_bullet();
extern void delete_enemy_bullet();
extern void delete_enemy_bullet_by_addres(struct enemy_bullet*);
extern void enemy_move_down();
extern void load_next_level(int,int,bool*);
extern void remove_enemy();
extern void remove_enemy_bullet();

extern struct enemy* find_xy_enemy(int,int);
extern struct enemy* choose_random_enemy();
#endif // ENEMY_H
