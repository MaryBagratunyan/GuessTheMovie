#pragma once
#include <vector>

#include "ImageSearchAlgorithm.h"
#include "Image.h"

struct FilmToImageAlgorithm
{
	Image process_film_name(const std::string& film_name)
	{
		ImageSearchAlgorithm searcher(film_name);
		std::vector<Image> im = searcher.get_images();
		return combine_images(im);
	}

	// TODO: do some smart stuff here
	Image combine_images(const std::vector<Image>& images)
	{
		if (!images.empty())
		{
			
			return images[0]; // this is a dummy, dude, be careful!
		}
		else
			return "Don't believe aliens.You didn't download image";
	}
};
