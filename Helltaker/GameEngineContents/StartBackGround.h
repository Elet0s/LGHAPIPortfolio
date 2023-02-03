#pragma once
#include <GameEngine/GameEngineActor.h>

class StartBackGround : public GameEngineActor
{
public:
	StartBackGround();
	~StartBackGround();

	StartBackGround(const StartBackGround& _Other) = delete;
	StartBackGround(StartBackGround&& _Other) noexcept = delete;
	StartBackGround& operator=(const StartBackGround& _Other) = delete;
	StartBackGround& operator=(StartBackGround&& _Other) noexcept = delete;
	void Start();
protected:

	void Update();
private:
	GameEngineRenderer* StartBackGround00_;
	GameEngineRenderer* StartBackGround01_;
	float BgCount_;
};