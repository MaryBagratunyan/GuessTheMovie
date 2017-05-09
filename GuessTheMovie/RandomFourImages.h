#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <iostream>

#include "Utils.h"

struct RandomFourImages
{
	std::vector<Link> random_four_images(const std::vector<Link>& all_URLs)
	{
		// Generating a random number from [0, a] to use as a vector index
		int a = all_URLs.size();

		// In order not to choose the same image twice
		std::vector<int> used_indexes;

		std::vector<Link> image_vector;
		int count = 4;
		while (count > 0)
		{
			srand(time(NULL));
			int index = rand() % a;
			if (std::find(used_indexes.begin(), used_indexes.end(), index) == used_indexes.end())
			{
				image_vector.push_back(all_URLs[index]);
				used_indexes.push_back(index);
				--count;
			}
		}

		std::cout << "Random vector is generated\n";
		return image_vector;
	}

};
