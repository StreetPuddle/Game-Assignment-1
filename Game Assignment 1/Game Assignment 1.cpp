#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <ctime>

//creates color based on randomly selected int values
//returns a mapping of int values to form color
ALLEGRO_COLOR makeColor();

//draws a randomly colored pixel on a portion of the screen
//@param color randomly generated color from makeColor() function
//@param SCREEN_W the screen's width, an int
//@param SCREEN_H the screen's height, an int
void draw_random_pixel(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H);

//draws a randomly colored and sized hollow ellipse on a portion of the screen
//@param color randomly generated color from makeColor() function
//@param SCREEN_W the screen's width, an int
//@param SCREEN_H the screen's height, an int
void draw_random_ellipse(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H);

//draws a randomly sized and color filled ellipse on a portion of the screen
//@param color randomly generated color from makeColor() function
//@param SCREEN_W the screen's width, an int
//@param SCREEN_H the screen's height, an int
void draw_random_filled_ellipse(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H);

//draws a randomly colored and sized line on a portion of the screen
//@param color randomly generated color from makeColor() function
//@param SCREEN_W the screen's width, an int
//@param SCREEN_H the screen's height, an int
void draw_random_lines(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H);

//draws a randomly colored and sized hollow rectangle on a portion of the screen
//@param color randomly generated color from makeColor() function
//@param SCREEN_W the screen's width, an int
//@param SCREEN_H the screen's height, an int
void draw_random_rectangles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H);

//draws a randomly sized and color filled rectangle on a portion of the screen
//@param color randomly generated color from makeColor() function
//@param SCREEN_W the screen's width, an int
//@param SCREEN_H the screen's height, an int
void draw_random_filled_rectangles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H);

//draws a randomly colored and sized hollow circle on a portion of the screen
//@param color randomly generated color from makeColor() function
//@param SCREEN_W the screen's width, an int
//@param SCREEN_H the screen's height, an int
void draw_random_circles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H);

//draws a randomly sized and color filled cicle on a portion of the screen
//@param color randomly generated color from makeColor() function
//@param SCREEN_W the screen's width, an int
//@param SCREEN_H the screen's height, an int
void draw_random_filled_circles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H);

//draws a randomly sized and color filled triangle on a portion of the screen
//@param color randomly generated color from makeColor() function
//@param SCREEN_W the screen's width, an int
//@param SCREEN_H the screen's height, an int
void draw_random_filled_triangles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H);

//randomly generating four points within the screen, to calculate a spline's trajectory
//@param points[]
//@param size
//@param width
//@param height
void getPoints(float points[], int size, int width, int height);

int main(int argc, char* argv[]) {

	using namespace std;
	int width = 800;
	int height = 600;
	srand(time(NULL));

	//timer, gets current time and declared duration
	time_t startTime = time(nullptr);
	int duration = 20;

	ALLEGRO_DISPLAY* display = NULL;

	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro!\n");
		return -1;
	}

	display = al_create_display(width, height);
	if (!display) {
		fprintf(stderr, "Failed to create display!");
		return -1;
	}

	al_init_primitives_addon();
	al_clear_to_color(al_map_rgb(50, 25, 100));

	//while loop that lasts 20 seconds
	while (time(nullptr) - startTime < duration) {

		//drawing stars :D
		draw_random_pixel(makeColor(), 800, 600);

		//ground
		al_draw_filled_ellipse(width / 2, height, 750, 135, al_map_rgb(0, 150, 125));

		//cat body
		al_draw_filled_ellipse(width / 1.55, height / 1.8, 75, 150, al_map_rgb(0, 0, 0));

		//cat head
		float cx = width / 2.0;
		float cy = height / 2.0;
		al_draw_filled_triangle(cx - 300, cy - 180, cx + 300, cy - 180, cx, cy, al_map_rgb(0, 0, 0));

		//cat eyes
		al_draw_filled_ellipse(width / 2.6, height / 3.75, 75, 20, al_map_rgb(255, 255, 255));
		al_draw_filled_ellipse(width / 1.6, height / 3.75, 75, 20, al_map_rgb(255, 255, 255));
		al_draw_filled_ellipse(width / 2.6, height / 3.75, 10, 20, al_map_rgb(255, 200, 0));
		al_draw_filled_ellipse(width / 1.6, height / 3.75, 10, 20, al_map_rgb(255, 200, 0));
		al_draw_line(width / 2.6, height / 3.0, width / 2.6, height / 4.25, al_map_rgb(0, 0, 0), 2);
		al_draw_line(width / 1.6, height / 3.0, width / 1.6, height / 4.25, al_map_rgb(0, 0, 0), 2);

		//cat nose
		al_draw_filled_triangle(cx - 15, cy - 75, cx + 15, cy - 75, cx, cy - 65, al_map_rgb(255, 150, 170));

		//cat ears
		al_draw_filled_triangle(cx - 200, cy - 180, cx - 60, cy - 180, cx - 150, cy - 280, al_map_rgb(0, 0, 0));
		al_draw_filled_triangle(cx + 250, cy - 180, cx + 100, cy - 180, cx + 200, cy - 280, al_map_rgb(0, 0, 0));

		//cat legs
		al_draw_filled_rectangle(width / 1.5, height / 1.23, width / 2.0, height / 1.3, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(width / 1.95, height / 1.28, 20, al_map_rgb(0, 0, 0));
		al_draw_line(width / 2.2, height / 1.24, width / 1.65, height / 2.5, al_map_rgb(0, 0, 0), 20);
		al_draw_filled_circle(width / 2.2, height / 1.28, 20, al_map_rgb(0, 0, 0));

		//cat tail
		float points[8] = { 550, 455, 650, 400, 500, 700, 780, 500 };
		al_draw_spline(points, al_map_rgb(0, 0, 0), 20);
		al_draw_filled_circle(780, 500, 10, al_map_rgb(0, 0, 0));

		al_flip_display();
	}

	al_destroy_display(display);

	return 0;
}

