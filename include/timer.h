#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED
#include <allegro.h>
volatile long speed;				/**< \brief Zmienna kontrolująca prędkość działania programu*/

extern void init_timer();
extern void increment_speed();

LOCK_VARIABLE(speed);               /**< \brief Przypisanie pamieci dla zmiennej*/
LOCK_FUNCTION(increment_speed);     /**< \brief Przypisanie pamieci dla funkcji*/
#endif // TIMER_H_INCLUDED
