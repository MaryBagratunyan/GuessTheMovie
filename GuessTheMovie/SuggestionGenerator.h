#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

#include "Utils.h"

bool is_word_not_linking(const std::string& s)
{
	// TODO: make this function into a function (struct with operator ())
	// and it should have linking_words as a static member
	std::vector<std::string> linking_words = {
		"a", "the", "of", "in", "A", "The", "Of", "In"
	};

	return std::find(linking_words.begin(), linking_words.end(), s) == linking_words.end();
}

// This struct is not needed yet
struct SuggestionGenerator
{

	// TODO: improve this generator
	std::vector<std::string> generate(const Film& film_name)
	{
		auto suggestions = split_the_string(film_name);
		std::vector <std::string> final_suggestions;

		std::copy_if(suggestions.begin(), suggestions.end(), std::back_inserter(final_suggestions), is_word_not_linking);
		
		return suggestions;
	}
};