#pragma once
#include <GameEngine/GameEngineActor.h>

class MenuBotUI : public GameEngineActor
{
public:
	MenuBotUI();
	~MenuBotUI();

	MenuBotUI(const MenuBotUI& _Other) = delete;
	MenuBotUI(MenuBotUI&& _Other) noexcept = delete;
	MenuBotUI& operator=(const MenuBotUI& _Other) = delete;
	MenuBotUI& operator=(MenuBotUI&& _Other) noexcept = delete;
	void Start();
protected:

	void Render();
	void Update();
private:
	float Width_;
	float Hight_;
	float Speed_;
	GameEngineRenderer* MenuBotUIRender_;

};