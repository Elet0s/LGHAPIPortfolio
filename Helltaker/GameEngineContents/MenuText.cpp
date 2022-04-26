#include"MenuText.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineInput.h>

MenuText::MenuText()
	:TextCount_(0)
	, MenuTextRenderer001_(nullptr)
	, MenuTextRenderer002_(nullptr)

{

}
MenuText::~MenuText()
{

}
void MenuText::Start()
{
	SetPosition({ 960,830 });
	MenuTextRenderer001_ = CreateRendererToScale("MenuText001.bmp", { 654 ,128 });

}
void MenuText::Render()
{


}
void MenuText::Update()
{
	if (true == GameEngineInput::GetInst()->IsDown("Next"))
	{
		if (TextCount_ == 0)
		{
			MenuTextRenderer001_->Death();
			MenuTextRenderer002_ = CreateRendererToScale("MenuText002.bmp", { 569 ,140 });
			TextCount_ += 1;
		}
		else if (TextCount_ == 1)
		{
			MenuTextRenderer002_->Death();
		}
	}
}