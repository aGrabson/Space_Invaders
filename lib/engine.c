#include "../include/engine.h"
#include <allegro.h>
/** \brief Ustawienie domyślnych wartości rozdzielczości i warunku kontynuacji wykonywania programu
*/
void init_engine_var()
{
    width=1024;
    height=768;
    close_button=false;
    game_mode=1;
}
/** \brief Zainicjowanie podstawowych parametrow biblioteki Allegro oraz funkcji startowych
* @param graphic_choice Informacja o wyborze trybu pełnoekranowego lub w oknie
*/
void start_allegro(int graphic_choice)
{
    init_engine_var();
    allegro_init();                                                          // Uruchomienie środowiska Allegro
    set_color_depth( 32 );                                                   // Ustawienie głębi kolorów na 32 bity
    if(graphic_choice==1)
        set_gfx_mode( GFX_AUTODETECT_WINDOWED, width, height, 0, 0);         // Aktywacja trybu graficznego w oknie z ustawioną rozdzielczoscią
    else if(graphic_choice==2)
        set_gfx_mode( GFX_AUTODETECT_FULLSCREEN, width, height, 0, 0);       // Aktywacja trybu graficznego fullscreen z ustawioną rozdzielczoscia
    set_window_title("Space Invaders");                                      // Ustalenie tytułu okna gry
    clear_bitmap(screen);                                                    // Wyczyszczenie zawartości ekranu
    install_keyboard();                                                      // Dodanie obslugi klawiatury
    install_timer();                                                         // Dodanie obslugi timerów
    install_int_ex(increment_speed,BPS_TO_TIMER(100));                       // Okreslenie czestotliwosci działania
    install_mouse();
    install_sound( DIGI_AUTODETECT, MIDI_AUTODETECT, "" );
    set_volume(75,75);
    start_window_counter=0;

    battle_sound=load_sample("source/battle_sound.wav");
    if(!battle_sound)
    {
        errors(error_sounds);
    }
    play_sample(battle_sound, 75, 127, 1000, 1);

    show_mouse(screen);
    high_score_file=NULL;
    win=false;
    lose=false;

    buffer=create_bitmap(width,height);                                 // Utworzenie pliku buforowego o podanej rozdzielczosci
    if(!buffer)                                                         //
    {                                                                   // Sprawdzenie czy udalo sie utworzyc bufor,
        errors(error_buffer);                                           // jeżli nie, przejdz do funkcji errors()
    }                                                                   //
    clear_bitmap(buffer);                                               // Wyczyszczenie zawartości bufora

    init_bullet_var(width,height);									    // Ininjacja zmiennych biblioteki bullet
    init_player(width,height);										    //	Ininjacja zmiennych biblioteki player
    init_main_menu(width,height);									    // Ininjacja zmiennych biblioteki main_menu
    init_settings(width,height);
    init_highscore(width,height);
    init_enemy(width,height);
    init_gui(width,height);
    create_enemies("data\\levels\\level1.txt",&win);					// Ininjacja zmiennych biblioteki settings
    init_bonus(width,height);


    width_starting_window=width*0.45;
    height_starting_window=height*0.45;
    ready_texture=load_bmp("source/ready.bmp",default_palette);
    steady_texture=load_bmp("source/steady.bmp",default_palette);
    go_texture=load_bmp("source/go.bmp",default_palette);
}
/** \brief Zakonczenie dzialania biblioteki, zamknięcie gry i usunięcie bitmap oraz dźwięków
*/
void stop_allegro()
{
    remove_int(increment_speed);                                        // Usuniecie timera
    destroy_bitmap(player_texture);									    // Usunięcie bitmapy przechowującej teksture gracza
    destroy_bitmap(bullet_texture);									    // Usunięcie bitmapy przechowującej teksture pocisku
    destroy_bitmap(lives);											    // Usunięcie bitmapy przechowującej teksture żyć
    destroy_bitmap(buffer);											    // Usunięcie bitmapy przeznaczonej na bufor ekranu
    destroy_bitmap(player_barrier_texture);
    destroy_bitmap(player_barrier_2_texture);
    destroy_bitmap(player_exp_first);
    destroy_bitmap(player_exp_last);
    destroy_bitmap(bonus_live_texture);
    destroy_bitmap(bonus_gun_texture);
    destroy_bitmap(bonus_barrier_texture);
    destroy_bitmap(enemy_texture);
    destroy_bitmap(enemy_2_texture);
    destroy_bitmap(enemy_UFO_texture);
    destroy_bitmap(enemy_UFO_2_texture);
    destroy_bitmap(enemy_octopus_texture);
    destroy_bitmap(enemy_octopus_2_texture);
    destroy_bitmap(enemy_shielded_texture);
    destroy_bitmap(enemy_shielded_2_texture);
    destroy_bitmap(enemy_bullet_texture);
    destroy_bitmap(back_not_active);
    destroy_bitmap(back_active);
    destroy_bitmap(hs_back_not_active);
    destroy_bitmap(hs_back_active);
    destroy_bitmap(top5);
    destroy_bitmap(fullscreen_not_active);
    destroy_bitmap(fullscreen_active);
    destroy_bitmap(windowed_not_active);
    destroy_bitmap(windowed_active);
    destroy_bitmap(ready_texture);
    destroy_bitmap(steady_texture);
    destroy_bitmap(go_texture);
    destroy_bitmap(score_texture);
    destroy_bitmap(score_bitmap);
    destroy_bitmap(lose_screen);
    destroy_bitmap(logo);
    destroy_bitmap(start_not_active);
    destroy_bitmap(start_active);
    destroy_bitmap(high_score_not_active);
    destroy_bitmap(high_score_active);
    destroy_bitmap(settings_not_active);
    destroy_bitmap(settings_active);
    destroy_bitmap(quit_not_active);
    destroy_bitmap(quit_active);
    destroy_bitmap(win_screen);
    destroy_bitmap(soundon_na);
    destroy_bitmap(soundon_a);
    destroy_bitmap(soundoff_na);
    destroy_bitmap(soundoff_a);

    destroy_sample( battle_sound );
    destroy_sample( sound_exp_enemy );
    destroy_sample( sound_exp );

    remove_enemy();
    remove_enemy_bullet();
    close_button=true;                                                             // Przerwanie petli glownej
    allegro_exit();                                                                // Wylaczenie srodowiska Allegro
}
/** \brief Aktualizacja stanu gry w zależności stanu zmiennej game_mode
*/
void update()
{
        if(key[KEY_ESC])                                                            //
        {                                                                           // Przerwanie petli glownej
            close_button=true;                                                      //
        }															                //
        if(game_mode==1)
        {
            update_main_menu(&game_mode,&close_button,&start_window_counter);	    // Aktualizacja trybu gry main_menu
        }
        else if(game_mode==2)
        {

            if(start_window_counter>0)
            {
                clear_bitmap(screen);
                if(start_window_counter<100)
                {
                    stretch_blit(go_texture,screen,0,0,
                    go_texture->w,go_texture->h,width/2-width_starting_window/2,
                    height/2-height_starting_window/2,width_starting_window,height_starting_window);
                }
                else if(start_window_counter<200)
                {
                    stretch_blit(steady_texture,screen,0,0,
                    steady_texture->w,steady_texture->h,width/2-width_starting_window/2,
                    height/2-height_starting_window/2,width_starting_window,height_starting_window);
                }
                else
                {
                    stretch_blit(ready_texture,screen,0,0,
                    ready_texture->w,ready_texture->h,width/2-width_starting_window/2,
                    height/2-height_starting_window/2,width_starting_window,height_starting_window);

                }
                start_window_counter--;
            }

            else
            {
                end_of_game();
                move_bonus(width);
                bonus_collision(player_pos_x,player_pos_y,&player_lives,&barrier_animation_1,&barrier_animation_2,&player_immortal,player_width,player_height,height,&activated_doubled_gun);
                update_player(width,height,buffer);
                update_enemy(bullet_pos_x,bullet_pos_y,width,height,&points,&win);
                move_bullet();											                                // Obsługa poruszania pocisku
                delete_bullet(0);										                                // Usunięcie pocisku
                if(player_lives<=0)
                {
                    player_pos_x=-width;
                    lose=true;
                    player_visable=false;
                }
                if(lose||win)
                    save_score(points);
            }
        }
        else if(game_mode==3)
        {
            update_highscore(&game_mode,&width,&height,&buffer);
        }
        else if(game_mode==4)
        {
            update_settings(&game_mode,&width,&height,&buffer);		                               // Aktualizacja trybu gry settings
        }
}
/** \brief Wyświetlanie obecnego stanu gry
*/
void render()
{
    if(start_window_counter!=0)
    {
        return;
    }
    clear_bitmap(buffer);                                                                                    // Wyczyszczenie zawartosci bufora ekranu
    if(game_mode==1)
    {
        render_main_menu(buffer);									                                         // Wyświetlanie elementów menu głównego
    }
    else if(game_mode==2)
    {
        draw_enemy(buffer);
        show_lives(buffer,width);									                                          // Wyświetlanie ilości żyć gracza
        draw_player(buffer);
        draw_bonus(buffer);										                                          // Wystrzelenie gracza
        draw_bullet(buffer,height,player_height,
                player_pos_x,player_width,&player_able_to_shoot);							                  // Wyświetlanie pocisku

        draw_enemy_bullet(buffer);
        draw_gui(buffer,points,height,lose,win);


    }
    else if(game_mode==3)
    {
        render_highscore(buffer,width,height);
    }
    else if(game_mode==4)
    {
        render_settings(buffer);									                                            // Wyświetlenie elementów zakładki ustawień
    }
    blit(buffer,screen,0,0,0,0,width,height);                                                                   // Kopiowanie zawartosci bufora na ekran
}

