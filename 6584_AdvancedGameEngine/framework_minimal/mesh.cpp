#pragma once

#include "mesh.h"

Mesh::Mesh(const char* id)
	: Asset(id)
{
}
Mesh::~Mesh()
{
}

const std::vector<GLfloat> Mesh::verticies() const
{
	return _verticies;
}