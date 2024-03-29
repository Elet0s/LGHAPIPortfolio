#include"MenuBackGround01.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>

MenuBackGround01::MenuBackGround01()
	: Width_(1960)
	, Hight_(544)
	, MenuBackGroundRender01_(nullptr)
	, Speed_(150.f)
{

}
MenuBackGround01::~MenuBackGround01()
{

}
void MenuBackGround01::Start()
{
	SetPosition({ 980,440 });
	MenuBackGroundRender01_ = CreateRendererToScale("MenuBGAnimation.bmp", { Width_ ,Hight_ });
	MenuBackGroundRender01_->SetScale({ Width_, Hight_ });

}
void MenuBackGround01::Render()
{

}
void MenuBackGround01::Update()
{
	SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * Speed_);
	if (GetPosition().x >= 2940)
	{
		SetPosition({ -980,440 });
	}
}