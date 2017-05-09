#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <curl/curl.h>

#include "Utils.h"
#include "CurlInit.h"


struct SendHttpRequest
{
	void search_for_movie(const Film& film_name, const std::string& path)
	{
		std::ofstream ofs(path + "\\http_response.txt");
		// Google custom search key(key) - AIzaSyCpjmisdo4rO1nHUk86MUvxgAt-T1wv6wE
		// Custom search engine ID(cx) - 005197290287553271722:qz4z4hoqhmc
		std::string search_link = "https://www.googleapis.com/customsearch/v1?key=AIzaSyCpjmisdo4rO1nHUk86MUvxgAt-T1wv6wE&amp;&cx=005197290287553271722:qz4z4hoqhmc&amp;&q=" + film_to_link(film_name) + "&amp;alt=json";
		if (CURLE_OK == curl_read(search_link, ofs))
		{
			std::cout << "The HTTP response is succesfully written to a http_response.txt\n";
		}

		curl_global_cleanup();
	}

	void search_for_images(const Link& link, const std::string& path)
	{
		std::ofstream ofs(path + "\\html.txt");
		if (CURLE_OK == curl_read(link.link, ofs))
		{
			std::cout << "The html file is succesfully written to a html.txt\n";
		}

		curl_global_cleanup();
	}
};