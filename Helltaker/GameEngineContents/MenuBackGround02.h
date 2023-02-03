#pragma once
#include <GameEngine/GameEngineActor.h>

class MenuBackGround02 : public GameEngineActor
{
public:
	MenuBackGround02();
	~MenuBackGround02();


	MenuBackGround02(const MenuBackGround02& _Other) = delete;
	MenuBackGround02(MenuBackGround02&& _Other) noexcept = delete;
	MenuBackGround02& operator=(const MenuBackGround02& _Other) = delete;
	MenuBackGround02& operator=(MenuBackGround02&& _Other) noexcept = delete;
	void Start();
protected:

	void Render();
	void Update();
private:
	float Width_;
	float Hight_;
	float Speed_;
	GameEngineRenderer* MenuBackGroundRender02_;

};