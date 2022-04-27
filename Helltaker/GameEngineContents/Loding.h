#pragma once
#include <GameEngine/GameEngineActor.h>

class Loding : public GameEngineActor
{
private:
	Loding();
	~Loding();

	Loding(const Loding& _Other) = delete;
	Loding(Loding&& _Other) noexcept = delete;
	Loding& operator=(const Loding& _Other) = delete;
	Loding& operator=(Loding&& _Other) noexcept = delete;

protected:
	void Start();
	void Update();
private:
	GameEngineRenderer* LodingRender_;
};