#include "../include/timer.h"
#include <allegro.h>
/** \brief Ustalenie startowej wartości speed
*/
void init_timer()
{
    speed=0;
}
/** \brief Zwiekszenie wartosci speed o 1
*/
void increment_speed()
{
    speed++;
}END_OF_FUNCTION(increment_speed);
