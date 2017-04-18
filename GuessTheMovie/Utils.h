#pragma once
#include <string>

typedef std::string Film;

struct Link
{
	Link(const std::string link) : link(link) {};
	std::string link;
};
