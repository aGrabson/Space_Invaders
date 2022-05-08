#include "../include/main_menu.h"
#include <allegro.h>
/** \brief Ustawienie wartosci poczatkowych zmiennych opisujacych menu główne oraz załadowanie tekstur
* @param width Szerokość okna aplikacji
* @param height Wysokość okna aplikacji
*/
void init_main_menu(int width, int height)
{
    logo_width=width*0.7192;																// Ustawienie szerokości loga gry
    logo_height=height*0.3444;                                                              // Ustawienie wysokości loga gry
    logo_pos_x=width/2-logo_width/2;                                                        // Ustawienie pozycji loga gry na osi X
    logo_pos_y=height*0.1;                                                                  // Ustawienie pozycji loga gry na osi Y

    start_width=width*0.3417;                                                               // Ustawienie szerokości przycisku start
    start_height=height*0.0911;                                                             // Ustawienie wysokości przycisku start
    start_pos_x=width/2-start_width/2;                                                      // Ustawienie pozycji przycisku start na osi X
    start_pos_y=height/2;                                                                   // Ustawienie pozycji przycisku start na osi Y
    start_button=false;                                                                     // Ustawienie stanu przycisku start na nie aktywny

    high_score_width=width*0.3417;                                                          // Ustawienie szerokości przycisku tablicy wyników
    high_score_height=height*0.0911;                                                        // Ustawienie wysokości przycisku tablicy wyników
    high_score_pos_x=width/2-high_score_width/2;                                            // Ustawienie pozycji przycisku tablicy wyników na osi X
    high_score_pos_y=start_pos_y+start_height+0.03*height;                                  // Ustawienie pozycji przycisku tablicy wyników na osi Y
    high_score_button=false;                                                                // Ustawienie stanu przycisku tablicy wyników na nie aktywny
																							//
    settings_width=width*0.3417;                                                            // Ustawienie szerokości przycisku opcje
    settings_height=height*0.0911;                                                          // Ustawienie wysokości przycisku opcje
    settings_pos_x=width/2-settings_width/2;                                                // Ustawienie pozycji przycisku opcje na osi X
    settings_pos_y=high_score_pos_y+high_score_height+0.03*height;                          // Ustawienie pozycji przycisku opcje na osi Y
    settings_button=false;                                                                  // Ustawienie stanu przycisku opcje na nie aktywny

    quit_width=width*0.3417;                                                                // Ustawienie szerokości przycisku wyjścia
    quit_height=height*0.0911;                                                              // Ustawienie wysokości przycisku wyjścia
    quit_pos_x=width/2-quit_width/2;                                                        // Ustawienie pozycji przycisku wyjścia na osi X
    quit_pos_y=settings_pos_y+settings_height+0.03*height;                                  // Ustawienie pozycji przycisku wyjścia na osi Y
    quit_button=false;                                                                      // Ustawienie stanu przycisku wyjścia na nie aktywny

    logo=load_bmp("source/logo.bmp",default_palette);                                       // Załadowanie tekstury loga gry

    if(!logo)                                                                               // Sprawdzenie czy udało się załadowac teksturę,
    {                                                                                       // jeżeli nie, przejdź do funkcji errors()
        errors(error_logo);                                                                          //
    }                                                                                       //

    start_not_active=load_bmp("source/start_na.bmp",default_palette);                       // Załadowanie tekstury nieaktywnego przycisku start
    start_active=load_bmp("source/start_a.bmp",default_palette);                            // Załadowanie tekstury aktywnego przycisku start

    high_score_not_active=load_bmp("source/high_score_na.bmp",default_palette);             // Załadowanie tekstury nieaktywnego przycisku tablicy wyników
    high_score_active=load_bmp("source/high_score_a.bmp",default_palette);                  // Załadowanie tekstury nieaktywnego przycisku tablicy wyników

    settings_not_active=load_bmp("source/settings_na.bmp",default_palette);                 // Załadowanie tekstury nieaktywnego przycisku opcje
    settings_active=load_bmp("source/settings_a.bmp",default_palette);                      // Załadowanie tekstury nieaktywnego przycisku opcje

    quit_not_active=load_bmp("source/quit_na.bmp",default_palette);                         // Załadowanie tekstury nieaktywnego przycisku wyjścia
    quit_active=load_bmp("source/quit_a.bmp",default_palette);                              // Załadowanie tekstury nieaktywnego przycisku wyjścia

    if((!start_not_active)||(!start_active)||(!high_score_not_active)||(!high_score_active) //
       ||(!settings_not_active)||(!settings_active)||(!quit_not_active)||(!quit_active))    // Sprawdzenie czy udało się załadowac teksturę,
    {                                                                                       // jeżeli nie, przejdź do funkcji errors()
        errors(error_button);                                                                          //
    }                                                                                       //
}
/** \brief Wyświetlenie elementów menu głównego
* @param *buffer Wskaźnik na bufor ekranu
*/
void render_main_menu(BITMAP *buffer)
{
    stretch_blit(logo,buffer,0,0,
	logo->w,logo->h,logo_pos_x,logo_pos_y,logo_width,logo_height);							// Wyświetlenie loga gry na buforze po przeskalowaniu

    if(start_button)
    {
        stretch_blit(start_active,buffer,0,0,
		start_active->w,start_active->h,start_pos_x,start_pos_y,start_width,start_height);	// Wyświetlenie aktywnego przycisku start na buforze po przeskalowaniu
    }
    else
    {
        stretch_blit(start_not_active,buffer,0,0,
		start_not_active->w,start_not_active->h,start_pos_x,
		start_pos_y,start_width,start_height);												// Wyświetlenie nieaktywnego przycisku start na buforze po przeskalowaniu
    }
    if(high_score_button)
    {
        stretch_blit(high_score_active,buffer,0,0,
		high_score_active->w,high_score_active->h,high_score_pos_x,
		high_score_pos_y,high_score_width,high_score_height);								// Wyświetlenie aktywnego przycisku tablicy wyników na buforze po przeskalowaniu
    }
    else
    {
        stretch_blit(high_score_not_active,buffer,0,0,
		high_score_not_active->w,high_score_not_active->h,
		high_score_pos_x,high_score_pos_y,high_score_width,high_score_height);				// Wyświetlenie nieaktywnego przycisku tablicy wyników na buforze po przeskalowaniu
    }
    if(settings_button)
    {
        stretch_blit(settings_active,buffer,0,0,
		settings_active->w,settings_active->h,settings_pos_x,
		settings_pos_y,settings_width,settings_height);										// Wyświetlenie aktywnego przycisku opcje na buforze po przeskalowaniu
    }
    else
    {
        stretch_blit(settings_not_active,buffer,0,0,
		settings_not_active->w,settings_not_active->h,settings_pos_x,
		settings_pos_y,settings_width,settings_height);										// Wyświetlenie nieaktywnego przycisku opcje na buforze po przeskalowaniu
    }
    if(quit_button)
    {
        stretch_blit(quit_active,buffer,0,0,
		quit_active->w,quit_active->h,quit_pos_x,
		quit_pos_y,quit_width,quit_height);													// Wyświetlenie aktywnego przycisku wyjścia na buforze po przeskalowaniu
    }
    else
    {
        stretch_blit(quit_not_active,buffer,0,0,
		quit_not_active->w,quit_not_active->h,quit_pos_x,
		quit_pos_y,quit_width,quit_height);													// Wyświetlenie nieaktywnego przycisku wyjścia na buforze po przeskalowaniu
    }


}
/** \brief Aktualizacja stanu elementów menu głównego
* @param *game_mode Wskaźnik na zmienną przechowującą aktualny stan gry
* @param *close_button Wskaźnik na zmienną decydującą o zamknięciu gry
* @param *start_window_counter Wskaźnik na zmienną, która określająca czas ekranu startowego
*/
void update_main_menu(int *game_mode,bool *close_button,int *start_window_counter)
{
    if(mouse_x>start_pos_x&&mouse_x<start_pos_x+start_width&&
	mouse_y>start_pos_y&&mouse_y<start_pos_y+start_height)								// Sprawdzenie czy kursor znajduje się w obrębie przycisku start
    {
        start_button=true;                                                              // Zmiana stanu przycisku start na aktywny
        if(mouse_b==1)
        {
            *start_window_counter=300;                                                  //
            *game_mode=2;                                                               //Zmiana trybu gry
        }                                                                               //
    }                                                                                   //
    else
    {
        start_button=false;                                                             // Zmiana stanu przycisku start na nieaktywny
    }
    if(mouse_x>high_score_pos_x&&mouse_x<high_score_pos_x+high_score_width&&
	mouse_y>high_score_pos_y&&mouse_y<high_score_pos_y+high_score_height)				// Sprawdzenie czy kursor znajduje się w obrębie przycisku tablicy wyników
    {
        high_score_button=true;                                                         // Zmiana stanu przycisku tablicy wyników na aktywny
        if(mouse_b==1)
        {                                                                               //
            *game_mode=3;
            position_mouse(900,150);                                                    //
        }                                                                               //Zmiana trybu gry
    }                                                                                   //
    else
    {
        high_score_button=false;                                                        // Zmiana stanu przycisku tablicy wyników na nieaktywny
    }
    if(mouse_x>settings_pos_x&&mouse_x<settings_pos_x+settings_width&&
	mouse_y>settings_pos_y&&mouse_y<settings_pos_y+settings_height)						// Sprawdzenie czy kursor znajduje się w obrębie przycisku opcje
    {
        settings_button=true;                                                           // Zmiana stanu przycisku opcje na aktywny
        if(mouse_b==1)
        {                                                                               //
            *game_mode=4;
            position_mouse(900,150);                                                    //
        }                                                                               //Zmiana trybu gry
    }                                                                                   //
    else
    {
        settings_button=false;                                                          // Zmiana stanu przycisku opcje na nieaktywny
    }
    if(mouse_x>quit_pos_x&&mouse_x<quit_pos_x+quit_width&&
	mouse_y>quit_pos_y&&mouse_y<quit_pos_y+quit_height)									// Sprawdzenie czy kursor znajduje się w obrębie przycisku wyjścia
    {
        quit_button=true;                                                               // Zmiana stanu przycisku wyjścia na aktywny
        if(mouse_b==1)
        {                                                                               //
            *close_button=true;                                                         //
        }                                                                               //Zmiana trybu gry
    }                                                                                   //
    else
    {
        quit_button=false;                                                              // Zmiana stanu przycisku wyjścia na nieaktywny
    }
}
