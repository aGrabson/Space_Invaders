#include "../include/highscore.h"
#include <allegro.h>

/** \brief Ustawienie wartosci poczatkowych zmiennych opisujacych zakładkę highscore oraz załadowanie tekstur
* @param width Szerokość okna aplikacji
* @param height Wysokość okna aplikacji
*/
void init_highscore(int width,int height)
{
    back_width=width*0.0683;															// Ustawienie szerokoœci przycisku cofania
    back_height=height*0.0911;															// Ustawienie wysokosci przycisku cofania
    back_pos_x=width*0.9;																// Ustawienie pozycji przycisku cofania na osi X
    back_pos_y=height*0.03;																// Ustawienie pozycji przycisku cofania na osi Y

    high_score_text_width=width*0.55;
    high_score_text_height=height*0.2;
    high_score_text_pos_x=width*0.2;
    high_score_text_pos_y=height*0.015;
    back_button=false;																	// Ustawienie stanu pocisku cofania na nieaktywny
    do_save=true;
    high_score_file=NULL;

    hs_back_not_active=load_bmp("source/back_na.bmp",default_palette);						// Za³adowanie tekstury przycisku cofania w stanie nieaktywnym
    hs_back_active=load_bmp("source/back_a.bmp",default_palette);							// Za³adowanie tekstury przycisku cofania w stanie aktywnym
    top5=load_bmp("source/top5.bmp",default_palette);

    if((!hs_back_not_active)||(!hs_back_active)||(!top5))												// Sprawdzenie czy uda³o siê za³adowac teksturê,
    {																					// je¿eli nie, przejdŸ do funkcji errors()
        errors(error_button);															//
    }
}

/** \brief  Aktualizacja stanu zakładki highscore
* @param *game_mode Wskaźnik na informacje o aktualnym trybie gry
* @param *width Wskaźnik na szerokość okna aplikacji
* @param *height Wskaźnik na wysokość okna aplikacji
* @param **buffer Wskaźnik na zmienną przechowującą wskaźnik na obszar pamięci przeznaczony na bufor ekranu
*/
void update_highscore(int *game_mode,int *width,int *height, BITMAP **buffer)
{
    if(mouse_x>back_pos_x&&mouse_x<back_pos_x+back_width&&
	mouse_y>back_pos_y&&mouse_y<back_pos_y+back_height)									// Sprawdzenie czy kursor znajduje siê w obrêbie przycisku
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
}

/** \brief Wyświetlenie stanu zakładki highscore
* @param *buffer Wskaźnik na bufor ekranu
* @param width Szerokość ekranu
* @param height Wysokość ekranu
*/
void render_highscore(BITMAP *buffer,int width, int height)
{
    if(back_button)
    {
        stretch_blit(hs_back_active,buffer,0,0,
		hs_back_active->w,hs_back_active->h,back_pos_x,
		back_pos_y,back_width,back_height);	                                            // Wyœwietlenie aktywnego przycisku cofania na buforze po przeskalowaniu
    }
    else
    {
        stretch_blit(hs_back_not_active,buffer,0,0,
		hs_back_not_active->w,hs_back_not_active->h,back_pos_x,
		back_pos_y,back_width,back_height);												// Wyœwietlenie nieaktywnego przycisku cofania na buforze po przeskalowaniu
    }

        stretch_blit(top5,buffer,0,0,
		top5->w,top5->h,high_score_text_pos_x,
		high_score_text_pos_y,high_score_text_width,high_score_text_height);

    int pos_x=2*width/5,pos_y=height/4,number,counter=0;
    high_score_file=fopen("data\\high_score.txt","r");
    if(high_score_file)
    {
        while(!feof(high_score_file))
        {
            fscanf(high_score_file,"%d",&number);
            if(!feof(high_score_file))
            {
                draw_score(buffer,pos_x-130,pos_y,counter+1,10,true);
                circlefill(buffer, pos_x-80, pos_y+58, (width/60)*0.6, makecol(255,255,255) );
                draw_score(buffer,pos_x,pos_y,number,10,false);
                pos_y+=100;
                counter++;
            }
        }
        fclose(high_score_file);
    }
}

/** \brief Zapisanie wyników do pliku
* @param points Stan aktualnej ilości punktów

*/
void save_score(int points)
{
    if(do_save)
    {
        high_score_file=fopen("data\\high_score.txt","a");
        if(high_score_file)
        {
            fprintf(high_score_file,"%d\n",points);
        }
        fclose(high_score_file);
        do_save=false;
        sort_score();
    }
}

/** \brief Sortowanie bąbelkowe wyników zapisanych w pliku
*/
void sort_score()
{
    int *highscore_table = NULL;

    int number,counter=0;
    high_score_file=fopen("data\\high_score.txt","r");
    if(high_score_file)
    {
        while(!feof(high_score_file))
        {

                fscanf(high_score_file,"%d",&number);
            if(!feof(high_score_file))
            {
                counter++;
                highscore_table=realloc(highscore_table,sizeof(int)*counter);
                highscore_table[counter-1]=number;
            }
        }
        fclose(high_score_file);
    }
    int i=0,tmp;
    while(i < counter-1)
    {
        int j=0;
        while(j < counter-i-1)
        {
            if(highscore_table[j] < highscore_table[j+1])
            {
                tmp=highscore_table[j];
                highscore_table[j]=highscore_table[j+1];
                highscore_table[j+1]=tmp;
            }
            j++;
        }
        i++;
    }
    high_score_file=fopen("data\\high_score.txt","w");
    if(high_score_file)
    {
        int m=0;
        while(m<5)
        {
            fprintf(high_score_file,"%d\n",highscore_table[m]);
            m++;
            counter--;
        }
        fclose(high_score_file);
    }
}
