#pragma once
class GamePlayUi
{
private:
	// constrcuter destructer
	GamePlayUi();
	~GamePlayUi();

	// delete Function
	GamePlayUi(const GamePlayUi& _Other) = delete;
	GamePlayUi(GamePlayUi&& _Other) noexcept = delete;
	GamePlayUi& operator=(const GamePlayUi& _Other) = delete;
	GamePlayUi& operator=(GamePlayUi&& _Other) noexcept = delete;
};