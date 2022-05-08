#include "../include/settings.h"
#include <allegro.h>
/** \brief Ustawienie wartosci poczatkowych zmiennych opisujacych zakładkę settings oraz załadowanie tekstur
* @param width Szerokość okna aplikacji
* @param height Wysokość okna aplikacji
*/
void init_settings(int width,int height)
{
    back_width=width*0.0683;
    back_height=height*0.0911;
    back_pos_x=width*0.9;
    back_pos_y=height*0.03;
    back_button=false;

    fullscreen_width=width*0.33;
    fullscreen_height=height*0.25;
    fullscreen_pos_x=width*0.33;
    fullscreen_pos_y=height*0.1;
    fullscreen_button=false;

    windowed_width=width*0.33;
    windowed_height=height*0.25;
    windowed_pos_x=width*0.33;
    windowed_pos_y=height*0.38;
    windowed_button=false;

    soundon_width=width*0.3;
    soundon_height=height*0.2;
    soundon_pos_x=width*0.52;
    soundon_pos_y=height*0.67;
    soundon_button=false;

    soundoff_width=width*0.3;
    soundoff_height=height*0.2;
    soundoff_pos_x=width*0.17;
    soundoff_pos_y=height*0.67;
    soundoff_button=false;



    back_not_active=load_bmp("source/back_na.bmp",default_palette);
    back_active=load_bmp("source/back_a.bmp",default_palette);

    fullscreen_not_active=load_bmp("source/fullscreen_na.bmp",default_palette);
    fullscreen_active=load_bmp("source/fullscreen_a.bmp",default_palette);

    windowed_not_active=load_bmp("source/windowed_na.bmp",default_palette);
    windowed_active=load_bmp("source/windowed_a.bmp",default_palette);

    soundon_na=load_bmp("source/soundon_na.bmp",default_palette);
    soundon_a=load_bmp("source/soundon_a.bmp",default_palette);
    soundoff_na=load_bmp("source/soundoff_na.bmp",default_palette);
    soundoff_a=load_bmp("source/soundoff_a.bmp",default_palette);



    if((!back_not_active)||(!back_active)||
       (!fullscreen_not_active)||(!fullscreen_active)||
       (!windowed_not_active)||(!windowed_active)||
       (!soundon_na)||(!soundon_a)||(!soundoff_na)||(!soundoff_a))
    {
        errors(error_button);
    }

}
/** \brief Aktualizacja stanu zakładki settings
* @param *game_mode Wskaźnik na informacje o aktualnym trybie gry
* @param *width Wskaźnik na szerokość okna aplikacji
* @param *height Wskaźnik na wysokość okna aplikacji
* @param **buffer Wskaźnik na zmienną przechowującą wskaźnik na obszar pamięci przeznaczony na bufor ekranu
*/
void update_settings(int *game_mode,int *width,int *height, BITMAP **buffer)
{
    if(mouse_x>back_pos_x&&mouse_x<back_pos_x+back_width&&
	mouse_y>back_pos_y&&mouse_y<back_pos_y+back_height)									// Sprawdzenie czy kursor znajduje się w obrębie przycisku
    {
        back_button=true;                                                               // Zmiana stanu przycisku cofania na aktywny

        if(mouse_b==1)                                                                  //
        {                                                                               //
            *game_mode=1;																//			Zmiana trybu gry
        }                                                                               //
    }
    else
    {
        back_button=false;																// Zmiana stanu przycisku cofania na nieaktywny
    }

    if(mouse_x>fullscreen_pos_x&&mouse_x<fullscreen_pos_x+fullscreen_width&&
	mouse_y>fullscreen_pos_y&&mouse_y<fullscreen_pos_y+fullscreen_height)									// Sprawdzenie czy kursor znajduje się w obrębie przycisku
    {
        fullscreen_button=true;                                                               // Zmiana stanu przycisku cofania na aktywny

        if(mouse_b==1)                                                                  //
        {
            stop_allegro();
            start_allegro(2);																//			Zmiana trybu gry
        }                                                                               //
    }
    else
    {
        fullscreen_button=false;																// Zmiana stanu przycisku cofania na nieaktywny
    }

    if(mouse_x>windowed_pos_x&&mouse_x<windowed_pos_x+windowed_width&&
	mouse_y>windowed_pos_y&&mouse_y<windowed_pos_y+windowed_height)									// Sprawdzenie czy kursor znajduje się w obrębie przycisku
    {
        windowed_button=true;                                                               // Zmiana stanu przycisku cofania na aktywny

        if(mouse_b==1)                                                                  //
        {                                                                               //
            stop_allegro();
            start_allegro(1);																//			Zmiana trybu gry
        }                                                                               //
    }
    else
    {
        windowed_button=false;																// Zmiana stanu przycisku cofania na nieaktywny
    }


    if(mouse_x>soundon_pos_x&&mouse_x<soundon_pos_x+soundon_width&&
	mouse_y>soundon_pos_y&&mouse_y<soundon_pos_y+soundon_height)									// Sprawdzenie czy kursor znajduje się w obrębie przycisku
    {
        soundon_button=true;                                                               // Zmiana stanu przycisku cofania na aktywny

        if(mouse_b==1)                                                                  //
        {                                                                               //
            set_volume(75,75);
            stop_sample(battle_sound);
            play_sample(battle_sound, 75, 127, 1000, 1);
        }                                                                  //
    }
    else
    {
        soundon_button=false;																// Zmiana stanu przycisku cofania na nieaktywny
    }

    if(mouse_x>soundoff_pos_x&&mouse_x<soundoff_pos_x+soundoff_width&&
	mouse_y>soundoff_pos_y&&mouse_y<soundoff_pos_y+soundoff_height)									// Sprawdzenie czy kursor znajduje się w obrębie przycisku
    {
        soundoff_button=true;                                                               // Zmiana stanu przycisku cofania na aktywny

        if(mouse_b==1)                                                                  //
        {                                                                               //
            stop_sample(battle_sound);
            set_volume(0,0);
                                                                    //			Zmiana trybu gry
        }                                                                               //
    }
    else
    {
        soundoff_button=false;																// Zmiana stanu przycisku cofania na nieaktywny
    }
}
/** \brief Wyświetlenie stanu zakładki settings
* @param *buffer Wskaźnik na bufor ekranu
*/
void render_settings(BITMAP *buffer)
{
    if(back_button)
    {
        stretch_blit(back_active,buffer,0,0,
		back_active->w,back_active->h,back_pos_x,
		back_pos_y,back_width,back_height);	                                            // Wyświetlenie aktywnego przycisku cofania na buforze po przeskalowaniu
    }
    else
    {
        stretch_blit(back_not_active,buffer,0,0,
		back_not_active->w,back_not_active->h,back_pos_x,
		back_pos_y,back_width,back_height);												// Wyświetlenie nieaktywnego przycisku cofania na buforze po przeskalowaniu
    }
    if(fullscreen_button)
    {
        stretch_blit(fullscreen_active,buffer,0,0,
		fullscreen_active->w,fullscreen_active->h,fullscreen_pos_x,
		fullscreen_pos_y,fullscreen_width,fullscreen_height);
    }
    else
    {
        stretch_blit(fullscreen_not_active,buffer,0,0,
		fullscreen_not_active->w,fullscreen_not_active->h,fullscreen_pos_x,
		fullscreen_pos_y,fullscreen_width,fullscreen_height);
    }
    if(windowed_button)
    {
        stretch_blit(windowed_active,buffer,0,0,
		windowed_active->w,windowed_active->h,windowed_pos_x,
		windowed_pos_y,windowed_width,windowed_height);
    }
    else
    {
        stretch_blit(windowed_not_active,buffer,0,0,
		windowed_not_active->w,windowed_not_active->h,windowed_pos_x,
		windowed_pos_y,windowed_width,windowed_height);
    }
    if(soundon_button)
    {
        stretch_blit(soundon_a,buffer,0,0,
		soundon_a->w,soundon_a->h,soundon_pos_x,
		soundon_pos_y,soundon_width,soundon_height);
    }
    else
    {
        stretch_blit(soundon_na,buffer,0,0,
		soundon_na->w,soundon_na->h,soundon_pos_x,
		soundon_pos_y,soundon_width,soundon_height);
    }
    if(soundoff_button)
    {
        stretch_blit(soundoff_a,buffer,0,0,
		soundoff_a->w,soundoff_a->h,soundoff_pos_x,
		soundoff_pos_y,soundoff_width,soundoff_height);
    }
    else
    {
        stretch_blit(soundoff_na,buffer,0,0,
		soundoff_na->w,soundoff_na->h,soundoff_pos_x,
		soundoff_pos_y,soundoff_width,soundoff_height);
    }
}
