#pragma once
#include <GameEngine/GameEngineActor.h>

// ���� :
class Player : public GameEngineActor
{
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

protected:

private:
	GameEngineRenderer* PlayerIdleRender_;
	float Speed_;
	void Start() override;
	void Update() override;
	void Render() override;


private:
	void IdleUpdate();
	void MoveUpdate();
	void AttackUpdate();
	void IdleStart();
	void MoveStart();
};


