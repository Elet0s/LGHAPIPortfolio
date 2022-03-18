#pragma once
class GameEngineNameObject
{
private:
	// constrcuter destructer
	GameEngineNameObject();
	~GameEngineNameObject();

	// delete Function
	GameEngineNameObject(const GameEngineNameObject& _Other) = delete;
	GameEngineNameObject(GameEngineNameObject&& _Other) noexcept = delete;
	GameEngineNameObject& operator=(const GameEngineNameObject& _Other) = delete;
	GameEngineNameObject& operator=(GameEngineNameObject&& _Other) noexcept = delete;
};