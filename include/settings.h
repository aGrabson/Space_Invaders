#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED
#include <allegro.h>
#include <stdbool.h>
#include "errors.h"
#include "engine.h"

int back_width;				    	/**< \brief Szerokość przycisku cofania*/
int back_height;				    /**< \brief Wysokosc przycisku cofania*/
int back_pos_x;				    	/**< \brief Pozycja przycisku cofania względem pozycji X*/
int back_pos_y;				    	/**< \brief Pozycja przycisku cofania względem pozycji Y*/
bool back_button;			    	/**< \brief Stan pocisku cofania*/

int fullscreen_width;				/**< \brief Szerokość przycisku fullscreen*/
int fullscreen_height;				/**< \brief Wysokosc przycisku fullscreen*/
int fullscreen_pos_x;				/**< \brief Pozycja przycisku fullscreen względem pozycji X*/
int fullscreen_pos_y;				/**< \brief Pozycja przycisku fullscreen względem pozycji Y*/
bool fullscreen_button;				/**< \brief Stan pocisku fullscreen*/

int windowed_width;					/**< \brief Szerokość przycisku windowed*/
int windowed_height;				/**< \brief Wysokosc przycisku windowed*/
int windowed_pos_x;					/**< \brief Pozycja przycisku windowed względem pozycji X*/
int windowed_pos_y;					/**< \brief Pozycja przycisku windowed względem pozycji Y*/
bool windowed_button;				/**< \brief Stan pocisku windowed*/

int soundon_width;					/**< \brief Szerokość przycisku wlaczenia dzwieku*/
int soundon_height;				    /**< \brief Wysokosc przycisku wlaczenia dzwieku*/
int soundon_pos_x;					/**< \brief Pozycja przycisku wlaczenia dzwieku względem pozycji X*/
int soundon_pos_y;					/**< \brief Pozycja przycisku wlaczenia dzwieku względem pozycji Y*/
bool soundon_button;				/**< \brief Stan pocisku wlaczenia dzwieku*/

int soundoff_width;					/**< \brief Szerokość przycisku wylaczenia dzwieku*/
int soundoff_height;				/**< \brief Wysokosc przycisku wylaczenia dzwieku*/
int soundoff_pos_x;					/**< \brief Pozycja przycisku wylaczenia dzwieku względem pozycji X*/
int soundoff_pos_y;					/**< \brief Pozycja przycisku wylaczenia dzwieku względem pozycji Y*/
bool soundoff_button;				/**< \brief Stan pocisku wylaczenia dzwieku*/


BITMAP *back_not_active;		    /**< \brief Wskaznik na obszar pamieci przeznaczony na teksture przycisku nieaktywnego*/
BITMAP *back_active;			    /**< \brief Wskaznik na obszar pamieci przeznaczony na teksture przycisku aktywnego*/
BITMAP *fullscreen_not_active;		/**< \brief Wskaznik na obszar pamieci przeznaczony na teksture przycisku nieaktywnego*/
BITMAP *fullscreen_active;			/**< \brief Wskaznik na obszar pamieci przeznaczony na teksture przycisku aktywnego*/
BITMAP *windowed_not_active;		/**< \brief Wskaznik na obszar pamieci przeznaczony na teksture przycisku nieaktywnego*/
BITMAP *windowed_active;			/**< \brief Wskaznik na obszar pamieci przeznaczony na teksture przycisku aktywnego*/
BITMAP *soundon_na;                 /**< \brief Wskaznik na obszar pamieci przeznaczony na teksture przycisku nieaktywnego*/
BITMAP *soundon_a;                  /**< \brief Wskaznik na obszar pamieci przeznaczony na teksture przycisku aktywnego*/
BITMAP *soundoff_na;                /**< \brief Wskaznik na obszar pamieci przeznaczony na teksture przycisku nieaktywnego*/
BITMAP *soundoff_a;                 /**< \brief Wskaznik na obszar pamieci przeznaczony na teksture przycisku aktywnego*/



extern void init_settings(int,int);
extern void update_settings(int*,int*,int*,BITMAP**);
extern void render_settings(BITMAP*);
#endif // SETTINGS_H_INCLUDED
