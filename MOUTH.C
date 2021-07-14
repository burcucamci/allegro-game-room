#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>



int main() {
	srand(time(NULL));
	al_init_primitives_addon();

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *queue = NULL;

	int xpos = 300, ypos = 300;
	int dotx = rand() % 550;
	int doty = rand() % 550;
	int r = 20;
	float startrad = 0.5, endrad = 5.25;
	float rotation = 0.0;

	al_init();
	al_install_keyboard();
	al_install_mouse();

	display = al_create_display(600, 600);
	//al_set_window_position(display, 3500, 500);
	queue = al_create_event_queue();


	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	



	while (1) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		al_clear_to_color(al_map_rgb(0, 0, 0));

		


		if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
			xpos += 10;
			rotation = 0.0;
			
		}

		else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
			xpos -= 10;
			rotation = 3.14;
		}

		else if (ev.keyboard.keycode == ALLEGRO_KEY_UP) {
			ypos -= 10;
			rotation = 4.71;

		}

		else if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
			ypos += 10;
			rotation = 1.57;
		}


		al_draw_filled_circle(dotx, doty, 3, al_map_rgb(255, 255, 255));
		
		//al_draw_filled_circle(xpos, ypos, r, al_map_rgb(255, 255, 255));

		al_draw_filled_pieslice(xpos, ypos, r, startrad+rotation, endrad, al_map_rgb(255, 255, 255));


		al_flip_display();


		if (abs(dotx - xpos) <= 20 && abs(doty - ypos) <= 20) {
			dotx = rand() % 550;
			doty = rand() % 550;
			r += 5;
		}



	}


	
	system("pause");
	return 0;
}