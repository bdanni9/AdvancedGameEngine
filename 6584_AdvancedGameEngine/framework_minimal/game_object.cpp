#pragma once

#include "game_object.h"
#include "scene.h"
#include "configuration.h"

Game_Object::Game_Object(const char* id)
	: _id(id)
{
}
Game_Object::~Game_Object()
{
}

const char* Game_Object::id() const
{
	return _id;
}

void Game_Object::simulate_physics(const double, const Assets*, const Scene*, const Configuration*)
{
}