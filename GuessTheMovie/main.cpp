#include <iostream>
#include <string>
#include "FilmToImageAlgorithm.h"
#include "ImageDisplayer.h"
#include "ImageSearchAlgorithm.h"


int main()
{
	// TODO: cover all functions with logs

	std::string film_name;
	std::getline(std::cin, film_name);

	FilmToImageAlgorithm algorithm;
	algorithm.process_film_name(film_name);
}