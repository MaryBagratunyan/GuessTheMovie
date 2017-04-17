#pragma once
#include <vector>

#include "ImageStorage.h"
#include "Image.h"

struct FilmToImageAlgorithm
{
	FilmToImageAlgorithm(): storage(ImageStorage()) {}

	Image process_film_name(const std::string& film_name)
	{
		std::vector<Image> im = storage.get_images_by_film_name(film_name);
		return combine_images(im);
	}

	// TODO: do some smart stuff here
	Image combine_images(const std::vector<Image>& images)
	{
		return images[0];  // this is a dummy, dude, be careful!
	}

	ImageStorage storage;

};
