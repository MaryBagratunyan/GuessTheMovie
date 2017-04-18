#pragma once

#include <iostream>
#include "Image.h"

struct ImageDisplayer
{
	// TODO: improve this!
	void show(const Image& image)
	{
		std::cout << image.path_to_pic << std::endl;
	}
};