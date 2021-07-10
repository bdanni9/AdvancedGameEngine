#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cstdio>

#include "engine.h"
#include "game_object.h"
#include "expectations.h"
#include "configuration.h"
#include "scene.h"
#include "assets.h"
#include "texture.h"

#define GLEW_STATIC
#include <glew.h>

#include <glfw3.h>

Engine::Engine(const char* game_name, Configuration* config)
{
	const auto initialize_glfw = [this, game_name, config]()
	{
		expect(glfwInit() == GLFW_TRUE, "Failed to initialize GLFW");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		_window = glfwCreateWindow(config->screen_width, config->screen_height, game_name, NULL, NULL);
		expect(_window != nullptr, "failed to create GLFW Window");
		glfwMakeContextCurrent(_window);
	};

	const auto initialize_glew = [this]()
	{
		glewExperimental = GL_TRUE;
		const GLenum init_result = glewInit();
		expect(glewInit() == GLEW_OK, (char*)glewGetErrorString(init_result));


	};

	initialize_glfw();
	initialize_glew();

}
Engine::~Engine()
{
}
void Engine::simulate(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	simulate_AI(seconds_to_simulate, assets, scene, config);
	simulate_physics(seconds_to_simulate, assets, scene, config);
	render(seconds_to_simulate, assets, scene, config);
}
void Engine::simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	for(auto game_object : scene->get_game_objects())
	{
		game_object->simulate_AI(seconds_to_simulate, assets, scene, config);
	}
}
void Engine::simulate_physics(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	for(auto game_object : scene->get_game_objects())
	{
		game_object->simulate_physics(seconds_to_simulate, assets, scene, config);
	}
}
void Engine::render(const double, const Assets*, const Scene*, const Configuration*)
{	
}

GLFWwindow* Engine::window() const
{
	return _window;
}