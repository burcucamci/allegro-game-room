#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>

int main(int argc, char **argv)
{
	srand(time(NULL));
	al_init_primitives_addon();
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *queue = NULL;
	ALLEGRO_TIMER *timer;


	int r = 20;
	int xpos = 300, ypos = 300;
	float inc = 0.01;
	int flag;
	int dotx = rand() % 550;
	int doty = rand() % 550;


	al_init();
	al_install_keyboard();
	al_install_mouse();

	display = al_create_display(600, 600);
	timer = al_create_timer(1.0 / 100);
	queue = al_create_event_queue();
	al_start_timer(timer);

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));


	//al_get_timer_started(timer);

	float startrad = 0.5, endrad = 5.25;
	float rotation = 0;
	//float startrad=0.52, endrad=5.23;



	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		al_clear_to_color(al_map_rgb(0, 0, 0));

		if (/*ev.type == ALLEGRO_EVENT_KEY_DOWN && */ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
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

		al_draw_filled_circle(dotx, doty, 2, al_map_rgb(255, 255, 255));

		al_draw_filled_pieslice(xpos, ypos, r, rotation + startrad, endrad, al_map_rgb(255, 255, 255));
		al_flip_display();


		if (startrad <= 0) {
			flag = 1;
		}
		if (startrad >= 0.5) {
			flag = 0;
		}

		if (flag == 1) {
			startrad += 0.017;
			endrad -= 0.034;
		}
		if (flag == 0) {
			startrad -= 0.017;
			endrad += 0.034;
		}



		if (abs(dotx - xpos) <= r && abs(doty - ypos) <= r) {
			dotx = rand() % 550;
			doty = rand() % 550;
			r += 4;
		}




	}



	al_destroy_display(display);
	al_destroy_event_queue(queue);

	return 0;
}