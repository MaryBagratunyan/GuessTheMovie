#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <curl/curl.h>
#include <vector>

#include "Utils.h"
#include "CurlInit.h"


struct Downloader
{
	bool download(const Link& link, const std::string& save_to, std::string image_name)
	{
		curl_global_init(CURL_GLOBAL_ALL);
		std::string path = save_to + "\\" + image_name + (link.link).substr((link.link).find_last_of('.'));

		std::ofstream ofs(path, std::ostream::binary);

		if (CURLE_OK == curl_read(link.link, ofs))
		{
			std::cout << "The image " << image_name << " is succesfully downloaded to this path: " << save_to << std::endl;
			return true;
		}

		std::cout << "Downloading failed\n";
		return false;
	}

	bool download(const std::vector<Link>& links, const std::string& save_to)
	{
		int image_name = 1;
		for (int i = 0; i < links.size(); ++i)
		{
			std::ostringstream oss;
			oss << image_name;
			if (!download(links[i], save_to, oss.str()))
			{
				return false;
			}
			++image_name;
		}
		return true;
	}
};