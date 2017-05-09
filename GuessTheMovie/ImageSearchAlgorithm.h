#pragma once

#include "Utils.h"
#include "ImageSearcher.h"
#include "Downloader.h"
#include "SuggestionGenerator.h"
#include "ImageStorage.h"


struct ImageSearchAlgorithm
{
	ImageSearchAlgorithm(const Film& film_name) : film_name(film_name) {}

	std::vector<Image> get_images()
	{
		const std::string film_folder_path = storage.get_film_folder_path(film_name);
		if (!storage.does_folder_exist(film_folder_path))
		{
			storage.create_folder(film_folder_path);
		}

		if (storage.is_folder_empty(film_folder_path))
		{
			create_missing_images();
		}

		return storage.get_folder_images(film_folder_path);
	}

	void create_missing_images()
	{
		std::string path_to_save = storage.get_film_folder_path(this->film_name);

		ImageSearcher searcher;
		std::vector<Link> links = searcher.total_search_result(film_name);

		Downloader downloader;
		downloader.download(links, path_to_save);
	}

	ImageStorage storage;
	Film film_name;
};
