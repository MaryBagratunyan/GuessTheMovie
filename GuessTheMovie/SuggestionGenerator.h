#pragma once
#include <vector>
#include <string>
#include "Utils.h"
struct SuggestionGenerator
{
	//TODO: add more types of suggestions
	std::vector<std::string> generate(const Film& film_name) const
	{
		std::vector<std::string> suggestions;
		suggestions.push_back(film_name);
		return suggestions;
	}
};