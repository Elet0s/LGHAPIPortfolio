#pragma once
#include <GameEngine/GameEngineActor.h>

class StartText : public GameEngineActor
{
public:
	StartText();
	~StartText();

	StartText(const StartText& _Other) = delete;
	StartText(StartText&& _Other) noexcept = delete;
	StartText& operator=(const StartText& _Other) = delete;
	StartText& operator=(StartText&& _Other) noexcept = delete;
	void Start();
protected:

	void Render();
	void Update();
private:
	float TextCount_;
	GameEngineRenderer* StartTextRender01;
	GameEngineRenderer* StartTextRender02;
	GameEngineRenderer* StartTextRender03;
	GameEngineRenderer* StartTextRender04;
	GameEngineRenderer* StartTextRender05;
	GameEngineRenderer* StartTextRender06;

public:
	inline float GetStartTextCount()
	{
		return TextCount_;
	}
};