#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class GameUi : public GameEngineActor
{
public:
	// constrcuter destructer
	GameUi();
	~GameUi();

	// delete Function
	GameUi(const GameUi& _Other) = delete;
	GameUi(GameUi&& _Other) noexcept = delete;
	GameUi& operator=(const GameUi& _Other) = delete;
	GameUi& operator=(GameUi&& _Other) noexcept = delete;

protected:

private:
	void Start() override;
	void Render() override;
};

