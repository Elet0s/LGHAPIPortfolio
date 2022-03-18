#pragma once
class GameEngnieImage
{
private:
	// constrcuter destructer
	GameEngnieImage();
	~GameEngnieImage();

	// delete Function
	GameEngnieImage(const GameEngnieImage& _Other) = delete;
	GameEngnieImage(GameEngnieImage&& _Other) noexcept = delete;
	GameEngnieImage& operator=(const GameEngnieImage& _Other) = delete;
	GameEngnieImage& operator=(GameEngnieImage&& _Other) noexcept = delete;
};