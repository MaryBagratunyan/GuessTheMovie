#pragma once
#include <vector>
#include <iostream>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "ImageSearchAlgorithm.h"
#include "Image.h"

ALLEGRO_BITMAP *load_bitmap_at_size(const char *filename, int w, int h)
{
	ALLEGRO_BITMAP *resized_bmp, *loaded_bmp, *prev_target;

	resized_bmp = al_create_bitmap(w, h);
	if (!resized_bmp) return NULL;

	loaded_bmp = al_load_bitmap(filename);
	if (!loaded_bmp)
	{
		al_destroy_bitmap(resized_bmp);
		return NULL;
	}

	prev_target = al_get_target_bitmap();
	al_set_target_bitmap(resized_bmp);

	al_draw_scaled_bitmap(loaded_bmp,
		0, 0,
		al_get_bitmap_width(loaded_bmp),
		al_get_bitmap_height(loaded_bmp),
		0, 0,
		w, h,
		0
	);

	al_set_target_bitmap(prev_target);
	al_destroy_bitmap(loaded_bmp);

	return resized_bmp;
}

struct FilmToImageAlgorithm
{
	void process_film_name(const std::string& film_name)
	{
		ImageSearchAlgorithm searcher(film_name);
		std::vector<Image> im = searcher.get_images();
		combine_images(im);
	}

	void combine_images(const std::vector<Image>& images)
	{
		if (!images.empty())
		{
			ALLEGRO_DISPLAY *display = NULL;
			ALLEGRO_BITMAP  *image1 = NULL;
			ALLEGRO_BITMAP  *image2 = NULL;
			ALLEGRO_BITMAP  *image3 = NULL;
			ALLEGRO_BITMAP  *image4 = NULL;
			
			if (!al_init()) {
				al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",
					NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			if (!al_init_image_addon()) {
				al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
					NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			display = al_create_display(600, 600);
			
			if (!display) {
				al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
					NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			const char * im1 = (images[0].path_to_pic).c_str();
			const char * im2 = (images[1].path_to_pic).c_str();
			const char * im3 = (images[2].path_to_pic).c_str();
			const char * im4 = (images[3].path_to_pic).c_str();

			image1 = load_bitmap_at_size(im1, 300, 300);
			image2 = load_bitmap_at_size(im2, 300, 300);
			image3 = load_bitmap_at_size(im3, 300, 300);
			image4 = load_bitmap_at_size(im4, 300, 300);
			
			if ((!image1)) {
				al_show_native_message_box(display, "Error", "Error", "Failed to load image1!",
					NULL, ALLEGRO_MESSAGEBOX_ERROR);
				al_destroy_display(display);
			}
			
			if ((!image2)) {
				al_show_native_message_box(display, "Error", "Error", "Failed to load image2!",
					NULL, ALLEGRO_MESSAGEBOX_ERROR);
				al_destroy_display(display);
			}
			
			if ((!image3)) {
				al_show_native_message_box(display, "Error", "Error", "Failed to load image3!",
					NULL, ALLEGRO_MESSAGEBOX_ERROR);
				al_destroy_display(display);
			}
			
			if ((!image4)) {
				al_show_native_message_box(display, "Error", "Error", "Failed to load image4!",
					NULL, ALLEGRO_MESSAGEBOX_ERROR);
				al_destroy_display(display);
			}
			
			al_draw_bitmap(image1, 0, 0, 0);
			al_draw_bitmap(image2, 0, 300, 0);
			al_draw_bitmap(image4, 300, 300, 0);
			al_draw_bitmap(image3, 300, 0, 0);
			al_flip_display();
			al_rest(6);
			al_destroy_display(display);
			al_destroy_bitmap(image1);
			
			std::cout << "Succesfully combined\n";
		}
		else
		{
			std::cout << "Combining failed\n";
		}
	}
};
