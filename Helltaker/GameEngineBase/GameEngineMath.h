#pragma once
class GameEngineMath
{
private:
	// constrcuter destructer
	GameEngineMath();
	~GameEngineMath();

	// delete Function
	GameEngineMath(const GameEngineMath& _Other) = delete;
	GameEngineMath(GameEngineMath&& _Other) noexcept = delete;
	GameEngineMath& operator=(const GameEngineMath& _Other) = delete;
	GameEngineMath& operator=(GameEngineMath&& _Other) noexcept = delete;
};