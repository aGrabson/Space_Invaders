#include "../include/bullet.h"
#include <allegro.h>
/** \brief Ustawienie wartosci poczatkowych zmiennych opisujacych pocisk
* @param width Szerokość okna aplikacji
* @param height Wysokość okna aplikacji
*/
void init_bullet_var(int width,int height)
{
    spawn_bullet=false;																			// Ustawienie stanu pocisku na niewidoczny
    bullet_width=width*0.007;																	// Ustawienie szerokości pocisku
    bullet_height=height*0.0266;																// Ustawienie wysokości pocisku
    bullet_pos_x=-1;
    bullet_pos_x_doubled=50;																	// Ustawienie startowej pozycji pocisku na osi X
    bullet_pos_y=-1;
    bullet_pos_y_doubled=50;
    activated_doubled_gun=false;
    spawn_bullet_doubled=false;                                                                 // Ustawienie startowej pozycji pocisku na osi Y
    bullet_speed=7;																				// Ustawienie prędkości poruszania się pocisku po planszy
    bullet_texture=load_bmp("source/bullet_player.bmp",default_palette);						// Załadowanie tekstury pocisku

    if(!bullet_texture)																			//
    {                                                                                           // Sprawdzenie czy udało się załadowac teksturę,
        errors(error_bullet);                                                                   // jeżeli nie, przejdź do funkcji errors()
    }
    bullet_sound=load_sample("source/bullet_sound.wav");
    if(!bullet_sound)
    {
        errors(error_sounds);
    }
}
/** \brief Rysoowanie pocisku
* @param *buffer Wskaźnik na bufor ekranu
* @param height Wysokość okna aplikacji
* @param width Szerokość okna aplikacji
* @param player_height Wysokości modelu gracza
* @param player_pos_x Pozycja gracza na osi X
* @param player_width Szerokość modelu gracza
* @param *player_able_to_shoot Zmienna sprawdzająca czy gracz może strzelać
*/
void draw_bullet(BITMAP *buffer,int height,int player_height,int player_pos_x,int player_width,bool *player_able_to_shoot)
{

    if((*player_able_to_shoot))
    {

            if(activated_doubled_gun)
            {
                if(spawn_bullet)
                {
                    stretch_blit(bullet_texture,buffer,0,0,
                    bullet_texture->w,bullet_texture->h,bullet_pos_x,
                    bullet_pos_y,bullet_width,bullet_height);
                }
                if(spawn_bullet_doubled)
                {

                    stretch_blit(bullet_texture,buffer,0,0,
                    bullet_texture->w,bullet_texture->h,bullet_pos_x_doubled,
                    bullet_pos_y_doubled,bullet_width,bullet_height);
                }
            }
            else
            {
                if(spawn_bullet)
                {
                    stretch_blit(bullet_texture,buffer,0,0,                                         //  Wyświetlenie przeskalowanego pocisku na buforze jeżeli
                    bullet_texture->w,bullet_texture->h,bullet_pos_x,                               //	spawn_bullet ma wartość true
                    bullet_pos_y,bullet_width,bullet_height);
                }
            }

    }
                                                                                                //
}
/** \brief Ustawienie pocisku przed graczem
* @param height Wysokość okna aplikacji
* @param player_height Wysokości modelu gracza
* @param player_pos_x Pozycja gracza na osi X
* @param player_width Szerokość modelu gracza
*/
void set_bullet_pos(int height,int player_height,int player_pos_x,int player_width)
{
    if(!(spawn_bullet||spawn_bullet_doubled))
    {
        if(player_pos_x>-1)
            play_sample(bullet_sound, 50, 127, 1000, 0 );

    if(!spawn_bullet)																			//
    {                                                                                           // Ustawienie pocisku przed graczem jeśli pocisk
            bullet_pos_y=height-player_height-bullet_height*2;                                      // nie istnieje
            bullet_pos_x=player_pos_x+player_width/2-bullet_width/2;                                //
    }
    if(activated_doubled_gun)
    {
        if(!spawn_bullet_doubled)
        {
            bullet_pos_y=height-player_height-bullet_height*2;
            bullet_pos_x=player_pos_x+player_width*0.25-bullet_width/2;
            bullet_pos_y_doubled=height-player_height-bullet_height*2;                                      // nie istnieje
            bullet_pos_x_doubled=player_pos_x+player_width*0.75-bullet_width/2;                                //
        }
    }
    }                                                                                  //
}
/** \brief Przemieszczanie się pocisku z określoną predkościa
*/
void move_bullet()
{
        if(activated_doubled_gun)                                                           // Przemieszczanie się pocisku jeśli
        {
            if(spawn_bullet)
            {
                bullet_pos_y-=bullet_speed;
            }
            if(spawn_bullet_doubled)
            {
                bullet_pos_y_doubled-=bullet_speed;
            }
        }
        else
        {
            if(spawn_bullet)
                bullet_pos_y-=bullet_speed;                                                              // pocisk istnieje
        }
}
/** \brief Usuwanie pocisku
* @param event Zmienna wymuszająca usunięcie pocisku
*/
void delete_bullet(int event)
{
    if(bullet_pos_y<0||event==1)																			//
    {
                                                                                           // Usuwanie pocisku jeśli nie znajduje
        spawn_bullet=false;
        bullet_pos_x=-1;
        bullet_pos_y=-1;																		// się na ekranie
    }
    if(bullet_pos_y_doubled<0 || event==2||activated_doubled_gun==false)
    {
        spawn_bullet_doubled=false;
        bullet_pos_x_doubled=-2;
        bullet_pos_y_doubled=-2;
    }
}