ALLEGRO_COLOR makeColor() {
	int red = rand() % 255;
	int green = rand() % 255;
	int blue = rand() % 255;

	return (al_map_rgb(red, green, blue));
}

void draw_random_pixel(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = rand() % (SCREEN_W);
	int y = rand() % (SCREEN_H);

	al_put_pixel(x, y, color);
}

void draw_random_ellipse(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 200 - rand() % (SCREEN_W);
	int y = 300 + rand() % (SCREEN_H);
	if (x < 1) x = 100;
	if (y < 1) y = 100;
	int rx = rand() % (x - 101);
	int ry = rand() % (y - 101);
	if (rx < 1) rx = 1;
	if (ry < 1) rx = 1;
	float thickness = rand() % 5;

	al_draw_ellipse(x, y, rx, ry, color, thickness);
}

void draw_random_filled_ellipse(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 600 + rand() % (SCREEN_W - 600);
	int y = 300 - rand() % (SCREEN_H - 300);
	int rx = rand() % 100;
	int ry = rand() % 100;
	if (rx < 1) rx = 1;
	if (ry < 1) ry = 1;

	al_draw_filled_ellipse(x, y, rx, ry, color);
}
void draw_random_lines(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 400 + rand() % (SCREEN_W - 400);
	int y = 100 - rand() % (SCREEN_H - 100);
	int x1 = 400 + rand() % (SCREEN_W - 400);
	int y1 = 100 - rand() % (SCREEN_H - 100);
	float thickness = rand() % 5;

	al_draw_line(x, y, x1, y1, color, thickness);
}
void draw_random_rectangles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 400 + rand() % (SCREEN_W - 400);
	int y = 250 - rand() % (SCREEN_H - 400);
	int x1 = 400 + rand() % (SCREEN_W - 400);
	int y1 = 250 - rand() % (SCREEN_H - 400);
	float thickness = rand() % 5;

	al_draw_rectangle(x, y, x1, y1, color, thickness);
}
void draw_random_filled_rectangles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 200 - rand() % (SCREEN_W - 200);
	int y = 250 - rand() % (SCREEN_H - 400);
	int x1 = 200 - rand() % (SCREEN_W - 200);
	int y1 = 250 - rand() % (SCREEN_H - 400);

	al_draw_filled_rectangle(x, y, x1, y1, color);
}

void draw_random_circles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = rand() % (SCREEN_W);
	int y = rand() % (SCREEN_H);
	int radius = rand() % 30;
	float thickness = rand() % 5;

	al_draw_circle(x, y, radius, color, thickness);
}
void draw_random_filled_circles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x = 200 + rand() % (SCREEN_W - 450);
	int y = 300 + rand() % (SCREEN_H);
	int radius = rand() % 30;

	al_draw_filled_circle(x, y, radius, color);
}
void draw_random_filled_triangles(ALLEGRO_COLOR color, const int SCREEN_W, const int SCREEN_H) {
	int x1 = 350 - rand() % (SCREEN_W - 500);
	int y1 = 150 + rand() % (SCREEN_H - 300);
	int x2 = 350 - rand() % (SCREEN_W - 500);
	int y2 = 150 + rand() % (SCREEN_H - 300);
	int x3 = 350 - rand() % (SCREEN_W - 500);
	int y3 = 150 + rand() % (SCREEN_H - 300);

	al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, color);
}

void getPoints(float points[], int size, int width, int height) {
	for (int i = 0; i < size; i += 2) {
		points[i] = rand() % width;
		points[i + 1] = rand() % height;
	}
}