#include "../include/player.h"
#include <stdio.h>
#include <allegro.h>
/** \brief Ustawienie wartosci poczatkowych zmiennych opisujacych gracza, napis "LIVES" oraz załadowanie tekstur
* @param width Szerokość okna aplikacji
* @param height Wysokość okna aplikacji
*/
void init_player(int width,int height)
{
    player_texture=load_bmp("source/player.bmp",default_palette);          // Zaladowanie tekstury gracza
    player_barrier_texture=load_bmp("source/player_barrier.bmp",default_palette);
    player_barrier_2_texture=load_bmp("source/player_barrier2.bmp",default_palette);
    player_width=width*0.0425*2;											   // Ustawienie szerokości gracza
    player_height=height*0.06*2;											   // Ustawienie szerokości gracza
    player_lives=1;														   // Ustawienie ilości żyć
    player_speed=width*0.0065;											   // Ustawienie prędkości poruszania się gracza po planszy
    player_padding=height*0.0166;										   // Ustawienie odległości gracza od dolnej krawędzi okna gry
    player_pos_x=width/2-player_width/2;								   // Ustawienie startowej pozycji gracza na osi X
    player_pos_y=height-player_height-player_padding;					   // Ustawienie startowej pozycji gracza na osi Y
    current_player_texture=player_texture;

    sound_exp=load_sample("source/sound_explosion.wav");
    if(!sound_exp)
    {
        errors(error_sounds);
    }

    lives=load_bmp("source/lives.bmp",default_palette);                     // Zaladowanie tekstury napisu "LIVES"
    lives_width=width*0.0918;											    // Ustawienie szerokości napisu "LIVES"
    lives_height=height*0.0422;											    // Ustawienie wysokości napisu "LIVES"

    player_exp_first=load_bmp("source/exp_first.bmp",default_palette);
    player_exp_last=load_bmp("source/exp_last.bmp",default_palette);

    points=0;
    player_movable=true;
    player_able_to_shoot=true;
    player_visable=true;
    player_immortal=0;

    if((!player_texture)||(!player_barrier_texture)||
       (!player_barrier_2_texture)||(!player_exp_first)||(!player_exp_last))      // Sprawdzenie czy udało się załadowac teksturę,
    {                                                                            // jeżeli nie, przejdź do funkcji errors()
        errors(error_player);
    }
    if(!lives)                                                                   // Sprawdzenie czy udało się załadowac teksturę,
    {                                                                            // jeżeli nie, przejdź do funkcji errors()
        errors(error_inscription);
    }

    animation_counter_1=0;
    animation_counter_2=0;
}
/** \brief Wyswietlenie gracza po przeskalowaniu
* @param *buffer Wskaźnik na bufor ekranu
*/
void draw_player(BITMAP *buffer)
{
    if(player_visable)
    {
        stretch_blit(current_player_texture,buffer,0,0,
        player_texture->w,player_texture->h,
        player_pos_x,player_pos_y,player_width,player_height);				   // Wyświetlenie gracza na buforze po przeskalowaniu
    }
    else if(animation_counter_1>0)
    {
        stretch_blit(player_exp_first,buffer,0,0,player_exp_first->w,player_exp_first->h,player_pos_x,player_pos_y,player_width,player_height);
    }
    else
    {
        stretch_blit(player_exp_last,buffer,0,0,player_exp_last->w,player_exp_last->h,player_pos_x,player_pos_y,player_width,player_height);
    }
}
/** \brief Poruszanie się gracza po osi X w kierunku określonym przez parametr n
* @param n Parametr decydujący o kierunku poruszania się gracza
* @param width Szerokość okna aplikacji
*/
void move_player(int n,int width)
{
    if(player_movable)
    {
            if(n==0)
            {
                player_pos_x-=player_speed;                                        // Poruszanie w lewo

                if(player_pos_x<0)                                                 //
                {                                                                  // Blokada wyjscia poza plansze
                    player_pos_x=0;                                                //
                }
            }
            else
            {
                player_pos_x+=player_speed;                                        // Poruszanie w prawo

                if(player_pos_x>width-player_width)                                //
                {                                                                  // Blokada wyjscia poza plansze
                    player_pos_x=width-player_width;                               //

                }
            }
    }

}
/** \brief Wyswietlenie aktualnego stanu zyc gracza wraz z napisem "LIVES" po przeskalowaniu
* @param *buffer Wskaźnik na bufor ekranu
* @param width Szerokość okna aplikacji
*/
void show_lives(BITMAP *buffer,int width)
{
    stretch_blit(lives,buffer,0,0,
	lives->w,lives->h,width-3*player_width-5*lives_width/4,
	2*player_height/7,lives_width,lives_height);						  // Wyświetlenie napisu "LIVES" na buforze po przeskalowaniu
    switch(player_lives)
    {
    case 3:
        stretch_blit(player_texture,buffer,0,0,							//
		player_texture->w,player_texture->h,width-player_width,			//
		0,player_width,player_height);									//
																	    //
        stretch_blit(player_texture,buffer,0,0,							//
		player_texture->w,player_texture->h,width-player_width*2,		//		Wyświetlenie tekstur żyć na buforze po przeskalowaniu
		0,player_width,player_height);									//
																		//
        stretch_blit(player_texture,buffer,0,0,							//
		player_texture->w,player_texture->h,width-player_width*3,		//
		0,player_width,player_height);									//
        break;															//
    case 2:
        stretch_blit(player_texture,buffer,0,0,							//
		player_texture->w,player_texture->h,width-player_width,			//
		0,player_width,player_height);									//
																		//		Wyświetlenie tekstur żyć na buforze po przeskalowaniu
        stretch_blit(player_texture,buffer,0,0,							//
		player_texture->w,player_texture->h,width-player_width*2,		//
		0,player_width,player_height);									//
        break;															//
    case 1:
        stretch_blit(player_texture,buffer,0,0,							//
		player_texture->w,player_texture->h,width-player_width,			//		Wyświetlenie tekstury życia na buforze po przeskalowaniu
		0,player_width,player_height);									//
    }
}

