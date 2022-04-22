#pragma once
#include <GameEngine/GameEngineActor.h>

class MenuBackGround01 : public GameEngineActor
{
public:
	MenuBackGround01();
	~MenuBackGround01();


	MenuBackGround01(const MenuBackGround01& _Other) = delete;
	MenuBackGround01(MenuBackGround01&& _Other) noexcept = delete;
	MenuBackGround01& operator=(const MenuBackGround01& _Other) = delete;
	MenuBackGround01& operator=(MenuBackGround01&& _Other) noexcept = delete;
protected:
	void Start();
	void Render();
	void Update();
private:
	float Width_;
	float Hight_;
	float Speed_;
	GameEngineRenderer* MenuBackGroundRender01_;

};