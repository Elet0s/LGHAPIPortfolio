#pragma once
#include <GameEngine/GameEngineActor.h>

class EndText : public GameEngineActor
{
protected:
	void Start();
	void Render();
	void Update();
private:
	float TextCount_;
	GameEngineRenderer* EndTextRender01;
	GameEngineRenderer* EndTextRender02;
public:
	EndText();
	~EndText();

	EndText(const EndText& _Other) = delete;
	EndText(EndText&& _Other) noexcept = delete;
	EndText& operator=(const EndText& _Other) = delete;
	EndText& operator=(EndText&& _Other) noexcept = delete;

};