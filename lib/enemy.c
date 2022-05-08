#include "../include/enemy.h"
#include <allegro.h>

/** \brief Zainicjowanie podstawowych parametrow wroga oraz załadowanie tekstur
* @param width Szerokość okna aplikacji
* @param height Wysokość okna aplikacji
*/
void init_enemy(int width,int height)
{
    enemy_width=width*0.0556;
    enemy_height=height*0.085;
    enemy_frame=1;
    animation_counter=0;
    level=NULL;
    aliens=NULL;
    x_start_pos=10;
    enemy_time_counter=0;
    level_number=1;
    y_start_pos=height*0.1;
    enemy_speed=width*0.002;
    enemy_bullet_width=10;
    enemy_bullet_height=20;
    enemy_down_move_value=enemy_height*0.5;
    enemy_counter=0;
    when_spawn_enemy_bullet=20;
    enemy_padding=bullet_width;
    srand(time(NULL));
    bullet=NULL;
    enemy_bullet_speed=height*0.005;
    enemy_texture=load_bmp("source/enemy.bmp",default_palette);
    enemy_2_texture=load_bmp("source/enemy2.bmp",default_palette);
    enemy_UFO_texture=load_bmp("source/UFO.bmp",default_palette);
    enemy_UFO_2_texture=load_bmp("source/UFO2.bmp",default_palette);
    enemy_octopus_texture=load_bmp("source/octopus.bmp",default_palette);
    enemy_octopus_2_texture=load_bmp("source/octopus2.bmp",default_palette);
    enemy_shielded_texture=load_bmp("source/shielded.bmp",default_palette);
    enemy_shielded_2_texture=load_bmp("source/shielded2.bmp",default_palette);
    enemy_bullet_texture=load_bmp("source/bullet.bmp",default_palette);
    do_file_addres=true;

    if((!enemy_texture)||(!enemy_2_texture)||(!enemy_UFO_texture)||
       (!enemy_UFO_2_texture)||(!enemy_octopus_texture)||(!enemy_octopus_2_texture)||
       (!enemy_shielded_texture)||(!enemy_shielded_2_texture)||(!enemy_bullet_texture))
    {
        errors(error_enemy);
    }

    sound_exp_enemy=load_sample("source/sound_explosion.wav");
    if(!sound_exp_enemy)
    {
        errors(error_sounds);
    }
}

/** \brief Generowanie ścieżki do następnego poziomu
* @param width Szerokość okna aplikacji
* @param height Wysokość okna aplikacji
* @param *win wskaźnik na informacje o tym czy gracz wygrał
*/
void load_next_level(int height,int width,bool *win)
{
    if(aliens==NULL&&do_file_addres)
    {
        enemy_speed=width*0.002;
        x_start_pos=10;
        y_start_pos=height*0.1;
        level_number++;
        char path[50];
        char number[5];
        strcpy(path,"data\\levels\\level");
        sprintf(number,"%d",level_number);
        strcpy(&path[17],number);
        strcpy(&path[17+strlen(number)],".txt");
        create_enemies(path,win);
    }

}

/** \brief Wyświetlenie przeciwników z listy
* @param *buffer Wskaźnik na bufor ekranu
*/
void draw_enemy(BITMAP *buffer)
{
    struct enemy* aliens_copy=aliens;
    while(aliens_copy!=NULL)
    {
        if(aliens_copy->id==1)
        {
            if(enemy_frame==1)
                stretch_blit(enemy_texture,buffer,0,0,enemy_texture->w,enemy_texture->h,aliens_copy->x,aliens_copy->y,enemy_width,enemy_height);
            else
                stretch_blit(enemy_2_texture,buffer,0,0,enemy_2_texture->w,enemy_2_texture->h,aliens_copy->x,aliens_copy->y,enemy_width,enemy_height);
        }
        else if(aliens_copy->id==2)
        {
            if(enemy_frame==1)
                stretch_blit(enemy_UFO_texture,buffer,0,0,enemy_UFO_texture->w,enemy_UFO_texture->h,aliens_copy->x,aliens_copy->y,enemy_width,enemy_height);
            else
                stretch_blit(enemy_UFO_2_texture,buffer,0,0,enemy_UFO_2_texture->w,enemy_UFO_2_texture->h,aliens_copy->x,aliens_copy->y,enemy_width,enemy_height);
        }
        else if(aliens_copy->id==3)
        {
            if(enemy_frame==1)
                stretch_blit(enemy_octopus_texture,buffer,0,0,enemy_octopus_texture->w,enemy_octopus_texture->h,aliens_copy->x,aliens_copy->y,enemy_width,enemy_height);
            else
                stretch_blit(enemy_octopus_2_texture,buffer,0,0,enemy_octopus_2_texture->w,enemy_octopus_2_texture->h,aliens_copy->x,aliens_copy->y,enemy_width,enemy_height);
        }
        else if(aliens_copy->id==4)
        {
            if(enemy_frame==1)
                stretch_blit(enemy_shielded_texture,buffer,0,0,enemy_shielded_texture->w,enemy_shielded_texture->h,aliens_copy->x,aliens_copy->y,enemy_width,enemy_height);
            else
                stretch_blit(enemy_shielded_2_texture,buffer,0,0,enemy_shielded_2_texture->w,enemy_shielded_2_texture->h,aliens_copy->x,aliens_copy->y,enemy_width,enemy_height);
        }
        aliens_copy=aliens_copy->next;
    }

}

