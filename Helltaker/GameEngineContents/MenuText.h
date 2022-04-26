#pragma once
#include <GameEngine/GameEngineActor.h>

class MenuText : public GameEngineActor
{
protected:
	void Start();
	void Render();
	void Update();
private:
	float TextCount_;
	GameEngineRenderer* MenuTextRenderer001_;
	GameEngineRenderer* MenuTextRenderer002_;
public:
	MenuText();
	~MenuText();

	MenuText(const MenuText& _Other) = delete;
	MenuText(MenuText&& _Other) noexcept = delete;
	MenuText& operator=(const MenuText& _Other) = delete;
	MenuText& operator=(MenuText&& _Other) noexcept = delete;

};