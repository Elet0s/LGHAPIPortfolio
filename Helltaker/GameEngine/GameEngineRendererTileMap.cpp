#include "GameEngineRendererTileMap.h"

float4 GameEngineRendererTileMap::GetWorldPostion(int _X, int _Y)
{
	float4 ReturnPos = TileSize_;

	ReturnPos.x *= _X;
	ReturnPos.y *= _Y;
	ReturnPos += TileSizeHalf_;

	return ReturnPos;
}

TileIndex GameEngineRendererTileMap::GetTileIndex(const float4& _Pos)
{
	return { static_cast<int>(_Pos.x / TileSize_.x), static_cast<int>(_Pos.y / TileSize_.y) };
}


void GameEngineRendererTileMap::DeleteTile(int _X, int _Y)
{
	if (nullptr == Tiles_[_Y][_X])
	{
		return;
	}

	delete Tiles_[_Y][_X];
	Tiles_[_Y][_X] = nullptr;
}

GameEngineRendererTileMap::GameEngineRendererTileMap(GameEngineActor* _Actor)
	: Master_(_Actor)
{
}

GameEngineRendererTileMap::~GameEngineRendererTileMap()
{
	for (size_t y = 0; y < Tiles_.size(); y++)
	{
		for (size_t x = 0; x < Tiles_[y].size(); x++)
		{
			if (nullptr == Tiles_[y][x])
			{
				continue;
			}
			delete Tiles_[y][x];
			Tiles_[y][x] = nullptr;
		}
	}
}