#pragma once
#include "GameEngineImage.h" 
#include <GameEngineBase/GameEngineMath.h>
#include <map>

// 기본적으로 리소스는 그냥 쓸수도 있지만
// 관리되는 리소스들은 전부다 이름이 있다고 보고 쓸겁니다.

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

private:
	// constrcuter destructer
	GameEngineImageManager();
	~GameEngineImageManager();

	// delete Function
	GameEngineImageManager(const GameEngineImageManager& _Other) = delete;
	GameEngineImageManager(GameEngineImageManager&& _Other) noexcept = delete;
	GameEngineImageManager& operator=(const GameEngineImageManager& _Other) = delete;
	GameEngineImageManager& operator=(GameEngineImageManager&& _Other) noexcept = delete;


/// <summary>
/// 일반이미지
/// </summary>
public:
	GameEngineImage* Find(const std::string& _Name);

	// 내가 비어있는 이미지를 만드는 기능이다.
	GameEngineImage* Create(const std::string& _Name, const float4& _Scale);
	GameEngineImage* Create(const std::string& _Name, HDC _DC);

	GameEngineImage* Load(const std::string& _Path);
	GameEngineImage* Load(const std::string& _Path, const std::string& _Name);

private:
	std::map < std::string, GameEngineImage* > AllRes;

	/// <summary>
/// 일반이미지
/// </summary>
public:
	GameEngineFolderImage* FolderImageFind(const std::string& _Name);
	GameEngineFolderImage* FolderImageLoad(const std::string& _Path);
	GameEngineFolderImage* FolderImageLoad(const std::string& _Path, const std::string& _Name);


protected:

private:
	std::map<std::string, GameEngineFolderImage*> AllFolderRes;

};

