#include"MenuTopUi.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>

MenuTopUi::MenuTopUi()
	: Width_(1920)
	, Hight_(440)
	, MenuTopUiRender_(nullptr)
	, Speed_(2000.f)
{

}
MenuTopUi::~MenuTopUi()
{

}
void MenuTopUi::Start()
{
	SetPosition({ 960,220 });
	MenuTopUiRender_ = CreateRendererToScale("MenuBG.bmp", { Width_ ,Hight_ });
	MenuTopUiRender_->SetScale({ Width_, Hight_ });

}
void MenuTopUi::Render()
{


}
void MenuTopUi::Update()
{
	if (GetPosition().y >= -768)//-494
	{
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * Speed_);
	}
}