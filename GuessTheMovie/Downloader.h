#pragma once

#include <iostream>
#include <vector>
#include "Utils.h"

struct Downloader
{
	// TODO: make the function really download an image from internet :)
	bool download(const Link& link, const std::string& save_to)
	{
		std::cout << "The image is succesfully downloaded to this path: " << save_to << std::endl;
		return true;
	}

	bool download(const std::vector<Link>& links, const std::string& save_to)
	{
		for (int i = 0; i < links.size(); ++i)
		{
			download(links[i], save_to);
		}

		return true;
	}
};