#include "include/engine.h"
#include <stdio.h>
#include <allegro.h>
/** \brief Główna funkcja programu w której są wywoływane podstawowe funkcje gry
 */
int main()
{

    start_allegro();

    while(!close_button)    ///
    {
                            ///
        update();           /// Petla glowna
        render();           ///
    }                       ///
    stop_allegro();
    return 0;
}
END_OF_MAIN()
