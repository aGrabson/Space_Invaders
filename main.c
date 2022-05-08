#include "include/engine.h"
#include <stdio.h>
#include <allegro.h>
/** \brief Główna funkcja programu w której są wywoływane podstawowe funkcje gry
 */
int main()
{

    start_allegro(1);
    while(!close_button)        ///
    {                           ///
        while(speed>0)          ///
        {                       ///
            update();           /// Petla glowna
            render();
            speed--;
        }                       ///
    }                           ///
    stop_allegro();
    return 0;
}
END_OF_MAIN()