/** \brief Wczytanie przeciwników z pliku i dodanie ich do listy
* @param *level_source_path Ścieżka do pliku zawierającego poziom
* @param *win wskaźnik na informacje o tym czy gracz wygrał
*/
void create_enemies(char *level_source_path,bool *win)
{
    char data;
    level=fopen(level_source_path,"r");
    if(level)
    {
        while(!feof(level))
        {
            data=(char)fgetc(level);
            if(data=='1')
            {
                insert_enemy_front(1);
                x_start_pos+=enemy_width+enemy_padding;
            }
            else if(data=='2')
            {
                insert_enemy_front(2);
                x_start_pos+=enemy_width+enemy_padding;
            }
            else if(data=='3')
            {
                insert_enemy_front(3);
                x_start_pos+=enemy_width+enemy_padding;
            }
            else if(data=='4')
            {
                insert_enemy_front(4);
                x_start_pos+=enemy_width+enemy_padding;
            }
            else if(data==' ')
            {
                x_start_pos+=enemy_width+enemy_padding;
            }
            else if(data=='\n')
            {
                x_start_pos=10;
                y_start_pos+=enemy_height+enemy_padding;
            }
        }
        fclose(level);
    }
    else
    {
        do_file_addres=false;
        *win=true;
    }

}

/** \brief Dodanie przeciwnika o danym id na początek listy
* @param id Identyfikator przeciwnika
*/
void insert_enemy_front(int id)
{
    struct enemy *new_enemy=(struct enemy*)malloc(sizeof(struct enemy));
    if(new_enemy!=NULL)
    {
        new_enemy->id=id;
        new_enemy->x=x_start_pos;
        new_enemy->y=y_start_pos;
        new_enemy->next=aliens;
        aliens=new_enemy;
        enemy_counter++;
    }
}

/** \brief Dodanie pocisku na początek listy
* @param x Pozycja nowo dodanego pocisku względem osi X
* @param y Pozycja nowo dodanego pocisku względem osi Y
*/
void insert_bullet_front(int x,int y)
{
    struct enemy_bullet *new_enemy=(struct enemy_bullet*)malloc(sizeof(struct enemy_bullet));
    if(new_enemy!=NULL)
    {
        new_enemy->x=x;
        new_enemy->y=y;
        new_enemy->next=bullet;
        bullet=new_enemy;
    }
}

/** \brief Wybór losowego przeciwnika
* @return Wskaźnik na losowo wybranego przeciwnika z listy
*/
struct enemy* choose_random_enemy()
{
    struct enemy* enemy_copy=aliens;
    int random_enemy=rand()%enemy_counter;
    int i=0;
    while(i<random_enemy)
    {
        enemy_copy=enemy_copy->next;
        i++;
    }
    return enemy_copy;
}

/** \brief Szukanie przeciwnika o podanych współrzędnych
* @param x Pozycja szukanego wroga względem osi X
* @param y Pozycja szukanego wroga względem osi Y
* @return Wskaźnik na przeciwnika z listy na pozycji XY, w przypadku gdy nie ma takiego przeciwnika, zwraca NULL.
*/
struct enemy* find_xy_enemy(int x,int y)
{
    struct enemy* enemy_copy=aliens;
    while(enemy_copy!=NULL)
    {
       if(enemy_copy->x==x&&enemy_copy->y==y)
            return enemy_copy;
        enemy_copy=enemy_copy->next;
    }
    return NULL;
}

/** \brief Sprawdza czy wylosowany nieprzyjaciel ma przed sobą sojusznika, jeśli nie: strzela.
* @param height Wysokość okna aplikacji
*/
void enemy_atack(int height)
{
    if(aliens==NULL)
        return;
    struct enemy* random_enemy=NULL;
    int local_enemy_y;
        random_enemy=choose_random_enemy();
        local_enemy_y=random_enemy->y;
        do
        {
            local_enemy_y+=enemy_height+enemy_padding;
            if(find_xy_enemy(random_enemy->x,local_enemy_y)!=NULL)
            {
                return;
            }
        }while(local_enemy_y<height);
        if(speed==1)
            enemy_time_counter++;
        if(enemy_time_counter==when_spawn_enemy_bullet)
        {
            insert_bullet_front(random_enemy->x+enemy_width/2,random_enemy->y+enemy_height);
            enemy_time_counter=0;
        }
}

