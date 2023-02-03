#pragma once
#include <GameEngine/GameEngineActor.h>
#include<GameEngine/GameEngineRenderer.h>
class GameEngineRenderer;
class BotUi : public GameEngineActor
{
public:
	BotUi();
	~BotUi();
	BotUi(const BotUi& _Other) = delete;
	BotUi(BotUi&& _Other) noexcept = delete;
	BotUi& operator=(const BotUi& _Other) = delete;
	BotUi& operator=(BotUi&& _Other) noexcept = delete;
	void Start() override;
protected:

	void Render() override;
private:
	GameEngineRenderer* BotUiRender01_;
	GameEngineRenderer* BotUiRender02_;


};

