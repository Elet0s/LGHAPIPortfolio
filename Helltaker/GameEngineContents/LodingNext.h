#pragma once
#include <GameEngine/GameEngineActor.h>

class LodingNext : public GameEngineActor
{
protected:

	void Update();
private:
	GameEngineRenderer* LodingNextRender_;
public:
	void Start();
	LodingNext();
	~LodingNext();


	LodingNext(const LodingNext& _Other) = delete;
	LodingNext(LodingNext&& _Other) noexcept = delete;
	LodingNext& operator=(const LodingNext& _Other) = delete;
	LodingNext& operator=(LodingNext&& _Other) noexcept = delete;

};