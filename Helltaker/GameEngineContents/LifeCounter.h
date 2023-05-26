#pragma once
#include <GameEngine/GameEngineActor.h>
#include<GameEngine/GameEngineFont.h>


class LifeCounter : public GameEngineActor // player 만들고 만들 것
{
public:

	GameEngineFont LifeFont_;
	int LifePoint_;
	std::string LifePointStr_;
private:

public:
	LifeCounter();
	~LifeCounter();

	LifeCounter(const LifeCounter& _Other) = delete;
	LifeCounter(LifeCounter&& _Other) noexcept = delete;
	LifeCounter& operator=(const LifeCounter& _Other) = delete;
	LifeCounter& operator=(LifeCounter&& _Other) noexcept = delete;

	void Start() override;
private:
	void Update() override;
	void Render() override;
};