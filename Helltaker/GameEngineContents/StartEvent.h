#pragma once
#include <GameEngine/GameEngineActor.h>

class StartEvent : public GameEngineActor
{
public:
	StartEvent();
	~StartEvent();

	StartEvent(const StartEvent& _Other) = delete;
	StartEvent(StartEvent&& _Other) noexcept = delete;
	StartEvent& operator=(const StartEvent& _Other) = delete;
	StartEvent& operator=(StartEvent&& _Other) noexcept = delete;
	void Start();
protected:

	void Update();
private:
	GameEngineRenderer* StartEvent_;
	float BgCount_;
};