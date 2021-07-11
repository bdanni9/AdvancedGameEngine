#include "Blocky.h"
#include "colored_2D_shader_program.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>

Blocky::Blocky(const char* id)
	: Game_Object(id)
{
	_total_time_s = 0;

}
Blocky::~Blocky()
{
}


void Blocky::simulate_AI(const double, const Assets*, const Scene*, const Configuration*)
{

}
void Blocky::render(const double seconds_to_simulate, const Assets* assets, const Scene*, const Configuration* config)
{
	_total_time_s += (float)seconds_to_simulate;

	/*
	std::vector<GLfloat> colors =
	{
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
	};
	*/
	std::vector<GLfloat> colors =
	{
		sinf(_total_time_s), cosf(_total_time_s), tanf(_total_time_s), 1.0f,
		sinf(_total_time_s), cosf(_total_time_s), tanf(_total_time_s), 1.0f,
		sinf(_total_time_s), cosf(_total_time_s), tanf(_total_time_s), 1.0f,
		sinf(_total_time_s), cosf(_total_time_s), tanf(_total_time_s), 1.0f,
		sinf(_total_time_s), cosf(_total_time_s), tanf(_total_time_s), 1.0f,
		sinf(_total_time_s), cosf(_total_time_s), tanf(_total_time_s), 1.0f,
	};

	const Colored_2D_Shader_Program* program = (Colored_2D_Shader_Program*)assets->get_asset("Shader_Program.2D.Colored");
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Square");

	program->render(config, mesh, &colors);
}