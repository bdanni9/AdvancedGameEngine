#pragma once

#include "square_mesh.h"

Square_Mesh::Square_Mesh()
	: Mesh("Mesh.Square")
{
	_verticies.insert(_verticies.end(), { -0.5f, 0.5f });  // v1
	_verticies.insert(_verticies.end(), { -0.5f, -0.5f }); // v2
	_verticies.insert(_verticies.end(), { 0.5f, -0.5f });  // v3
	_verticies.insert(_verticies.end(), { -0.5f, 0.5f });  // v1
	_verticies.insert(_verticies.end(), { 0.5f, -0.5f });  // v3
	_verticies.insert(_verticies.end(), { 0.5f, 0.5f });   // v4
}
Square_Mesh::~Square_Mesh()
{
}