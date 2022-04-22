#include"MenuBackGround00.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>

MenuBackGround00::MenuBackGround00()
	: Width_(1920)
	, Hight_(1080)
	, MenuBackGroundRender00_(nullptr)
{

}
MenuBackGround00::~MenuBackGround00()
{

}
void MenuBackGround00::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	MenuBackGroundRender00_ = CreateRendererToScale("MenuBG.bmp", { Width_ ,Hight_ });
	MenuBackGroundRender00_->SetScale({ Width_, Hight_ });

}
void MenuBackGround00::Render()
{

}