#pragma once
#include <GameEngine/GameEngineActor.h>
#include<GameEngine/GameEngineRenderer.h>
class ClearEvent : public GameEngineActor
{
public:
	ClearEvent();
	~ClearEvent();
	ClearEvent(const ClearEvent& _Other) = delete;
	ClearEvent(ClearEvent&& _Other) noexcept = delete;
	ClearEvent& operator=(const ClearEvent& _Other) = delete;
	ClearEvent& operator=(ClearEvent&& _Other) noexcept = delete;
	void Start() override;
protected:

	void Render() override;
	void Update();
private:
	GameEngineRenderer* ClearBackGroundRender_;
};