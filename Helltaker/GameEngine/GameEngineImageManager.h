#pragma once
#include <map>
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineImage.h"

// �⺻������ �����Ǵ� ���ҽ����� ���� �̸��� ���� �Ұ�.
class GameEngineImageManager
{
private:
	static GameEngineImageManager* Inst_;

public:
	static GameEngineImageManager* GetInst()
	{
		return Inst_;
	}

	static void Destroy()
	{
		if (nullptr == Inst_)
		{
			return;
		}

		delete Inst_;
		Inst_ = nullptr;
	}

	GameEngineImage* Find(const std::string& _Name);

	// ���� ����ִ� �̹����� ����� ���.
	GameEngineImage* Create(const std::string& _Name, const float4& _Scale);
	GameEngineImage* Create(const std::string& _Name, HDC _DC);

	GameEngineImage* Load(const std::string& _Path);
	GameEngineImage* Load(const std::string& _Path, const std::string& _Name);



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
	std::map<std::string, GameEngineImage*> AllRes;
};