/** \brief Kolizja pocisków z wrogami
* @param bullet_pos_x Pozycja pocisku względem osi X
* @param bullet_pos_y Pozycja pocisku względem osi Y
* @param *points wskaźnik na informacje o aktualnej ilości punktów
*/
void enemy_bullet_collision(int bullet_pos_x,int bullet_pos_y,int *points)
{
    struct enemy* aliens_copy=aliens;
    while(aliens_copy!=NULL)
    {
        if(bullet_pos_x<=aliens_copy->x+enemy_width&&bullet_pos_x>=aliens_copy->x&&
           bullet_pos_y<=aliens_copy->y+enemy_height&&bullet_pos_y>=aliens_copy->y)
        {
            play_sample(sound_exp_enemy, 50, 127, 1000, 0 );
            if(aliens_copy->id==1)
            {
                (*points)+=100;
            }
            else if(aliens_copy->id==2)
            {
                (*points)+=50;
            }
            else if(aliens_copy->id==3)
            {
                (*points)+=200;
            }
            else if(aliens_copy->id==4)
            {
                aliens_copy->id=1;
                (*points)+=75;
                delete_bullet(1);
                return;
            }
            delete_enemy(aliens_copy,&aliens);
            delete_bullet(1);
        }
        if(bullet_pos_x_doubled<=aliens_copy->x+enemy_width&&bullet_pos_x_doubled>=aliens_copy->x&&
           bullet_pos_y_doubled<=aliens_copy->y+enemy_height&&bullet_pos_y_doubled>=aliens_copy->y)
        {
            if(aliens_copy->id==1)
            {
                (*points)+=100;
            }
            else if(aliens_copy->id==2)
            {
                (*points)+=50;
            }
            else if(aliens_copy->id==3)
            {
                (*points)+=200;
            }
            else if(aliens_copy->id==4)
            {
                aliens_copy->id=1;
                (*points)+=75;
                delete_bullet(2);
                return;
            }
            delete_enemy(aliens_copy,&aliens);
            delete_bullet(2);
        }
        aliens_copy=aliens_copy->next;
    }
}

/** \brief Usuwa podanego przeciwnika
* @param *enemy_pointer Wskaźnik na kosmitę, który ma zostać usunięty z listy
* @param **aliens_copy Wskaźnik na początek listy przeciwników
*/
void delete_enemy(struct enemy* enemy_pointer,struct enemy** aliens_copy)
{
    if(*aliens_copy!=NULL)
    {
        if(*aliens_copy==enemy_pointer)
        {
            struct enemy* next=(*aliens_copy)->next;
            spawn_bonus((*aliens_copy)->x,(*aliens_copy)->y);
            free(*aliens_copy);
            *aliens_copy=next;
            enemy_counter--;
            enemy_speed=enemy_speed+enemy_speed*0.05;
        }
        else
        {
            delete_enemy(enemy_pointer,&(*aliens_copy)->next);
        }
    }
}

/** \brief Poruszanie się wrogów
* @param **aliens_copy Wskaźnik na początek listy przeciwników
* @param width Szerokość ekranu aplikacji
*/
void move_enemy(struct enemy** aliens_copy,int width)
{
    if(*aliens_copy!=NULL)
    {
        (*aliens_copy)->x+=(int)enemy_speed;
        move_enemy(&(*aliens_copy)->next,width);
    }
}

/** \brief Przeszukanie który element listy wrogów jest najbardziej na prawo
* @return Pozycje na osi X najbardziej na lewo położonego elementu listy przeciwników
*/
int find_max_x_enemy_right()
{
    int result_enemy;
    struct enemy* enemy_copy=aliens;
    if(enemy_copy!=NULL)
    {
        result_enemy=enemy_copy->x;
    }
    else
    {
        return 0;
    }
    while(enemy_copy!=NULL)
    {
        if(enemy_copy->x>result_enemy)
        {
            result_enemy=enemy_copy->x;
        }
        enemy_copy=enemy_copy->next;
    }
    return result_enemy;
}

/** \brief Przeszukanie który element listy wrogów jest najbardziej na lewo
* @return Pozycje na osi X najbardziej na lewo położonego elementu listy przeciwników
*/
int find_max_x_enemy_left()
{
    int result_enemy;
    struct enemy* enemy_copy=aliens;

    if(enemy_copy!=NULL)
    {
        result_enemy=enemy_copy->x;
    }
    else
    {
        return 0;
    }
    while(enemy_copy!=NULL)
    {
        if(enemy_copy->x<result_enemy)
        {
            result_enemy=enemy_copy->x;
        }
        enemy_copy=enemy_copy->next;
    }
    return result_enemy;
}

