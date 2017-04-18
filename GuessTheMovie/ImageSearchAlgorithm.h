#pragma once
#include <vector>
#include <string>
#include "Utils.h"
#include "Link.h"
#include "ImageSearcher.h"
#include "Downloader.h"
#include "SuggestionGenerator.h"


struct ImageSearchAlgorithm
{
	SuggestionGenerator suggen;
	ImageSearcher imsear;
	Downloader down;
	std::string folder_name;
	void image_search_algorithm_in_use(const Film& film_name)
	{
		std::vector<std::string> suggestions = suggen.generate(film_name);
		std::vector<Link> links = imsear.search_for(suggestions);
		for (int i = 0; i < links.size(); ++i)
		{
			down.download(links[i], folder_name);
		}

	}
};
