#pragma once
#include <iostream>
#include <vector>
#include "Image.h"
#include "Utils.h"

Image dummy_image()
{
	return Image("Hello World");
}

struct ImageStorage
{
	// TODO: here we should check that folder /storage exists, otherwise
	// we should create it!
	ImageStorage() 
	{
		path_base = "storage/";
	}

	// TODO: this should work as follows:
	// check if the folder /storage/film_name exists
	// if it exists, then return its contents
	// otherwise create it and use something to generate them
	std::vector<Image> get_images_by_film_name(const Film& film_name)
	{
		const std::string film_folder_path = get_film_folder_path(film_name);
		if (!does_folder_exist(film_folder_path))
		{
			create_folder(film_folder_path);
		}
		
		if (is_folder_empty(film_folder_path))
		{
			create_missing_images(film_name, film_folder_path);
		}
		
		return get_folder_contents(film_folder_path);
	}

	// TODO: implement this function
	void create_folder(const std::string& path) 
	{
		std::cout << "Creating folder at " << path;

		std::cout << "Finished creating folder at " << path;
	}
	// TODO: implement this function
	bool does_folder_exist(const std::string& path) { return false; }

	// TODO: implement this function
	bool is_folder_empty(const std::string& path) { return true; }

	// TODO: check this function for complex film names
	std::string get_film_folder_path(const Film& film_name)
	{
		return path_base + film_name;
	}

	// TODO: implement this function
	void create_missing_images(const Film& film_name, const std::string& path_to_save) 
	{}

	std::vector<Image> get_folder_contents(const std::string& path)
	{
		// This is a dummy content for testing purposes
		std::vector<Image> images;
		for (int i = 0; i < 4; ++i)
		{
			images.push_back(dummy_image());
		}
		return images;
	}

	std::string path_base;
};
