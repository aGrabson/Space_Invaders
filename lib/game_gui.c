#include "../include/game_gui.h"
/** \brief Ustawienie wartosci poczatkowych zmiennych opisujacych układu graficznego
* @param width Szerokość okna aplikacji
* @param height Wysokość okna aplikacji
*/
void init_gui(int width,int height)
{
    score_width=width*0.05834*1.8;
    score_height=height*0.0422*1.8;
    score_pos_x=0;
    score_pos_y=0;

    score_texture=load_bmp("source/score.bmp",default_palette);
    lose_screen=load_bmp("source/YOU_LOSE.bmp",default_palette);
    win_screen=load_bmp("source/YOU_WON.bmp",default_palette);

    if((!score_texture) || (!lose_screen) || (!win_screen))
    {
        errors(error_inscription);
    }

    end_screen_width=lose_screen->w;
    end_screen_height=lose_screen->h;
    end_screen_pos_x=width/2-end_screen_width/2;
    end_screen_pos_y=height/2-end_screen_height/2;
}

/** \brief Rysowanie elementów interfejsu graficznego
* @param *buffer Wskaźnik na bufor ekranu
* @param points Zmienna przechowujaca wynik
* @param height Wysokość okna aplikacji
* @param lose Zmienna informująca, czy gracz przegrał
* @param win Zmienna informująca, czy gracz wygrał
*/
void draw_gui(BITMAP* buffer,int points,int height,bool lose,bool win)
{
    stretch_blit(score_texture,buffer,0,0,score_texture->w,score_texture->h,score_pos_x,score_pos_y,score_width,score_height);
    draw_score(buffer,score_pos_x+score_width,score_pos_y+height*0.015,points,4.5,false);
    if(lose)
    {
        stretch_blit(lose_screen,buffer,0,0,lose_screen->w,lose_screen->h,end_screen_pos_x,end_screen_pos_y,end_screen_width,end_screen_height);
        draw_score(buffer,end_screen_pos_x+end_screen_width/2,end_screen_pos_y+end_screen_height/2,points,7.0,true);
    }
    else if(win)
    {
        stretch_blit(win_screen,buffer,0,0,win_screen->w,win_screen->h,end_screen_pos_x,end_screen_pos_y,end_screen_width,end_screen_height);
        draw_score(buffer,end_screen_pos_x+end_screen_width/2,end_screen_pos_y+end_screen_height/2,points,7.0,true);
    }
    destroy_bitmap(score_bitmap);
}

/** \brief Rysowanie aktualnego wyniku
* @param *buffer Wskaźnik na bufor ekranu
* @param pos_x Pozycja wyświetlanego wyniku względem osi X
* @param pos_y Pozycja wyświetlanego wyniku względem osi Y
* @param points Zmienna przechowujaca wynik
* @param scale Zmienna, która mówi o skalowaniu napisu
* @param center Informacja o tym, czy napis ma być wyśrodkowany względem osi symetrii.
*/
void draw_score(BITMAP *buffer,int pos_x,int pos_y,int points,double scale,bool center)
{
    sprintf(score_num,"%d",points);
    score_bitmap=create_bitmap(text_length(font,score_num),text_height(font));
    clear_bitmap(score_bitmap);
    textout_ex(score_bitmap,font,score_num,0,0,makecol(255,255,255),-1);
    if(center)
        stretch_blit(score_bitmap,buffer,0,0,score_bitmap->w,score_bitmap->h,pos_x-(text_length(font,score_num)/2)*scale,pos_y,text_length(font,score_num)*scale,text_height(font)*scale);
    else
        stretch_blit(score_bitmap,buffer,0,0,score_bitmap->w,score_bitmap->h,pos_x,pos_y,text_length(font,score_num)*scale,text_height(font)*scale);
    destroy_bitmap(score_bitmap);
}
