#pragma once
class GameApp
{
private:
	// constrcuter destructer
	GameApp();
	~GameApp();

	// delete Function
	GameApp(const GameApp& _Other) = delete;
	GameApp(GameApp&& _Other) noexcept = delete;
	GameApp& operator=(const GameApp& _Other) = delete;
	GameApp& operator=(GameApp&& _Other) noexcept = delete;
};