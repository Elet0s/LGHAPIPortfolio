#pragma once
#include <GameEngine/GameEngineActor.h>

class MenuBackGround00 : public GameEngineActor
{
public:
	MenuBackGround00();
	~MenuBackGround00();

	MenuBackGround00(const MenuBackGround00& _Other) = delete;
	MenuBackGround00(MenuBackGround00&& _Other) noexcept = delete;
	MenuBackGround00& operator=(const MenuBackGround00& _Other) = delete;
	MenuBackGround00& operator=(MenuBackGround00&& _Other) noexcept = delete;
	void Start();
protected:

	void Render();
private:
	float Width_;
	float Hight_;
	GameEngineRenderer* MenuBackGroundRender00_;

};