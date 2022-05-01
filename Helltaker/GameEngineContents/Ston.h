#pragma once
#include "PlayerEnums.h"
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRendererTileMap.h>

class Ston : public Tile
{
public:

	Ston();
	~Ston();


	Ston(const Ston& _Other) = delete;
	Ston(Ston&& _Other) noexcept = delete;
	Ston& operator=(const Ston& _Other) = delete;
	Ston& operator=(Ston&& _Other) noexcept = delete;
};