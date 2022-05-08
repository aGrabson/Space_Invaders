#include "../include/bonus.h"
#include <stdio.h>
#include <time.h>

/** \brief Zainicjowanie podstawowych parametrow zwiazanych z bonusami
* @param width Szerokość okna aplikacji
* @param height Wysokość okna aplikacji
*/
void init_bonus(int width,int height)
{
    bonus_width=width*0.05;
    bonus_height=height*0.05;
    bonus_speed=height*0.0045;
    bonus_pos_x=0;
    bonus_pos_y=0;
    bonus_available=true;
    bonus_selection=-1;
    bonus_gun_timer=0;
    chance_of_bonus=15;
    bonus_live_texture=load_bmp("source/bonus_live.bmp",default_palette);
    bonus_gun_texture=load_bmp("source/bonus_gun.bmp",default_palette);
    bonus_barrier_texture=load_bmp("source/bonus_barrier.bmp",default_palette);

    if((!bonus_live_texture)|| (!bonus_gun_texture)|| (!bonus_barrier_texture))
    {
        errors(error_bonus);
    }
}

/** \brief Rysowanie odpowiedniego bonusu na ekranie
* @param *buffer Wskaźnik na bufor ekranu
*/
void draw_bonus(BITMAP *buffer)
{
    if(bonus_selection==0)
        stretch_blit(bonus_live_texture,buffer,0,0,bonus_live_texture->w,bonus_live_texture->h,bonus_pos_x,bonus_pos_y,bonus_width,bonus_height);
    else if(bonus_selection==1)
        stretch_blit(bonus_gun_texture,buffer,0,0,bonus_gun_texture->w,bonus_gun_texture->h,bonus_pos_x,bonus_pos_y,bonus_width,bonus_height);
    else if(bonus_selection==2)
        stretch_blit(bonus_barrier_texture,buffer,0,0,bonus_barrier_texture->w,bonus_barrier_texture->h,bonus_pos_x,bonus_pos_y,bonus_width,bonus_height);
}

/** \brief Poruszanie się bonusów po planszy
* @param width Szerokość okna aplikacji
*/
void move_bonus(int width)
{
    if(!bonus_available)
    {
        bonus_pos_y+=bonus_speed;
    }
}

/** \brief Pojawienie się bonusów
* @param x Pozycja wroga względem osi X
* @param y Pozycja wroga względem osi Y
*/
void spawn_bonus(int x, int y)
{
    if(((rand()% 100+1))<=chance_of_bonus)
    {
        if(bonus_available)
        {
            bonus_selection = rand() % 3;
            bonus_pos_x=x;
            bonus_pos_y=y;
            bonus_available=false;
        }
    }
}

/** \brief Wykrycie złapania bonusu przez gracza
* @param x Pozycja gracza względem osi X
* @param y Pozycja gracza względem osi Y
* @param *player_lives Stan żyć gracza
* @param *barrier_animation_1 Stan licznika pierwszej animacji bariery
* @param *barrier_animation_2 Stan licznika drugiej animacji bariery
* @param *player_immortal Stan licznika nieśmiertelności gracza
* @param player_width Szerokość statku kosmicznego gracza
* @param player_height Wysokość statku kosmicznego gracza
* @param height Wysokość planszy
* @param *activated_doubled_gun Stan aktywności strzelania z ulepszonym działkiem
*/
void bonus_collision(int x,int y,int *player_lives,int *barrier_animation_1,int *barrier_animation_2,int *player_immortal,int player_width,int player_height,int height,bool *activated_doubled_gun)
{
    if(bonus_gun_timer>0)
    {
        bonus_gun_timer-=1;
    }
    else
    {
        *activated_doubled_gun=false;
    }
    if(!bonus_available)
    {
        if(bonus_pos_y>=height)
        {
            bonus_available=true;
            return;
        }
        if(((bonus_pos_x>=x && bonus_pos_x<=x+player_width)||(bonus_pos_x+bonus_width>=x && bonus_pos_x+bonus_width<=x+player_width))&&
           ((bonus_pos_y>=y && bonus_pos_y<=y+player_height)||(bonus_pos_y+bonus_height>=y && bonus_pos_y+bonus_height<=y+player_height)))
        {
            if(bonus_selection==0)
            {
                if((*player_lives)<3)
                {
                    (*player_lives)=(*player_lives)+1;
                }
            }
            else if(bonus_selection==1)
            {
                bonus_gun_timer=500;
                if(bonus_gun_timer>0)
                {
                    *activated_doubled_gun=true;
                }
                if(bonus_gun_timer==0)
                {
                    *activated_doubled_gun=false;
                }
            }
            else if(bonus_selection==2)
            {
                (*barrier_animation_1)=400;
                (*barrier_animation_2)=100;
                (*player_immortal)=500;
            }
            bonus_available=true;
            bonus_selection=-1;
        }
    }
}
