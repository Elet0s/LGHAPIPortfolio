#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRenderer.h>

class Monster : public GameEngineActor
{
public:

	Monster();
	~Monster();
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;
	bool RState_;
protected:
	void Start() override;
	void Update() override;
private:
	GameEngineRenderer* MonsterRender_;

};