#pragma once

#include <fstream>
#include <algorithm>
#include <iostream>

#include "Utils.h"

struct GetSiteURLFromText
{
	Link extract_site_link(const std::string& path)
	{
		std::string txt_path = path + "\\http_response.txt";
		std::ifstream ifs(txt_path);
		std::string temp = "   \"link\":";
		while (ifs.is_open())
		{
			std::string s;
			std::getline(ifs, s);
			if (s.empty())
				continue;

			bool match = true;
			for (int i = 0; i < temp.size(); ++i)
			{
				if (temp[i] != s[i])
				{
					match = false;
					break;
				}
			}

			if (match)
			{
				std::string res = s.substr(12);
				res.pop_back();
				res.pop_back();
				std::cout << "The extracted link of site is: " << res << std::endl;
				return Link(res);
			}
		}
	}

	Link site_gallery_link(const Link& site_link)
	{
		std::string temp = "mediaindex?refine=still_frame&ref_=ttmi_ref_sf";
		std::cout << "The link for photos is: " << site_link.link + temp << std::endl;
		return Link(site_link.link + temp);
	}
};
