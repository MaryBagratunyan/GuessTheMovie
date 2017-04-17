#pragma once

#include <string>

struct Image
{
	Image(const std::string& path_to_pic) : path_to_pic(path_to_pic) {}

	std::string path_to_pic;
};
