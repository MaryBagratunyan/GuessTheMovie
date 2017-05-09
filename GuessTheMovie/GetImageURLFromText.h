#pragma once

#include <fstream>
#include <algorithm>
#include <iostream>

#include "Utils.h"
#include "Image.h"

int str_to_int(std::string& s)
{
	for (int i = s.size() - 1; i >= 0; --i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			break;
		}
		else
		{
			s.pop_back();
		}
	}
	int res = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		res += (s[i] - '0')*pow(10, s.size() - i - 1);
	}
	return res;
}


struct GetImageURLFromText
{
	std::vector<Link> extract_image_url(const std::string& path)
	{
		std::string txt_path = path + "\\html.txt";
		std::ifstream ifs(txt_path);

		int unneunnecessary_strings = 765;
		while (unneunnecessary_strings > 0)
		{
			std::string s;
			std::getline(ifs, s);
			--unneunnecessary_strings;
		}

		std::string temp = "src=\"";
		std::string start_from = "    <div class=\"media_index_pagination leftright\">";
		bool need_to_check = true;
		int count = 0;
		std::vector<Link> v;

		while (ifs.is_open())
		{
			std::string s;
			std::getline(ifs, s);
			if (need_to_check && (s != start_from))
			{
				continue;
			}

			if (need_to_check && (s == start_from))
			{
				need_to_check = false;
				std::string s;
				std::getline(ifs, s);
				std::string num;
				if (s.find("1-") == std::string::npos)
				{
					num = s.substr(35, 4);
				}
				else
					num = s.substr(37, 4);
				count = str_to_int(num);
				continue;
			}

			if (count > 30)
				count = 30;

			while (count > 0)
			{
				bool match = true;
				std::string s;
				std::getline(ifs, s);

				if (s.empty())
					continue;

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
					std::string temp = "_V1";
					auto it = std::search(s.begin(), s.end(), temp.begin(), temp.end());
					std::string res = s.substr(5, it - s.begin() - 2) + ".jpg";
					v.push_back(Link(res));
					--count;
				}
			}
			std::cout << "The URLs are succesfully exracted\n";
			return v;
		}
	}
};
