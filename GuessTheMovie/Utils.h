#pragma once

#include <string>
#include <vector>
#include <sstream>

typedef std::string Film;

struct Link
{
	Link(const std::string link) : link(link) {};
	std::string link;
};

std::vector<std::string> split_the_string(const std::string& s)
{
	std::vector<std::string> words;
	std::istringstream iss(s);

	while (iss)
	{
		std::string substr;
		iss >> substr;
		words.push_back(substr);
	}

	return words;
}

std::string film_to_link(const Film& film)
{
	std::vector<std::string> words = split_the_string(film);
	if (words.size() == 1)
		return words[0];

	std::string result = words[0] + '+';
	for (int i = 1; i < words.size(); ++i)
	{
		result += words[i] + '+';
	}
	result.pop_back();

	return result;
}