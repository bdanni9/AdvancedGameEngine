#include "pointy_head.h"
#include "colored_2D_shader_program.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>

Pointy_Head::Pointy_Head(const char* id)
	: Game_Object(id)
{
}
Pointy_Head::~Pointy_Head()
{
}


void Pointy_Head::simulate_AI(const double, const Assets*, const Scene*, const Configuration*)
{
}
void Pointy_Head::render(const double, const Assets* assets, const Scene*, const Configuration* config)
{
	std::vector<GLfloat> colors =
	{
		//Used to change the color of the vertices in the triangle
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
	};

	const Colored_2D_Shader_Program* program = (Colored_2D_Shader_Program*)assets->get_asset("Shader_Program.2D.Colored");
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Triangle");

	program->render(config, mesh, &colors);
}