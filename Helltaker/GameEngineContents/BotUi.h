#pragma once
#include <GameEngine/GameEngineActor.h>

// ���� :
class BotUI : public GameEngineActor
{
public:
	// constrcuter destructer
	BotUI();
	~BotUI();

	// delete Function
	BotUI(const BotUI& _Other) = delete;
	BotUI(BotUI&& _Other) noexcept = delete;
	BotUI& operator=(const BotUI& _Other) = delete;
	BotUI& operator=(BotUI&& _Other) noexcept = delete;

protected:

private:
	void Start() override;
	void Render() override;
};

