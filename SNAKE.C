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
	
	al_init();
	al_install_keyboard();
	
	display = al_create_display(600, 600);
	al_set_window_position(display, 3500, 500);
	timer = al_create_timer(1.0 / 20);
	queue = al_create_event_queue();
	al_start_timer(timer);

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));

	int cnt = 3, i;
	int direction = 1;

	int snk[50][2] = { { 300, 300 }, { 280, 300 }, { 280, 280 } };
	int baitx1 = rand() % 550;
	int baity1 = rand() % 550;




	while (1)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		al_clear_to_color(al_map_rgb(0, 0, 0));

		if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT && direction != 3) {
			direction = 1;
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && direction != 4) {
			direction = 2;
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT && direction != 1) {
			direction = 3;
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_UP && direction != 2) {
			direction = 4;
		}
		


		if (direction == 1) {
			snk[0][0] += 20;
		}
		else if (direction == 2) {
			snk[0][1] += 20;
		}
		else if (direction == 3) {
			snk[0][0] -= 20;
		}
		else if (direction == 4) {
			snk[0][1] -= 20;
		}


		if (abs(snk[0][0] - baitx1) < 20 && abs(snk[0][1] - baity1) < 20) {
			printf("%d\n", ++cnt);
			baitx1 = rand() % 550;
			baity1 = rand() % 550;
		}


		for (i = 49; i > 0; i--) {
			if (abs(snk[0][0] - snk[i][0]) < 20 && abs(snk[0][1] - snk[i][1]) < 20) {
				printf("cortladiniz");
				system("pause");
			}
		}


		for (i = cnt; i > 0; i--) {
			snk[i][0] = snk[i - 1][0];
			snk[i][1] = snk[i - 1][1];
		}


		al_draw_filled_rectangle(baitx1, baity1, baitx1 + 20, baity1 + 20, al_map_rgb(255, 255, 255));


		for(i = 0; i < cnt; i++){
			al_draw_filled_rectangle(snk[i][0], snk[i][1], snk[i][0] + 20, snk[i][1] + 20, al_map_rgb(255, 255, 255));
		}



		al_flip_display();

	
		
	}


	system("pause");
	al_destroy_display(display);
	al_destroy_event_queue(queue);

	return 0;
}