#include "assets.h"
#include "shader.h"
#include "texture.h"
#include "Triangle_Mesh.h"
#include "Square_Mesh.h"
#include "colored_2D_shader_program.h"

#define GLEW_STATIC
#include <glew.h>

#include <iostream>

Assets::Assets()
{
	Triangle_Mesh* tringle_mesh = new Triangle_Mesh();
	_assets.insert({ tringle_mesh->id(), tringle_mesh });

	Shader* colored_2D_vertex_shader = new Shader("Shader.Colored.2D.Vertex", "Shaders/colored.2D.vertex_shader.glsl", Shader::Type::Vertex);
	_assets.insert({ colored_2D_vertex_shader->id(), colored_2D_vertex_shader });

	Shader* colored_2D_fragment_shader = new Shader("Shader.Colored.2D.Fragment", "Shaders/colored.2D.fragment_shader.glsl", Shader::Type::Fragment);
	_assets.insert({ colored_2D_fragment_shader->id(), colored_2D_fragment_shader });

	Colored_2D_Shader_Program* colored_2D_program = new Colored_2D_Shader_Program(colored_2D_vertex_shader, colored_2D_fragment_shader);
	_assets.insert({ colored_2D_program->id(), colored_2D_program });

	Square_Mesh* square_mesh = new Square_Mesh();
	_assets.insert({ square_mesh->id(), square_mesh });

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