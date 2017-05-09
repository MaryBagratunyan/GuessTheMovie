#pragma once
#include <iostream>
#include <vector>
#include <boost\filesystem.hpp>

#include "Image.h"
#include "Utils.h"



struct ImageStorage
{
	ImageStorage() 
	{
		path_base = "storage/";
	}

	void create_folder(const std::string& path) 
	{
        std::cout << "Creating folder at " << path << std::endl;
		if (boost::filesystem::create_directories(path))
		 std::cout << "Finished creating folder at " << path << std::endl;
	}
	
	bool does_folder_exist(const std::string& path)
	{
		return boost::filesystem::exists(path);	
	}

	
	bool is_folder_empty(const std::string& path)
	{
		return boost::filesystem::is_empty(path);
	}

	
	std::string get_film_folder_path(const Film& film_name)
	{
		std::vector<std::string> words = split_the_string(film_name);
		std::string result;
		for (int i = 0; i < words.size(); ++i)
		{
			if (words[i][0] >= 'a' && words[i][0] <= 'z')
			{
				words[i][0] = (words[i][0] - 'a') + 'A';
			}

			result += words[i];
		}

		return path_base + result;
	}

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
