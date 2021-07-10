#pragma once

#include <string>
#include <iostream>

class Assets;
class Input;
struct Configuration;
class Scene;

class Game_Object
{
public:
	Game_Object(const char* id);
	~Game_Object();

	const char* id() const;

	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) = 0;
	virtual void simulate_physics(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config);
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) = 0;

protected:
	const char* _id;
};