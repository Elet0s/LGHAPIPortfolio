#pragma once
#include <GameEngine/GameEngineActor.h>

class MenuBackGround03 : public GameEngineActor
{
public:
	MenuBackGround03();
	~MenuBackGround03();


	MenuBackGround03(const MenuBackGround03& _Other) = delete;
	MenuBackGround03(MenuBackGround03&& _Other) noexcept = delete;
	MenuBackGround03& operator=(const MenuBackGround03& _Other) = delete;
	MenuBackGround03& operator=(MenuBackGround03&& _Other) noexcept = delete;
protected:
	void Start();
	void Render();
	void Update();
private:
	float Width_;
	float Hight_;
	float Speed_;
	GameEngineRenderer* MenuBackGroundRender03_;

};