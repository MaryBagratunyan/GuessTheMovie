#pragma once

#include <vector>
#include "Utils.h"


struct ImageSearcher
{
	// TODO: find out how to make searches programmatically
	//and improve the search_for function
	Link search_for(std::string what)
	{
		Link dummylink("https://amazingslider.com/wp-content/uploads/2012/12/dandelion.jpg");
		return dummylink;
	}
	std::vector<Link> total_search_result(const std::vector<std::string>& suggestions)
	{
		std::vector<Link> linklist;
		for (int i = 0; i < suggestions.size(); ++i)
		{
			ImageSearcher searcher;
			linklist.push_back(searcher.search_for(suggestions[i])); 
		}

		return linklist;
	}

};