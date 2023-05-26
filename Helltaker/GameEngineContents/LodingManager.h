#pragma once
#include<GameEngine/GameEngineActor.h>

class LodingManager : public GameEngineActor
{
public:


protected:

private:
	GameEngineRenderer* LodingStartRender_;
	GameEngineRenderer* LodingEndRender_;
	bool SafeLoding_; // false∏È ¡ÿ∫Òµ  
	bool ChapterReload_;

public:
	LodingManager();
	~LodingManager();

	LodingManager(const LodingManager& _Other) = delete;
	LodingManager(LodingManager&& _Other) noexcept = delete;
	LodingManager& operator=(const LodingManager& _Other) = delete;
	LodingManager& operator=(LodingManager&& _Other) noexcept = delete;

	void Shoot(const std::string& _Text);
	void Reload();
	void Start();
	void Update();

protected:


private:

};