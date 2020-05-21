#include "MapLoader.h"

MapLoader::MapLoader(std::string file)
{
	map.LoadFile(file.c_str());
}