/** \brief Wyswietlenie aktualnego stanu zyc gracza wraz z napisem "LIVES" po przeskalowaniu
* @param *buffer Wskaźnik na bufor ekranu
*/
void player_bullet_collision(BITMAP* buffer)
{
    struct enemy_bullet *bullet_cpy=bullet;
    if(player_immortal>0)
    {
        player_immortal--;
        return;
    }
    if(player_immortal==0)
    {
        while(bullet_cpy!=NULL)
        {
            if(bullet_cpy->x>=player_pos_x+player_width*0.28125&&bullet_cpy->x<=player_pos_x+player_width*0.75&&
               bullet_cpy->y>=player_pos_y+player_height*0.1875&&bullet_cpy->y<=player_pos_y+player_height*0.75&&
               bullet_cpy->x+enemy_bullet_width>=player_pos_x+player_width*0.28125&&
               bullet_cpy->y+enemy_bullet_height>=player_pos_y+player_height*0.1875
               )
            {
                play_sample(sound_exp, 50, 127, 1000, 0 );
                current_player_texture=player_barrier_texture;
                player_lives--;
                delete_enemy_bullet_by_addres(bullet_cpy);
                animation_counter_1=25;
                player_immortal=250;
                return;
            }
            bullet_cpy=bullet_cpy->next;
        }
    }
}

/** \brief Aktualizacja gracza
* @param width Szerokość okna aplikacji
* @param height Wysokość okna aplikacji
* @param *buffer Wskaźnik na bufor ekranu
*/
void update_player(int width,int height,BITMAP* buffer)
{
    if(find_max_y_enemy_down()+enemy_height>=player_pos_y)
    {
        player_lives=0;
        enemy_frame=0;
    }
    player_exp_animation(buffer,width);
    player_barrier_animation(buffer,width);
    if(key[KEY_A]||key[KEY_LEFT])                            //
    {                                                        // Poruszanie gracza w lewo
        move_player(0,width);                                //
    }
    if(key[KEY_D]||key[KEY_RIGHT])                           //
    {                                                        // Poruszanie gracza w prawo
        move_player(1,width);                                //
    }
    if(key[KEY_SPACE])                                       //
    {                                                        //

        set_bullet_pos(height,player_height,                 // Wystrzelenie pocisku
        player_pos_x,player_width);           //
        spawn_bullet=true;
        spawn_bullet_doubled=true;                                   //
    }
    player_bullet_collision(buffer);
}

/** \brief Stan gracza oraz animacja wybuchu statku
* @param *buffer Wskaźnik na bufor ekranu
* @param width Szerokość okna aplikacji
*/
void player_exp_animation(BITMAP* buffer,int width)
{
    if(animation_counter_1>0)
    {
        player_visable=false;
        player_movable=false;
        player_able_to_shoot=false;
        animation_counter_1--;
        if(animation_counter_1==0)
        {

            animation_counter_2=25;
        }
    }
    else if(animation_counter_2>0)
    {
        player_visable=false;
        animation_counter_2--;
        if(animation_counter_2==0)
        {
            barrier_animation_1=200;
            player_visable=true;
            player_movable=true;
            player_able_to_shoot=true;
            if(player_lives>0)
            {
                player_pos_x=width/2-player_width/2;
            }
        }
    }
}

/** \brief Stan gracza oraz animacja bariery po śmierci gracza
* @param *buffer Wskaźnik na bufor ekranu
* @param width Szerokość okna aplikacji
*/
void player_barrier_animation(BITMAP* buffer, int width)
{
    if(barrier_animation_1>100)
    {
        current_player_texture=player_barrier_texture;
        player_visable=true;
        player_movable=true;
        barrier_animation_1--;
    }
    if(barrier_animation_1<=100 && barrier_animation_1>0)
    {
        current_player_texture=player_barrier_2_texture;
        barrier_animation_1--;
    }
    if(barrier_animation_1==0)
    {
        current_player_texture=player_texture;
    }
}
