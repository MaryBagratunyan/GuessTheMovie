#include <iostream>
#include <string>
#include "FilmToImageAlgorithm.h"
#include "ImageDisplayer.h"
#include "ImageSearchAlgorithm.h"


int main()
{
	// TODO: cover all functions with logs


	std::string film_name;
	std::cin >> film_name;



	FilmToImageAlgorithm algorithm;

	Image image = algorithm.process_film_name(film_name);

	ImageDisplayer displayer;
	displayer.show(image);

}