#pragma once
#include "tinyxml2.h"
#include <string>
class MapLoader
{
	tinyxml2::XMLDocument map;
public:
	MapLoader(std::string file);
};

