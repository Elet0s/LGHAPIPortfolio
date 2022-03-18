#pragma once
#include"GameEngineImageManager.h"
#include<map>
class GameEngineImageManager
{
private:
	static GameEngineImageManager* Inst_;
public:
	static GameEngineImageManager* GetInst()
	{
		return Inst_;
		static void Destroy()
		{
			if (true)
			{

			}
		}
	}

private:
	// constrcuter destructer
	GameEngineImageManager();
	~GameEngineImageManager();

	// delete Function
	GameEngineImageManager(const GameEngineImageManager& _Other) = delete;
	GameEngineImageManager(GameEngineImageManager&& _Other) noexcept = delete;
	GameEngineImageManager& operator=(const GameEngineImageManager& _Other) = delete;
	GameEngineImageManager& operator=(GameEngineImageManager&& _Other) noexcept = delete;
private:
	std::map<std::string, GameEngineImage>
};