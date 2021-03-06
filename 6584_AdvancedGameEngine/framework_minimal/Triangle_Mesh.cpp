#pragma once
#include "triangle_mesh.h"

Triangle_Mesh::Triangle_Mesh()
	: Mesh("Mesh.Triangle")
{
	//These are used to make the vertice of the triangle 
	_verticies.insert(_verticies.end(), { -0.5f, -0.5f }); // v1
	_verticies.insert(_verticies.end(), { 0.0f, 0.5f });   // v2
	_verticies.insert(_verticies.end(), { 0.5f, -0.5f });  // v3
}
Triangle_Mesh::~Triangle_Mesh()
{
} 