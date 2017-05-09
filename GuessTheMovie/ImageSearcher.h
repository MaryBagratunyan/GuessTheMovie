#pragma once

#include <vector>

#include "SendHttpRequest.h"
#include "GetSiteURLFromText.h"
#include "GetImageURLFromText.h"
#include "RandomFourImages.h"
#include "Utils.h"
#include "ImageStorage.h"


// As the initial version of the project will get Image URLs from
// one site, instead of searching for generated suggestions, I am going to
// make some temporary changes in ImageSearcher's struct
struct ImageSearcher
{
	Link search_for(const Film& film)
	{
		ImageStorage image_storage;
		std::string path = image_storage.get_film_folder_path(film);

		SendHttpRequest send_request;
		send_request.search_for_movie(film, path);

		GetSiteURLFromText get_url;

		return Link(get_url.extract_site_link(path));
	}
	
	std::vector<Link> total_search_result(const Film& film)
	{
		Link link = search_for(film);

		ImageStorage image_storage;
		std::string path = image_storage.get_film_folder_path(film);

		GetSiteURLFromText get_site_url;
		Link gallery_link(get_site_url.site_gallery_link(link));

		SendHttpRequest send_request;
		send_request.search_for_images(gallery_link, path);

		GetImageURLFromText get_url;
		std::vector<Link> all_links = get_url.extract_image_url(path);

		RandomFourImages random_images;
		std::vector<Link> linklist = random_images.random_four_images(all_links);

		return linklist;
	}

};