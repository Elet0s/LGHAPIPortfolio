#include"MenuBackGround02.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>

MenuBackGround02::MenuBackGround02()
	: Width_(1960)
	, Hight_(544)
	, MenuBackGroundRender02_(nullptr)
	, Speed_(150.f)
{

}
MenuBackGround02::~MenuBackGround02()
{

}
void MenuBackGround02::Start()
{
	SetPosition({ -980,440 });
	MenuBackGroundRender02_ = CreateRendererToScale("MenuBGAnimation.bmp", { Width_ ,Hight_ });
	MenuBackGroundRender02_->SetScale({ Width_, Hight_ });

}
void MenuBackGround02::Render()
{

}
void MenuBackGround02::Update()
{
	SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * Speed_);
	if (GetPosition().x >= 2940)
	{
		SetPosition({ -980 ,440 });
	}
}