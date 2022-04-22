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
	SetPosition({ 1780,540 });
	MenuBackGroundRender02_ = CreateRendererToScale("MainBG02.bmp", { Width_ ,Hight_ });
	MenuBackGroundRender02_->SetScale({ Width_, Hight_ });

}
void MenuBackGround02::Render()
{

}
void MenuBackGround02::Update()
{
	SetMove(float4::LEFT * GameEngineTime::GetDeltaTime() * Speed_);
	if (GetPosition().x <= -260)
	{
		SetPosition({ 1760,540 });
	}
}