/** \brief Rysowanie wszystkich pocisków z listy
* @param *buffer Wskaźnik na bufor ekranu
*/
void draw_enemy_bullet(BITMAP *buffer)
{
    struct enemy_bullet *bullet_cpy=bullet;
    while(bullet_cpy!=NULL)
    {
        stretch_blit(enemy_bullet_texture,buffer,0,0,enemy_bullet_texture->w,enemy_bullet_texture->h,bullet_cpy->x,bullet_cpy->y,enemy_bullet_width,enemy_bullet_height);
        bullet_cpy=bullet_cpy->next;
    }
}

/** \brief Poruszanie się pocisku
*/
void move_enemy_bullet()
{
    struct enemy_bullet *bullet_cpy=bullet;
    while(bullet_cpy!=NULL)
    {
        bullet_cpy->y+=enemy_bullet_speed;
        bullet_cpy=bullet_cpy->next;
    }
}

/** \brief Aktualizacja stanu przeciwników
* @param bullet_pos_x Pozycja pocisku względem osi X
* @param bullet_pos_y Pozycja pocisku względem osi Y
* @param width Szerokość ekranu aplikacji
* @param height Wysokość ekranu aplikacji
* @param *points Wskaźnik na aktualną ilość punktów
* @param *win Wskaźnik na informacje o tym czy gracz wygrał
*/
void update_enemy(int bullet_pos_x,int bullet_pos_y,int width,int height,int *points,bool *win)
{
    if(speed==1)
        animation_counter++;
    if(animation_counter==25)
    {
        animation_counter=0;
        enemy_frame*=-1;
    }
    move_enemy(&aliens,width);
    move_enemy_bullet();
    if(find_max_x_enemy_right()+enemy_width>=width||find_max_x_enemy_left()<=0)
    {
        enemy_speed=-enemy_speed;
        enemy_move_down();
    }
    load_next_level(height,width,win);
    delete_enemy_bullet();
    enemy_bullet_collision(bullet_pos_x,bullet_pos_y,points);
    enemy_atack(height);
}

/** \brief Usunięcie pocisków wroga znajdujących się poza planszą
*/
void delete_enemy_bullet()
{
    struct enemy_bullet *bullet_cpy=bullet;
    while(bullet_cpy!=NULL)
    {
        if(bullet_cpy->y<=0)
            delete_enemy_bullet_by_addres(bullet_cpy);
        bullet_cpy=bullet_cpy->next;
    }
}

/** \brief Usuwa podany pocisk przeciwnika
* @param *bullet_to_delete wskaźnik na element listy pocisków do usunięcia
*/
void delete_enemy_bullet_by_addres(struct enemy_bullet* bullet_to_delete)
{
    struct enemy_bullet *bullet_cpy=bullet;
    while(bullet_cpy!=NULL)
    {
        if(bullet_cpy->next==bullet_to_delete)
        {
            bullet_cpy->next=bullet_to_delete->next;
            free(bullet_to_delete);
            return;
        }
        bullet_cpy=bullet_cpy->next;
    }
}

/** \brief Przesunięcie przeciwników w dół o określoną wartość
*/
void enemy_move_down()
{
    struct enemy *enemy_cpy=aliens;
    while(enemy_cpy!=NULL)
    {
        enemy_cpy->y+=enemy_down_move_value;
        enemy_cpy=enemy_cpy->next;
    }
}

/** \brief Wyczyszczenie przeciwników z listy
*/
void remove_enemy()
{
    while(aliens!=NULL)
    {
        struct enemy *next=aliens->next;
        free(aliens);
        aliens=next;
    }
    enemy_counter=0;
}

/** \brief Wyczyszczenie elementów z listy pocisków
*/
void remove_enemy_bullet()
{
    while(bullet!=NULL)
    {
        struct enemy_bullet *next=bullet->next;
        free(bullet);
        bullet=next;
    }
}

/** \brief Wyszukanie najniżej położonych przeciwników na liście
* @return Pozycje na osi Y najniżej położonego elementu listy przeciwników
*/
int find_max_y_enemy_down()
{
    int result_enemy;
    struct enemy* enemy_copy=aliens;

    if(enemy_copy!=NULL)
    {
        result_enemy=enemy_copy->y;
    }
    else
    {
        return 0;
    }
    while(enemy_copy!=NULL)
    {
        if(enemy_copy->y>result_enemy)
        {
            result_enemy=enemy_copy->y;
        }
        enemy_copy=enemy_copy->next;
    }
    return result_enemy;
}
