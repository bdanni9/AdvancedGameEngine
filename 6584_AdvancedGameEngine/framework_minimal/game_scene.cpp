#include "game_scene.h"

#include "Pointy_Head.h"
#include "Blocky.h"
#include"Square_Box.h"

Game_Scene::Game_Scene()
	: Scene("Game")
{ 
	/*Pointy_Head* pointy_head = new Pointy_Head("Game_Object.Pointy_Head");
	_game_objects[pointy_head->id()] = pointy_head;*/

	Blocky* blocky = new Blocky("Game_Object.Square_Mesh");
	_game_objects[blocky->id()] = blocky;
}

Game_Scene::~Game_Scene()
{

}

void Game_Scene::update(const double)
{
}