#pragma once

#include "game_object.h"

class Square_Box : public Game_Object
{
public:
	Square_Box(const char* id);
	~Square_Box();

	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;
private:
	float _total_time_s;

};
