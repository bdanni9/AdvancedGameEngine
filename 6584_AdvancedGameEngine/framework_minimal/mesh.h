#pragma once

#include "asset.h"

#include <vector>

#define GLEW_STATIC
#include <glew.h>

class Mesh : public Asset
{
public:
	Mesh(const char* id);
	~Mesh();

	const std::vector<GLfloat> verticies() const;
protected:
	std::vector<GLfloat> _verticies;
};

