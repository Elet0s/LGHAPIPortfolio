#pragma once
#include <GameEngine/GameEngineActor.h>
#include<GameEngine/GameEngineRenderer.h>
class GameEngineRenderer;
class TopUi :	public GameEngineActor
{
public:
	TopUi();
	~TopUi();


	TopUi(const TopUi& _Other) = delete;
	TopUi(TopUi&& _Other) noexcept = delete;
	TopUi& operator=(const TopUi& _Other) = delete;
	TopUi& operator=(TopUi&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Render() override;
private:
	GameEngineRenderer* TopUiRender01_;
	GameEngineRenderer* TopUiRender02_;
};