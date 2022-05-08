#include "../include/errors.h"
#include <allegro.h>
#include "../include/engine.h"

/** \brief Egzekwowanie błędów
* @param event informacja jakie zdarzenie miało miejsce
*/
void errors(int event)
{
    set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );										// Aktywacja trybu komunikatów tekstowych  Allegro
    switch(event)
    {
    case error_player:																		//
        allegro_message( "Nie zaladowano tekstury gracza!" );					//
        break;																	//
    case error_inscription:																		//
        allegro_message( "Nie zaladowano tekstury napisu!" );					//
        break;																	//
    case error_enemy:                                                                     //
        allegro_message( "Nie zaladowano tekstury wroga!" );                    //
        break;                                                                  //
    case error_bullet:                                                                     //
        allegro_message( "Nie zaladowano tekstury pocisku!" );                  //			Wyświetlenie adekwatnego komunikatu
        break;                                                                  //
    case error_buffer:                                                                     //
        allegro_message( "Nie udalo sie utworzyc bufora pamieci!" );            //
        break;                                                                  //
    case error_logo:                                                                     //
        allegro_message( "Nie zaladowano tekstury loga gry!" );                 //
        break;                                                                  //
    case error_button:                                                                     //
        allegro_message( "Nie zaladowano tekstury jednego z przyciskow!" );     //
        break;                                                                  //
    case error_sounds:
        allegro_message( "Nie zaladowano pliku dzwiekowego gry!" );
        break;
    case error_bonus:
        allegro_message( "Nie zaladowano tekstury jednego z bonusow!" );
    }
    stop_allegro();                                                             // Wyłączenie Allegro
    exit(0);                                                                    // Zakończenie działania programu
}
