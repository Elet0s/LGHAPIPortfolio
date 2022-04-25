#include"MenuBotUI.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>

MenuBotUI::MenuBotUI()
	: Width_(1920)
	, Hight_(640)
	, MenuBotUIRender_(nullptr)
	, Speed_(2000.f)
{

}
MenuBotUI::~MenuBotUI()
{

}
void MenuBotUI::Start()
{
	SetPosition({ 960,740 });
	MenuBotUIRender_ = CreateRendererToScale("MenuBG.bmp", { Width_ ,Hight_ });
	MenuBotUIRender_->SetScale({ Width_, Hight_ });

}
void MenuBotUI::Render()
{


}
void MenuBotUI::Update()
{
	if (GetPosition().y <= 1308)//1034
	{
		SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * Speed_);
	}
}