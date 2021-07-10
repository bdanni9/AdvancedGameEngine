#include "assets.h"
#include "shader.h"
#include "texture.h"

#define GLEW_STATIC
#include <glew.h>

#include <iostream>

Assets::Assets()
{
}
Assets::~Assets()
{
}

const Asset* Assets::get_asset(const char* id) const
{
	if(_assets.find(id) == _assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID: " << id << std::endl;
		exit(1);
	}

	return _assets.find(id)->second;
}