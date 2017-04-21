#pragma once
#include <iostream>
#include <vector>
#include <boost\filesystem.hpp>
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

	// TODO: implement this function
	void create_folder(const std::string& path) 
	{
        std::cout << "Creating folder at " << path << std::endl;
		if (boost::filesystem::create_directories(path))
		 std::cout << "Finished creating folder at " << path << std::endl;
	}
	// TODO: implement this function
	bool does_folder_exist(const std::string& path)
	{
		return boost::filesystem::exists(path);	
	}

	// TODO: implement this function
	bool is_folder_empty(const std::string& path)
	{
		return boost::filesystem::is_empty(path);
	}

	// TODO: check this function for complex film names
	std::string get_film_folder_path(const Film& film_name)
	{
		return path_base + film_name;
	}

	std::vector<Image> get_folder_images(const std::string& path)
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
