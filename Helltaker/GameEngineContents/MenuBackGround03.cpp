#include"MenuBackGround03.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>

MenuBackGround03::MenuBackGround03()
	: Width_(1960)
	, Hight_(544)
	, MenuBackGroundRender03_(nullptr)
	, Speed_(150.f)
{

}
MenuBackGround03::~MenuBackGround03()
{

}
void MenuBackGround03::Start()
{
	SetPosition({ 3020,540 });
	MenuBackGroundRender03_ = CreateRendererToScale("MainBG01.bmp", { Width_ ,Hight_ });
	MenuBackGroundRender03_->SetScale({ Width_, Hight_ });

}
void MenuBackGround03::Render()
{

}
void MenuBackGround03::Update()
{
	SetMove(float4::LEFT * GameEngineTime::GetDeltaTime() * Speed_);
	if (GetPosition().x <= -260)
	{
		SetPosition({ 1760,540 });
	}
}