/** \brief Zatrzymanie działania gry
*/
void end_of_game()
{
    if(lose||win)
    {
        enemy_speed=0;
        when_spawn_enemy_bullet=0;
        enemy_bullet_speed=0;
        bonus_speed=0;
        player_speed=0;
        player_able_to_shoot=false;
        if(key[KEY_ENTER])
        {
            game_mode=1;

            destroy_bitmap(player_texture);
            destroy_bitmap(lives);
            destroy_bitmap(player_exp_first);
            destroy_bitmap(player_exp_last);
            destroy_bitmap(enemy_texture);
            destroy_bitmap(enemy_2_texture);
            destroy_bitmap(enemy_UFO_texture);
            destroy_bitmap(enemy_UFO_2_texture);
            destroy_bitmap(enemy_octopus_texture);
            destroy_bitmap(enemy_octopus_2_texture);
            destroy_bitmap(enemy_shielded_texture);
            destroy_bitmap(enemy_shielded_2_texture);
            destroy_bitmap(enemy_bullet_texture);
            destroy_bitmap(player_barrier_2_texture);
            destroy_bitmap(player_barrier_texture);
            game_reset();
        }
    }
}

/** \brief Resetowanie ustawień gry
*/
void game_reset()
{
    remove_enemy();
    remove_enemy_bullet();
    init_player(width,height);
    init_enemy(width,height);
    level_number=0;
    lose=false;
    win=false;
    player_lives=3;
    do_save=true;
    points=0;
    bonus_speed=height*0.0045;
    bonus_selection=-1;
    activated_doubled_gun=false;
    barrier_animation_1=0;
    barrier_animation_2=0;
    player_immortal=0;
}
