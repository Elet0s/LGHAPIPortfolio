#pragma once
#include <GameEngine/GameEngineActor.h>

class Loding : public GameEngineActor
{
private:
	GameEngineRenderer* LodingRender_;
protected:

	void Update();

public:
	void Start();
	void Reload();
	Loding();
	~Loding();

	Loding(const Loding& _Other) = delete;
	Loding(Loding&& _Other) noexcept = delete;
	Loding& operator=(const Loding& _Other) = delete;
	Loding& operator=(Loding&& _Other) noexcept = delete;
};