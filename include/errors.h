#ifndef ERRORS_H_INCLUDED
#define ERRORS_H_INCLUDED
#include <allegro.h>
enum error_type                 /**< \brief Typ wyliczeniowy, odpowiadaj�cy r�nego rodzaju b��dom.*/
{
    error_player,
    error_inscription,
    error_enemy,
    error_bullet,
    error_buffer,
    error_logo,
    error_button,
    error_sounds,
    error_bonus
};
extern void errors(int);


#endif // ERRORS_H_INCLUDED
