#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRendererTileMap.h>
class Helper :	public Tile
{
public:
	// constrcuter destructer
	Helper();
	~Helper();

	// delete Function
	Helper(const Helper& _Other) = delete;
	Helper(Helper&& _Other) noexcept = delete;
	Helper& operator=(const Helper& _Other) = delete;
	Helper& operator=(Helper&& _Other) noexcept = delete;
};