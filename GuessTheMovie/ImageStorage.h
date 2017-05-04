#pragma once
#include <iostream>
#include <vector>
#include <boost\filesystem.hpp>
#include "Image.h"
#include "Utils.h"



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

	/*std::vector<Image> get_folder_images(const std::string& path)
	{
		// This is a dummy content for testing purposes
		std::vector<Image> images;
		for (int i = 0; i < 4; ++i)
		{
			images.push_back(dummy_image());
		}
		return images;
	}*/
	std::vector<Image> get_folder_images(const std::string& path)
	{

		std::vector<Image> image_vector;
		boost::filesystem::directory_iterator it(path);
		const std::vector<std::string> image_extensions = { ".jpg", ".JPG", ".png",".PNG",".gif",".GIF" };
		while (it != boost::filesystem::directory_iterator())
		{
			for (int i = 0; i < image_extensions.size(); ++i)
			{
				if (it->path().extension() == image_extensions[i])
					image_vector.push_back(it->path().string());

			}
			++it;
		}

		return image_vector;
	}
	std::string path_base;
};
