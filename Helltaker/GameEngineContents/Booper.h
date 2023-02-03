#pragma once
#include <GameEngine/GameEngineActor.h>

class Booper : public GameEngineActor
{
public:
	Booper();
	~Booper();

	Booper(const Booper& _Other) = delete;
	Booper(Booper&& _Other) noexcept = delete;
	Booper& operator=(const Booper& _Other) = delete;
	Booper& operator=(Booper&& _Other) noexcept = delete;

	void Start();
protected:

	void Update();
private:
	GameEngineRenderer* BooperRender_;
};