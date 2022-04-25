#include"MenuText001.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>

MenuText001::MenuText001()
	: Width_(654)
	, Hight_(130)
	, MenuTextRenderer001_(nullptr)
{

}
MenuText001::~MenuText001()
{

}
void MenuText001::Start()
{
	SetPosition({ 960,830 });
	MenuTextRenderer001_ = CreateRendererToScale("MenuText001.bmp", { Width_ ,Hight_ });
	MenuTextRenderer001_->SetScale({ Width_, Hight_ });

}
void MenuText001::Render()
{


}